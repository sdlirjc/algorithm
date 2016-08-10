class Solution {
public:
    vector<vector<int> >  threeSumClosest(vector<int> &num, int target) {
        int n=num.size();
        set<string>container;
        vector<vector<int> >val;
        vector<string>numStr(n);
        if (n==0){
            return val;
        }
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            numStr[i]=to_string(num[i]);
        }
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=num[i]+num[start]+num[end];
                if(sum==target){
                    vector<int>candidate(3);
                    candidate[0]=num[i];
                    candidate[1]=num[start];
                    candidate[2]=num[end];
                    val.push_back(candidate);
                    start++;
                    end--;
                    while(start<end&&num[start]==num[start-1]){start++;}
                    while(start<end&&num[end]==num[end+1]){end--;}
                }else if(sum>target){
                    end--;
                }else{
                    start++;
                }
            }
            if(i<n){
                while(num[i]==num[i+1]){i++;}
            }
        }
        return val;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        return threeSumClosest(num,0);
    }
};

