#include "Imitator.h"

Imitator::Imitator(): firstInput("")
{
	// TODO добавить title к консольке и поменять цвет самой консольки
	/*const char* consoleTitle = "Машина Поста";
	SetConsoleTitle(consoleTitle);*/

	// Увеличиваем буфер конcольки
	_COORD coordinates;
	coordinates.X = 500;
	coordinates.Y = 500;

	if (0 == SetConsoleScreenBufferSize(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coordinates
	)) {
		throw strcat(errorMsg, "Ошибка изменения буфера консоли");
	}

	//this->editComand();
	this->editTape();
}

void Imitator::controlMode(const char* mode)
{
	switch (_getch()) {
	case VK_ESCAPE:
		(mode == "edit tape") ? this->editComand() : this->editTape();
		break;
	case VK_CONTROL:
		(mode == "execute") ? this->editComand() : this->execute();
		break;
	case VK_TAB:
		getline(cin, firstInput);
	default:
		printf("Ввод запрещен!");
		getchar();

		if (mode == "edit tape") {
			this->editTape();
		}
		else if (mode == "edit comand") {
			this->editComand();
		}
		else {
			this->execute();
		}
	}
}

void Imitator::editTape()
{
	helper.infoMessage("редактирования ленты");
	try {
		tape.showEdit();
	}
	catch (const char* e) {
		throw strcat(errorMsg, e);
	}

	printf("\nИндекс ленты, где меняем значение(стрелками отмечены десятки)\n(если там стоит метка, то ее убираем, если ее там нет, то ставим):");
	this->controlMode("edit tape");
	
	if (firstInput.length()) {
		try {
			tape.editTape(tape.validate(firstInput));
			firstInput = "";
		}
		catch (const char* e) {
			printf("\n%s\n", e);
			getchar();
			Imitator::editTape();
		}
	}

	Imitator::editTape();
}

void Imitator::editComand()
{
	helper.infoMessage("редактирования команд");
	try {
		tape.show();
	}
	catch (const char* e) {
		throw strcat(errorMsg, e);
	}

	printf("\n:");
	this->controlMode("edit comand");
}

void Imitator::execute()
{
	helper.infoMessage("компиляции");
	getchar();
}