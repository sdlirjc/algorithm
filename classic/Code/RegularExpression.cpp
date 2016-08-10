class Solution {

public:

    bool isMatch(const char *s, const char *p) {

        if (!s||!p)return false;

        int c=0,ssize=0,psize=0;

        while (s[c]!='\0') c++;

        ssize=c;

        c=0;

        while(p[c]!='\0')c++;

        psize=c;

        if(ssize==0&&psize==0)return true;

        if(psize==0)return false;

        bool b[ssize+1][psize+1];

        for(int i=0;i<ssize+1;i++){

            for(int j=0;j<psize+1;j++){

                b[i][j]=false;

            }

        }

        b[0][0]=true;

        for(int j=0;j<psize;j++){

            if(p[j]=='*'){

                if(j>0&&b[0][j-1]) b[0][j+1]=true;

                if(j<1)continue;

                if(p[j-1]!='.'){

                    for(int i =0;i<ssize;i++){

                        if(b[i+1][j]||j>0&&b[i+1][j-1]||i>0&&j>0&&b[i][j+1]&&s[i]==s[i-1]&&s[i-1]==p[j-1])

                            b[i+1][j+1]=true;

                    }

                    

                }else{

                    int i=0;

                    while (j>0&&i<ssize&!b[i+1][j-1]&&!b[i+1][j]){

                        i++;

                    }

                    for(;i<ssize;i++){

                        b[i+1][j+1]=true;

                    }

                }

            }else{

                for(int i=0;i<ssize;i++){

                    if(s[i]==p[j]||p[j]=='.') b[i+1][j+1]=b[i][j];

                }

            }

        }

        return b[ssize][psize];

    }

};
