#include "Imitator.h"

Imitator::Imitator(): userInput(""), statusExit(false)
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
		statusExit = true;
		printf("\n\nЗавершение программы имитатора...");
		getchar();
		break;
	case VK_SPACE:
		(mode == "edit tape") ? this->editCommand() : this->editTape();
		break;
	case VK_RETURN:
		this->execute();
		break;
	case VK_TAB:
		getline(cin, userInput);
		return;
	default:
		printf("Ввод запрещен!");
		getchar();

		if (mode == "edit tape") {
			this->editTape();
		}
		else {
			this->editCommand();
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
	
	if (userInput.length()) {
		try {
			tape.editTape(helper.validateNumber(userInput));
			userInput = "";
		}
		catch (const char* e) {
			printf("\n%s\n", e);
			getchar();
			Imitator::editTape();
		}
	}

	if (!statusExit) {
		Imitator::editTape();
	}
}

void Imitator::editCarret()
{

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

	printf("\nИндекс команды для редактирования (для добавления - индекс следующей после последней): ");
	this->controlMode("edit command");

	if (userInput.length()) {
		try {
			int indexEdit = helper.validateNumber(userInput);
			string input;
			userInput = "";

			if (indexEdit <= command.getAmountCommands() - 1) {
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

	if (!statusExit) {
		Imitator::editCommand();
	}
}

void Imitator::execute()
{
	helper.infoMessage("компиляции");
	int currentCommand = 0;
	bool success = true;
	int commandsAmount = command.getAmountCommands();
	while (true) {
		string textCommand = "Еще до начала :)", nextCommand = "Еще до начала :)";

		helper.infoMessage("компиляции");
		try {
			tape.show();
			command.show(currentCommand);

			try {
				textCommand = command.getCurrent(currentCommand);
				char operation = textCommand.at(0);
				nextCommand = textCommand.substr(1, textCommand.length() - 1);

				if (operation == '>') {
					tape.moveCarret(tape.getCarret() + 1);
				}
				else if (operation == '<') {
					tape.moveCarret(tape.getCarret() - 1);
				}
				else if (operation == 'V') {
					if (tape.isMarked(tape.getCarret())) {
						printf("\nПопытка поставить метку туда, где она уже есть\n");
						throw 0;
					}

					tape.editTape(tape.getCarret());
				}
				else if (operation == 'X') {
					if (!tape.isMarked(tape.getCarret())) {
						printf("\nПопытка убрать метку, оттуда, где ее нет\n");
						throw 0;
					}

					tape.editTape(tape.getCarret());
				}
				else if (operation == '?') {
					size_t delimiter = textCommand.find(";");
					if (delimiter != string::npos) {
						if (tape.isMarked(tape.getCarret())) {
							nextCommand = textCommand.substr(delimiter + 1, textCommand.length() - delimiter - 1);
						}
						else {
							nextCommand = textCommand.substr(1, delimiter - 1);
						}
					}
					else {
						throw 0;
					}
				}
				else if (operation == '!') {
					break;
				}
				else {
					throw 0;
				}
			}
			catch (const char* e) {
				printf("\nОшибка: %s\n", e);
				throw 0;
			}
			

			Sleep(1000);
			try {
				currentCommand = helper.validateNumber(nextCommand);
			}
			catch (const char* e) {
				printf("%s - %s\n", nextCommand.c_str(), e);
				throw 0;
			}
			
		}
		catch (const char* e) {
			throw strcat(errorMsg, e);
		}
		catch (int e) {
			success = false;
			printf("\nКомпиляция прервана на команде - %d. %s\n", currentCommand, textCommand.c_str());
			getchar();
			break;
		}
	}
	
	if (success) {
		printf("\nПрограма успешно завершилась\n");
		getchar();
	}

	Imitator::editCommand();
}