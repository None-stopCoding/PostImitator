#pragma once
class Tape
{
	const int TAPE_SIZE = 100;			// ����� �����
	const int CARRET_START_POS = 10;	// ����������� ������� ������

	int* tape;							//  ����������� ����� ���������, \
											0 - ��� �����, \
											1 - ���� �����
	int carret;							// ������� ������� �������
public:
	Tape();								// ������� �����
	void show();						// ������� ����� � �������
	void showEdit();					// ������� ������� � ������ ��������������
	void editTape(int);					// �������� ����� �� �������
	int validate(char* );				// ��������� ������
};

