class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1||s.size()==0){
            return s;
        }
        string val;
        for(int i=0;i<nRows;i++){
            int j=0;
            int index=j*(2*nRows-2)+i;
            while(index<s.size()){
                val.push_back(s[index]);
                if(i>0&&i<nRows-1){
                    int zigzagIndex=j*(2*nRows-2)+2*nRows-2-i;
                    if(zigzagIndex<s.size()){
                        val.push_back(s[zigzagIndex]);
                    }
                }
                j++;
                index=j*(2*nRows-2)+i;
            }
        }
        return val;
    }
};
