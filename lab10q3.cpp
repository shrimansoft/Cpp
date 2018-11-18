#include<iostream>

using namespace std;

class rectangle
{
	private:
		float le,br;
	public:
		rectangle()
		{
			cout<<"\nEnter the length of the rectangle:";
			cin>>le;
			cout<<"\nEnter the breadth of the rectangle:";
			cin>>br;
		}
		rectangle(float a,float b)
		{
			le=a;
			br=b;
		}

		float area()
		{
			return le*br;
		}
		float perimeter()
		{
			return 2*(le+br);
		}
		
};



int main()
{
	cout<<"\n\n Enter the deatels of first rectangle:";
	rectangle r1;
	cout<<"\n\n Enter the deatels of secand rectangle:";
	rectangle r2;
	if(r1.area()!=r2.area())
	cout<<"\nThe Area of "<<((r1.area()<r2.area())?"secand":"first")<<"  grater\n";
	else
	cout<<"\nThe Area are equal";
	if(r1.perimeter()!=r2.perimeter())
	cout<<"\nThe perimeter of "<<((r1.perimeter()<r2.perimeter())?"secand":"first")<<"  grater\n";
	else
	cout<<"\nThe perimerer are equal";

}
