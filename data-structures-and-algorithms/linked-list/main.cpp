/*

    Basic operations:
    - insertion
        - at the end
        - at an index
    - deletion
        - end node
        - at an index
    - display
    - search
    - reverse

*/

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class SinglyLinkedList
{
private:
    int length;
    node *head;
    node *tail;

public:

    // constructor
    SinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // insert a node
    void insertNode(int value)
    {
        // new node
        node *temp = new node;
        temp->data = value;

        // if list is empty
        if ( head == nullptr )
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
            length++;
        }

        else
        {
            tail->next = temp;
            tail = temp;
            temp->next = nullptr;
            length++;
        }
        
    }

    void printNodes()
    {
        node *temp = head;

        for ( int i = 0 ; i < length ; i++ )
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // removes node at index
    void removeNode(int index)
    {
        node *temp = head;

        // if at index 0
        if ( index == 0 )
        {
            temp->next = nullptr;
            free(temp);
        }

        else
        {
            // get to index
            for ( int i = 0 ; i < index - 1; i++ )
                temp = temp->next;

            node *foo = temp->next;

            temp->next = foo->next;
            free(foo);
        }

        length--;
    }

    // prints indices of nodes that contain val
    void findNode(int x)
    {
        node *temp = head;

        for ( int i = 0 ; i < length ; i++ )
        {
            if ( temp->data == x )  cout << i << " ";

            // next node
            temp = temp->next;
        }

        cout << endl;
    }

    void insertAtTail(int value)
    {
        insertAtTail(head, value);
    }

    void insertAtTail(node* root, int value)
    {

        // new node
        node *newnode = new node;
        newnode->data = value;
        newnode->next = nullptr;

        // temp node
        node *temp = root;

        while ( temp->next != nullptr )
            temp = temp->next;

        temp->next = newnode;
        length++;

    }



};


int main()
{

    SinglyLinkedList mylist;
    mylist.insertNode(10);
    mylist.insertNode(20);
    mylist.insertNode(40);
    mylist.insertNode(40);
    mylist.insertAtTail(50);
    mylist.printNodes();


    // mylist.findNode(40);


    





}

