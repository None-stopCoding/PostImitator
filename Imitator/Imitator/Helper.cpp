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
	printf("\nПереключение режимов возможно только перед началом ввода!");
	printf("\n\tCtrl - режим редактирования/ выполнения");
	printf("\n\tEsc - режим редактирования ленты/ команд");
	printf("\nВы в режиме %s\n", mode);
}