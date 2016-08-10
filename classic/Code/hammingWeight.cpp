class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t tmp=0;
        while(n>0){
            tmp+=n&1;
            n=n>>1;
        }
        return tmp;
    }
};
