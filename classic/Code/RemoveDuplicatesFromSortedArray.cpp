class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2)return n;
        int index=0;
        for(int i=0;i<n;i++){
            if(i==0||A[i]!=A[i-1]){
                A[index]=A[i];
                index++;
            }
        }
        return index;
    }
};
