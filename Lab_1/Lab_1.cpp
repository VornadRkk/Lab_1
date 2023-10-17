#include "matrix.h"
#include<iostream>
using namespace std;
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	/*Matrix<complex<double>> a(1, 3, complex<double>(1.0, 1.0));
	Matrix<complex<double>> b(1, 3, complex<double>(2.0, 2.0));
	Matrix<complex<double>> c(1, 3, complex<double>(3.0, 3.0));*/
	Matrix<float>a(1, 3, 1.2);
	Matrix<float>b(1, 3, 2.4);
	Matrix<float>c(1, 3, 3.5);
	bool coplanar = checking_for_coplanarity(a, b, c);
	cout << coplanar;



	return 0;
}