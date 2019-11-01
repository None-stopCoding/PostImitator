#include "Helper.h"

Helper::Helper() {}

void Helper::infoMessage(const char* mode)
{
	system("cls");
	printf("������������ ������� �������� ������ ����� ������� �����!");
	printf("\n\tEnter  - �������������");
	printf("\n\t������ - ����� ��������������");
	printf("\n\t\t1 - �������������� ������");
	printf("\n\t\t2 - �������������� �����");
	printf("\n\t\t3 - �������������� �������");
	printf("\n\tTab    - ����� ����� ������ (����� ���, ��� ������ ������, ������� Tab)\n\t\t\t(��������� ������ ��� ����������� ������������ �������)");
	printf("\n\tEsc    - �����");
	printf("\n\n�� � ������ %s\n", mode);
}
string Helper::generateStringForEditTapeMode(int size, string str)
{
	string  line = "",
			space = "         ";

	if (str.length()) {
		for (int jump = 0; jump < size; jump += 10) {
			line += space + str;
		}
	}

	return line + "\n";
}

int Helper::validateNumber(string &input)
{
	if (input.find_first_not_of("0123456789") == std::string::npos) {
		return atoi(input.c_str());
	}
	else {
		throw "�� �������� ������";
	}
}