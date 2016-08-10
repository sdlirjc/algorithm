#include "header.h"

class Solution {
public:
    int candy(vector<int> &ratings) {
        int mi=99999;
        int total=0;
        int N=ratings.size();
        vector<int>candy(N,1);
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }else if(ratings[i]<ratings[i-1]){
                if(i==N-1)candy[i]=1;
                else {
                    if(ratings[i]<=ratings[i+1]){
                        candy[i]=min(1,candy[i-1]-1);
                    }else{
                        candy[i]=candy[i-1]-1;
                    }
		}
            } else {
                candy[i]=1;
            }
            if (candy[i]<=0){
                if(i<N-1){
                    if(ratings[i]<=ratings[i+1]&&ratings[i]<ratings[i-1]){
                        int low=candy[i];
                        candy[i]+=abs(low)+1;
                        for(int retro=i;retro>0&&ratings[retro-1]>ratings[retro];retro--){
                            candy[retro-1]+=abs(low)+1;
                        }
                    }
                }else{
                    if(ratings[i]<ratings[i-1]){
                        int low=candy[i];
                        candy[i]+=abs(low)+1;
                        for(int retro=i;retro>0&&ratings[retro-1]>ratings[retro];retro--){
                            candy[retro-1]+=abs(low)+1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<candy[i]<<" "<<ratings[i]<<endl;
            total+=candy[i];
        }
        return total;
    }
    int candy2(vector<int> &ratings) {
        int mi=999999;
        int total=0;
        int N=ratings.size();
        vector<int>candy(N,1);
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        for(int i=N-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                if(i==N-1)candy[i]=1;
                candy[i-1]=candy[i]+1;
                cout<<"i: "<<i<<" "<<candy[i]<<" "<<candy[i-1]<<endl; 
            }else if(ratings[i-1]<ratings[i]){
                if(candy[i-1]>=candy[i]){
                    if(i==N-1) candy[i]=1;
                    else candy[i]=candy[i-1]+1;
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<candy[i]<<" "<<ratings[i]<<endl;
            total+=candy[i];
        }
        return total;
    }
};

int main(){
    Solution * s = new Solution();
    vector<int>v;
    //int input[5]={4,2,3,4,1};
    //int input[5]={1,2,4,4,3};
    //int input[10]={5,1,1,1,10,2,1,1,1,3};
    //int input[2]={2,1};
    //int input[2]={2,2};
    //int input[3]={1,2,2};
    int input[100]={58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
    for(int i=0;i<100;i++){
        v.push_back(input[i]);
    }
    cout<<s->candy2(v)<<endl;
}

