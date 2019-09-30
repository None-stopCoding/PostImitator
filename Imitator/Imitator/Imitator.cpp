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

	this->editCommand();
}

void Imitator::controlMode(const char* mode)
{
	switch (_getch()) {
	case VK_ESCAPE:
		(mode == "edit tape") ? this->editCommand() : this->editTape();
		break;
	case VK_CONTROL:
		(mode == "execute") ? this->editCommand() : this->execute();
		break;
	case VK_TAB:
		getline(cin, firstInput);
		return;
	default:
		printf("Ввод запрещен!");
		getchar();

		if (mode == "edit tape") {
			this->editTape();
		}
		else if (mode == "edit command") {
			this->editCommand();
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
			tape.editTape(helper.validateNumber(firstInput));
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

void Imitator::editCommand()
{
	helper.infoMessage("редактирования команд");
	try {
		tape.show();
		command.show();
	}
	catch (const char* e) {
		throw strcat(errorMsg, e);
	}

	printf("\nИндекс команды для редактирования (для добавления - индекс следующей после последней):");
	this->controlMode("edit command");

	if (firstInput.length()) {
		try {
			int indexEdit = helper.validateNumber(firstInput);
			string input;
			firstInput = "";

			if (indexEdit <= command.getAmountCommands()) {
				printf("\nРедактирование %d комманды: ", indexEdit);

				if (getline(cin, input)) {
					command.edit(indexEdit, command.validate(input));
				}
			}
			else {
				printf("\nДобавление команды: ");

				if (getline(cin, input)) {
					command.add(command.validate(input));
				}
			}
		}
		catch (const char* e) {
			printf("\n%s\n", e);
			getchar();
			Imitator::editCommand();
		}
	}

	Imitator::editCommand();
}

void Imitator::execute()
{
	helper.infoMessage("компиляции");
	try {
		tape.show();
		command.show(0);
	}
	catch (const char* e) {
		throw strcat(errorMsg, e);
	}
	
}