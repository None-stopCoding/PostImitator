#include <iostream>

#include "Helper.h"

Helper::Helper() {}

char* Helper::concatError(char* baseError, const char* addError)
{
	char error[1000];
	strcpy(error, addError);
	strcat(baseError, addError);
	return baseError;
}

void Helper::infoMessage(const char* mode)
{
	printf("\n������������ ������� �������� ������ ����� ������� �����!");
	printf("\n\tCtrl - ����� ��������������/ ����������");
	printf("\n\tEsc - ����� �������������� �����/ ������");
	printf("\n�� � ������ %s\n", mode);
}