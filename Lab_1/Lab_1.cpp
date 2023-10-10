#include "Lab_1.h"
#include<iostream>
using namespace std;
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	Matrix<int> a(5, 3, 5);
	Matrix<int> b(4, 5, 1);
	Matrix<int> c(4, 5, 1);
	auto result = a * b;
	cout << result;
}