class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> used;
        if(start.size()!=end.size()){
            return 0;
        }
        if(start.empty()||end.empty()){
            return 1; 
        }
        if(dict.size()==0){
            return 0;
        }
        int distance=1;
        queue<string>q;
        queue<string>todo;
        q.push(start);
        used.insert(start);
        while(!q.empty()){
            string top=q.front();
            q.pop();
            
            for(int i=0;i<top.size();i++){
                for(char j='a';j<='z';j++){
                    string tmp=top;
                    tmp[i]=j;
                    if(end==tmp){
                        return distance+1;
                    }
                    if(dict.find(tmp)!=dict.end()){
                        if(used.find(tmp)==used.end()){
                            used.insert(tmp);
                            if(dict.size()<used.size()){
                                return 0;
                            }
                            todo.push(tmp);
                        }
                    }
                }
            }
            if(q.empty()){
                swap(q,todo);
                distance++;
            }
        }
        return 0;
    }
};
