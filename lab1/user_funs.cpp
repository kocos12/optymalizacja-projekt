#include"user_funs.h"
#include <cmath>


matrix f1(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	y = -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * 3.14, 2)) + 0.002 * pow(0.1 * x(), 2);
	return y;
}

matrix df1(double t, matrix Y, matrix ud1, matrix ud2) {

	double a = 0.98;
	double b = 0.63;
	double g = 9.81;
	double Pa = 0.75;
	double Pb = 1;
	double Va_pocz = 5;
	double Vb_pocz = 1;
	double tempA_pocz = 90;
	double tempB_pocz = 10;
	double DB = 36.5665;

	matrix dY(3, 1);

	double Fin = 0.01;
	double FAout = a * b * m2d(ud2) * sqrt((2 * g * Y(0)) / Pa);
	double FBout = a * b * DB * sqrt(2 * g * Y(1) / Pb);

	dY(0) = -FAout;
	dY(1) = FAout + Fin - FBout;
	dY(2) = Fin / Y(1) * (10 - Y(2)) + FAout / Y(1) * (tempA_pocz - Y(2));

	return dY;

}

matrix fR(matrix x, matrix ud1, matrix ud2)
{
	matrix Yj;

	matrix Y0 = matrix(3, new double[3]{ 5, 1, 10 });

	matrix *Y = solve_ode(df1, 0, 1, 1000, Y0, ud1, x);

	double maks = -1000000;
	for (int i = 0; i < 3; i++){
		if (Y[i] > maks) {
			maks = m2d(Y[i]);
		}
	}
	double y = abs(maks - 50);
	return y;
}
