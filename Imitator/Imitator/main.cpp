#include <iostream>

#include "Imitator.h"
#include "Tape.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Imitator app;
	try {
		app.run();
	}
	catch (const char* e) {
		system("cls");
		printf("\n%s\n", e);
	}
}
