#include<iostream>

using namespace std;

class StackArr{

private :

int stack[20];
int *head;
int *tail;

public :

StackArr() {
head=NULL;
tail=NULL;
}
int *plusOne(int *point){
	if(point==stack+19)
	point=stack;
	else
	point++;
	return point;
}

void push(int in) {

	if(plusOne(head)==tail)
			cout<<"stack overflow";
	else{
		if(head==NULL){
			head=stack;
			tail=stack;
			*head=in;
		}
		else{
			head=plusOne(head);
			*head=in;
		}
	}
}


int pop() {

	if(head==NULL){
		cout<<"stack underflow";
		return 0;
	}
	else{
		int retu=*tail;
		if(head==tail){
			head=NULL;
			tail=NULL;
		}
		else
			tail=plusOne(tail);
		return retu;
	}
}

int size() {
int *temp=tail;
if(tail==NULL)
return 0;
else{
int count=1;
while(temp!=head){
temp=plusOne(temp);
count++;
}
return count;
}
}

bool isEmpty(){
	if(head==NULL)
		return true;
	else
		return false;

}

void display(){
int *temp=tail;
for(int i=0;i<size();i++){
cout<<" -> "<<*temp;
temp=plusOne(temp);
}
cout<<endl;
}

};










int main()
{
StackArr s1;
cout<<s1.size();
s1.push(5);

cout<<s1.size();
s1.display();
s1.push(4);
cout<<s1.size();
s1.display();
s1.push(7);
s1.display();
s1.push(2);
s1.display();
s1.push(9);
s1.display();
s1.push(1);
s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
}
