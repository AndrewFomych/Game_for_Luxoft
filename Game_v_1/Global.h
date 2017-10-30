#pragma once
#include <iostream>

	extern bool gameOver;
	extern const int WIDTH;
	extern const int HEIGTHT;
	enum moveCar { STOP = 0, LEFT, RIGHT, UP, DOWN };
	extern moveCar dir;
	extern int x, y, carY, carX, car2X, car2Y;
	extern int coordinateOfBarierX[20], coordinateOfBarierY[20],
		coordinateOfBarier2X[20], coordinateOfBarier2Y[20];
	extern int lengthOfBarier, lengthOfBarier2;
	extern int randomNamber1, randomNamber2, randomNamber3, randomNamber4, randomNamber5,
		randomNamber6, randomNamber7, randomNamber8, randomNamber9, randomNamber10, randomNamber11;
	extern int wait;
