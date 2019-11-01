// How do you find the missing number in a given integer array of 1 to 100?

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> findMissingIntegers(vector<T> array){

    vector<T> missing = {0};

    int j = 0;

    for ( int i = 0 ; i < array.size() ; i++ ){

        if ( i + j != array[i] ){  // 12 != 12, i = 1 13 != 14, 14 != 15

            missing.push_back(i+j);
            j++;
        }
    }

    return missing;

}


int main(){

    // Creating an array with missing integers

    vector<int> array;

    for( int i = 0; i < 100 ; i++ ) 
        array.push_back(i+1);

    // Deleting some integers

        array.erase(array.begin() + 21);
        array.erase(array.begin() + 12); // 13
        array.erase(array.begin() + 95);

    vector<int> missing = findMissingIntegers(array);

    for (int i = 0; i < missing.size(); i++)
        cout << missing[i] << endl;

}