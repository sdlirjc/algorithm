/*637 · Valid Word Abbreviation
Algorithms
Easy
Accepted Rate
33%
Description
Solution18
Notes99+
Discuss3
Leaderboard
Record
Description
Given a non-empty string word and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Wechat reply 【Two Sigma】 get the latest requent Interview questions. (wechat id : jiuzhang1104)


Where 1 means one character is omitted, 2 means two characters are omitted, and so on.
Notice that only the above abbreviations are valid abbreviations of the string word. Any other string is not a valid abbreviation of word.

Example
Example 1:

Input : s = "internationalization", abbr = "i12iz4n"
Output : true
Example 2:

Input : s = "apple", abbr = "a2e"
Output : false
Tags
Company
Google
Related Problems

639
Word Abbreviation
Hard

779
Generalized Abbreviation
Medium

890
Minimum Unique Word Abbreviation
Hard
Recommend Courses
*/
/**
 * You can create and use dynamic array in your code.
 * You can replace "int" to any other type you want to put in the array, e.g. float, char*, list_node*.
 * Create an empty int array:         int* arr = NULL;
 * Add an element to the back:        cvector_push_back(arr, 42);
 * Remove an element from the back:   cvector_pop_back(arr);
 * Get size of a dynamic array:       cvector_size(arr)
 * For other macros, see https://github.com/eteran/c-vector
 */
/**
 * @param word: a non-empty string
 * @param abbr: an abbreviation
 * @return: true if string matches with the given abbr or false
 */
bool valid_word_abbreviation(char* word, char* abbr) {
    int m = strlen(word);
    int n = strlen(abbr);
    int j = 0;
    int cnt=0;
    if(n>m){
        return false;
    }
    for(int i=0;i<n;i++){
        if(abbr[i]>='0'&&abbr[i]<='9'){
            cnt *=10;
            cnt += abbr[i]-'0';
            continue;
        }else{
            j+=cnt;
            //printf("m:%d,n:%d,i:%d;j:%d,cnt:%d\n",m,n,i,j,cnt);
            cnt=0;
        }
        if(abbr[i]!=word[j]){
            return false;
        }
        j++;
    }
    if(j+cnt>m){
        return false;
    }
    return true;
}
