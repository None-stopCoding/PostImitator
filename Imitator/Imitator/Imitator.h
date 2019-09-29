#pragma once
#include "Tape.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "������ � ������ ���������.�������� ���� ���������.\n�������:\t";

	Tape tape;							// ����� ���������
	Helper helper;						// ��������

	void execute();						// ����� ����������
	void editTape();					// �������������� �����
	void editComand();					// �������������� ������
	char* controlMode(const char*);		// ���� ������� ������� (��������� ������������� �������)

public:
	Imitator();							// ������ ���������
};

