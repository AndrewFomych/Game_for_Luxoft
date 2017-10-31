#pragma once
extern enum moveCar { STOP = 0, LEFT, RIGHT, UP, DOWN };
extern moveCar dir;
class Input {
public:
	void move();
private:
	enum keyButtom { Left = 75, Right = 77, Up = 72, Down = 80, Esc = 27, Enter = 13 };
};