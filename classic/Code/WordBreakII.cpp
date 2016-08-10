class Solution {
public:
    void solve(int start,string s,unordered_set<string> &dict,int n,vector<string>&solution,vector<char>&valid,string& result){
        if(start==n){
            //cout<<"DEBUG: "<<result<<endl;
            solution.push_back(result.substr(0,result.size()-1));
            //result="";

            return;
        }
        for(int i=start;i<n;i++){
            string sub=s.substr(start,i-start+1);
            //cout<<"sub: "<<sub<<endl;
            if(dict.find(sub)!=dict.end()){
                if(valid[i+1]==0||valid[i+1]==1){
                    int resultSize=result.size();
                    result.append(sub).append(" ");
                    int beforeChange=solution.size();
                    //cout<<"start: "<<start<<" i: "<<i<<" "<<n<<" result: "<<result<<" oldSize: "<<resultSize<<" solution: "<<solution.size()<<endl;
                    solve(i+1,s,dict,n,solution,valid,result);
                    if(solution.size()==beforeChange){
                        valid[i+1]=2;
                    }else{
                        valid[i+1]=1;
                    }
                    result=result.substr(0,resultSize);
                    //result.resize(result.size()-sub.size()-1);
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string result;
        vector<string>solution;
        int n=s.size();
        vector<char>valid(s.size()+1,0);//0:new;1:good;2:bad
        solve(0,s,dict,n,solution,valid,result);
        return solution;
    }
};

