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
        return *search_recursion(value,&root);
    }

    Node** search_recursion(int value,Node** curr)
    {
        if((*curr) == NULL)
        return NULL;
        else if((*curr)->data == value)
        return curr;
        else if((*curr) -> data > value)
        search_recursion(value,&((*curr)->leftChild));
        else if((*curr) -> data < value)
        search_recursion(value,&((*curr)->rightChild));

    } 

    Node ** find_min(Node **curr)
    {
        if((*curr)!= NULL)
        {
            if((*curr)->leftChild != NULL)
            return find_min(&(*curr)->leftChild);
            else
            return curr;
        }
    }

    Node* replace_At_Parent(Node **A, Node *B)
    {
        B->leftChild= (*A)->leftChild;
        B->rightChild = (*A)->rightChild;
        Node* temp = *A;
        *A = B;

        return temp;
    }

    void deleteNode(int value)
    {
        Node** temp= search_recursion(value,&root);

        if(*temp!=NULL)
        {
            
        }



    }
    Node* delete_recursion(Node **curr)
    {
        cout<<"checkpoint 1"<< (*curr)->data << endl;
        Node* temp = *curr;
        if((*curr)->rightChild == NULL)
        {
            if((*curr)->leftChild != NULL)
            *curr = (*curr)->leftChild;
            else
            {
                *curr==NULL;
            }
            
        }
        else
        {
            return replace_At_Parent(curr,delete_recursion(find_min(&((*curr)->rightChild))));
        }
        
        

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

    Node* temp= new Node(9);
     s1.delete_recursion(s1.search_recursion(10,&(s1.root)));

cout<<endl;
    // s1.display();


cout <<endl;
     cout<<(*s1.find_min(&(find->rightChild)))->data;
}
