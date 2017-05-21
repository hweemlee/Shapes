// File Name: ShapeAnimator.h
// Name of Author: Hwee Lee
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 5 hours

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

//A global constant
//It is the handle to the output console
const HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);

// A shape has a direction and is able to move in that direction.
// The move is a virtual member function.
class Shape
{
	private:
		int dRow; //direction of row motion
		int dCol; //direction of column motion
	public:
		/*
		Shape(){
			dRow = 0;
			dCol = 0;
		}
		Shape(int dRow , int dCol);
		*/
		virtual void setDirection(int dRow, int dCol);
		void getDirection(int &dRow , int &dCol);
		virtual void move() = 0;
};

// A SimpleShape can be drawn at a given position in a specified color
// A SimpleShape inherits from Shape class
class SimpleShape : public Shape
{
	private:
		int rowPos;
		int colPos;
		int color;
	public:

		void getPosition(int &x , int &y);
		void setPosition(int x , int y);

		//get color variable
		int getColor();

		//set color variable
		void setColor(int c);

		virtual void draw() = 0;
		void move();

};

// A Box is a rectangular type of shape
// A Box inherits from SimpleShape
class Box : public SimpleShape
{
	private:
		int width;
		int height;
	public:
		//default constructor
		Box()
		{
			width = 0;
			height = 0;

		}
		Box(int rowPos , int colPos, int width , int height);
		void draw();
};

// A Tent is an isosceles triangle whose horizontal base has a
// given length and whose height is half the length of the base.
// The position of the triangle is the left endpoint of the base
// A Tent inherits from SimpleShape
class Tent : public SimpleShape
{
	private:
		int baseLength;
	public:
		//default constructor
		Tent()
		{
			baseLength = 0;
		}
		Tent(int baseRowPos , int baseColPos  , int baseLength);
		void draw();

};

// A ComplexShape is made up of simpler shapes. It is represented
// as a vector of pointers to the simpler shapes that make it up
// A ComplexShape inherits from Shape
class ComplexShape : public Shape
{
	private:
		vector<Shape *> shapes;
	public:
		ComplexShape(Shape ** shapeCollection, int shapesCount);
		virtual void move();
		virtual void setDirection(int dRow , int dCol);
};
