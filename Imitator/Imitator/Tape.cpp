#include <iostream>

#include "Tape.h"

Tape::Tape() : tape(new int[this->TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// устанавливаем дефолтные значения меток на ленте
	tape[10] = 1;
	tape[11] = 1;
	tape[13] = 1;
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

	// выводим ленту
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		switch (this->tape[section]) {
		case 0:
			printf("O");		// метка не стоит
			break;
		case 1:
			printf("0");		// метка стоит
			break;
		default:
			throw "Ошибка в отображении ленты";
		}
	}
	return;
}