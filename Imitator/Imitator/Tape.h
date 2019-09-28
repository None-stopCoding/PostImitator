#pragma once
class Tape
{
	const int TAPE_SIZE = 200;			// длина ленты
	const int CARRET_START_POS = 10;	// изначальная позиция кретки

	int* tape;							//  бесконечная лента имитатора, \
											0 - нет метки, \
											1 - есть метка
	int carret;							// текущая позиция каретки
public:
	Tape();
	void show();

};

