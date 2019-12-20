// lr_1_opi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "cmath"
#include <conio.h>

using namespace std;
//-------------------------------------------------------------------------
struct Matrix{
	int countOfStrings;
	int countOfColumns;
	int **Array;
	float averageOrSimilarValue;
	int coordI;
	int coordJ;
} Matrix1, Matrix2, Matrix3;
//-------------------------------------------------------------------------
bool checkError(int first, int second) {
	/**** *** * P1 * *** ****/
/********* проверка на правильность создания матрицы *********/
	/*
	Вход: Размерность массива
	Выход: Истинны ли введенные данные или ложны
	*/
	if (((first > 1) && (first < 21)) || ((second > 1) && (second < 21))) {
		return true;
	}
	else {
		return false;
	}
}
//-------------------------------------------------------------------------
bool checkError(int elem1_1, int elem1_2, int elem2_1, int elem2_2) {
	/**** *** * P1 * *** ****/
/********* проверка на правильность создания матриц согласно условия их неравенства *********/
	/*
	Вход: Размерность массивов
	Выход: Одинаковы ли размерности двух массиво, если нет, то истина
	*/
	if ((elem1_1 == elem1_2) && (elem2_1 == elem2_2)) {
		return false;
	}
	else {
		return true;
	}
}
//-------------------------------------------------------------------------
int** insertionOfMatrixByFuncRand(int **Array, int countOfStr, int countOfClmn) {
	/**** *** * P2 * *** ****/
/********* Ввод матрицы случайным образом *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива заполенного случайными числами
	*/
	for (int i = 0; i < countOfClmn; i++) {
		for (int j = 0; j < countOfStr; j++) {
			Array[i][j] = rand() % 100;
		}
	}
	return Array;
}
//-------------------------------------------------------------------------
int** insertionOfMatrixBySelfInput(int **Array, int countOfStr, int countOfClmn) {
	/**** *** * P2 * *** ****/
/********* Ввод матрицы вручную *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива заполненного вручную
	*/
	for (int i = 0; i < countOfClmn; i++) {
		for (int j = 0; j < countOfStr; j++) {
			cout<<"Insert value to Array["<<i+1<<"]["<<j+1<<"] = ";
			cin>>Array[i][j];
		}
	}
	return Array;
}
//-------------------------------------------------------------------------
bool insertionOfMatrixByFileOpen(int **Array, int countOfStrings, int countOfColumns) {
	/**** *** * P2 * *** ****/
/********* Ввод матрицы с файла *********/
	/*
	Вход: Массив и его размерность
	Выход: Возврат массива загруженного из файла 
		или о невозможности считывания данных из файла
	*/
	int m = 0, n = 0;
	ifstream fin("file1.txt", ios_base::in);
	if (fin.is_open()) {
		for (int i = 0; i < countOfColumns; i++) {
			for (int j = 0; j < countOfStrings; j++) {
				if (fin) {
					fin>>Array[i][j];
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
		return true;
	}
    else {	
		cout<<"File can not be opened!\n";
		_getch();
		return false;
	}
}
//-------------------------------------------------------------------------
bool typeOfInsertion(int **Array, int countOfStrings, int countOfColumns) {
	/**** *** * P1 * *** ****/
/********* Выбор ввод матрицы *********/
	/*
	Вход: Массив и его размерность
	Выход: Истина, если введено верное число
	*/
	int temp = 0, choice = 0;
	cout<<"Types of input of information:\n";
	cout<<"	1. By function rand()\n";
	cout<<"	2. By self input\n";
	cout<<"	3. By loading from the file\n\n";
	cout<<"Insert your choice of input: ";
	cin>>choice;
	cout<<endl;
	switch(choice) {
		case 1:
			insertionOfMatrixByFuncRand(Array, countOfStrings, countOfColumns);
			return true;
		case 2:
			insertionOfMatrixBySelfInput(Array, countOfStrings, countOfColumns);
			cout<<endl;
			return true;
		case 3:
			cout<<"\nIf you want to change values, that will be inserted from file,\n open file with name \"file1.txt\", and change them!";
			cout<<"\n\nPress any key to continue...\n\n";
			_getch();
			insertionOfMatrixByFileOpen(Array, countOfStrings, countOfColumns);
			return true;
		default:
			cout<<"\nInserted value isn't correct!\n\n";
			return false;
	}
}
//-------------------------------------------------------------------------
void outputOfArray(int **Array, int countOfStr, int countOfClmn) {
	/**** *** * P1 * *** ****/
/********* Вывод матрицы *********/
	/*
	Вход: Массив и его размерность
	Выход: Вывод на консоль массива
	*/
	for (int i = 0; i < countOfClmn; i++) {
		for (int j = 0; j < countOfStr; j++) {
			cout.width(3);
			cout<<Array[i][j]<<" ";
		}
		cout<<endl;
	}
}
//-------------------------------------------------------------------------
void arithmeticAverage(int **Array, int countOfStr, int countOfClmn) {
	/**** *** * P1 * *** ****/
/********* Среднее арифметическое матрицы *********/
	/*
	Вход: Массив и его размерность
	Выход: Подсчет среднего арифметического массива
	*/
	int sum = 0;
	float average = 0.0;
	for (int i = 0; i < countOfClmn; i++) {
		for (int j = 0; j < countOfStr; j++) {
			sum += Array[i][j];
		}
	}
	average = (float)(sum) / (float)(countOfStr*countOfClmn);
	Matrix2.averageOrSimilarValue = average;
}
//-------------------------------------------------------------------------
void mostSimilar(int **Array, int countOfStr, int countOfClmn, float average) {
	/**** *** * P1 * *** ****/
/********* Нахождения наиболее близкого значения к среднему в матрице  *********/
	/*
	Вход: Массив, его размерность и среднее арифметическое
	Выход: Запись в структуру координат и самого максимально близкого числа к среднему арифметическому другой матрицы
	*/
	float temp1 = 0., temp2 = 0.;
	temp2 = (float)(abs(Array[0][0] - average));
	for (int i = 0; i < countOfClmn; i++) {
		for (int j = 0; j < countOfStr; j++) {
			temp1 = (float)(abs(average - Array[i][j]));
			if (temp1 <= temp2) {
				temp2 = temp1;
				Matrix1.averageOrSimilarValue = Array[i][j];
				Matrix1.coordI = i;
				Matrix1.coordJ = j;
			}
		}
	}
}
//-------------------------------------------------------------------------
bool copyingOfMatrix() {
	/**** *** * P2 * *** ****/
/********* Копирования согласно условию матрицы 2 в матрицу 1 *********/
	/*
	Вход: данные из структуры
	Выход:
		истина - копирование второй матрицы в первую
		ложь - определение места с которого будет выполнятся функция копирования большей матрицы чем первая
	*/
	if (((Matrix1.coordI + Matrix2.countOfColumns) <= Matrix1.countOfColumns) && ((Matrix1.coordJ + Matrix2.countOfStrings) <= Matrix1.countOfStrings)) {
		cout<<"Copying the matrix 2 into the matrix 1:\n\n";
		for (int i = 0; i < Matrix2.countOfColumns; i++) {
			for (int j = 0; j < Matrix2.countOfStrings; j++) {
				Matrix1.Array[Matrix1.coordI + i][Matrix1.coordJ + j] = Matrix2.Array[i][j];
			}
		}
		return true;
	}
	else {
		cout<<"Copying the matrix 2 into the matrix 1:\n\n";
		if ((Matrix1.coordI + Matrix2.countOfColumns) < Matrix1.countOfColumns) {
			Matrix3.countOfColumns = Matrix1.countOfColumns;
		}
		else {
			Matrix3.countOfColumns = Matrix1.coordI + Matrix2.countOfColumns;
		}
		if ((Matrix1.coordJ + Matrix2.countOfStrings) < Matrix1.countOfStrings) {
			Matrix3.countOfStrings = Matrix1.countOfStrings;
		}
		else {
			Matrix3.countOfStrings = Matrix1.coordJ + Matrix2.countOfStrings;
		}
		return false;
	}
}
//-------------------------------------------------------------------------
void copyingOfMatrixIfNewBigerThenPrevious() {
	/**** *** * P2 * *** ****/
/********* Создание третьей матрицы в случае переполнения первой *********/
	/*
	Вход: данные из структуры
	Выход: создание третей матрицы, заполнение первой матрицей и копирование второй в третью матрицу
	*/
	for (int i = 0; i < Matrix1.countOfColumns; i++) {
		for (int j = 0; j < Matrix1.countOfStrings; j++) {
			Matrix3.Array[i][j] = Matrix1.Array[i][j];
		}
	}
	for (int i = 0; i < Matrix2.countOfColumns; i++) {
		for (int j = 0; j < Matrix2.countOfStrings; j++) {
			Matrix3.Array[Matrix1.coordI + i][Matrix1.coordJ + j] = Matrix2.Array[i][j];
		}
	}
}
void typeOfCopying() {
	/**** *** * P1 * *** ****/
/********* Копирование матриц *********/
	/*
	Вход: данные из структуры
	Выход: Копирование:
		1. Либо вторая матрицы в первую;
		2. Либо создание третей, заполнение первой матрицей и копирование второй в третью матрицу
	Вывод матрицы в консоль
	*/

	if (copyingOfMatrix()) {
		outputOfArray(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns);
	}
	else {
		Matrix3.Array = new int*[Matrix3.countOfColumns];
		for (int i = 0; i < Matrix3.countOfColumns; i++) {
			Matrix3.Array[i] = new int[Matrix3.countOfStrings];
			for (int j = 0; j < Matrix3.countOfStrings; j++) {
				Matrix3.Array[i][j] = 0;
			}
		}
		copyingOfMatrixIfNewBigerThenPrevious();
		outputOfArray(Matrix3.Array, Matrix3.countOfStrings, Matrix3.countOfColumns);
	}
}
//-------------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	/**** *** * P0 * *** ****/
/********* Создание первой матрицы Р0.1 *********/
	for (;;) {
		/*Ввод размерности матрицы*/
		cout<<"Insert count of columns: ";
		cin>>Matrix1.countOfColumns;
		cout<<"Insert count of strings: ";
		cin>>Matrix1.countOfStrings;

		/*Проверка на правильность размерности матрицы*/
		if (!checkError(Matrix1.countOfColumns, Matrix1.countOfStrings)) {
			cout<<"\nInserted values must be more then 1 and less then 21\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*Выделение памяти для матрицы*/
		Matrix1.Array = new int*[Matrix1.countOfColumns];
		for (int i = 0; i < Matrix1.countOfColumns; i++) {
			Matrix1.Array[i] = new int[Matrix1.countOfStrings];
		}

		cout<<"\nMatrix 1:\n\n";

		/*Выбор типа ввода матрицы*/
		if (typeOfInsertion(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns)) {}
		else {
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*Вывод матрицы в консоль*/
		outputOfArray(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns);
		cout<<endl;
		break;
	}

/********* Конец создания первой матрицы *********/
/********* Создание второй матрицы Р0.2 *********/
	for (;;) {
		/*Ввод размерности матрицы*/
		cout<<"Insert count of columns: ";
		cin>>Matrix2.countOfColumns;
		cout<<"Insert count of strings: ";
		cin>>Matrix2.countOfStrings;

		/*Проверка на правильность размерности матрицы*/
		if (!checkError(Matrix2.countOfColumns, Matrix2.countOfStrings)) {
			cout<<"\nInserted values must be more then 1 and less then 21\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*Проверка на неодинаковость размерности матриц*/
		if (!checkError(Matrix1.countOfColumns, Matrix2.countOfColumns, Matrix1.countOfStrings, Matrix2.countOfStrings)) {
			cout<<"\nInserted values must be different\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*Выделение памяти для матрицы*/
		Matrix2.Array = new int*[Matrix2.countOfColumns];
		for (int i = 0; i < Matrix2.countOfColumns; i++) {
			Matrix2.Array[i] = new int[Matrix2.countOfStrings];
		}

		cout<<"\nMatrix 2:\n\n";

		/*Выбор типа ввода матрицы*/
		if (typeOfInsertion(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns)) {}
		else {
			cout<<"\nPress any key to continue...\n\n";
			_getch();
			continue;
		}

		/*Вывод второй матрицы, а так же среднего арифметичекского второй матрицы и наиболее близкого к нему значения из первой матрицы*/
		outputOfArray(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns);
		arithmeticAverage(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns);
		cout<<endl<<"Arithmetic average of the second matrix is: "<<Matrix2.averageOrSimilarValue<<endl<<endl;
		mostSimilar(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns, Matrix2.averageOrSimilarValue);
		cout<<"The most similar value in the first matrix is: "<<Matrix1.averageOrSimilarValue<<endl<<endl;
		break;
	}
/********* Конец создания второй матрицы *********/

/********* Копирование второй матрицы во вторую согласно условию Р0.3 *********/
	typeOfCopying();
	
	cout<<"\nPress any key to continue...";
	_getch();
} //конец