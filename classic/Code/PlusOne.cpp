class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        
        if(digits.size()==0){return digits;}
        
        for (int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
                continue;
            }else{
                digits[i]+=1;
                return digits;
            }
        }
        vector<int>result(digits.size()+1,0);
        result[0]=1;
        return result;
    }
};
