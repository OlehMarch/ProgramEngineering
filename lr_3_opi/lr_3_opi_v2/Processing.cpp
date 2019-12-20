#include "stdafx.h"
#include "Processing.h"

	void Processing::taskFunc() {
		/*Функция обработки массива согласно задания (строки поменять со столбцами)*/
		cout << endl;
		if (isEqual() == NULL) {
			for (unsigned int i = 0; i < countStr; i++) {
				for (unsigned int j = i; j < countClmn; j++) {
					swap(Array[i][j], Array[j][i]);
				}
			}
		}
		else if (isEqual() == 1) {
			fileOutput();
			ifstream fin("file.out", ios_base::in);
			if (fin) {
				swap(countStr, countClmn);
				creationOfArray();
			}
			for (unsigned int j = 0; j < countStr; j++) {
				for (unsigned int i = 0; i < countClmn; i++) {
					fin >> Array[i][j];
				}
			}
		}
	}