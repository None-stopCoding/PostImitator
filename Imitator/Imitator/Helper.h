#pragma once
class Helper
{
public:
	Helper();
	void infoMessage(const char*);												// информационное сообщение про режимы
	char* generateStringForEditTapeMode(int size = 0, const char* str = "");	// генерация строки для подсказки
};

