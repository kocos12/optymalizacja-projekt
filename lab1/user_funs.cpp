#include"user_funs.h"
#include <cmath>

matrix f1(matrix x, matrix ud1, matrix ud2) {
	double e = 2.718281828459;
	double pi = 3.141592;
	return -cos(0.1 * m2d(x)) * pow(e, -(0.1 * m2d(x) - 2 * pi * 0.1 * m2d(x) - 2 * pi)) + 0.002 * (0.1 * m2d(x)) * (0.1 * m2d(x));
}
