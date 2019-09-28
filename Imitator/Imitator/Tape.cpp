#include <iostream>

#include "Tape.h"

Tape::Tape() : tape(new int[this->TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// ������������� ��������� �������� ����� �� �����
	tape[10] = 1;
	tape[11] = 1;
	tape[13] = 1;
}

void Tape::show()
{
	// ������� �������
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		if (carret == section) {
			printf("+");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	// ������� �����
	for (int section = 0; section < this->TAPE_SIZE; section++) {
		switch (this->tape[section]) {
		case 0:
			printf("O");		// ����� �� �����
			break;
		case 1:
			printf("*");		// ����� �����
			break;
		default:
			throw "������ � ����������� �����\n";
		}
	}
	return;
}