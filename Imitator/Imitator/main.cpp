#include <iostream>

#include "Imitator.h"

int main()
{
	// TODO Создать сущность Лента
	Imitator app;
	app.run();

	if (app.__getState() == 101) {
		system("cls");
		printf("Ошибка в работе имитатора. Приносим свои извинения.");
	}
}
