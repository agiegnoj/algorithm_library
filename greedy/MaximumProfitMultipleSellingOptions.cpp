#include <vector>
using namespace std;

class MaximizeProfitMultipleSellingOptions{

    long maximiumProfit(const vector<int>& prices){
        if (prices.size() == 0)
        return 0;

        long profit = 0;
        int index = 1;

        while (index < prices.size()){
            if (prices[index] > prices[index-1])
            profit += prices[index]-prices[index-1];
        }

        return profit;
    }

};
