class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1) {
            return 0;
        }
        vector<int>maxFromLeft(prices.size(),0);
        vector<int>maxFromRight(prices.size(),0);
        int minV=99999;
        int maxP=-99999;
        for(int i=0;i<prices.size();i++){
            minV=min(minV,prices[i]);
            int temp=prices[i]-minV;
            maxP=max(maxP,temp);
            maxFromLeft[i]=maxP;
        }
        maxP=-99999;
        int maxV=-99999;
        for(int i=prices.size()-1;i>=0;i--){
            maxV=max(maxV,prices[i]);
            int temp=maxV-prices[i];
            maxP=max(maxP,temp);
            maxFromRight[i]=maxP;
        }
        int maxProfit=-99999;
        for(int i=0;i<prices.size()-1;i++){
            int sum=maxFromLeft[i]+maxFromRight[i+1];
            maxProfit=max(maxProfit,sum);
        }
        maxProfit=max(maxProfit,maxFromRight[0]);
        return maxProfit;
    }
};
