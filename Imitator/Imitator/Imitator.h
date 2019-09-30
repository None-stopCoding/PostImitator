#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;


#include "Tape.h"
#include "Command.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "Ошибка в работе имитатора.Приносим свои извинения.\nТриггер:\t";
	string userInput;					// значение при первом вводе (при выборе режима)
	bool statusExit;					// true - завершение

	Tape tape;							// лента имитатора
	Command command;					// команды
	Helper helper;						// помощник

	void execute();						// режим компиляции
	void editTape();					// редактирование ленты
	void editCommand();					// редактирование команд
	void controlMode(const char*);		// ввод первого символа (обработка переключателя режимов)

public:
	Imitator();							// запуск имитатора
};

