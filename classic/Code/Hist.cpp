#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

string normalize(string input){
    string output;
    for(int i=0;i<input.length();i++){
        if(input[i]>='A'&&input[i]<='Z'){
            output+=input[i]+('a'-'A');
        }else if (input[i]>='a'&&input[i]<='z'){
            output+=input[i];
        }
    } 
    return output;
}

void merge(vector<string>&keys,vector<int>&freq,const vector<string>leftKey, const vector<int>leftFreq,const vector<string>rightKey, 
    const vector<int> rightFreq)
{
    int counterLeft=0;
    int counterRight=0;
    keys.clear();
    freq.clear();
    while (counterRight<rightFreq.size()&&counterLeft<leftFreq.size()){
        if (rightFreq[counterRight]>leftFreq[counterLeft]){
            freq.push_back(rightFreq[counterRight]);
            keys.push_back(rightKey[counterRight]);
            counterRight++;
        }else {
            freq.push_back(leftFreq[counterLeft]);
            keys.push_back(leftKey[counterLeft]);
            counterLeft++;
        }
    }
    if(counterLeft<leftKey.size()){
        for(int i=counterLeft;i<leftKey.size();i++) {
            freq.push_back(leftFreq[i]);
            keys.push_back(leftKey[i]);
        }
    }
    if(counterRight<rightKey.size()){
        for(int i=counterRight;i<rightKey.size();i++) {
            freq.push_back(rightFreq[i]);
            keys.push_back(rightKey[i]);
        }
    }
}

void sort(vector<string>&keys,vector<int>&freq){
    if (keys.size()!=freq.size()) return;
    if (keys.size()<=1) return;
    int mid=keys.size()/2;
    vector<string>leftKey;
    vector<string>rightKey;
    vector<int>leftFreq;
    vector<int>rightFreq;
    for (int i=0;i<mid;i++){
        leftKey.push_back(keys.at(i));
        leftFreq.push_back(freq.at(i));
    }
    for (int i=mid;i<keys.size();i++){
        rightKey.push_back(keys.at(i));
        rightFreq.push_back(freq.at(i));
    }
    sort(leftKey,leftFreq);
    sort(rightKey,rightFreq);
    merge(keys, freq, leftKey, leftFreq,rightKey,rightFreq);
}

void sortMap(map<string,int>histogram){
	map<string,int>::iterator it;
	vector<string> keys;
    vector<int> freq;
	for(it=histogram.begin();it!=histogram.end();it++){
		keys.push_back(it->first);
		freq.push_back(it->second);
	}
    sort(keys,freq);
    for (int i=0;i<keys.size();i++){
        cout<<keys[i]<<" "<<freq[i]<<endl;
    }
}

map<string,int>countFreq(ifstream& in_stream){
	
	string line;
	map<string,int> histogram;
	map<string,int>::iterator it;
	while(!in_stream.eof())
	{
	    getline(in_stream,line);
		if(line.size()>0){
			vector<string>strs;

            split(strs,line,is_any_of(" .\":;,?/\\|{}[]+-*#%^@'’"));
            for (int i=0;i<strs.size();i++){
                strs[i]=normalize(strs[i]);
                if(strs[i].length()>1){
                    if (histogram.find(strs[i])==histogram.end()){
                        histogram.insert ( pair<string,int>(strs[i],1) );
                    }else{
                        map<string,int>::iterator it = histogram.find(strs[i]);
                        int freq = it->second;
                        histogram[strs[i]]=freq+1;
                    }
                }
            }
		}
	}
    //merge sort
    sortMap(histogram);    

	return histogram;
}
int main (int argc, char *argv[]) {

	if (argc!=2){ 
		cout<<"Input txt file name!"<<endl;
		return -1 ;
	}
	ifstream f(argv[1]);
	if (!f.good()) {
		cout<<"Input txt file is corrupted!"<<endl;
		f.close();
		return -2;
	}
	map<string,int>counter=countFreq(f);
	f.close();
}

