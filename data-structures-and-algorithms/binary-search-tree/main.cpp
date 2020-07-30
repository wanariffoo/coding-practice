/*
    Basic operations:
        - insert(Node* root, int value)
        - search(int value)     : return the node if value exists
        - delete
        - findMin
        - findMax
        - display through these traversals
            - preorder
            - inorder
            - postorder
        - getHeight

*/

#include <iostream>
#include <cmath>

using namespace std;


class BST
{

    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node* x, int value);
    
    //// Traversals
    void inorder(Node* t);
    void preorder(Node* t);
    void postorder(Node* t);
    void levelorder(Node* t);

    Node* find(Node* t, int value);
    Node* findMin(Node* t);
    Node* findMax(Node* t);
    
    Node* remove(Node* t, int value);

    int getHeight(Node* t);
    void printLevel(Node* t, int level);
    
public:

    BST()
    {
        root = nullptr;
    }

    void insert(int value) 
    {
        root = insert(root, value);
    }

    bool search(int value)
    {
        Node* temp = find(root, value);

        if ( temp != root )
            return false;
        
        else
            return true;
    }

    int findMin()
    {
        auto temp = findMin(root);

        return temp->data;
    }

    int findMax()
    {
        auto temp = findMax(root);

        return temp->data;
    }


    void display(int x)
    {
        switch(x)
        {
            case 1: // inorder
                inorder(root);
                cout << endl;
                break;

            case 2: // preorder
                preorder(root);
                cout << endl;
                break;

            case 3:
                postorder(root);
                cout << endl;
                break;

            case 4:
                levelorder(root);
                break;
        }
    }

    void remove(int value)
    {
        root = remove(root, value);
    }

    int getHeight()
    {
        return getHeight(root);
    }

};




int main()
{
    BST mytree;

    mytree.insert(12);
    mytree.insert(5);
    mytree.insert(15);
    mytree.insert(3);
    mytree.insert(7);
    mytree.insert(1);
    mytree.insert(9);
    mytree.insert(13);
    mytree.insert(17);


    // Display
    // 1 : inorder
    // 2 : preorder
    // 3 : postorder
    mytree.display(4);
    
    // cout << mytree.search(3) << endl;
    cout << "Min: " << mytree.findMin() << endl;
    cout << "Max: " << mytree.findMax() << endl;

    mytree.remove(15);
    cout << "Tree max height: " << mytree.getHeight() << endl;

    



}


BST::Node* BST::insert(Node* x, int value)
{
    // if tree is empty or when recursion reaches a suitable leaf
    // only create node when the node is not occupied, i.e. when x == nullptr
    if ( x == nullptr )
    {
        // create a new node
        x = new Node;
        x->data = value;
        x->left = nullptr;
        x->right = nullptr;
    }

    // if LHS
    else if ( value < x->data ) 
        x->left = insert( x->left, value );

    // if RHS
    else
        x->right = insert( x->right, value );

    return x;
}

void BST::inorder(Node* t)
{
    // base
    if ( t == nullptr )
        return;

    // go LHS first, recursion will stop when it reaches the lowest LHS leaf
    inorder(t->left);

    // print
    cout << t->data << " ";

    // RHS
    inorder(t->right);

}

// preorder
void BST::preorder(Node* t)
{
    // base
    if ( t == nullptr )
        return;

    // prints the root first
    cout << t->data << " ";

    // prints left child
    preorder(t->left);

    // prints right child
    preorder(t->right);

}

// postorder
void BST::postorder(Node* t)
{
    // base
    if (t == nullptr)
        return;

    // LHS first
    postorder(t->left);

    // RHS next
    postorder(t->right);

    // print lastly root
    cout << t->data << " ";

}

// level-order
void BST::levelorder(Node* t)
{
    int max_height = getHeight(t);

    // print nodes on every level
    for ( int i = 0 ; i < max_height ; i++ )
    {
        printLevel( t, i );
        cout << endl;
    }
}

BST::Node* BST::find(Node* t, int value)
{
    // base: if not found
    if ( t == nullptr )
        return nullptr;
    
    // LHS
    else if ( value < t->data )
        return find(t->left, value);

    // RHS
    else if ( t->data < value )
        return find(t->right, value);
    
    // base: if found
    else
        return t;

}

BST::Node* BST::findMin(Node* t)
{
    // base
    if ( t->left == nullptr )
        return t;
    
    return findMin(t->left);
}

BST::Node* BST::findMax(Node* t)
{
    // base
    if (t->right == nullptr)
        return t;

    return findMax(t->right);
}

BST::Node* BST::remove(Node* t, int value)
{
        Node* temp;

        if(t == NULL)
            return NULL;
        else if(value < t->data)
            t->left = remove(t->left, value);
        else if(value > t->data)
            t->right = remove(t->right, value);

        // case 1 : if there are two children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove( t->right, t->data );
        }

        // case 2 : if there's one child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;

}

int BST::getHeight(Node* t)
{
    // height of root = max( getHeight(LHS), getHeight(RHS) ) + 1
    //
    // left height <- getHeight(t->left)
    // right height <- getHeight(t->right)
    //
    // return max(left height, right height)

    // exit condition / base
    if ( t == nullptr )
        return -1;  // because you want to negate the return max() + 1
                    // else, leaf nodes will have a height of 1

    int left_height = getHeight(t->left);
    int right_height = getHeight(t->right);

    return max(left_height, right_height) + 1;

}

void BST::printLevel(Node* t, int level)
{
    if (t == nullptr)  
        return;  
    if (level == 0)  
        cout << t->data << " ";  
    else if (level > 0)  
    {  
        printLevel(t->left, level-1);  
        printLevel(t->right, level-1);  
    }  
}