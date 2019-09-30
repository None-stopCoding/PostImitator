#include "Command.h"

Command::Command(): listSize(0) {}

void Command::show(int carret)
{
	if (-1 <= carret && carret <= listSize) {
		printf("\n");
		for (int index = 0; index < listSize; index++) {
			printf("%s%d. %s\n", ((carret != -1 && carret == index) ? "  ->\t" : "\t"), index, commandsList[index].c_str());
		}
	}
	else {
		throw "¬ыход за кол-во команд при отображении каретки команд";
	}
}

void Command::edit(int index, string command)
{
	commandsList[index] = command;
}

void Command::add(string command)
{	
	commandsList.push_back(command);
	listSize = commandsList.size();
}

string Command::validate(string input)
{
	if (input.find_first_not_of("<>!?;0123456789VX") == std::string::npos) {
		input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
		return input;
	}
	else {
		throw "Ќеверный синтаксис";
	}
}

int Command::getAmountCommands()
{
	return listSize;
}

string Command::getCurrent(int index)
{
	if (0 <= index && index < listSize) {
		return commandsList[index];
	}
	else {
		throw "ќбращение к несуществующей команде";
	}
}