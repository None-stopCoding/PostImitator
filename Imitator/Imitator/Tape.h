#pragma once
#include "Helper.h";

class Tape
{
	const int TAPE_SIZE = 100;			// ����� �����
	const int CARRET_START_POS = 10;	// ����������� ������� ������

	int* tape;							//  ����������� ����� ���������, \
											0 - ��� �����, \
											1 - ���� �����
	int carret;							// ������� ������� �������
	Helper helper;						// ��������

public:
	Tape();								// ������� �����
	void show();						// ������� ����� � �������
	void showEdit();					// ������� ������� � ������ ��������������
	void editTape(int);					// �������� ����� �� �������
	int validate(char* );				// ��������� ������
};

