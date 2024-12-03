#include <vector>
using namespace std;

class MaximizeProfitOneSellingOption{
 
    long maximiumProfit(vector<int> prices){

        if (prices.size() == 0|| prices.size() == 1 )
        return 0;

        long minPrice = prices[0];
        long profit = 0;

        int i = 1;

        while (i < prices.size()){
            if (prices[i] > minPrice){
                profit = max(profit, prices[i]-minPrice);
            }else{
                minPrice = min(minPrice, (long)prices[i]);
            }
        }

        return profit;
    }


};
