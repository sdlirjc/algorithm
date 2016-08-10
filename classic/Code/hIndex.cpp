class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int>count(citations.size()+1,0);
        for(int i=0;i<citations.size();i++){
            if(citations[i]>citations.size()){
                count[citations.size()]++;
            }else{
                count[citations[i]]++;
            }
        }
        int h=0;
        for(int i=citations.size();i>=0;i--){
            h+=count[i];
            if(h>=i){
                return i;
            }
        }
        return 0;
    }
};
