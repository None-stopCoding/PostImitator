#include <iostream>
#include <Windows.h>

#include "Imitator.h"

Imitator::Imitator() : state(0)
{
	// TODO добавить title к консольке и поменять цвет самой консольки
	/*const char* consoleTitle = "Машина Поста";
	SetConsoleTitle(consoleTitle);*/

	errorMsg = "Ошибка в работе имитатора. Приносим свои извинения.\nТриггер:\t";

	// Увеличиваем буфер конcольки
	_COORD coordinates;
	coordinates.X = 500;
	coordinates.Y = 500;

	if (0 == SetConsoleScreenBufferSize(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coordinates
	)) {
		state = 101;
	}
}

void Imitator::run()
{
	try {
		tape.show();
	}
	catch (char* e) {
		throw strcat(errorMsg, e);
	}
}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}