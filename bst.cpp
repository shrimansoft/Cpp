//Binary search tree
#include<iostream>
using namespace std;

//The node class
class Node{
	public:
	int data;
	Node* l = NULL;
	Node* r = NULL;
	
	//Constructor
	Node(int val){
		data = val;
	}
};

//The tree class
class BST{
	public:
	Node* root;
	//Constructor
	BST(){
		root = NULL;
	}

	//The functionssssssss......
	//Insert
	void insert(int value){
		//If tree is null insert and leave
		if(root==NULL){
			root = new Node(value);
			return;
		}
		insertHelper(root, value);
	}

	void insertHelper(Node* curr, int value){
		//move accordingly (but check before moving)
		if(curr->data > value){
			//If the next position is NULL, insert
			if(curr->l==NULL){
				curr->l = new Node(value);
				return;
			}
			//else go for recursion
			else{insertHelper(curr->l, value);}
		}
		else{
			//If the next position is NULL, insert
			if(curr->r==NULL){
				curr->r = new Node(value);
				return;
			}
			//else go for recursion
		 	else {insertHelper(curr->r, value);}
		}
		
	}

	void display(){
		display2(root);
		cout<<"\b "<<endl;
	}
	
	//This is inorder display...
	void display2(Node* curr){
		//Base condition
		if(curr == NULL){return;}
		//display left
		display2(curr->l);
		//display current
		cout << curr->data << ",";
		//display right
		display2(curr->r);
	}




	//Search
	Node* search(int val){
		return search2(val, root);
	}

	Node* search2(int val,Node* curr){
		//If tree is empty or reached the end of tree or value found
		if(curr == NULL || curr->data == val){return curr;}
		else if(curr->data > val){return search2(val, curr->l);}
		else{return search2(val, curr->r);}

	}

};
int main(){
	BST b1;
	b1.insert(3);
	b1.insert(4);
	b1.insert(2);
	b1.display();
	Node* find = b1.search(2);
	if (find!=NULL){cout << find->data << endl;}
	else{cout << "The number is not there in the tree" << endl;} 
return 0;
}
