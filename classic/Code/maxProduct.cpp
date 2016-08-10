class Solution {

public:

    int maxProduct(vector<string>& words) {

        int len = words.size();

        int * num = new int[len];

        for(int i=0;i<len;i++){

            int k=0;

            for (int j=0;j<words[i].length();j++){

                k|=(1<<(char)(words[i][j]-'a'));

            }

            num[i]=k;

        }

        int c=0;

        for(int i=0;i<len-1;i++){

            for (int j=i+1;j<len;j++){

                if((num[i]&num[j])==0){

                    c=max(c,(int)(words[i].length()*words[j].length()));

                }

            }

        }

        return c;

    }

};
