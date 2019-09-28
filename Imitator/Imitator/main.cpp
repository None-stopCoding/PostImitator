#include <iostream>

#include "Imitator.h"
#include "Tape.h"

int main()
{
	Imitator app;
	app.run();

	if (app.__getState() == 101) {
		system("cls");
		printf("");
	}
}
