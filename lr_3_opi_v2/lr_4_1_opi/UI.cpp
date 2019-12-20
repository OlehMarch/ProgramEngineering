#include "stdafx.h"
#include "UI.h"

	void UI::setCountStr(int cStr) {
		countStr = cStr;
	}

	int UI::getCountStr() {
		return countStr;
	}

	void UI::setCountClmn(int cClmn) {
		countClmn = cClmn;
	}

	int UI::getCountClmn() {
		return countClmn;
	}

	int UI::getLength() {
		/*������� ��� ���������� ������ ����� ��������� �������*/
		return length = countStr * countClmn;
	}

	bool UI::checkError(int cStr, int cClmn) {
		/*�������� �� ������������ ����� �������*/
		if ((cStr > 1) && (cStr < 21) && (cClmn > 1) && (cClmn < 21)) {
			return true;
		}
		return false;
	}

	void UI::insertionOfNods() {
		/*������ ���� ��������� �������*/
		cout << "\nInsert values to array:\n\n";
		for (unsigned int i = 0; i < countClmn; i++) {
			for (unsigned int j = 0; j < countStr; j++) {
				cout << "Array[" << i + 1 << "][" << j + 1 << "] = ";
				cin >> Array[i][j];
			}
		}
	}

	void UI::randInsertion() {
		/*��������� ���� ��������� �������*/
		for (unsigned int i = 0; i < countClmn; i++) {
			for (unsigned int j = 0; j < countStr; j++) {
				Array[i][j] = rand() % 100;
			}
		}
	}

	void UI::outputOfArray() {
		/*����� ������� � �������*/
		cout << "\n\nOutput of array:\n";
		for (unsigned int i = 0; i < countClmn; i++) {
			for (unsigned int j = 0; j < countStr; j++) {
				cout.width(3);
				cout << Array[i][j];
			}
			cout << "\n";
		}
	}

	UI::UI() {
		Array = NULL;
		countStr = NULL;
		countClmn = NULL;
	}
	
	UI::~UI() {
		delete Array;
	}

