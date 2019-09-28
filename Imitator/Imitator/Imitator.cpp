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

void Imitator::run()
{
	this->helper();
	this->edit();
}

void Imitator::helper()
{
	printf("\nПереключение режимов:");
	printf("\n\tCtrl+1 - режим редактирования");
	printf("\n\tCtrl+2 - режим выполнения\n");
}

void Imitator::edit()
{
	bool wrongInput = false;
	do {
		try {
			tape.show();
		}
		catch (const char* e) {
			this->concatError(e);
			throw errorMsg;
		}

		printf("\n\n\t1. Лента");
		printf("\n\t2. Команды");
		printf("\nВыберите объект редактирования: ");
		switch (_getch()) {
		case 49:
			this->editTape();
			break;
		case 50:
			this->editComand();
			break;
		default:
			system("cls");
			wrongInput = true;
		}
	} while (wrongInput);
		
}

void Imitator::execute()
{

}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}