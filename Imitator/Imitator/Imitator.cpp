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
	printf("\nПереключение режимов возможно только перед началом ввода!");
	printf("\n\tCtrl - режим редактирования/ выполнения");
	printf("\n\tEsc - режим редактирования ленты/ команд");
	printf("\nВы в режиме %s\n", mode);
}

void Imitator::edit()
{
	this->editComand();
}

void Imitator::editTape()
{
	this->helper("редактирования ленты");
	try {
		tape.showEdit();
	}
	catch (const char* e) {
		this->concatError(e);
		throw errorMsg;
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
	case 48 ... 57:
		input -= 48;
		break;
	default:
		printf("\nВвод только чисел\n");
		getchar();
		Imitator::editTape();
	}

	try {
		int secondInput = _getch();
		if (secondInput != VK_RETURN) {
			if (48 >= secondInput && secondInput <= 57) {
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
	this->helper("редактирования команд");
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