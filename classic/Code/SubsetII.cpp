class Solution {
public:
    void generateSub(vector<int>&S,int step,vector<vector<int> >&result,vector<int>&output){
        for(int i=step;i<S.size();i++){
            output.push_back(S[i]);
            result.push_back(output);
            if(i<S.size()-1){
                generateSub(S,i+1,result,output);
            }
            output.pop_back();
            while(i<S.size()-1&&S[i]==S[i+1]){
                i++;
            }
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> >result;
        vector<int>output;
        if(S.size()==0)return result;
        result.push_back(output);
        sort(S.begin(),S.end());
        generateSub(S,0,result,output);
    }
};
