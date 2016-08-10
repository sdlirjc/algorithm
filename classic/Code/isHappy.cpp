class Solution {
public:
    vector<int>split(int n){
        vector<int>v;
        while(n>0){
            int tmp=n/10;
            int d = n%10;
            v.push_back(d);
            n=tmp;
        }
        return v;
    }
    bool happy(int n,set<int>numbers) {
        numbers.insert(n);
        vector<int> v = split(n);
        int tmp=0;
        for(int i=0;i<v.size();i++){
            tmp+=v[i]*v[i];
        }
        if(tmp==1){return true ; }
        else {
            if(numbers.count(tmp)>0){
                return false;
            }else{
                return happy(tmp,numbers);
            }
        }
    }
    bool isHappy(int n) {
        if(n==1){
            return true; 
        }
        set<int>numbers;
        numbers.insert(n);
        return happy(n,numbers);
    }
};
