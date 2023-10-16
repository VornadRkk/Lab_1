#include "matrix.h"
#include<iostream>
using namespace std;
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	Matrix<int> a(3, 3, 5);
	Matrix<int> b(3, 3, 1);
	b = a;
	cout << b;
	return 0;
}