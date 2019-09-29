#pragma once
#include "Tape.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "Ошибка в работе имитатора.Приносим свои извинения.\nТриггер:\t";

	Tape tape;							// лента имитатора
	Helper helper;						// помощник

	void editTape();					// редактирование ленты
	char* controlMode(const char*);		// ввод первого символа (обработка переключателя режимов)

public:
	Imitator();							// запуск имитатора
	void execute();						// режим компиляции
	void editComand();					// редактирование команд
};

