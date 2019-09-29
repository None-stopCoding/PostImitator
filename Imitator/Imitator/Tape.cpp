#include <iostream>
#include <string>
using namespace std;

#include "Tape.h"

Tape::Tape() : tape(new int[TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// ������������� ��������� �������� ����� �� �����
	tape[10] = 1;
	tape[11] = 1;
	tape[13] = 1;
}

void Tape::show()
{
	system("cls");
	// ������� �������
	for (int section = 0; section < TAPE_SIZE; section++) {
		if (carret == section) {
			printf("+");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	// ������� �����
	for (int section = 0; section < TAPE_SIZE; section++) {
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
	printf("\n");
	return;
}

void Tape::showEdit()
{
	this->show();
	
	char* up = helper.generateStringForEditTapeMode(TAPE_SIZE, "^");
	char* vertical = helper.generateStringForEditTapeMode(TAPE_SIZE, "|");
	char* number = helper.generateStringForEditTapeMode();

	printf("%s%s%s\n", up, vertical, number);
}

void Tape::editTape(int index)
{
	if (index < 0 || index >= TAPE_SIZE) {
		throw "���, �� ����� �� ����������. ��������� �� �������, �������� ���.";
	}

	tape[index] = (tape[index]) ? 0 : 1;
}

int Tape::validate(char* input)
{
	int validateInput = atoi(input);
	return validateInput;
}