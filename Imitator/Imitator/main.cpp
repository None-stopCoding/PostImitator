#include <iostream>

#include "Imitator.h"
#include "Tape.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Imitator app;
	try {
		app.editComand(); // запускаем имитатор в режиме редактировани команд
	}
	catch (const char* e) {
		system("cls");
		printf("\n%s\n", e);
	}
}
