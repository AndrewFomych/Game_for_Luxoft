#pragma once
class Logic {
public:
	void move();
	void dontGo();
	void gameOver1(int _randomNumber1, int _randomNumber2);
	void gameOver2(int _randomNumber1, int _randomNumber2);
	void randomCars(int _coordinateOfBarierX[], int _coordinateOfBarierY[], 
		int _carX, int _carY, int _lengthOfBarier);
	void timer();
	void distanceCar();
	double getDist();
	int getMin();
	int getSec();
	int getSpeed();
	void setSpeed(int _speed);
	void setGameOver(bool _gameOver);
	bool getGameOver();

private:
	bool gameOver;
	int speed;
	int coordX, coordY;
	int coord2X, coord2Y;
	double dist = 0;
	int sec = 0;
	int min = 0;
};
