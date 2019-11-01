#include "Helper.h"

Helper::Helper() {}

void Helper::infoMessage(const char* mode)
{
	system("cls");
	printf("Переключение режимов возможно только перед началом ввода!");
	printf("\n\tEnter  - компилировать");
	printf("\n\tПробел - режим редактирования");
	printf("\n\t\t1 - редактирование команд");
	printf("\n\t\t2 - редактирование ленты");
	printf("\n\t\t3 - редактирование каретки");
	printf("\n\tTab    - режим ввода данных (перед тем, как ввести данные, нажмите Tab)\n\t\t\t(необходим только при возможности переключения режимов)");
	printf("\n\tEsc    - выход");
	printf("\n\nВы в режиме %s\n", mode);
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
		throw "Не является числом";
	}
}