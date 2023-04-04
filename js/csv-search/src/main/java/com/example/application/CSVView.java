package com.example.application;

import com.opencsv.CSVParser;
import com.opencsv.CSVParserBuilder;
import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;
import com.opencsv.exceptions.CsvException;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.grid.Grid;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import com.vaadin.flow.component.textfield.TextField;
import com.vaadin.flow.component.upload.Upload;
import com.vaadin.flow.component.upload.receivers.MemoryBuffer;
import com.vaadin.flow.data.value.ValueChangeMode;
import com.vaadin.flow.router.Route;
import com.vaadin.flow.shared.util.SharedUtil;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

@Route("")
public class CSVView extends VerticalLayout {
    private Grid<String[]> grid = new Grid<>();
    List<String[]> cache=new ArrayList<>();

    public CSVView() {
        MemoryBuffer buffer = new MemoryBuffer();
        Upload upload = new Upload(buffer);
        upload.setAcceptedFileTypes(".csv");
        upload.addSucceededListener(e -> {
            displayCsv(buffer.getInputStream());
        });
        add(upload, grid);
        TextField filterText = new TextField();
        filterText.setPlaceholder("Filter by name...");
        filterText.setClearButtonVisible(true);
        filterText.setValueChangeMode(ValueChangeMode.LAZY);
        Button searchButton = new Button("Search");
        HorizontalLayout toolbar = new HorizontalLayout(filterText, searchButton);
        searchButton.addClickListener(e->{filter(filterText.getValue());});
        add(toolbar, grid);
    }
    private void filter(String keyword) {
        List<String[]>items=new ArrayList<>();
        for(int i=0;i<cache.size();i++){
            boolean flag=false;
            for(int j=0;j<cache.get(i).length;j++){
                if(cache.get(i)[j].toLowerCase().contains(keyword.toLowerCase())){
                    flag=true;
                    break;
                }
            }
            if(flag){
                items.add(cache.get(i));
            }
        }
        grid.setItems(items);

    }

    private void displayCsv(InputStream resourceAsStream) {
        // Change the separator if needed to something else (for example, to ',').
        CSVParser parser = new CSVParserBuilder().withSeparator(';').build();
        CSVReader reader =
                new CSVReaderBuilder(new InputStreamReader(resourceAsStream)).withCSVParser(parser).build();
        try {
            List<String[]> entries = reader.readAll();
            String[] headers = entries.get(0);
            grid.removeAllColumns();
            for (int i = 0; i < headers.length; i++) {
                int colIndex = i;
                String header = SharedUtil.camelCaseToHumanFriendly(headers[colIndex]);
                grid.addColumn(row -> row[colIndex])
                        .setHeader(header);
            }
            cache=entries.subList(1, entries.size());
            grid.setItems(entries.subList(1, entries.size()));
        } catch (IOException | CsvException e) {
            e.printStackTrace();
        }
    }
}