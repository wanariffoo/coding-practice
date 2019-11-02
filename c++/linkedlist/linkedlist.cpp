/* Linked List

    NOTE:
    - Nodes are zero-indexed

    Functions
                - InsertAtBeginning()   : insert node at the beginning of the list
essential       - InsertAt()            : insert node at the k-th node
                - InsertAtEnd()         : insert node at the end of the list
essential       - RemoveAt()            : remove k-th node
                - RemoveMiddle()        : removes the middle element of the list
                - NumberOfNodes()       : returns the size of the lst
                - isEven()              :
                - isSorted()            : returns true if the list is sorted lowest to highest
essential       - PrintAll()            : prints values of all nodes
                - PrintInReverse()      : prints values in reverse order
                - BubbleSort()          : sorts list with bubble sort algorithm
essential       - Swap(x,y)             : swaps x-th and y-th nodes
                - OccurenceOfInt()      : frequency of an integer in the list
                - SumOfNLastNodes()     : sum of N last nodes
    
*/


#include <iostream>

struct node
{
    int value;
    node* next;
};


class LinkedList
{
    node* head;
    node* tail;
    int size;

public:
    LinkedList()
    {
        size = 0;
        head = nullptr;
    }

    void InsertAtBeginning(int data)
    {
        node* temp = new node;

        if ( head == nullptr )
        {
            head = temp;
            temp->value = data;
            temp->next = nullptr;
        }
        else
        {
            temp->next = head;
            temp->value = data;
            head = temp;
        }
        size++;
    }

    void RemoveAt(int position)
    {
        node* previous;
        node* current;
        
        current = head;

        for ( int i = 0; i < position ; i++ )
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;

        size--;
        std::cout << "RemoveAt() : Node at position " << position << " was removed" << std::endl;

    }

    void RemoveMiddle()
    {
        if ( !isEven() )
        {
            int middle = (size - 1) / 2;
            RemoveAt(middle);
        }

        else
        {
            std::cout << "List is even." << std::endl;
        }

    }

    // TODO: doesn't work 
    void RemoveDuplicates()
    {
        node* current = head;
        int data;
        
        for ( int i = 0 ; current->next != nullptr ; ++i )
        {
            data = current->value;
            std::cout << "data = " << data << std::endl;
            if ( data == current->next->value )
            {
                std::cout << "data = " << data << " , current->value = " << current->value << std::endl;
                current->next = current->next->next;
                current = current->next->next;
            }
            else
            {
            current = current->next;
            }
            std::cout << "end of for" << std::endl;
        }
    }

    void PrintAll()
    {
        node* temp;
        temp = head;
        std::cout << "PrintAll() : ";

        for ( int i = 0 ; i < size ; ++i )
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }


    int At(int position)
    {
        node* temp = head;

        if ( position == 0 )
            return temp->value;

        
        for ( int i = 0 ; i < position ; ++i )
        {
            temp = temp->next;
        }

        return temp->value;

    }
        
    void PrintInReverse()
    {
        node* temp;
        std::cout << "PrintInReverse() : ";

        for ( int i = size ; i != 0 ; i-- )
                std::cout << At(i-1) << " ";
    
        std::cout << std::endl;
    }

    int numberOfNodes()
    {
        return size;
    }

    bool isEven()
    {
        if ( size % 2 == 0)
        {
            std::cout << "LinkedList is even-sized" << std::endl;
            return true;
        }

        else
        {
            std::cout << "LinkedList is odd-sized" << std::endl;
            return false;
        }
    }

    node* goTo(int position)
    {
        node* temp = head;

        for ( int i = 0 ; i < position ; ++i )
        {
            temp = temp->next;
        }

        return temp;
    }


    bool isSorted()
    {
        int temp = head->value;

        for ( int i = 1 ; i < size ; ++i )
        {
            if ( temp > At(i) )
                return false;
        }

        return true;

    }


    void Swap(int pos1, int pos2)
    {
        node* temp1 = head;
        node* temp2 = head;

        // getting to pos1
        for (int i = 0 ; i < pos1 ; ++i)
            temp1 = temp1->next;

        // getting to pos2
        for (int i = 0 ; i < pos2 ; ++i)
            temp2 = temp2->next;

        int tempvalue;

        // swap values of the two nodes
        tempvalue = temp1->value;
        temp1->value = temp2->value;
        temp2->value = tempvalue;

    }

    void BubbleSort()
    {
        node* current;
        node* previous;

        while(!isSorted())
        {
            current = head->next;
            previous = head;
            
            for( int i = 1 ; i < size; ++i )
            {
                if ( previous->value > current->value )
                    Swap(i-1, i);

                    previous = current;
                    current = current->next;
            }
        }
    }

    int OccurenceOfInt(int value)
    {
        int n = 0;

        for ( int i = 0 ; i < size ; ++i )
        {
            if (At(i) == value)
            {
                n++;
            }
        }

        return n;
    }


    int SumOfNLastNodes(int N)
    {
        int sum = 0;
        node* temp;

        // getting to the start position of the N array
        temp = goTo(size-N);

        for ( int i = 0; i < N ; ++i )
        {
            sum += temp->value;
            temp = temp->next;    
        }

        return sum;
    }

    
};

int main()
{
    // 25 10 20 20 30 
    LinkedList myList;
    myList.InsertAtBeginning(30);
    myList.InsertAtBeginning(20);
    myList.InsertAtBeginning(20);
    myList.InsertAtBeginning(10);
    myList.InsertAtBeginning(25);

    myList.PrintAll();

    myList.RemoveDuplicates();

    myList.PrintAll();




}