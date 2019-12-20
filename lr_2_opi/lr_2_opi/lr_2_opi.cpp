// lr_2_opi.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "cmath"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
//-------------------------------------------------------------------------
struct HArray{
	int *Array;
	int countOfElements;
}HArray1, HArray2;
//-------------------------------------------------------------------------
struct TDArray{
	int **Array;
}TDArray1;
//-------------------------------------------------------------------------
bool checkError(int value) {
	/**** *** ** *P1* ** *** ****/
/*This function is performed to check values*/
	/*
	Input: value to check
	Output: true if value pass the required terms
	*/
	if ((value > 1) && (value < 21)) {
		return true;
	}
	return false;
}
//-------------------------------------------------------------------------
int* insertionOfArrayByFuncRand(int *Array, int countOfElements) {
	/**** *** * P2 * *** ****/
/********* Ввод массива случайным образом *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива заполенного случайными числами
	*/
	for (int i = 0; i < countOfElements; i++) {
		Array[i] = rand() % countOfElements;
	}
	return Array;
}
//-------------------------------------------------------------------------
int* insertionOfArrayBySelfInput(int *Array, int countOfElements) {
	/**** *** * P2 * *** ****/
/********* Ввод массива вручную *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива заполненного вручную
	*/
	for (int i = 0; i < countOfElements; i++) {
		cout<<"Insert value to Array["<<i+1<<"] = ";
		cin>>Array[i];
		if (Array[i] >= countOfElements){
			cout<<"inserted values must be less then count of elements in your array!\n";
			i -= 1;
			continue;
		}
	}
	return Array;
}
//-------------------------------------------------------------------------
bool insertionOfArrayByFileOpen(int *Array, int countOfElements) {
	/**** *** * P2 * *** ****/
/********* Ввод массива с файла *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива загруженного из файла 
		или о невозможности считывания данных из файла
	*/
	int m = 0;
	ifstream fin("file1.txt", ios_base::in);
	if (fin.is_open()) {
		for (int i = 0; i < countOfElements; i++) {
			if (fin) {
				fin>>Array[i];
				m = i;
			}
			else {
				Array[i] = rand() % countOfElements;
			}
		}
		Array[m] = rand() % countOfElements;
		fin.close();
		return true;
	}
    else {	
		cout<<"File can not be opened!\n";
		_getch();
		return false;
	}
}
//-------------------------------------------------------------------------
bool typeOfInsertion(int *Array, int countOfElements) {
	/**** *** ** *P1* ** *** ****/
/*This function created to choose type of insertion of array*/
	/*
	Input: array and his length
	Output: true if type of insertion was inserted right
	*/
	int choice = 0;
	while(true) {
		try {
			cout<<"\nWould you like to insert this array by function rand()\n (yes (press 1) / no (press any other key)): ";
			cin>>choice;
			fflush(stdin);
			cin.clear();
			if ((choice == 1) || (choice <= 0) || (choice > 1)) {
				break;
			}
			throw 1;
		}
		catch (...) {
			cout<<"\nValue that you're inserted are not correct!";
			cout<<"\nInset it again!\n\n";
			continue;
		}
        break;
	}
	if (choice == 1) {
		/*insertion of function by rand() function*/
		insertionOfArrayByFuncRand(Array, countOfElements);
		return true;
	}
	else {
		while(true) {
			try {
				cout<<"\nWould you like to insert this array by yourself\n (yes (press 1) / no (press any other key)): ";
				cin>>choice;
				fflush(stdin);
				cin.clear();
				if ((choice == 1) || (choice <= 0) || (choice > 1)) {
					break;
				}
				throw 1;
			}
			catch (...) {
				cout<<"\nValue that you're inserted are not correct!";
				cout<<"\nInset it again!\n\n";
				continue;
			}
			break;
		}
		if (choice == 1) {
			/*insertion of function by yourself*/
			cout<<endl;
			insertionOfArrayBySelfInput(Array, countOfElements);
			return true;
		}
		else {
			while(true) {
				try {
					cout<<"\nWould you like to insert this array from file\n (yes (press 1) / no (press any other key)): ";
					cin>>choice;
					fflush(stdin);
					cin.clear();
					if ((choice == 1) || (choice <= 0) || (choice > 1)) {
						break;
					}
					throw 1;
				}
				catch (...) {
					cout<<"\nValue that you're inserted are not correct!";
					cout<<"\nInset it again!\n\n";
					continue;
				}
				break;
			}
			if (choice == 1) {
				/*insertion of function from file*/
				cout<<"\nIf you want to change values, that will be inserted from file,\n open file with name \"file1.txt\", and change them!";
				cout<<"\n\nPress any key to continue...\n";
				_getch();
				insertionOfArrayByFileOpen(Array, countOfElements);
				return true;
			}
			else {
				cout<<"\nFailed to insert values to array, because of\n denying of all variaty of insertion!";
				return false;
			}
		}
	}
}
//-------------------------------------------------------------------------
void outputOfArray(int *Array, int countOfElements) {
	/**** *** * P1 * *** ****/
/********* Вывод матрицы *********/
	/*
	Вход: Массив и его размерность
	Выход: Вывод на консоль массива
	*/
	cout<<endl;
	for (int i = 0; i < countOfElements; i++) {
		cout.width(3);
		cout<<Array[i];
	}
}
//-------------------------------------------------------------------------
void outputOfRelatedPairs() {
	/**** *** * P1 * *** ****/
/********* Вывод попарно связаных элементов двух массивов *********/
	/*
	Вход: из структур
	Выход: в структуру и на экран
	*/
	int temp1 = 0, temp = 1;
	while (temp) {
		if (TDArray1.Array[0][temp1] != 1) {
			TDArray1.Array[0][temp1] = 1;
			temp = HArray1.Array[temp1];
			cout.width(3);
			cout<<HArray1.Array[temp1];
		}
		else {
			break;
		}
		if (TDArray1.Array[1][temp] != 1) {
			TDArray1.Array[1][temp] = 1;
			temp1 = HArray2.Array[temp];
			cout.width(3);
			cout<<HArray2.Array[temp];
		}
		else {
			break;
		}
		cout<<endl;
	}
}
//-------------------------------------------------------------------------
void outputOfNonRelatedItems() {
	/**** *** * P1 * *** ****/
/********* Вывод попарно не связаных элементов двух массивов *********/
	/*
	Вход: из структур
	Выход: на экран
	*/
	cout<<"\nOutput of non related elements in array 1:\n";
	for (int i = 0; i < HArray1.countOfElements; i++) {
		if (TDArray1.Array[0][i] != 1) {
			cout.width(3);
			cout<<HArray1.Array[i];
		}
	}
	cout<<"\n\nOutput of non related elements in array 2:\n";
	for (int i = 0; i < HArray2.countOfElements; i++) {
		if (TDArray1.Array[1][i] != 1) {
			cout.width(3);
			cout<<HArray2.Array[i];
		}
	}
}
//-------------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	/**** *** ** *P0* ** *** ****/
/**** * Ввод первого массива * ****/

	int temp = 0;
	
	while(true) {
		try {
			cout<<"Insert count of elements of array: ";
		    cin>>temp;
			fflush(stdin);
			cin.clear();
			if ((temp == 0) || !checkError(temp)) {
				throw 1;
			}
		}
		catch (...) {
			cout<<"\nValue that you're inserted are not correct!";
			cout<<"\nInset it again!\n\n";
			continue;
		}
        break;
	}
	HArray1.countOfElements = temp;

	HArray2.countOfElements = HArray1.countOfElements; //forget ";" and mixed up HArray1 with HArray2 (HArray1 = HArray2)
	HArray1.Array = new int[HArray1.countOfElements];
	HArray2.Array = new int[HArray2.countOfElements];

	/*type of insertion of array*/
	for (;;) {
		if (typeOfInsertion(HArray1.Array, HArray1.countOfElements)) {
			break;
		}
		else {
			cout<<"\nInset value again!\n\n";
			continue;
		}
	}

	cout<<"\nArray 1: ";
	outputOfArray(HArray1.Array, HArray1.countOfElements);
	cout<<"\n";

/**** * Конец вводa первого массива * ****/
/**** * Ввод второго массива * ****/

	for (;;) {
		if (typeOfInsertion(HArray2.Array, HArray2.countOfElements)) {
			break;
		}
		else {
			cout<<"\n\nInset value again!\n\n";
			continue;
		}
	}

	cout<<"\nArray 2: ";
	outputOfArray(HArray2.Array, HArray2.countOfElements);

/**** * Конец вводa второго массива * ****/

	TDArray1.Array = new int*[2];
	for (int i = 0; i < 2; i++) {
		TDArray1.Array[i] = new int[HArray1.countOfElements];
		for (int j = 0; j < HArray1.countOfElements; j++) {
			TDArray1.Array[i][j] = 0;
		}
	}
	cout<<"\n\nOutput pairs of related items:\n";
	outputOfRelatedPairs();
	cout<<endl<<"Output of connection between arrays:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < HArray1.countOfElements; j++) {
			cout.width(3);
			cout<<TDArray1.Array[i][j];
		}
		cout<<endl;
	}
	outputOfNonRelatedItems();

	cout<<"\n\nPress any key to continue...";
	_getch();
}// end of main