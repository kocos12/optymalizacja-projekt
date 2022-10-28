#include"user_funs.h"
#include <cmath>

matrix f1(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	y = -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * 3.14, 2)) + 0.002 * pow(0.1 * x(), 2);
	return y;
}

matrix fR(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	matrix y0 = matrix(3, new double[3]{ 5, 1, 10 });
	matrix* y = solve_ode(df1, 0, 1, 1000, y0, ud1, x);

	double maks = -1000000;
	for (int i = 0; i < 3; i++){
		if (y[i] > maks) {
			maks = m2d(y[i]);
		}
	}
	double y = abs(maks - 50);
	return y;
}
matrix df1(double t, matrix Y, matrix ud1, matrix ud2) {
	double a, b, o; //???
	double Pa = 0.75;
	double Pb = 1;
	double Va_pocz = 5;
	double Vb_pocz = 1;
	double tempA_pocz = 90;
	double _Temporary_buffer_size)

	matrix dY(3, 1);
}
