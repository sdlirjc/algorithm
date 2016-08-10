class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==1){
            return 10;
        }
        vector<int>num(10,0);
        num[0]=9;
        for(int i=1;i<10;i++){
            num[i]=num[i-1]*(10-i);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=num[i];
        }
        return sum+1;
    }
};
