/*You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/
class Solution {
public:
    string itos(int num){
        string Result;          // string which will contain the result
        ostringstream convert;   // stream used for the conversion
        convert << num;      // insert the textual representation of 'Number' in the characters in the stream
        Result = convert.str(); // set 'Result' to the contents of the stream
        return Result;
    }
    string getHint(string secret, string guess) {
        if(secret.size()==0||guess.size()==0){return "";}
        if(secret.size()!=guess.size()){return "";}
        int same=0;
        string reduceSecret="";
        string reduceGuess="";
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                same++;
            }else{
                reduceSecret+=secret[i];
                reduceGuess+=guess[i];
            }
        }
        int n = reduceSecret.size();
        map<char,int> mapSecret;
        map<char,int> mapGuess;
        for(int i=0;i<n;i++){
            if(mapSecret.find(reduceSecret[i])==mapSecret.end()){
                mapSecret.insert(pair<char,int>(reduceSecret[i],1));
            }else{
                mapSecret[reduceSecret[i]]=mapSecret[reduceSecret[i]]+1;
            }
            if(mapGuess.find(reduceGuess[i])==mapGuess.end()){
                mapGuess.insert(pair<char,int>(reduceGuess[i],1));
            }else{
                mapGuess[reduceGuess[i]]=mapGuess[reduceGuess[i]]+1;
            }
        }
        int sum=0;
        for(map<char,int>::iterator it = mapSecret.begin();it!=mapSecret.end();it++){
            if(mapGuess.find(it->first)!=mapGuess.end()){
                int tmp=min(mapGuess[it->first],it->second);
                sum+=tmp;
            }
        }
        string ret="";
        ret+=itos(same);
        ret+='A';
        ret+=itos(sum);
        ret+='B';
        return ret;
    }
};
