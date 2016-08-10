class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>buy(prices.size(),0);
        vector<int>sell(prices.size(),0);
        /*0: nothing, -1: sell , 1: buy*/
        char last = 0;
        if(prices.size()==0){
            return 0;
        }
        if(prices.size()==1){
            return 0;
        }
        if(prices.size()==2){
            return max(0,prices[1]-prices[0]);
        }
        buy[0]=-prices[0];
        sell[0]=0;
        buy[1]=-prices[1];
        sell[1]=buy[0]+prices[1];
        for(int i=2;i<prices.size();i++){
            int delta = prices[i] - prices[i-1];
            buy[i] = max(sell[i-2]-prices[i],buy[i-1]-delta);
            sell[i] = max(buy[i-1]+prices[i],sell[i-1]+delta);
        }
        int retVal=0;
        for(int i=0;i<sell.size();i++){
            retVal=max(sell[i],retVal);
        }
        return retVal;
    }
};
