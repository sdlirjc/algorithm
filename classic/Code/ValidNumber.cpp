#include"header.h"
class Solution {
public:
    bool isNumber(const char *s) {
        //0:invalid
        //1:space
        //2:sign
        //3:numbers
        //4:.
        //5:E
        int tran[][6]={
            // each col in a row is next input 
            -1, 0, 3, 1, 2, -1 , //0:starting space // current input 
            -1, 8, -1, 1, 4, 5, //1:number
            -1, -1, -1, 4, -1, -1, //2:start with .
            -1, -1, -1, 1, 2, -1,//3:sign
            -1, 8,-1,4,-1,5,//4:eg:5.
            -1, -1, 6, 7, -1, -1, //5: after E
            -1, -1, -1, 7, -1, -1, //6:sign after E
            -1, 8, -1, 7, -1, -1, //7: number after E
            -1, 8, -1, -1, -1, -1,//8: ending space
        };
        int state=0;
        while(*s){
            int input=0;
            if(*s==' '){input=1;}
            else if(*s=='+'||*s=='-'){input=2;}
            else if(isdigit(*s)){input=3;}
            else if(*s=='.'){input=4;}
            else if(*s=='e'||*s=='E'){input=5;}
            cout<<"input:"<<input<<endl;
            state=tran[state][input];
            if(state==-1){return false;}
            s++;
        }
        return state==1||state==4||state==7||state==8;
    }
};
int main(){
    Solution s;
    cout<<s.isNumber(".p7")<<endl;
}
