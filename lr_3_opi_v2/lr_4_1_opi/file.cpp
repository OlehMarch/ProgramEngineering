#include "stdafx.h"
#include "file.h"

	void File::fileInsertionOfNods() {
		/*Файловый ввод матрицы*/
		int m = 0, n = 0;
		ifstream fin("file.in", ios_base::in);
		ifstream fin2("file.out", ios_base::in);
		if (fin2.is_open()) {
			for (unsigned int i = 0; i < countStr; i++) {
				for (unsigned int j = 0; j < countClmn; j++) {
					if (fin2) {
						fin2 >> Array[i][j];
						m = i;
						n = j;
					}
					else {
						Array[i][j] = rand() % 100;
					}
				}
			}
			Array[m][n] = rand() % 100;
			fin2.close();
		}
		else if (fin.is_open()) {
			for (unsigned int i = 0; i < countStr; i++) {
				for (unsigned int j = 0; j < countClmn; j++) {
					if (fin) {
						fin >> Array[i][j];
						m = i;
						n = j;
					}
					else {
						Array[i][j] = rand() % 100;
					}
				}
			}
			Array[m][n] = rand() % 100;
			fin.close();
		}
		else {	
			cout<<"File can not be opened!\n";
			_getch();
		}
		return;
	}

	void File::fileOutput() {
		/*Файловый вывод матрицы*/
		ofstream fout("file.out", ios_base::out);
		for (unsigned int i = 0; i < countClmn; i++) {
			for (unsigned int j = 0; j < countStr; j++) {
				if (fout) {
					fout << Array[i][j] << " ";
				}
			}
		}
	}