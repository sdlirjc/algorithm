class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ind=-1;
        for(int i=num.size()-2;i>=0;i--){
            if(num[i]<num[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            sort(num.begin(),num.end());
        }else{
            int right=ind+1;
            for(int i=ind+1;i<num.size();i++){
                if(num[i]>num[ind]&&num[i]<num[right]){
                    right=i;
                }
            }
            swap(num[ind],num[right]);
            sort(num.begin()+ind+1,num.end());
        }
    }
};
