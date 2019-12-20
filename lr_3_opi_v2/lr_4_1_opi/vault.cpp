#include "stdafx.h"
#include "vault.h"

	void Vault::creationOfArray() {
		/*функция выдиления памяти для массива*/
		Array = new int*[countClmn];
		for (unsigned int i = 0; i < countClmn; i++) {
			Array[i] = new int[countClmn];
		}
	}

	int Vault::isEqual() {
		/*Проверка на эквивалентность количества строк и столбцов массива*/
		if (countStr == countClmn) return 0;
		else if ((countStr > countClmn) || (countStr < countClmn)) return 1;
		return 2;
	}