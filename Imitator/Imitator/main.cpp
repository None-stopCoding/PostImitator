#include <iostream>

#include "Imitator.h"

int main()
{
	// TODO ������� �������� �����
	Imitator app;
	app.run();

	if (app.__getState() == 101) {
		system("cls");
		printf("������ � ������ ���������. �������� ���� ���������.");
	}
}
