typedef unsigned long long int LONG;

class Solution {
public:
    int N;
    LONG hash(char*s,int m){
        if(m==0)return 0;
        int p=1;
        LONG l=(s[0]-'a')%N;
        for(int i=1;i<m;i++){
            p*=N;
            l+=p*((s[i]-'a')%N);
        }
        return l;
    }
    char *strStr(char *haystack, char *needle) {
        int hl=strlen(haystack);
        int nl=strlen(needle);
        if(nl==0)return haystack;
        if(hl<nl){return NULL;}
        N=30;
        LONG hn=hash(needle,nl);
        LONG hh=hash(haystack,nl);
        if(hn==hh){
            return haystack;
        }
        LONG head=pow(N,nl-1);
        for(int i=1;i<hl-nl;i++){
            hh=hh/N+head*((haystack[i+nl-1]-'a')%N);
            if(hh==hn)return &haystack[i];
        }
        return NULL;
    }
};
