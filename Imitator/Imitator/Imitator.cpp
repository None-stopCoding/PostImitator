#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

#include "Imitator.h"

Imitator::Imitator() : state(0)
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
		throw this->concatError("Ошибка изменения буфера консоли");
	}
}

char* Imitator::concatError(const char* msg)
{
	char error[1000];
	strcpy(error, msg);
	strcat(errorMsg, error);
	return errorMsg;
}

void Imitator::run()
{
	printf("\nПереключение режимов:");
	printf("\n\t- режим редактирования");
	printf("\n\t- режим выполнения\n");

	this->edit();
}

void Imitator::edit()
{
	try {
		tape.show();
	}
	catch (const char* e) {
		throw this->concatError(e);
	}
}

void Imitator::execute()
{

}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}