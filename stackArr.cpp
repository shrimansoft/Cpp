#include<iostream>

using namespace std;

class StackArr{

private :

int stack[20];
int *top;

public :

StackArr() {
top=NULL;
}

void push(int in) {

	if(top==stack+19)
			cout<<"stack overflow";
	else{
		if(top==NULL)
			top=stack;
		else
			top++;
		*top=in;
	}
}


int pop() {

	if(top==NULL)
		cout<<"stack underflow";
	else{
		int retu=*top;
		if(top==stack)
			top=NULL;
		else
			top--;
		return retu;
	}
}

int size() {

return top-stack+1;
}

bool isEmpty(){
	if(top==NULL)
	return true;
	else
	return false;

}

void display(){
for(int i=0;i<size();i++)
cout<<" -> "<<*(top-i);

cout<<endl;
}

};










int main()
{
StackArr s1;
s1.push(5);
s1.display();
s1.push(4);
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
