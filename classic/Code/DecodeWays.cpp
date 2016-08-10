class Solution {
public:
    bool valid(char a){
        if(a>='1'&&a<='9'){
            return true;
        }else{
            return false;
        }
    }
    bool valid(char a,char b){
        if((a=='1'&&b>='0'&&b<='9')||(a=='2'&&b>='0'&&b<='6')){
            return true;
        }
        return false;
    }
    int numDecodings(string s) {
        int n=s.size();
        if(n==0)return 0;
        if(n==1){
            if(valid(s[0])){
                return 1;
            }else{
                return 0;
            }
        }
        vector<int>num(n,0);
        if(valid(s[0])){
            num[0]=1;
        }else{
            num[0]=0;
        }
        if(valid(s[1])){
            if(valid(s[0],s[1])){
                num[1]=2;
            }else{
                num[1]=num[0];
            }
        }else{
            if(valid(s[0],s[1])){
                num[1]=1;
            }else{
                num[1]=0;
            }
        }
        for(int i=2;i<n;i++){
            if(valid(s[i])){
                if(valid(s[i-1],s[i])){
                    num[i]=num[i-2]+num[i-1];
                }else {
                    num[i]=num[i-1];
                }
            }else{
                if(valid(s[i-1],s[i])){
                    num[i]=num[i-2];
                }else {
                    num[i]=0;
                }
            }
        }
        return num[n-1];
    }
};
