// Write code to reverse a C-Style String (C-String means that “abcd” is represented as five characters, including the null character )

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

bool isUnique(const char* a){

    char b = a[0];

    for(int i = 1; i < 6 - 1; i++){
        if (b == a[i]){
            return false;
        }
    }
        
    return true;

}

int main()
{

    const char* name = "aaric";

    cout << "Is name unique? " <<isUnique(name) << endl;

    

}

