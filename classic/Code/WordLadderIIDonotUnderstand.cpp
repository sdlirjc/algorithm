class Solution {
    
public:
    map<string,vector<string> >mp;//key: current string, value: old string list
    vector<vector<string> > result;
    vector<string> path;//solution
    void findDict2(string element,unordered_set<string>&dict,set<string>&next_level){
        int size=element.size();
        for(int i=0;i<size;i++){
            string tmp=element;
            for(char j='a';j<='z';j++){
                tmp[i]=j;
                if(dict.find(tmp)!=dict.end()){
                    next_level.insert(tmp);
                    mp[tmp].push_back(element);
                }
            }
        }
    }
    void output(string start,string end){
        if(start==end){
            reverse(path.begin(),path.end());
            result.push_back(path);
            reverse(path.begin(),path.end());
        }else{
            for(int i=0;i<mp[end].size();i++){
                path.push_back(mp[end][i]);
                output(start,mp[end][i]);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        mp.clear();
        result.clear();
        path.clear();
        
        dict.insert(start);
        dict.insert(end);
        
        set<string>current_level;
        set<string>next_level;
        current_level.insert(start);
        path.push_back(end);
        
        while (true){
            for(auto it=current_level.begin();it!=current_level.end();it++){
                dict.erase(*it);
            }
            for(auto it=current_level.begin();it!=current_level.end();it++){
                findDict2(*it,dict,next_level);
            }
            if(next_level.empty()){return result;}
            else{
                if(next_level.find(end)!=next_level.end()){
                    output(start,end);
                    return result;
                }
            }
            current_level.clear();
            current_level=next_level;
            
            next_level.clear();
        }
        return result;
    }
};
