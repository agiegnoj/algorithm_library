#include <vector>
#include <type_traits> 
#include <iostream>
using namespace std;
template <typename T>

class MatrixMultiplication{
    public: 

    vector<vector<T>> multiplyMatrices(vector<vector<T>> m1, vector<vector<T>> m2){
         if (!is_arithmetic<T>::value) 
          throw invalid_argument("Type has to be arithmetic.");
  

        if (m1[0].size() != m2.size())
        throw invalid_argument("Matrices are not valid.");
        
           return iterativeMultiplication(m1, m2);
        
        
    }


    vector<vector<T>> iterativeMultiplication(vector<vector<T>> m1, vector<vector<T>> m2){
        int size1 = m1.size();
        int size2 = m2[0].size();
        vector <vector<T>> res (size1, vector<T>(size2, 0));

        for (int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++){
                for (int k = 0; k < m1[0].size(); k++){
                    res[i][j] += m1[i][k]*m2[k][j];

                }
            }
        }

        return res;

    }

    };

    int main (){
    vector<vector<int>> m1 = {
        {12, 3},
        {5, 2},
      

    };

    vector<vector<int>> m2 = {
        {3, 7},
        {5, 12}     
    };

   MatrixMultiplication <int> mm;

    vector<vector<int>> res2 = mm.multiplyMatrices(m1, m2);

    cout << "\n";

    for (int i = 0; i < res2.size(); i++){
        if (i != 0) cout << "\n";
        for (int j = 0; j<  res2.size(); j++){
            cout << res2[i][j] << " ";
        }
        
    }



}
