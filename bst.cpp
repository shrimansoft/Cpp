#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BST
{
    public:
    Node* root;


    BST()
    {
        root=NULL;
    }

    void insert(int value)
    {
        insert_recursion(value,&root);
    }
    void insert_recursion(int value,Node  **curr)
    {
        Node* temp = new Node(value);
        // cout << temp->data;
        if(*curr == NULL)
        {
            *curr = temp;
        }
        else
        {
            if(value < (*curr)->data)
            insert_recursion(value,&((*curr)->leftChild));

            if(value >= (*curr)->data)
            insert_recursion(value,&((*curr)->rightChild));
        }
        
    }

    void display()
    {
        display_recursion(root);
    }
    void display_recursion(Node* curr )
    {
        if (curr != NULL) 
        {
            display_recursion(curr->leftChild);
            cout << curr-> data << " : ";
            display_recursion(curr->rightChild);
        }
        
    }

    Node* search(int value)
    {
        return search_recursion(value,root);
    }

    Node* search_recursion(int value,Node* curr)
    {
        if(curr == NULL)
        return NULL;
        else if(curr->data == value)
        return curr;
        else if(curr -> data > value)
        search_recursion(value,curr->leftChild);
        else if(curr -> data < value)
        search_recursion(value,curr->rightChild);

    } 
    
};
int main()
{
    BST s1;
    s1.insert(5);
    s1.insert(10);
    s1.insert(4);
    s1.insert(25);
    s1.insert(23);        
    s1.insert(15);
    s1.insert(12);
    s1.insert(0);
    s1.insert(3);
    // cout << s1.root->data;
    s1.display();
    cout<<endl;

    Node* find = s1.search(10);
	if (find!=NULL){cout << find->data << endl;}
	else{cout << "The number is not there in the tree" << endl;} 

}
