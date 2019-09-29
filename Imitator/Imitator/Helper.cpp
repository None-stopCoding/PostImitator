#include "Helper.h"

Helper::Helper() {}

void Helper::infoMessage(const char* mode)
{
	printf("\n������������ ������� �������� ������ ����� ������� �����!");
	printf("\n\tCtrl - ����� ��������������/ ����������");
	printf("\n\tEsc - ����� �������������� �����/ ������");
	printf("\n\tShift - �������� ������ ��� ����� ������ ���� ����");
	printf("\n�� � ������ %s\n", mode);
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