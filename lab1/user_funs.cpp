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
	double FAout, FBout;
	if (Y(0) > 0) FAout = a * b * m2d(ud2) * sqrt((2 * g * Y(0)) / Pa);
	else FAout = 0;
	
	if (Y(1) > 1) {
		 FBout = a * b * DB * sqrt(2 * g * Y(1) / Pb);
	}
	else
	{
		 FBout = 0;
	}
	

	dY(0) = -FAout;
	dY(1) = FAout + Fin - FBout;
	dY(2) = Fin / Y(1) * (tempB_pocz - Y(2)) + FAout / Y(1) * (tempA_pocz - Y(2));

	return dY;

}

matrix fR(matrix x, matrix ud1, matrix ud2)
{

	matrix Y0 = matrix(3, new double[3]{ 5, 1, 10 });
	
	matrix *Y = solve_ode(df1, 0, 1, 1000, Y0, ud1, x);

	double y;
	double maks = Y[1](0,2);
	for (int i = 0; i < get_len(Y[0]); i++){
		if (Y[1](i,2) > maks) {
			maks = Y[1](i,2);
		}

		y = abs(maks - 50);
		
		if (ud2 == 10) cout << i << "\t" << Y[1](i,0) << "\t" << Y[1](i,1) << "\t" << Y[1](i,2) << endl;
	}

	//cout << y << endl;
	return y;
}

matrix f2(matrix x, matrix ud1, matrix ud2) {	
	double pi = 3.1415;
	matrix wynik(0);
	wynik = (x[0] * x[0]) + (x[1] * x[1]) - cos(2.5 * pi * m2d(x[0])) - cos(2.5 * pi * m2d(x[1])) + 2;
	return wynik;
}