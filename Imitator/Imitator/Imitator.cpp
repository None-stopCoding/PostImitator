#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

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
		throw helper.concatError(errorMsg, "Ошибка изменения буфера консоли");
	}
}

void Imitator::editTape()
{
	helper.infoMessage("редактирования ленты");
	try {
		tape.showEdit();
	}
	catch (const char* e) {
		throw helper.concatError(errorMsg, e);
	}

	printf("\nИндекс ленты, где меняем значение\n(если там стоит метка, то ее убираем, если ее там нет, то ставим):");
	int input = _getch();
	switch (input) {
	case VK_ESCAPE:
		this->editComand();
		break;
	case VK_CONTROL:
		this->execute();
		break;
	default:
		if (48 <= input && input <= 57) {
			input -= 48;
		}
		else {
			printf("\nВвод только чисел\n");
			getchar();
			Imitator::editTape();
		}
	}

	try {
		int secondInput = _getch();
		if (secondInput != VK_RETURN) {
			if (48 <= secondInput && secondInput <= 57) {
				tape.editTape(atoi(
					strcat(&to_string(input)[0], &to_string(secondInput)[0])
				));
			}
			else {
				throw "\nВвод только чисел";
			}
		}
		else {
			tape.editTape(atoi(&to_string(input)[0]));
		}
	} catch (const char* e) {
		printf("\n%s\n", e);
		getchar();
		Imitator::editTape();
	}
}

void Imitator::editComand()
{
	helper.infoMessage("редактирования команд");
	try {
		tape.show();
	}
	catch (const char* e) {
		throw helper.concatError(errorMsg, e);
	}

	printf("Inside");
}

void Imitator::execute()
{
	helper.infoMessage("компиляции");
}

/* Геттеры */
int Imitator::__getState()
{
	return state;
}