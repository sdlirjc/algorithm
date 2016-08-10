#include"header.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star=false;
        const char * str , * ptr ; 
        for (str=s,ptr=p;*str!='\0';str++,ptr++){
            switch(*ptr){
                case '*':
                    star=true;
                    s=str;
                    p=ptr;
                    while(*p=='*'){
                        p++;
                    }
                    if(*p=='\0'){
                        return true;
                    }
                    str=s-1;
                    ptr=p-1;
                    
                    break;
                case '?':
                    //s++;
                    //p++;
                    break;
                default :
                {
                    if(*str!=*ptr){
                        if(!star){
                            return false;
                        }
                        s++;
                        str=s-1;
                        ptr=p-1;
                    }
                }
                
            }
        }
        while(*ptr=='*'){
            ptr++;
        }
        return (*ptr=='\0');
    }
};

int main(int argc,char**argv){
    Solution s ; 
    //cout<<s.isMatch("b","*?*?")<<endl;
    cout<<s.isMatch("baabba","?*?a??")<<endl;
}
