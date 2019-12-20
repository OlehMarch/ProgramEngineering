#pragma once
#include "targetver.h"
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <conio.h>
#include "vault.h"
using namespace std;

class UI: public Vault {
public:

	void setCountStr(int cStr);

	int getCountStr();

	void setCountClmn(int cClmn);

	int getCountClmn();

	int getLength();

	bool checkError(int cStr, int cClmn);

	void insertionOfNods();

	void randInsertion();

	void outputOfArray();

	UI();
	
	~UI();

};