class Solution {
public:
    int consecutiveLength(int k,unordered_map<int,int>&hashmap,vector<int>&length){
        if(hashmap.find(k)==hashmap.end()){
            return 0;
        }
        int i=hashmap[k];
        if(length[i]>0){
            return length[i];
        }
        length[i]=consecutiveLength(k-1,hashmap,length)+1;
        return length[i];
    }
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,int>hashmap;
        vector<int>length(num.size(),0);
        for(int i=0;i<num.size();i++){
            hashmap[num[i]]=i;
        }
        for(int i=0;i<num.size();i++){
            if(length[i]>0)continue;
            length[i]=consecutiveLength(num[i],hashmap,length);
        }
        int m=0;
        for(int i=0;i<num.size();i++){
            m=max(m,length[i]);
        }
        return m;
    }
};
