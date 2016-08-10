class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long dvd = dividend>0?dividend:-dividend;
        unsigned long dvs = divisor>0?divisor:-divisor;
        if(dvd<dvs)return 0;
        int sign=1;
        if(dividend<0){sign*=-1;}
        if(divisor<0){sign*=-1;}
        int step=0;
        int absdvs=dvs;
        while(dvs<dvd){
            dvs=dvs<<1;
            step++;
        }
        unsigned long result=0;
        while(dvd>=absdvs){
            if(dvs<=dvd){
                dvd-=dvs;
                result+=(unsigned long)1<<step;
            }
            dvs=dvs>>1;
            step--;
        }
        return result*sign;
    }
};
