//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//TO BE OPTIMISED

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        for(int i=0 ; i<prices.size()-1 ;++i)
        {
            for(int j=i+1;j<prices.size() ;++j)
            {
                if(prices[j]-prices[i]>profit && i<j && i!=j)
                    profit = prices[j]-prices[i];
            }
        }
        return profit;
    }
};