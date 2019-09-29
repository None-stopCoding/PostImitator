#pragma once
#include "Tape.h"
#include "Helper.h"

class Imitator
{
	// ����� ������
	char errorMsg[200] = \
		"������ � ������ ���������.�������� ���� ���������.\n�������:\t";
	int state;							// ������ ������ �������� (	0 - ����� �������������� �����, \
																	1 - ����� ��������� ������, \
																	2 - ����� ����������, \
																	3 - ������ ����������, \
																	101 - ��������� ������)
	Tape tape;							// ����� ���������
	Helper helper;						// ��������

	void editTape();					// �������������� �����
	char* firstInput();					// ���� ������� ������� (��������� ������������� �������)

public:
	Imitator();							// ������ ���������
	void execute();						// ����� ����������
	void editComand();					// �������������� ������

	// �������
	int __getState();
};

