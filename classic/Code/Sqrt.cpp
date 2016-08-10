class Solution {
public:
    int sqrt(int x) {
        if (x<2)return x;
        float diff=0.01;
        int low=0;
        int high=x;
        while(low<=high){
            float mid=(low+high)/2;
            if((mid*mid-x)>diff){
                high=mid-1;
            }else if(x-mid*mid>diff){
                low=mid+1;
            }else {
                return int(mid);
            }
        }
        return high;
        
    }
};
