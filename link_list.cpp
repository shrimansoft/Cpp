#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(){
        next = NULL;
    }

};

class LinkedList{
    public:
    // Head -> Node type ptr
    Node * head;

    // Construct
    LinkedList(){
        head = NULL;
    } 

    // Insert
    void insert(int value){
       Node * temp = new Node; 
       temp->data = value;
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
	       Node * tail=head;
	       while(tail->next!=NULL)
		       tail=tail->next;
	       tail->next = temp;
       }
    } 

    void insertAt(int pos, int value){

		// Create a node
		Node * temp = new Node;
		temp -> data = value;
	    if(pos-1){

		// Reach the place before the pos
		Node * current = head;
		for(int i=1;i<pos-1;i++)
			current = current->next;

		// Moving ptrs like magic ! if not head
		temp->next = current->next;
		current->next = temp;
	    }
	    else{
		temp->next=head;
	    	head=temp;
	    }	
		

    }

    // Deletion of last element
    void delet(){
	    if(head==NULL)
		    cout<<"underflow!!\n";
	    else{
		    if(head->next==NULL){
			    delete head;
			    head=NULL;
		    }
		    else{
			    Node * current = head;
			    while(current->next->next != NULL)
				    current = current->next;
			    delete current->next;
			    current->next=NULL;
		    }
	    }
    }

    int countIrems(){
	    if(head==NULL)
		    return 0;
	    else{
		    Node * current = head;
		    int i=1;
		    while(current->next!=NULL){
			    current=current->next;
			    i++;
		    }
		    return i;
	    }
    }
	    
    void deleteAt(int pos){
	    if(head==NULL){
		    cout<<"underflow!!\n";
	    }
	    else{
		    if(pos>countIrems())
			    cout<<"Node not exist!!\n:";
		    else{
			    if(pos==countIrems())
				    delet();
			    else{
				    Node * temp,* current=head;
				    for(int i=pos;i-2;i--)
					    current=current->next;
				    temp=current->next;
				    current->next=current->next->next;
				    delete temp;
			    }
		    }
	    }
    }		    
    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();
    l1.delet();
    l1.display();
    l1.insertAt(2,8);
    l1.display();
    return 0;
}
