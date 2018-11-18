#include <iostream>


// ********************************************************************
//  Declaration of class Point
// ********************************************************************
using namespace std;
// class Point represents a two-dimensional point
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 

  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);

  // member function for moving a point by dx, dy:
  void Move(int dx, int dy);

  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;

  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);

//Lab 7 exercise 4.1. Add declaration of member function Print here:
  void Print();
// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  


// ********************************************************************
//  Methods for class Point
// ********************************************************************

// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}

// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
void Point::Print()
{
	cout<<'('<<X<<','<<Y<<')';
}    

//Lab 7 exercise 4.1. Add definition of member function print:


// ********************************************************************
//  Declaration of class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 

// ********************************************************************
//  Methods for class Rectangle
// ********************************************************************
class rectangle
{
private:
	Point A,B,C,D;
	int side1(){
	return (C.Get_X())-(A.Get_X());
	}
	int side2(){
	return (C.Get_Y())-(A.Get_Y());
	}

public: 
 //default constructor
 rectangle();
 
 //class constructor
 rectangle(Point,Point);

 //print
 void print();

 //area
 int area();

};
//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE: 

 //DEFAULT VALUES OF COORDINATES
 rectangle::rectangle()
 {
	A=Point(0,0);
	B=Point(1,0);
	C=Point(1,1);
	D=Point(0,1); 
 } 

 //COORDINATES ACCORDING TO USER 
 rectangle::rectangle(Point p1,Point p2)
 {
 	A=p1;
	B=Point(p2.Get_X(),p1.Get_Y());
	C=p2;
	D=Point(p1.Get_X(),p2.Get_Y()); 
 }
 
 void rectangle::print()
 {
 
	cout<<"\nA: ";
	A.Print();

	cout<<"\nB: ";
	B.Print();

	cout<<"\nC: ";
	C.Print();

	cout<<"\nD: ";
	D.Print();       
        
 }

 //AREA
  int rectangle::area()
 {
  return side1()*side2();
 }



// ********************************************************************
//  main() function for testing classes Point and Rectangle
// ********************************************************************



// Testing classes Point and Rectangle
int main()
{
// Declaring a point using default class constructor (x = y = 0):
  Point p1;
  cout<< "The x value for p1 is " << p1.Get_X() << endl;
  cout<< "The y value for p1 is " << p1.Get_Y() << endl;

// Declaring a point with coordinates X = 2, Y = 3:
  Point p2(2, 3);
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

// Moving point p2 by (1, -1):
  p2.Move(1, -1);
  cout<< "After the move:" << endl;
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

//Lab 7 exercise 4.1. Test member function print on points p1, p2:

  cout<<"\nthe cordinate of p1 is :";
  p1.Print();
  cout<<"\nthe cordinate of p2 is :";
  p2.Print();
//Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here:  
rectangle r1(Point(5,6),Point(2,1));
 r1.print();

 
cout<<"area of rectangle is:"<<r1.area()<<endl; 

  return 0;
}

//---------------------- point.cpp ------------------------------------//
//
//
