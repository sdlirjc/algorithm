/*266. Palindrome Permutation My Submissions QuestionEditorial Solution
Total Accepted: 14141 Total Submissions: 27418 Difficulty: Easy
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd = 0 ; 
        int count[256]={0};
        for(char c : s){
            count[c]++;
            if (count[c]%2!=0){
                odd++;
            }else{
                odd--;
            }
        }
        if(odd<=1){
            return true;
        }else{
            return false;
        }
    }
};
