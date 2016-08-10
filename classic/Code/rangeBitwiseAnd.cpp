/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

我们再来看一个范围[26, 30]，它们的二进制如下：

11010　　11011　　11100　　11101　　11110

发现了规律后，我们只要写代码找到左边公共的部分即可，*/

class Solution {

public:

    int rangeBitwiseAnd(int m, int n) {

        if(m==n){return m;}

        int tmp=0;

        while(m!=n){

            m=m>>1;

            n=n>>1;

            tmp++;

        }

        while(tmp>0){

            m=m<<1;

            tmp--;

        }

        return m;

    }

};
