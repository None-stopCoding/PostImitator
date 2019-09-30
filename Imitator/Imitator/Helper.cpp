#include "Helper.h"

Helper::Helper() {}

void Helper::infoMessage(const char* mode)
{
	system("cls");
	printf("\nПереключение режимов возможно только перед началом ввода!");
	printf("\n\tCtrl - режим редактирования/ выполнения");
	printf("\n\tEsc - режим редактирования ленты/ команд");
	printf("\n\tTab - нажимаем каждый раз перед вводом чего либо");
	printf("\nВы в режиме %s\n", mode);
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