class Solution {

public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int>result;

        set<int>set1;

        set<int>set2;

        for(int i=0;i<nums1.size();i++){

            set1.insert(nums1[i]);

        }

        for(int j=0;j<nums2.size();j++){

            if(set1.find(nums2[j])!=set1.end()){

                set2.insert(nums2[j]);

            }

        }

        for(set<int>::iterator it=set2.begin();it!=set2.end();it++){

            result.push_back(*it);

        }

        return result;

    }

};
