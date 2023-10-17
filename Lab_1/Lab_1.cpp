#include "matrix.h"
#include<iostream>
using namespace std;
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	Matrix<complex<double>> a(1, 3, complex<double>(1.0, 1.0));
	Matrix<complex<double>> b(1, 3, complex<double>(2.0, 2.0));
	Matrix<complex<double>> c(1, 3, complex<double>(3.0, 3.0));
	/*Matrix<int> a(1, 3, 1);
	Matrix<int> b(1, 3, 2);
	Matrix<int> c(1, 3, 3);*/
	bool coplanar = checking_for_coplanarity(a, b, c);
	cout << coplanar;
	return 0;
}