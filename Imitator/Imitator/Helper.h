#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Helper
{
public:
	Helper();
	void infoMessage(const char*);												// �������������� ��������� ��� ������
	string generateStringForEditTapeMode(int size, string str = "");	// ��������� ������ ��� ���������
};

