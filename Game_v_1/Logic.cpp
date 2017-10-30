#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Global.h"
#include "Logic.h"
using namespace std;



	void Logic::move() {
		switch (dir)
		{
		case LEFT:
			--x;
			break;
		case RIGHT:
			++x;
			break;
		case UP:
			if (speed < 110) {
				speed += 10;
				wait -= 30;
			}
			break;
		case DOWN:
			if (speed > 10) {
				speed -= 10;
				wait += 30;
			}
			else {
				cout << "\n	don`t stop!\n";
				Sleep(500);
			}
			break;
		}
		++carY;
		if (carY == 19) {
			carY = 0;
			carX = rand() % 10;
			randomNamber1 = rand() % 4;
			randomNamber2 = rand() % 2;
			randomNamber3 = rand() % 4;
			randomNamber4 = rand() % 2;
			randomNamber11 = rand() % 4;
			lengthOfBarier = (rand() % 3) + 1;
		}

		--car2Y;
		if (car2Y == 0) {
			car2Y = 19;
			car2X = 10;
			randomNamber5 = rand() % 8;
			randomNamber6 = rand() % 4;
			randomNamber7 = rand() % 8;
			randomNamber8 = rand() % 4;
			randomNamber9 = rand() % 8;
			lengthOfBarier2 = (rand() % 3) + 1;
		}
		dontGo();
	}


	void Logic::dontGo() {
		if (x >= WIDTH - 2)
			x = 18;

		if (x < 0)
			x = 0;
	}


	void Logic::gameOver1(int _randomNumber1, int _randomNumber2) {
		for (int i = 0; i < 20; i++) {
			if (coordinateOfBarierX[i] == x + _randomNumber1 && coordinateOfBarierY[i] == (y + 1) + _randomNumber2)
				gameOver = true;
		}
	}


	void Logic::gameOver2(int _randomNumber1, int _randomNumber2) {
		for (int i = 0; i < 20; i++) {
			if (coordinateOfBarier2X[i] == x - _randomNumber1 && coordinateOfBarier2Y[i] == (y + 1) + _randomNumber2)
				gameOver = true;
		}
	}


	void Logic::randomCars(int _coordinateOfBarierX[], int _coordinateOfBarierY[],
		int _carX, int _carY, int _lengthOfBarier) {

		coordX = _coordinateOfBarierX[0];
		coordY = _coordinateOfBarierY[0];
		_coordinateOfBarierX[0] = _carX;
		_coordinateOfBarierY[0] = _carY;

		for (int i = 1; i < _lengthOfBarier; i++) {
			coord2X = _coordinateOfBarierX[i];
			coord2Y = _coordinateOfBarierY[i];
			_coordinateOfBarierX[i] = coordX;
			_coordinateOfBarierY[i] = coordY;
			coordX = coord2X;
			coordY = coord2Y;
		}
	}


	void Logic::timer() {
		sec = clock() / (800 + wait);

		if (sec > 60) {
			sec -= 60;
			min = 1;
		}
		if (sec > 120) {
			sec -= 120;
			min = 2;
		}
	}


	void Logic::distanceCar() {
		if (min != 0)
			dist = speed * ((min * 60) + sec);
		else
			dist = speed * sec;
	}


	double Logic::getDist() {
		return dist;
	}

	int Logic::getMin() {
		return min;
	}

	int Logic::getSec() {
		return sec;
	}

	int Logic::getSpeed() {
		return speed;
	}

	void Logic::setSpeed(int _speed) {
		speed = _speed;
	}
