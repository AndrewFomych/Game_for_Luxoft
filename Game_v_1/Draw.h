#pragma once
class Draw {
public:
	void map(double _dist, int _min, int _sec, int _speed);

	void randomCars(int _lengthOfBarier, int _iteration_i, int _iteration_j,
		int _randomNumber1, int _randomNumber2, int coordinateOfBarierX[], int coordinateOfBarierY[]);

private:
	bool print;
	int iteration_i, iteration_j;
};