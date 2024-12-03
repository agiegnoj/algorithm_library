#include <vector>
using namespace std;
template <typename T>

class SelectionSort{
    public:

    vector <T> selectionSort(vector<T>& arr){
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic.");

        for (int i = 0; i<arr.size()-1; i++){
            int minIndex = i;
            
            for (int j = i+1; j< arr.size(); j++){
                if (arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }

            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        return arr;
    }


};


