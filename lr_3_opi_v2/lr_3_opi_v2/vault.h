#pragma once
#include "targetver.h"
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <conio.h>
using namespace std;

class Vault {
protected:

	int **Array;
	unsigned int countStr;
	unsigned int countClmn;
	unsigned int length;

public:

	void creationOfArray();

	int isEqual();

};