#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

bool gameOver;
const int width = 20;
const int heigtht = 20;
enum eDirect { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirect dir;
int x, y, carY, carX, car2X, car2Y;
int tailX[20], tailY[20], tail2X[20], tail2Y[20];
int nTail, nTail2;
int randiz1, randiz2, randiz3, randiz4, randiz5, randiz6, randiz7, randiz8, randiz9, randiz10, randiz11;
int slp = 300;


using namespace std;

class Draw
{

public:
	void map(double _dist, int _timer_m, int _timer_s, int _speed) {
		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

		for (int i = 0; i < heigtht; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0 || j == width - 1)
					cout << "#";
				if (j == width / 2)
					cout << "|";
				if (i == y && j == x)
					cout << "0";

				else {
					bool print = false;
					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == j + randiz11 && tailY[k] == i) {
							print = true;
							cout << "1";
						}
					}

					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == (j + randiz1) && tailY[k] == i + randiz2) {
							print = true;
							cout << "1";
						}
					}

					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == (j + randiz3) && tailY[k] == i + randiz4) {
							print = true;
							cout << "1";
						}
					}

					for (int k = 0; k < nTail2; k++) {
						if (tail2X[k] == j - randiz5 && tail2Y[k] == i + randiz6) {
							print = true;
							cout << "1";
						}
					}

					for (int k = 0; k < nTail2; k++) {
						if (tail2X[k] == j - randiz7 && tail2Y[k] == i + randiz8) {
							print = true;
							cout << "1";
						}
					}
					for (int k = 0; k < nTail2; k++) {
						if (tail2X[k] == j - randiz9 && tail2Y[k] == i + randiz10) {
							print = true;
							cout << "1";
						}
					}
					if (!print)
						cout << " ";
				}
			}

			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

		cout << "speed: " << _speed << endl;
		cout << "time: " << _timer_m << " min, " << _timer_s << " sec" << endl;
		cout << "distance: " << _dist << endl;
	}
};

class Input {
private:
	bool point = true;
public:
	void move() {
		dir = STOP;
		Sleep(slp);
		if (_kbhit()) {
			switch (_getch())
			{
			case 75:
				dir = LEFT;
				break;
			case 77:
				dir = RIGHT;
				break;
			case 72:
				dir = UP;
				break;
			case 80:
				dir = DOWN;
				break;
			case 27:
				exit(0);
				break;
			case 13:
				system("pause");
				break;
			}
		}

	}

};

class Logic {
private:
	int speed;
	int prevX;
	int prevY;
	int prev2X, prev2Y;
	double dist = 0;
	int timer_s = 0;
	int timer_m = 0;

public:
	void move() {
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
				slp -= 30;
			}
			break;
		case DOWN:
			if (speed > 10) {
				speed -= 10;
				slp += 30;
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
			randiz1 = rand() % 4;
			randiz2 = rand() % 2;
			randiz3 = rand() % 4;
			randiz4 = rand() % 2;
			randiz11 = rand() % 4;
		}

		--car2Y;
		if (car2Y == 0) {
			car2Y = 19;
			car2X = 10;
			randiz5 = rand() % 8;
			randiz6 = rand() % 4;
			randiz7 = rand() % 8;
			randiz8 = rand() % 4;
			randiz9 = rand() % 8;
		}

		if (x >= width - 2)
			x = 18;

		if (x < 0)
			x = 0;
	}

	void GameOver1(int _randiz1, int _randiz2) {
		for (int i = 0; i < 20; i++) {
			if (tailX[i] == x + _randiz1 && tailY[i] == (y + 1) + _randiz2)
				gameOver = true;
		}
	}

	void GameOver2(int _randiz1, int _randiz2) {
		for (int i = 0; i < 20; i++) {
			if (tail2X[i] == x - _randiz1 && tail2Y[i] == (y + 1) + _randiz2)
				gameOver = true;
		}
	}

	void randomCars(int _tailX[], int _tailY[], int _carX, int _carY, int _nTail) {
		prevX = _tailX[0];
		prevY = _tailY[0];
		_tailX[0] = _carX;
		_tailY[0] = _carY;

		for (int i = 1; i < _nTail; i++) {
			prev2X = _tailX[i];
			prev2Y = _tailY[i];
			_tailX[i] = prevX;
			_tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
	}

	void timer() {
		timer_s = clock() / (800 + slp);

		if (timer_s > 60) {
			timer_s -= 60;
			++timer_m;
		}
	}

	void Distance() {
		if (timer_m != 0)
			dist = speed * ((timer_m * 60) + timer_s);
		else
			dist = speed * timer_s;
	}

	double getDist() {
		return dist;
	}

	int getTimer_m() {
		return timer_m;
	}

	int getTimer_s() {
		return timer_s;
	}

	int getSpeed() {
		return speed;
	}

	void setSpeed(int _speed) {
		speed = _speed;
	}
};

void Setup() {
	gameOver = false;
	dir = STOP;
	x = 14;
	y = 10;
	carY = 0;
	car2Y = 19;
	car2X = 10;
	nTail = 2;
	nTail2 = 2;
}

int main()
{
	Setup();
	Draw draw;
	Input input;
	Logic logic;
	logic.setSpeed(10);
	while (!gameOver) {
		draw.map(logic.getDist(), logic.getTimer_m(), logic.getTimer_s(), logic.getSpeed());
		logic.GameOver1(randiz11, 0);
		logic.GameOver1(randiz1, randiz2);
		logic.GameOver1(randiz3, randiz4);
		logic.GameOver2(randiz5, randiz6);
		logic.GameOver2(randiz7, randiz8);
		logic.GameOver2(randiz9, randiz10);
		input.move();
		logic.move();
		logic.timer();
		logic.Distance();
		logic.randomCars(tailX, tailY, carX, carY, nTail);
		logic.randomCars(tail2X, tail2Y, car2X, car2Y, nTail2);
	}
	cout << "Game Over!\n";
	system("pause");

	return 0;
}
