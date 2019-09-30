#include "Tape.h"

Tape::Tape() : tape(new int[TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// устанавливаем дефолтные значения меток на ленте
	tape[10] = 1;
	tape[11] = 1;
	tape[13] = 1;
}

Tape::~Tape()
{
	delete[] tape;
}

void Tape::show()
{
	// выводим картеку
	for (int section = 0; section < TAPE_SIZE; section++) {
		if (carret == section) {
			printf("+");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	// выводим ленту
	for (int section = 0; section < TAPE_SIZE; section++) {
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
	
	string up = helper.generateStringForEditTapeMode(TAPE_SIZE, "^");
	string vertical = helper.generateStringForEditTapeMode(TAPE_SIZE, "|");
	cout << up << vertical << endl;
}

void Tape::editTape(int index)
{
	if (index < 0 || index >= TAPE_SIZE) {
		throw "Увы, но лента не бесконечна. Обращение по индексу, которого нет.";
	}

	tape[index] = (tape[index]) ? 0 : 1;
}

void Tape::moveCarret(string direction)
{
	if (direction == "left") {
		if (carret) {
			carret--;
		}
		else {
			throw "Выход каретки за левую 'границу' ленты";
		}
	}
	else if (direction == "right") {
		if (carret < TAPE_SIZE) {
			carret++;
		}
		else {
			throw "Выход каретки за правую 'границу' ленты";
		}
	}
	else {
		throw "Неверное направление движения каретки";
	}
}

bool Tape::isMarked(int index)
{
	if (0 <= index && index < TAPE_SIZE) {
		return tape[index];
	}
	else {
		throw "Увы, но лента не бесконечна. Обращение по индексу, которого нет.";
	}
}

int Tape::getCarret()
{
	return carret;
}