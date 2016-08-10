class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<numbers.size();i++){
            map[numbers[i]]=i+1;
        }
        vector<int>value;
        for(int i=0;i<numbers.size();i++){
            int left=target-numbers[i];
            if(map.find(left)!=map.end()){
                if(map[left]>i+1){
                    value.push_back(i+1);
                    value.push_back(map[left]);
                    break;
                }
            }
        }
        return value;
    }
};
