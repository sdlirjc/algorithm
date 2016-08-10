class Solution {
    
public:
    int N;
    vector<vector<string> >ret;
    bool ispa(string a){
        if(a.size()==0||a.size()==1)return true;
        for(int i=0;i<a.size()/2;i++){
            if(a[i]!=a[a.size()-1-i]){
                return false;
            }
        }
        return true;
    }
    void part(string s, int start, vector<string>partition) {
        if(s.size()==start) {
            ret.push_back(partition);
            return;
        }
        for(int i=start;i<s.size();i++){
            string tmp=s.substr(start,i-start+1);
            if(ispa(tmp)){
                partition.push_back(tmp);
                part(s,i+1,partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        N=s.size();
        vector<string> partition;
        part(s, 0, partition);
        return ret;
    }
};
