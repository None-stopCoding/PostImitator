#include "Tape.h"

Tape::Tape() : tape(new int[TAPE_SIZE]()), carret(CARRET_START_POS) 
{
	// ������������� ��������� �������� ����� �� �����
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
	
	string up = helper.generateStringForEditTapeMode(TAPE_SIZE, "^");
	string vertical = helper.generateStringForEditTapeMode(TAPE_SIZE, "|");
	cout << up << vertical << endl;
}

void Tape::editTape(int index)
{
	if (0 <= index && index < TAPE_SIZE) {
		tape[index] = (tape[index]) ? 0 : 1;
	}
	else {
		throw "���, �� ����� �� ����������. ��������� �� �������, �������� ���.";
	}
}

void Tape::moveCarret(int index)
{
	if (0 <= index && index < TAPE_SIZE) {
		carret = index;
	}
	else {
		throw "����� ������� �� '�������' �����";
	}
}

bool Tape::isMarked(int index)
{
	if (0 <= index && index < TAPE_SIZE) {
		return tape[index];
	}
	else {
		throw "���, �� ����� �� ����������. ��������� �� �������, �������� ���.";
	}
}

int Tape::getCarret()
{
	return carret;
}