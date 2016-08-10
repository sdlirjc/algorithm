class Solution {

public:

    int maxProfit(vector<int> &prices) {

        if(prices.size()<=1)return 0;

        int mi=INT_MAX;

        int ma=INT_MIN;

        for(int i=0;i<prices.size();i++){

            mi=min(mi,prices[i]);

            ma=max(prices[i]-mi,ma);

        }

        return ma;

        

    }

};
