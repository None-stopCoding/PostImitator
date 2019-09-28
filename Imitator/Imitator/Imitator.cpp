#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>

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
		this->concatError("Ошибка изменения буфера консоли");
		throw errorMsg;
	}
}

void Imitator::concatError(const char* msg)
{
	char error[1000];
	strcpy(error, msg);
	strcat(errorMsg, error);
}

void Imitator::helper(const char* mode)
{
	printf("\nПереключение режимов:");
	printf("\n\tCtrl - режим редактирования/ выполнения");
	printf("\nВы в режиме %s\n", mode);
}

void Imitator::edit()
{
	this->helper("редактирования");
	this->editComand();
}

void Imitator::editTape()
{
	try {
		tape.showEdit();
	}
	catch (const char* e) {
		this->concatError(e);
		throw errorMsg;
	}

	printf("\nИндекс ленты, где меняем значение (если там стоит метка, то ее убираем, если ее там нет, то ставим):");

	int key = _getch();
	if (key == VK_CONTROL) {
		this->editComand;
	}
}

void Imitator::editComand()
{
	try {
		tape.show();
	}
	catch (const char* e) {
		this->concatError(e);
		throw errorMsg;
	}

	printf("Inside");
}

void Imitator::execute()
{
	this->helper("компиляции");
}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}