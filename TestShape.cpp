// File Name: TestShape.cpp
// Name of Author: Hwee Lee
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 5 hours

#include "ShapeAnimator.h"

int main()
{
    // Create a tent and a box according to the requirements
    Tent tent(40,20,13);
    Box box(5,15,4,7);

    // Draw the tent and the box
    tent.draw();
    box.draw();


    // Set direction of motion for the two shapes
    // Tent moves straight up
    tent.setDirection(0,-1);
    // Box moves horizontally to the right
    box.setDirection(1,0);

    // Simultaneously move the tent and the box
    for (int k = 0; k < 12; k++)
    {
        Sleep(75);
        tent.move();   //move tent
        box.move();   //move box
    }


    // Move the box farther to the right
    for (int k = 0; k < 48; k++)
    {
        Sleep(75);
        box.move();
    }

    Shape *myShapes[] = {&tent, &box};

    // Create a complex shape composed of the tent and the box
    // Hints: you need to plug in above myShapes array

    ComplexShape complex(myShapes, 2);


    // Set directions for the two shapes
    
    //tent is movint to the right
    tent.setDirection(-1,0);

    //set box to move up
    box.setDirection(0,-1);


    // Move the complex shape: this will move both the tent and the box
    for (int k = 0; k < 12; k++)
    {
        Sleep(75);
        complex.move();
    }

    box.setDirection(-1,0);
    // Continue moving the box by itself
    for (int k = 0; k < 36; k ++)
    {
        Sleep(75);
        box.move();
    }

    return 0;
}

