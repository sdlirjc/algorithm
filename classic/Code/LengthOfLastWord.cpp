class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i=-1;
        int size=strlen(s);
        for(i=size-1;i>=0;i--){
            if(s[i]!=' '){
                break;
            }
        }
        if(i==-1){return 0;}
        int count=0;
        for(int j=i;j>=0;j--){
            if(s[j]==' '){break;}
            count++;
        }
        return count;
    }
};
