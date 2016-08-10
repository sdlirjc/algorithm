class FenwickTree{

    vector<int>C;

    int n;

    inline int lowbit(int x){

        return x&-x;

    }

public:

    FenwickTree(int _n){

        n=_n;

        C=vector<int>(n+1,0);

    }

    void add(int x,int val){

        

        while(x<=n){

            C[x]+=val;

            x+=lowbit(x);

        }

        

    }

    int sum(int x){

        int tmp=0;

        while(x>0){

            tmp+=C[x];

            x-=lowbit(x);

        }

        return tmp;

    }

    

};

class Solution {

public:

    vector<int> countSmaller(vector<int>& nums) {

        vector<int>tmp=nums;

        FenwickTree fenwickTree(nums.size());

        sort(tmp.begin(),tmp.end());

        map<int,int>dict;

        for(int i=0;i<nums.size();i++){

            dict[tmp[i]]=i+1;

        }

        vector<int>ans(nums.size(),0);

        for(int i=nums.size()-1;i>=0;i--){

            //从右向左扫描，每次统计比其小于1的个数（就是求和），然后把当前的数加入Fenwick中（当前数在序列中排的位置（因为前面离散化了）个数加1)

            ans[i]=fenwickTree.sum(dict[nums[i]]-1);

            fenwickTree.add(dict[nums[i]],1);

        }

        return ans;

    }

    vector<int> countSmallerBrutal(vector<int>& nums) {

        vector<int>ret(nums.size(),0);

        for(int i=0;i<ret.size();i++){

            int tmp=0;

            for(int j=0;j<nums.size();j++){

                if(nums[j]<ret[i]){

                    tmp++;

                }

            }

            ret[i]=tmp;

        }

        return ret;

    }

};
