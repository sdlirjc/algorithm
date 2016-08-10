class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3)return n;
        int counter=0;
        int index=0;
        for(int i=0;i<n;i++){
            if(A[i]==A[i-1]){
                counter++;
            }else{
                counter=0;
            }
            if(counter<2){
                A[index]=A[i];
                index++;
            }
        }
        return index;
    }
};
