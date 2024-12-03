#include <vector>

using namespace std;

class MaxProductSubarray{
    
    public:
    long long maxProduct(vector <int> nums){

        if (nums.size() == 0) return 0;

        long currentMax = nums[0];
        long currentMin = nums[0];
        long globalMax = nums[0];

        for (int num :nums){
            long temp = max (max(currentMin * num, (long)num), currentMax*num);
            currentMin = min(min(temp *num, (long)num), currentMin*num);
            currentMax = temp;
            globalMax = max (currentMax, globalMax);
        }       
        return  globalMax;
    }

    
    };