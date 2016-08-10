class Solution {
public:
    void partitionIP(string s,string ip,int start,int part,vector<string>&col){
        if((s.size()-start)>(4-part)*3){return;}
        if((s.size()-start)<(4-part)){return;}
        if(start==s.size()&&part==4){
            ip.resize(ip.size()-1);
            col.push_back(ip);
            return;
        }
        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10+s[i]-'0';
            if(num<=255){
                ip+=s[i];
                partitionIP(s,ip+'.',i+1,part+1,col);
            }
            if(num==0){//0.0.0.0 valid, but need to avoid 0.1.010.01
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string>col;
        partitionIP(s,ip,0,0,col);
        return col;
    }
};
