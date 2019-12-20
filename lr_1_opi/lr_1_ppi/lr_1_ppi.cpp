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
/********* �������� �� ������������ �������� ������� *********/
	/*
	����: ����������� �������
	�����: ������� �� ��������� ������ ��� �����
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
/********* �������� �� ������������ �������� ������ �������� ������� �� ����������� *********/
	/*
	����: ����������� ��������
	�����: ��������� �� ����������� ���� �������, ���� ���, �� ������
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
/********* ���� ������� ��������� ������� *********/
	/*
	����: ������ � ��� �����������
	�����: ������� ������� ����������� ���������� �������
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
/********* ���� ������� ������� *********/
	/*
	����: ������ � ��� �����������
	�����: ������� ������� ������������ �������
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
/********* ���� ������� � ����� *********/
	/*
	����: ������ � ��� �����������
	�����: ������� ������� ������������ �� ����� 
		��� � ������������� ���������� ������ �� �����
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
/********* ����� ���� ������� *********/
	/*
	����: ������ � ��� �����������
	�����: ������, ���� ������� ������ �����
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
/********* ����� ������� *********/
	/*
	����: ������ � ��� �����������
	�����: ����� �� ������� �������
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
/********* ������� �������������� ������� *********/
	/*
	����: ������ � ��� �����������
	�����: ������� �������� ��������������� �������
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
/********* ���������� �������� �������� �������� � �������� � �������  *********/
	/*
	����: ������, ��� ����������� � ������� ��������������
	�����: ������ � ��������� ��������� � ������ ����������� �������� ����� � �������� ��������������� ������ �������
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
/********* ����������� �������� ������� ������� 2 � ������� 1 *********/
	/*
	����: ������ �� ���������
	�����:
		������ - ����������� ������ ������� � ������
		���� - ����������� ����� � �������� ����� ���������� ������� ����������� ������� ������� ��� ������
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
/********* �������� ������� ������� � ������ ������������ ������ *********/
	/*
	����: ������ �� ���������
	�����: �������� ������ �������, ���������� ������ �������� � ����������� ������ � ������ �������
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
/********* ����������� ������ *********/
	/*
	����: ������ �� ���������
	�����: �����������:
		1. ���� ������ ������� � ������;
		2. ���� �������� ������, ���������� ������ �������� � ����������� ������ � ������ �������
	����� ������� � �������
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
/********* �������� ������ ������� �0.1 *********/
	for (;;) {
		/*���� ����������� �������*/
		cout<<"Insert count of columns: ";
		cin>>Matrix1.countOfColumns;
		cout<<"Insert count of strings: ";
		cin>>Matrix1.countOfStrings;

		/*�������� �� ������������ ����������� �������*/
		if (!checkError(Matrix1.countOfColumns, Matrix1.countOfStrings)) {
			cout<<"\nInserted values must be more then 1 and less then 21\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*��������� ������ ��� �������*/
		Matrix1.Array = new int*[Matrix1.countOfColumns];
		for (int i = 0; i < Matrix1.countOfColumns; i++) {
			Matrix1.Array[i] = new int[Matrix1.countOfStrings];
		}

		cout<<"\nMatrix 1:\n\n";

		/*����� ���� ����� �������*/
		if (typeOfInsertion(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns)) {}
		else {
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*����� ������� � �������*/
		outputOfArray(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns);
		cout<<endl;
		break;
	}

/********* ����� �������� ������ ������� *********/
/********* �������� ������ ������� �0.2 *********/
	for (;;) {
		/*���� ����������� �������*/
		cout<<"Insert count of columns: ";
		cin>>Matrix2.countOfColumns;
		cout<<"Insert count of strings: ";
		cin>>Matrix2.countOfStrings;

		/*�������� �� ������������ ����������� �������*/
		if (!checkError(Matrix2.countOfColumns, Matrix2.countOfStrings)) {
			cout<<"\nInserted values must be more then 1 and less then 21\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*�������� �� �������������� ����������� ������*/
		if (!checkError(Matrix1.countOfColumns, Matrix2.countOfColumns, Matrix1.countOfStrings, Matrix2.countOfStrings)) {
			cout<<"\nInserted values must be different\n\n";
			cout<<"Press any key to continue...\n\n";
			_getch();
			continue;
		}

		/*��������� ������ ��� �������*/
		Matrix2.Array = new int*[Matrix2.countOfColumns];
		for (int i = 0; i < Matrix2.countOfColumns; i++) {
			Matrix2.Array[i] = new int[Matrix2.countOfStrings];
		}

		cout<<"\nMatrix 2:\n\n";

		/*����� ���� ����� �������*/
		if (typeOfInsertion(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns)) {}
		else {
			cout<<"\nPress any key to continue...\n\n";
			_getch();
			continue;
		}

		/*����� ������ �������, � ��� �� �������� ���������������� ������ ������� � �������� �������� � ���� �������� �� ������ �������*/
		outputOfArray(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns);
		arithmeticAverage(Matrix2.Array, Matrix2.countOfStrings, Matrix2.countOfColumns);
		cout<<endl<<"Arithmetic average of the second matrix is: "<<Matrix2.averageOrSimilarValue<<endl<<endl;
		mostSimilar(Matrix1.Array, Matrix1.countOfStrings, Matrix1.countOfColumns, Matrix2.averageOrSimilarValue);
		cout<<"The most similar value in the first matrix is: "<<Matrix1.averageOrSimilarValue<<endl<<endl;
		break;
	}
/********* ����� �������� ������ ������� *********/

/********* ����������� ������ ������� �� ������ �������� ������� �0.3 *********/
	typeOfCopying();
	
	cout<<"\nPress any key to continue...";
	_getch();
} //�����