class Solution {
public:
    void combine(vector<string>&result,int n,string&str,int left,int right){
        if (left+right==2*n){
            result.push_back(str);
            return;
        }
        if(left<n){
            string str1=str;
            str1+='(';
            combine(result,n,str1,left+1,right);
        }
        if(right<left){
            string str2=str;
            str2+=')';
            combine(result,n,str2,left,right+1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string str;
        if(n!=0)combine(result,n,str,0,0);
        return result;
    }
};
