/*

293. Flip Game

    Total Accepted: 11623
    Total Submissions: 22754
    Difficulty: Easy

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]

If there is no valid move, return an empty list [].

*/


class Solution {

public:

    vector<string> generatePossibleNextMoves(string s) {

        set<string> set;

        vector<string> ret;

        if(s.size()==0){

            return ret;

        }

        for(int i=0;i<s.size()-1;i++){

            if(s[i]=='+' && s[i+1] == '+'){

                string tmp = s; 

                tmp[i] = '-';

                tmp[i+1] = '-';

                set.insert(tmp);

            }

        }

        for(string key : set){

            ret.push_back(key);

        }

        return ret;

    }

};
