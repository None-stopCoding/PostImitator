#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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
char* Helper::generateStringForEditTapeMode(int size, const char* str = "")
{
	if (size) {
		if (strlen(str)) {
			char line[1000];

			char probel[10] = "         ";
			char* tab = strcat(probel, str);
			for (int jump = 0; jump < size; jump += 10) {
				line += strcat(line, tab);
			}
		}
		else {

		}
	}

	return 0;
}