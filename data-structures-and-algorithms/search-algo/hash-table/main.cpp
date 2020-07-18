/*
    Hash table
    
    Basic operations
        - search
        - insert
        - delete

    A very simple hash function is used

*/

#include<iostream>
# define SIZE 10

using namespace std;

struct dataItem
{
    int data;
    int key;
};

// hash function that takes in a key to return an index
int hashFunction(int key)
{
    return key % SIZE;
}



int main()
{
    
    
}

    