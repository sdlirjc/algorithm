class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N=gas.size();
        vector<int>diff(N);
        for (int i=0;i<N;i++){
            diff[i]=gas[i]-cost[i];
        }
        int left=0,sum=0,start=0;
        for(int i=0;i<N;i++){
            left+=diff[i];
            sum+=diff[i];
            if(sum<0){
                sum=0;
                start=i+1;
            }
        }
        if(left<0){
            return -1;
        }else{
            return start;
        }
    }
};
