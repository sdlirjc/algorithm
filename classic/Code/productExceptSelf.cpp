class Solution {

public:

    vector<int> productExceptSelf(vector<int>& nums) {

        int count=0;

        for(int num:nums){

            if(!num)count++;

        }

        if(count==nums.size()){return nums;}

        int mul = 1;

        for(int num:nums){

            if(num){

                mul *= num ;

            }

        }

        for(int i=0;i<nums.size();i++){

            if(nums[i]){

                if(count){

                    nums[i] = 0;

                }else{

                    nums[i] = mul / nums[i];

                }

            }else{

                if(count>1){

                    nums[i] = 0;

                }else{

                    nums[i] = mul;

                }

            }

        }

        return nums;

    }

};
