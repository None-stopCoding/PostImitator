#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <map>
using namespace std;


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

