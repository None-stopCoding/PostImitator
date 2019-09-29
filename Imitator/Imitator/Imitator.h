#pragma once
#include "Tape.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "������ � ������ ���������.�������� ���� ���������.\n�������:\t";

	Tape tape;							// ����� ���������
	Helper helper;						// ��������

	void editTape();					// �������������� �����
	char* controlMode(const char*);		// ���� ������� ������� (��������� ������������� �������)

public:
	Imitator();							// ������ ���������
	void execute();						// ����� ����������
	void editComand();					// �������������� ������
};

