class Solution {

public:

    vector<int> singleNumber(vector<int>& nums) {

        int tmp=0;

        for(int v:nums){

            tmp^=v;

        }

        int mask=tmp&(-tmp);

        int x=0,y=0;

        for(int v:nums){

            if(v&mask){

                x^=v;

            }else{

                y^=v;

            }

        }

        return vector<int>{x,y};

    }

};
