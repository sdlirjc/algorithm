#include <iostream>
#include <string>
#include <vector>
#include <stack>  
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        vector<string>strs;
        string c("");
        string o("");
        string s1("");
        int ind1=0;
        int ind2=0;
        bool on=false;
        string n="";
        bool last=false;
        for (int i=0;i<s.size();i++){
            if(s[i]==0){
                continue;
            }
            if(s[i]==' '){
                if(last){
                    continue;
                }else{
                    n+=s[i];
                    last=true;
                }
            }else{
                last=false;
                n+=s[i];
            }
        }
        s=n;
        //cout<<"s.size(): "<<s.size()<<endl;
        for (int i=0;i<int(s.size());i++){
            if(on==false&&s[i]==' '){
                ind1=i;
                //cout<<"ind1:"<<ind1<<endl;
                on=true;
            }
            //cout<<"before i: "<<i<<" on:"<<on<<" ind2:"<<ind2<<" s[i+1]:"<<s[i+1]<<"|"<<endl;
            if(on==true&&s[i]==' '){
                ind2=i;
                if(s[i+1]!=' '){
                    //cout<<"on change to false: on:"<<on<<" ind2:"<<ind2<<" s[i+1]:"<<s[i+1]<<"|"<<endl;
                    on=false;
                }
            }
            //cout<<"after i: "<<i<<" on:"<<on<<" ind2:"<<ind2<<" s[i+1]:"<<s[i+1]<<"|"<<endl;
            if(on==false&&ind2-ind1>1){
                s1="";
                //cout<<ind1<<" "<<ind2<<endl;
                for(int j=0;j<ind1;j++){
                    s1+=s[j];
                }
                for(int j=ind1;j<int(s.size())-(ind2-ind1-1);j++){
                    s1+=s[j+(ind2-ind1)];
                }
                s=s1;
            }
            //cout<<"last i: "<<i<<" on:"<<on<<" ind2:"<<ind2<<" s[i+1]:"<<s[i+1]<<"|"<<endl;
        }
        //cout<<"DEBUG: 2: s.size(): "<<s.size()<<" s: |"<<s<<"|"<<endl;
        for (int i=0;i<s.size();i++){
            if(s[i]!=' ')
                c+=s[i];
            else{
                strs.push_back(c);    
                c="";
            }    
        }
        if(c.size()>0)strs.push_back(c);    
        for(int i=0;i<strs.size();i++){
            //cout<<"DEBUG:"<<i<<" "<<strs[i]<<endl;
        }
        for(int i=int(strs.size())-1;i>0;i--){
            //cout<<"DEBUG:"<<strs[i]<<endl;
            o+=strs[i]+" ";    
        }
        if(strs.size()>0)
            o+=strs[0];
        s=o;
        n="";
        bool found=false;
        //for(int i=0;i<s.size();i++)cout<<"|"<<s[i]-0<<"|"<<endl;
        for (int i=0;i<s.size();i++){
            if(found==false&&(s[i]==' '||s[i]==0)){
                continue;
            }
            if(found==false&&s[i]!=' '&&s[i]!=0){
                n+=s[i];
                found=true;
                continue;
            }
            if(found==true){
                n+=s[i];
            }
        }
        s=n;
        found=false;
        stack<char> mystack;
        for (int i=s.size()-1;i>=0;i--){
            if(!found&&(s[i]==32||s[i]==0)){
                continue;
            }
            if(!found&&s[i]!=' '&&s[i]!=0){
                mystack.push(s[i]);
                found=true;
                continue;
            }
            if(found){
                mystack.push(s[i]);
            }
        }
        n="";
        while (!mystack.empty())
        {
            n+=mystack.top();
            mystack.pop();
        }
        s=n;
        //cout<<s<<endl;
        n="";
        last=false;
        for (int i=0;i<s.size();i++){
            if(s[i]==0){
                continue;
            }
            if(s[i]==' '){
                if(last){
                    continue;
                }else{
                    n+=s[i];
                    last=true;
                }
            }else{
                last=false;
                n+=s[i];
            }
        }
        s=n;
        //for(int i=0;i<s.size();i++)cout<<"|"<<s[i]-0<<"|"<<endl;
    }
    Solution(){}
};
int main(){
    Solution * s = new Solution();
    //string in("a");
    //string in("");
    //string in("    ");
    //string in("1    ");
    //string in(" 1");
    //string in("a b");
    //string in("  a  b ");
    string in("  a  b   c d  e  ");
    s->reverseWords(in);
    cout<<"|"<<in<<"|"<<endl;
}
