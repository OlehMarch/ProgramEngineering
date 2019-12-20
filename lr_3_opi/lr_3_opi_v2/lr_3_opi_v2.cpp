// lr_3_opi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <conio.h>
#include "vault.h"
#include "file.h"
#include "UI.h"
#include "Processing.h"
using namespace std;
//----------------------------------------------
void typeOfInsertion(Processing *prc) {
	/*Выбор типа ввода матрицы*/
	int choice = 0;
	for (;;) {
		cout << "\nInsert type of insertion of the matrix:\n"
			<< "	1. By function rand;\n"
			<< "	2. By selfinput;\n"
			<< "	3. By loading data from file;\n"
			<< "\nYour choice: ";
		cin >> choice;
		cin.clear();
		fflush(stdin);
		switch(choice) {
			case 1: {
				prc->randInsertion();
				return;
			}
			case 2: {
				prc->insertionOfNods();
				return;
			}
			case 3: {
				prc->fileInsertionOfNods();
				return;
			}
			default: {
				cout << "\nInserted values aren't correct!\n";
				continue;
			}
		}
	}
}
//----------------------------------------------
void typeOfOutput(Processing *prc) {
	/*Выбор типа вывода матрицы*/
	int choice = 0;
	for (;;) {
		cout << "\nInsert output type of the matrix:\n"
			<< "	1. To console;\n"
			<< "	2. To file;\n"
			<< "\nYour choice: ";
		cin >> choice;
		cin.clear();
		fflush(stdin);
		switch(choice) {
			case 1: {
				prc->outputOfArray();
				return;
			}
			case 2: {
				prc->fileOutput();
				return;
			}
			default: {
				cout << "\nInserted values aren't correct!\n";
				continue;
			}
		}
	}
}
//----------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	Processing *prc = new Processing;
	unsigned int cStr, cClmn;

	for (;;) {
		cin.clear();
		fflush(stdin);
		cout << "Insert length and height of array: ";
		cin >> cStr >> cClmn;

		if (!prc->checkError(cStr, cClmn)) {
			cout << "\nInserted values aren't correct!\n\n";
			continue;
		}
		break;
	}

	prc->setCountStr(cStr);
	prc->setCountClmn(cClmn);
	prc->creationOfArray();
	typeOfInsertion(prc);
	typeOfOutput(prc);
	prc->taskFunc();
	typeOfOutput(prc);

	cout << "\nPress any key to continue...";
	_getch();
	return;
}   