// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/6626937/beats-100-of-runtimes-simple-solution-by-r7oj/
// Beats 100% of runtimes and ~54% of memory utilizations

int maxProfit(int* prices, int days) 
{
    int max_profit = 0;
    for(int i = 1; i < days; i++) 
    {
        if(prices[i] > prices[i-1]) max_profit += prices[i] - prices[i-1];
    }
    return max_profit;
}
