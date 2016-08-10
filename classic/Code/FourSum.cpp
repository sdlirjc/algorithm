#include "header.h"
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> >vval;
        vector<vector<int> >vv;
        unordered_set<string>vset;
        if(num.size()<4){return vval;}
        unordered_map<int,vector<pair<int,int> > >mp;
        for(int i=0;i<num.size();i++){
            int a1=num[i];
            for(int j=i+1;j<num.size();j++){
                int a2=num[j]; 
                pair<int,int>p(i,j);
                if(mp.find(a1+a2)==mp.end()){
                    vector<pair<int,int> > pairvector;
                    pairvector.push_back( p  );
                    mp[a1+a2]=pairvector;
                }else{
                    mp[a1+a2].push_back(p);
                }
            }
        }
        cout<<mp.size()<<endl;
        for(auto &i:mp){
            pair<int,vector<pair<int,int> > >pa=i;
            int sum2=pa.first;
            if(mp.find(target-sum2)!=mp.end()){
                
                for(int l=0;l<i.second.size();l++){
                    for(int j=0;j<mp[target-sum2].size();j++){
                        vector<int>v(4,0);
                        v[0]=i.second[l].first;
                        v[1]=i.second[l].second;
                        v[2]=mp[target-sum2][j].first;
                        v[3]=mp[target-sum2][j].second;
                        sort(v.begin(),v.end());
                        int save=true;
                        for(int k=1;k<4;k++){
                            if(v[k]==v[k-1]){
                                save=false;
                            }
                        }
                        if(save){
                            string tmp4char="";
                            for(int k=0;k<4;k++){
                                char strtmp[20];
                                sprintf(strtmp,"%d",v[k]);
                                tmp4char.append(":"+string(strtmp));
                            }
                            if(vset.find(tmp4char)==vset.end()){
                                vv.push_back(v);
                                vset.insert(tmp4char);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<string> covered;
        for(int i=0;i<vv.size();i++){
            vector<int> val(4);
            for(int j=0;j<4;j++){
                val[j]=num[vv[i][j]];
            }
            sort(val.begin(),val.end());
            string s="";
            for(int j=0;j<4;j++){
                char strtmp[20];
                sprintf(strtmp,"%d",val[j]);
                s.append("-"+string(strtmp));
            }
            if(covered.find(s)==covered.end()){
                covered.insert(s);
                vval.push_back(val);
            }
        }
        return vval;
    }
};
int main(int argc,char**argv){
    Solution s;
    vector<int>input;
    //for(int i=0;i<4;i++){input.push_back(0);}
    //for(int i=0;i<99;i++){input.push_back(i);}
    int inputArray[]={91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    int target=-236727523;
    int n=sizeof(inputArray)/sizeof(inputArray[0]);
    for(int i=0;i<n;i++){
        input.push_back(inputArray[i]);
        cout<<input.size()<<endl;
    }
    vector<vector<int> >output=s.fourSum(input,target);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}
