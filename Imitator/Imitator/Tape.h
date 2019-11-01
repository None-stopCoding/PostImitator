#pragma once
using namespace std;

#include "Helper.h"

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
	~Tape();							// ������ �����
	void show();						// ������� ����� � �������
	void showEdit();					// ������� ������� � ������ ��������������
	void editTape(int);					// �������� ����� �� �������
	void moveCarret(int);			// ������� �������
	bool isMarked(int);					// ����� �� �����

	int getCarret();					// �������� ��������� �������
};

