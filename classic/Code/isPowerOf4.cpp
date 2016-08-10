class Solution {

public:

    bool isPowerOfFour(int num) {

        if(num<=0){

            return false;

        }

        if(num==1){

            return true; 

        }

        if(num==2){

            return false; 

        }

        vector<int>v;

        while (num>0){

            v.push_back(num&0x1);

            num=num>>1;

        }

        int counter=0;

        for(int i=0;i<v.size()-1;i++){

            if(v[i]==1){

                return false;

            }

            counter++;

        }

        if(counter%2!=0){

            return false;

        }

        return v[v.size()-1];

    }

};
