#include <vector>
using namespace std;

template <typename T>
class BinarySearch{
    public:

    int binarySearchIndex(const vector<T>& arr, T target){

        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic.");

        int left = 0;
        int right = arr.size()-1;

        while (left <= right){
            int mid = left + (right-left)/2;
            if (arr[mid] == target){
                return mid;
            }else if (arr[mid] < target){
                left= mid+1;
            }else{
                right = mid-1;
            }
        }

        return -1;
    }
};


