#include <iostream>

#include "Tape.h"

Tape::Tape() : tape(new int[this->TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// устанавливаем дефолтные значения меток на ленте
	tape[10] = 1;
	tape[11] = 1;
	tape[13] = 2;
}

void Tape::show()
{
	// выводим картеку
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		if (carret == section) {
			printf("+");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	// выводим ленту
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		switch (this->tape[section]) {
		case 0:
			printf("O");		// метка не стоит
			break;
		case 1:
			printf("*");		// метка стоит
			break;
		default:
			throw "Ошибка в отображении ленты\n";
		}
	}
	printf("\n");
	return;
}

void Tape::showEdit()
{
	this->show();
	int rows = 0;
	while (rows++ < 3) {
		for (int section = 0; section < this->TAPE_SIZE; section += 10) {
			switch (rows) {
			case 0:
				printf("^");
				break;
			case 1:
				printf("|");
				break;
			case 2:
				printf("%d", section);
				break;
			default:
				throw "Ошибка в отображении ленты (режим редактирования)\n";
			}
		}
	}
}