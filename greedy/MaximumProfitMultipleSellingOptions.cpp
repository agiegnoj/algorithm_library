#include <vector>
using namespace std;

class MaximizeProfitMultipleSellingOptions{

    long maximiumProfit(const vector<int>& prices){
        if (prices.size() == 0)
        return 0;

        long profit = 0;

        int i = 1;

        while (i < prices.size()){
            if (prices[i] > prices[i-1])
            profit += prices[i]-prices[i-1];
        }

        return profit;
    }

};