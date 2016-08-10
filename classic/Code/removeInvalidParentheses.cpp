class Solution {
public:
    void update(string s, queue<string>&q, set<string>&visited){
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==')'){
                string tmp = s.substr(0,i)+s.substr(i+1);
                if(visited.find(tmp)==visited.end()){
                    visited.insert(tmp);
                    q.push(tmp);
                }
            }
        }
    }
    bool isValid(string s){
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]==')'){
                if(count<=0){
                    return false;
                }else{
                    count--;
                }
            }
        }
        return count==0;
    }
    vector<string>getMax(vector<string>v){
        int maxSize=0;
        for(int i=0;i<v.size();i++){
            maxSize = max(int(v[i].size()),maxSize);
        }
        vector<string>res;
        for(int i=0;i<v.size();i++){
            if(v[i].size()==maxSize){
                res.push_back(v[i]);
            }
        }
        return res;
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> visited;
        visited.insert(s);
        queue<string> q;
        q.push(s);
        vector<string>res;
        while(!q.empty()){
            s = q.front();
            q.pop();
            if(isValid(s)){
                res.push_back(s);
                continue;
            }else{
                update(s,q,visited);
            }
        }
        return getMax(res);
    }
};
