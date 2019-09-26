#include <iostream>
#include <Windows.h>

#include "Imitator.h"

Imitator::Imitator() : state(0), tape(new int[this->TAPE_SIZE]()) 
{
	// TODO добавить title к консольке и поменять цвет самой консольки
	/*const char* consoleTitle = "Машина Поста";
	SetConsoleTitle(consoleTitle);*/

	// Увеличиваем буфер конcольки
	_COORD coordinates;
	coordinates.X = 500;
	coordinates.Y = 500;

	if (0 == SetConsoleScreenBufferSize(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coordinates
	)) {
		this->state = 101;
	}

	// устанавливаем дефолтные значения каретки и меток на ленте
}

void Imitator::run()
{
	this->show();
}

void Imitator::show()
{
	// выводим картеку
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		break;
	}
	// выводим ленту
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		switch (this->tape[section]) {
		case 0:
			printf("O");		// метка не стоит
			break;
		case 1:
			printf("0");		// метка стоит
			break;
		case 2:
			//U + 26C9 - каретка белая
			break;
		default:
			break;
		}
	}
	return;
}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}