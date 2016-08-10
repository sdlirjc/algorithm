class Solution {

public:

    

    string reverseVowels(string s) {

        int i1=0;

        int i2=s.size()-1;

        string vowel = "aeiouAEIOU";

        while (vowel.find(s[i1])==string::npos){

            i1++;

        }

        while (vowel.find(s[i2])==string::npos){

            i2--;

        }

        while(i1<i2){

            char tmp=s[i1];

            s[i1]=s[i2];

            s[i2]=tmp;

            i1++;

            i2--;

            while (vowel.find(s[i1])==string::npos){

                i1++;

            }

            while (vowel.find(s[i2])==string::npos){

                i2--;

            }

        }

        return s;

    }

};
