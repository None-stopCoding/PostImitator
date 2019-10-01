#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <conio.h>
using namespace std;


#include "Tape.h"
#include "Command.h"
#include "Helper.h"

class Imitator
{
	char errorMsg[200] = "������ � ������ ���������.�������� ���� ���������.\n�������:\t";
	string userInput;					// �������� ��� ������ ����� (��� ������ ������)
	bool statusExit;					// true - ����������

	Tape tape;							// ����� ���������
	Command command;					// �������
	Helper helper;						// ��������

	void execute();						// ����� ����������
	void editTape();					// �������������� �����
	void editCommand();					// �������������� ������
	void controlMode(const char*);		// ������������� �������

public:
	Imitator();							// ������ ���������
};

