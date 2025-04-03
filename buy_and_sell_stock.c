// Beat 100% of runtimes as of 4/3/2025 with 82% of memory usages beat
// https://assets.leetcode.com/users/images/bba5d76a-174e-4523-9480-65a92d4c0458_1743718868.113725.png
// Yes I know the image says "Wrong answer" in the bottom right lol, copy and past this code yourself and watch you beat 99.9% of runtimes

int maxProfit(int* prices, int days) 
{
    if(days < 2) return 0;

    int minimum=prices[0];
    int profit=0;
    
    for(int n = 1; n < days; n++) 
    {
        if(prices[n] < minimum) 
        {
            minimum=prices[n];
        }
        int local_profit = prices[n] - minimum;
        if(local_profit >= profit) 
        {
            profit=local_profit;
        }
    }
    return profit;
}
