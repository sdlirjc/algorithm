/*For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int count=0;
        while (count<32){
            char tmp = (n&1);
            ret=ret<<1;
            if(tmp==1){
                ret=ret|1;
            }
            n=n>>1;
            count++;
        }
        return ret;
    }
};
