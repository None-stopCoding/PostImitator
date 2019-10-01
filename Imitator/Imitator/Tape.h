#pragma once
using namespace std;

#include "Helper.h"

class Tape
{
	const int TAPE_SIZE = 100;			// длина ленты
	const int CARRET_START_POS = 10;	// изначальная позиция кретки

	int* tape;							//  бесконечная лента имитатора, \
											0 - нет метки, \
											1 - есть метка
	int carret;							// текущая позиция каретки
	Helper helper;						// помощник

public:
	Tape();								// создаем ленту
	~Tape();							// крашим ленту
	void show();						// вывести ленту в консоль
	void showEdit();					// вывести консоль в режиме редактирования
	void editTape(int);					// изменяем ленту по индексу
	void moveCarret(int);			// двигаем каретку
	bool isMarked(int);					// стоит ли метка

	int getCarret();					// получаем положение каретки
};

