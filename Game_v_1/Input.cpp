#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Global.h"
#include "Input.h"
using namespace std;

	void Input::move() {
		dir = STOP;
		Sleep(wait);
		if (_kbhit()) {
			switch (_getch())
			{
			case Left:
				dir = LEFT;
				break;
			case Right:
				dir = RIGHT;
				break;
			case Up:
				dir = UP;
				break;
			case Down:
				dir = DOWN;
				break;
			case Esc:
				exit(0);
				break;
			case Enter:
				system("pause");
				break;
			}
		}

	}

