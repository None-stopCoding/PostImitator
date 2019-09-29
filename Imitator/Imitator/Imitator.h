#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <map>
using namespace std;


#include "Tape.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "Ошибка в работе имитатора.Приносим свои извинения.\nТриггер:\t";

	Tape tape;							// лента имитатора
	Helper helper;						// помощник

	void execute();						// режим компиляции
	void editTape();					// редактирование ленты
	void editComand();					// редактирование команд
	char* controlMode(const char*);		// ввод первого символа (обработка переключателя режимов)

public:
	Imitator();							// запуск имитатора
};

