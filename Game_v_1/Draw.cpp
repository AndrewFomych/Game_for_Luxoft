#include "stdafx.h"
#include <iostream>
#include "Draw.h"
#include "Global.h"
using namespace std;


	void Draw::map(double _dist, int _min, int _sec, int _speed) {
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
					print = false;
					iteration_i = i;
					iteration_j = j;

					randomCars(lengthOfBarier, iteration_i, iteration_j,
						randomNamber11, 0, coordinateOfBarierX, coordinateOfBarierY);

					randomCars(lengthOfBarier, iteration_i, iteration_j,
						randomNamber1, randomNamber2, coordinateOfBarierX, coordinateOfBarierY);

					randomCars(lengthOfBarier, iteration_i, iteration_j,
						randomNamber3, randomNamber4, coordinateOfBarierX, coordinateOfBarierY);

					randomCars(lengthOfBarier2, iteration_i, iteration_j,
						-randomNamber5, randomNamber6, coordinateOfBarier2X, coordinateOfBarier2Y);

					randomCars(lengthOfBarier2, iteration_i, iteration_j,
						-randomNamber7, randomNamber8, coordinateOfBarier2X, coordinateOfBarier2Y);

					randomCars(lengthOfBarier2, iteration_i, iteration_j,
						-randomNamber9, randomNamber10, coordinateOfBarier2X, coordinateOfBarier2Y);

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
		cout << "time: " << _min << " min, " << _sec << " sec" << endl;
		cout << "distance: " << _dist << endl;
	}

	void Draw::randomCars(int _lengthOfBarier, int _iteration_i, int _iteration_j,
		int _randomNumber1, int _randomNumber2, int coordinateOfBarierX[], int coordinateOfBarierY[]) {

		for (int k = 0; k < _lengthOfBarier; k++) {
			if (coordinateOfBarierX[k] == _iteration_j + _randomNumber1 && coordinateOfBarierY[k] == _iteration_i + _randomNumber2) {
				print = true;
				cout << "1";
			}
		}
	}
