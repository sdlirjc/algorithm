class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0){
            return 0;
        }
        if(citations.size()==1){
            return min(citations[0],1);
        }
        int low=0;
        int high=citations.size()-1;
        int mid=0;
        while (low<high){
            mid=(low+high)/2;
            if (citations[mid]>(citations.size()-mid)){
                high = mid ;
            }else{
                low = mid +1;
            }
        }
        if(citations[low]==0){
            return 0;
        }else if (citations[low-1]==(citations.size()-low+1)&&citations[low-1]!=0){
            return citations.size()-low+1;
        }else{
            return citations.size()-low;
        }
    }
};
