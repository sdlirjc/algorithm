class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial=1;
        vector<int>num(n,1);
        for(int i=1;i<n;i++){
            factorial*=i+1;
            num[i]=i+1;
        }
        string result;
        k=k-1;
        factorial/=n;
        for(int i=0;i<n;i++){
            int choosed=k/factorial;
            result.push_back(num[choosed]+'0');
            for(int j=choosed;j<n;j++){
                num[j]=num[j+1];
            }
            k=k%factorial;
            if(i!=n-1)factorial/=n-i-1;
        }
        return result;
    }
};

