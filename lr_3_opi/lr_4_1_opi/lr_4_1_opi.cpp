// lr_4_1_opi.cpp : Defines the entry point for the console application.
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
	char choice;
	for (;;) {
		cout << "\nWould you like to insert this array by function rand() (y/n): ";
		cin >> choice;
		cin.clear();
		fflush(stdin);
		if (choice == 'y') {
			prc->randInsertion();
			return;
		}
		else if (choice == 'n') {
			cout << "\nWould you like to insert this array by selfinput (y/n): ";
			cin >> choice;
			cin.clear();
			fflush(stdin);
			if (choice == 'y') {
				prc->insertionOfNods();
				return;
			}
			else if (choice == 'n') {
				cout << "\nWould you like to insert this array from file (y/n): ";
				cin >> choice;
				cin.clear();
				fflush(stdin);
				if (choice == 'y') {
					prc->fileInsertionOfNods();
					return;
				}
				else if (choice == 'n') {
					cout<<"\nFailed to insert values to array, because of\n denying of all variaty of insertion!\n";
				}
				else {
					cout << "\nInserted value aren't correct!\n";
					continue;
				}
			}
			else {
				cout << "\nInserted value aren't correct!\n";
				continue;
			}
		}
		else {
			cout << "\nInserted value aren't correct!\n";
			continue;
		}
	}
}
//----------------------------------------------
void typeOfOutput(Processing *prc) {
	/*Выбор типа вывода матрицы*/
	char choice;
	for (;;) {
		cout << "\nWould you like to output this array to console (y/n): ";
		cin >> choice;
		cin.clear();
		fflush(stdin);
		if (choice == 'y') {
			prc->outputOfArray();
			return;
		}
		else if (choice == 'n') {
			cout << "\nWould you like to output this array to file (y/n): ";
			cin >> choice;
			cin.clear();
			fflush(stdin);
			if (choice == 'y') {
				prc->fileOutput();
				return;
			}
			else if (choice == 'n') {
				cout<<"\nFailed to insert values to array, because of\n denying of all variaty of insertion!\n";
			}
			else {
				cout << "\nInserted value aren't correct!\n";
				continue;
			}
		}
		else {
			cout << "\nInserted value aren't correct!\n";
			continue;
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