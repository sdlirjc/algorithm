#include "header.h"
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<int>lev;
        int len=0;
        int l=0;
        int m=words.size();
        for(int i=0;i<m;i++){
            len+=words[i].size();
            if(len<=L){//&&words[i][words[i].size()-1]!='.'){
                lev.push_back(l);
                len++;//adding " "
            }else{
                l++;
                lev.push_back(l);
                len=words[i].size()+1;//initiate
            }
        }
        lev.push_back(-1);//m+1 
        vector<int>sp(l+1,L);//lenght of each line 
        vector<int>sp_mode(l+1,0);
        vector<int>nword(l+1,0);
        for(int i=0;i<m;i++){
            sp[lev[i]]-=words[i].size();//white space
            nword[lev[i]]++;
        }
        for(int i=0;i<=l;i++){
            cout<<"nword[i]: "<<nword[i]<<endl;
            if(nword[i]>1){
                sp_mode[i]=sp[i]%(nword[i]-1);
                sp[i]=sp[i]/(nword[i]-1);
            }
            cout<<"sp[i]: "<<sp[i]<<endl;
        }
        cout<<"DEBUG:10 "<<l<<endl;
        vector<string>res(l+1,"");
        for(int i=0;i<m;i++){
            cout<<"DEBUG: i:"<<i<<" lev[i]: "<<lev[i]<<" nword[lev[i]]: "<<nword[lev[i]]<<" "<<res[lev[i]]<<endl;
        }
        for(int i=0;i<m;i++){
            
            cout<<"i:"<<i<<" lev[i]: "<<lev[i]<<" nword[lev[i]]: "<<nword[lev[i]]<<" "<<res[lev[i]]<<endl;
            if(nword[lev[i]]==1){
                cout<<words[i]<<" "<<lev[i]<<endl;
                cout<<res[lev[i]]<<endl;
                res[lev[i]]+=words[i];
                cout<<res[lev[i]]<<endl;
                cout<<"sp:"<<sp[lev[i]]<<endl;
                res[lev[i]]+=string(sp[lev[i]],' ');
                cout<<res[lev[i]]<<endl;
                nword[lev[i]]=0;
            }
        }
        vector<bool>flag(l+1,false);
        cout<<"DEBUG:15"<<endl;
        for(int i=0;i<m;i++){//find the last line
            if(nword[lev[i]]>0){
                if(lev[i+1]!=lev[i]&&lev[i+1]==-1){
                    string w = words[i];
                    if (w[w.size()-1]=='.'){
                        flag[lev[i]]=true;
                    }
                }
            }
        }
        cout<<"DEBUG:20"<<endl;
        for(int i=0;i<m;i++){
            cout<<"i before: "<<i<<" nword[lev[i]]: "<<nword[lev[i]]<<" "<<res[lev[i]]<<endl;
            if(nword[lev[i]]>0){
                if(flag[lev[i]]){
                    res[lev[i]]+=words[i];
                    nword[lev[i]]--;
                    if(nword[lev[i]]>0){
                        res[lev[i]]+=' ';
                    }else{
                        res[lev[i]]+=string(L-res[lev[i]].size(),' ');
                    }
                }else{
                    res[lev[i]]+=words[i];
                    nword[lev[i]]--;
                    if(nword[lev[i]]>0){
                        if(sp_mode[lev[i]]>0){
                            res[lev[i]]+=string(sp[lev[i]]+1,' ');
                            sp_mode[lev[i]]--;
                        }else{
                            res[lev[i]]+=string(sp[lev[i]],' ');
                        }
                    }
                }
            }
            cout<<"i: "<<i<<" "<<res[lev[i]]<<endl;
        }
        return res;
    }
};
int main(){
    Solution s ; 
    vector<string>input;
    //string str[]={"a","b","c","d.","e"};
    string str[]={"Twenty","years","from","now","you","will","be","more","disappointed","by","the","things","you","didn't","do","than","by","the","ones","you","did.","So","throw","off","the","bowlines,","Sail","away","from","the","safe","harbor.","Catch","the","trade","winds","in","your","sails.","Explore.","Dream."};
    //string str[]={"Listen","to","many,","speak","to","a","few."};
    for(int i=0;i<sizeof(str)/sizeof(str[0]);i++){
        input.push_back(str[i]);
    }
    
    vector<string>vec=s.fullJustify(input,15);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}
