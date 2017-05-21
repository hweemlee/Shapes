// File Name: ShapeAnimator.cpp
// Name of Author:
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 5 hours

#include "ShapeAnimator.h"

//Shape Functions

/*

 Shape::Shape(int dRow , int dCol){
	this-> dRow = dRow;
	this -> dCol = dCol;
}
*/
void Shape::setDirection(int dRow , int dCol){
	this -> dRow = dRow;
	this -> dCol = dCol;
}

void Shape::getDirection(int &x , int &y){
	x = dRow;
	y = dCol;
}

//*************************************************************
// Moves a simple shape one step by erasing the shape         *
// at its current position, changing its position, and then   *
// redrawing the shape at its new position.                   *
//*************************************************************

void SimpleShape::getPosition(int &x , int &y) {
			x = rowPos;
			y = colPos;
		}
void SimpleShape::setPosition(int x , int y) {
			rowPos = x;
			colPos = y;
		}

		//get color variable
int SimpleShape::getColor(){
			return color;
		}

		//set color variable
void SimpleShape::setColor(int c)
		{
			color = c;
		}

void SimpleShape::move()
{
    int dRow, dCol; // Direction of motion
    int savedColor = color;

    color = 0;      // Drawing in color 0 erases the shape
    setColor(color);
    draw();

    // Compute the new position for the shape by adding a step in
    // the proper direction to the current position
    getDirection(dRow , dCol);
    rowPos += dRow;
    colPos += dCol;

    // Draw the shape at its new position in its specified color
    color = savedColor;
    setColor(color);
    draw();

}

//***********************************
// Draws a tent at its position     *
//***********************************
void Tent::draw()
{

	int rowPos, colPos;
	getPosition(rowPos,colPos);
	COORD pos;


	int currentLength = baseLength;
	int tentHeight = currentLength/2;

	pos.X = rowPos + tentHeight;
	pos.Y = colPos;


    // Set the color attribute
    SetConsoleTextAttribute(outHandle, getColor());

    // Draw the lines that form the tent beginning with
    // the base and moving up toward the point

    //keeps track of the number of rows in triangle
    for (int r = tentHeight ; r > 0 ; r--)
    {
    	SetConsoleCursorPosition(outHandle, pos);

		//prints stars
		for (int star = 0 ; star < currentLength ; star++)
		{
			cout << "*";
		}

		currentLength -=2;
    	pos.Y--; //move up a row
    	pos.X++; //increment x position
    }

    // Restore normal attribute
    SetConsoleTextAttribute(outHandle, 7);

}

//**********************************
// Draws a box shape               *
//**********************************
void Box::draw()
{
    int rowPos, colPos;
    getPosition(rowPos,colPos);
    COORD pos;

    pos.X = rowPos;
    pos.Y = colPos;

    // Set the color attribute for the box
    SetConsoleTextAttribute(outHandle, getColor());

	
    // Draw the lines that make up the  box
    for (int r = 0; r < height; r++)
    {
        SetConsoleCursorPosition(outHandle, pos);

        //prints a line in the box shape
	for(int i = 0 ; i < width ; i++) {
			cout<<"*";
	}
		pos.Y++;
    }

    // Restore normal text attribute
    SetConsoleTextAttribute(outHandle, 7);

}
//***********************************************
// Box Constructor sets the color, position,    *
// dimensions for a box shape, and draws        *
// the box at its initial position              *
//***********************************************
Box::Box(int rowPos, int colPos , int width , int height)
{
    setColor(4);

    this -> width = width;
    this -> height = height;
    setPosition(rowPos, colPos);
}

//***********************************************
// Constructor sets the color for a Tent shape, *
// sets the position of the tent as well as the *
// length of its base and draws it at its       *
// initial position                             *
//***********************************************
Tent::Tent(int baseRowPos , int baseColPos , int baseLength)
{
	setColor(2);
    this -> baseLength = baseLength;
    setPosition(baseRowPos, baseColPos);
}

//*********************************************************************
// Constructor builds a complex shape by assembling a vector of       *
// constituent shapes                                                 *
//*********************************************************************
ComplexShape::ComplexShape(Shape ** shapeCollection, int shapesCount)
{
    Shape *p;
    for (int k = 0; k < shapesCount; k++)
    {
        p = shapeCollection[k];
        shapes.push_back(p);
    }
}

//**************************************
// Moves a complex shape by moving the *
// constituent shapes                  *
//**************************************

void ComplexShape::move(){

	for (unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->move();

}

void ComplexShape::setDirection(int x , int y )
{
	for (unsigned int i = 0 ; i <shapes.size() ; i++)
		shapes[i]->setDirection(x,y);

}

