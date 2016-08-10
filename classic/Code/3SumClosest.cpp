class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n=num.size();
        
        if (n==0){
            return 0;
        }
        sort(num.begin(),num.end());
        int minV=INT_MAX;
        int record=INT_MAX;
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=num[i]+num[start]+num[end];
                if(sum==target){
                    minV=0;
                    record=sum;
                    break;
                }else if(sum>target){
                    if(sum-target<minV){
                        minV=sum-target;
                        record=sum;
                    }
                    end--;
                }else{
                    if(target-sum<minV){
                        minV=target-sum;
                        record=sum;
                    }
                    start++;
                }
            }
        }
        return record;
    }
};
