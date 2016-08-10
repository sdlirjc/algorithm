class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>ret;
        for(int i=0;i<input.size();i++){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                vector<int> leftResult = diffWaysToCompute(input.substr(0,i));
                vector<int> rightResult = diffWaysToCompute(input.substr(i+1));
                for(int j=0;j<leftResult.size();j++){
                    for(int k=0;k<rightResult.size();k++){
                        if(input[i]=='+'){
                            ret.push_back(leftResult[j]+rightResult[k]);
                        }else if(input[i]=='-'){
                            ret.push_back(leftResult[j]-rightResult[k]);
                        }else if(input[i]=='*'){
                            ret.push_back(leftResult[j]*rightResult[k]);
                        }
                    }
                }
            }
        }
        if(ret.size()==0){
            ret.push_back(atoi(input.c_str()));
        }
        return ret;
    }
};
