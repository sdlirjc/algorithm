class Solution {

public:

    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int>ret;

        int left=0;

        int right=numbers.size()-1;

        while(left<right){

            int tmp=numbers[left]+numbers[right];

            if(tmp==target){

                ret.push_back(left+1);

                ret.push_back(right+1);

                return ret;

            }else if(tmp>target){

                right--;

            }else{

                left++;

            }

        }

        return ret;

    }

};
