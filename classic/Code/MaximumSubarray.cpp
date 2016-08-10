class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ma=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            ma=max(ma,sum);
            sum=max(sum,0);
        }
        return ma;
    }
};
