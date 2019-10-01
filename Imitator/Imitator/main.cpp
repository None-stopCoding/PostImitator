#include "Imitator.h"

int main()
{
	setlocale(LC_ALL, "ru");

	try {
		Imitator start;			// запускаем имитатор
	}
	catch (const char* e) {
		system("cls");
		printf("\n%s\n", e);
		getchar();
	}

	return 0;
}
