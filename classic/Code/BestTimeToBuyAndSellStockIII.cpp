#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxDiff(vector<int>&prices,int start,int end){
		int maxVal=0;
		int minVal=1e6;
		if(start>=0&&end<=prices.size()){
			for(int i=start;i<end;i++){
				maxVal=max(maxVal,prices[i]-minVal);
				minVal=min(minVal,prices[i]);
			}
		}
		return maxVal;
	}
    int maxProfit(vector<int> &prices) {
		if(prices.size()==0||prices.size()==1)return 0;
    	if(prices.size()==2)return max(prices[1]-prices[0],0);
    	vector<int>maxPrices1=maxPricesFront(prices);
    	vector<int>maxPrices2=maxPricesBack(prices);
		int N=prices.size();
		int maxVal=0;
		for(int i=0;i<N;i++){
			int maxProfit=maxPrices1[i]+maxPrices2[i];
			cout<<"i: "<<i<<" maxProfit: "<<maxProfit<<" left: "<<maxPrices1[i]<<" right: "<<maxPrices2[i]<<endl;
			if(maxProfit>maxVal)maxVal=maxProfit;
		}
		return maxVal;
	}
	vector<int>maxPricesBack(vector<int> &prices) {
    	vector<int>maxPrices;
		int n=prices.size();
		for(int i=0;i<prices.size();i++){
			maxPrices.push_back(maxDiff(prices,i,prices.size()));
		}
		return maxPrices;
	}
	vector<int>maxPricesFront(vector<int> &prices) {
    	vector<int>maxPrices;
		for(int i=0;i<prices.size();i++){
			maxPrices.push_back(maxDiff(prices,0,i));
		}
		return maxPrices;
	}
};
int main(){
	Solution s;
	vector<int>prices;
	//int pricesArray[]={0,1,0,2};
	int pricesArray[]={2,4,1};
	//int pricesArray[]={2,1};
	for(int i=0;i<3;i++){
		prices.push_back(pricesArray[i]);
	}
	cout<<s.maxProfit(prices)<<endl;
}
int main2(){
	Solution s;
	vector<int>prices;
	cout<<s.maxProfit(prices)<<endl;
}
