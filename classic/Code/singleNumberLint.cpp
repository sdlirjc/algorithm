


Given 2*n + 1 numbers, every numbers occurs twice except one, find it.


class Solution {

public:

    /**

     * @param A: Array of integers.

     * return: The single number.

     */

    int singleNumber(vector<int> &A) {

        // write your code here

        int tmp=0;

        for(int i=0;i<A.size();i++){

            tmp = A[i]^tmp;

        }

        return tmp;

    }

};


