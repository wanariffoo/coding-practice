#include <iostream>

using namespace std;

class Stack
{
    int *array;
    int top; // keeps track of the index which is top
    int size;

public:

    Stack(int n)
    {
        size = n;
        array = new int[size];  // assigns pointer to an array
        top = -1; // is empty
    }

    ~Stack()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return ( top == -1 ? true : false );
    }

    bool isFull()
    {
        return ( top == (size - 1) ? true : false );
    }

    void push(int x)
    {
        if ( isFull() )
        {
            cout << "Stack overflow!" << endl;
            exit(EXIT_FAILURE);
        }

        else
        {
            top++;
            array[top] = x;
        }

    }

    void pop()
    {
        top--;
    }

    int peek()
    {
        return array[top];
    }


};


int main()
{
    Stack mystack(5);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);

    

    // cout << mystack.peek() << endl;
    // mystack.pop();
    // cout << mystack.peek() << endl;


}