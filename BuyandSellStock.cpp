// Buy and sell stocks
// max profit buying and selling only 1 stock

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int min = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            profit = max(profit, prices[i] - min);
        }
        return profit;
    }
};
// max profit buysing and selling multiple stocks
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};