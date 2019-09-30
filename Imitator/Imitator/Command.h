#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Command
{
	const size_t MAX_AMOUNT_COMMANDS = 1000;

	vector<string> commandsList;			// список комманд
	int listSize;					// кол-во комманд
public:
	Command();							// создаем хранитель команд
	void show(int carret = -1);			// выводим список команд
	void edit(int, string);				// редактировать команду
	void add(string);					// добавить команду
	string validate(string);			// валидируем команды

	int getAmountCommands();			//геттеры
};

