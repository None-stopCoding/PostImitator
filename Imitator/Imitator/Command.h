#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Command
{
	const size_t MAX_AMOUNT_COMMANDS = 1000;

	vector<string> commandsList;			// ������ �������
	int listSize;					// ���-�� �������
public:
	Command();							// ������� ��������� ������
	void show(int carret = -1);			// ������� ������ ������
	void edit(int, string);				// ������������� �������
	void add(string);					// �������� �������
	string validate(string);			// ���������� �������

	int getAmountCommands();			//�������
};

