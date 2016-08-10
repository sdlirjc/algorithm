class Solution {
public:
	Solution();
	virtual ~Solution();
    int minPatches(vector<int>& nums, long n) {
        if (n==0){
            return 0;
        }
        long miss=1;
        int count=0;
        int i=0;
        while (miss<=n){
        	cout<<"miss:"<<miss<<"count:"<<count<<endl;
            if(i<nums.size()){
            	if(miss>=nums[i]){
            		miss+=nums[i];
            		i++;
            	}else{
                    miss*=2;
                    count++;
            	}
            }else{
                miss*=2;
                count++;
            }
        }
        return count;
    }
};


