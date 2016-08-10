class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while (*haystack){
            char * h=haystack;
            for(char*n=needle;;h++,n++){
                if(!*n)return haystack;
                if(*n!=*h)break;
            }
            if(!*h)return NULL;
            haystack++;
        }
        if(*needle)return NULL;
        else{return "";}
        
    }
};
