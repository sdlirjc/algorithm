class Solution {
public:
    bool contain(vector<int>&appear,vector<int>&expect){
        for(int i=0;i<expect.size();i++){
            if(expect[i]!=0){
                if(appear[i]<expect[i])return false;
            }
        }
        return true;
    }
    string minWindow(string S, string T) {
        vector<int>appear('z'-'A'+1,0);
        vector<int>expect('z'-'A'+1,0);
        if(S.size()==0)return "";
        for(int i=0;i<T.size();i++){
            expect[T[i]-'A']++;
        }
        int minV=99999;
        string val="";
        int appeared=0;
        int j=0;//j: start
        for(int i=0;i<S.size();i++){
            appear[S[i]-'A']++;
            if(contain(appear,expect)){
                int start=0;
                for(;j<=i;j++){
                    appear[S[j]-'A']--;
                    if(contain(appear,expect)==false){
                        start=j;
                        j++;
                        break;
                    }
                }
                if(minV>i-start+1){
                    minV=i-start+1;
                    val=S.substr(start,minV);
                }
            }
        }
        return val;
    }
};
