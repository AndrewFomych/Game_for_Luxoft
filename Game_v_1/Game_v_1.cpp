#include "stdafx.h"
#include <iostream>
#include "Global.h"
#include "Draw.h"
#include "Input.h"
#include "Logic.h"
using namespace std;
extern moveCar dir;

void setup() {
	dir = STOP;
	x = 14;
	y = 10;
	carY = 0;
	car2Y = 19;
	car2X = 10;
	lengthOfBarier = 2;
	lengthOfBarier2 = 2;
}

int main()
{
	setup();
	Draw draw;
	Input input;
	Logic logic;
	logic.setSpeed(10);
	logic.setGameOver(false);
	while (!logic.getGameOver()) {
		draw.map(logic.getDist(), logic.getMin(), logic.getSec(), logic.getSpeed());
		logic.gameOver1(randomNamber11, 0);
		logic.gameOver1(randomNamber1, randomNamber2);
		logic.gameOver1(randomNamber3, randomNamber4);
		logic.gameOver2(randomNamber5, randomNamber6);
		logic.gameOver2(randomNamber7, randomNamber8);
		logic.gameOver2(randomNamber9, randomNamber10);
		input.move();
		logic.move();
		logic.timer();
		logic.distanceCar();
		logic.randomCars(coordinateOfBarierX, coordinateOfBarierY, carX, carY, lengthOfBarier);
		logic.randomCars(coordinateOfBarier2X, coordinateOfBarier2Y, car2X, car2Y, lengthOfBarier2);
	}
	cout << "Game Over!\n";
	system("pause");

	return 0;
}
