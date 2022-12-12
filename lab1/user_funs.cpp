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
	double pi = 3.141592;
	return (x(0) * x(0)) + (x(1) * x(1)) - cos(2.5 * pi * x(0)) - cos(2.5 * pi * x(1)) + 2;
}

matrix fR_lab2(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	matrix Y0(2, 1), Y_ref(2, new double[2]{ 3.14,0 });
	matrix* Y = solve_ode(df_lab2, 0, 0.1, 100, Y0, Y_ref, x); 
	int n = get_len(Y[0]);
	cout << "n = " << n << endl;
	y = 0;
	double t = 0.0;
	for (int i = 0; i < n; i++) {
		y = y + 10 * pow(Y_ref(0) - Y[1](i, 0), 2) + pow(Y_ref(1) - Y[1](i, 1), 2) + pow(x(0) * (Y_ref(0) - Y[1](i, 0)) + x(1) * (Y_ref(1) - Y[1](i, 1)), 2);
		y = y * 0.1;
		cout << t << "\t"<<Y[1](i, 0)<< "\t" <<  Y[1](i, 1) << endl;
		t += 0.1;
	}
	return y;
}

matrix df_lab2(double t, matrix Y, matrix ud1, matrix ud2) {
	double mr = 1, l = 0.5, mc = 9, b = 0.5;
	double I = ((mr * l * l) / 3) + (mc * l * l);
	matrix dY(2, 1);
	dY(0) = Y(1);
	dY(1) = (ud2(0) * (ud1(0) - Y(0)) + ud2(1) * (ud1(1) - Y(1)) - b * Y(1)) / I;
	return dY;
}

matrix f3(matrix x, matrix ud1, matrix ud2)
{
	double pi = 3.141592;
	return pow((x(0) - 2), 2) + pow((x(1) - 3), 2);
	//return (sin(pi * sqrt((x(0) / pi) * (x(0) / pi) + (x(1) / pi) * (x(1) / pi)))) / (pi * sqrt(pow(x(0) / pi, 2) + pow(x(1) / pi, 2)));
}

matrix f4(matrix x, matrix ud1, matrix ud2)
{
	return pow((x(0) + 2 * x(1) - 7), 2) + pow((2 * x(0) + x(1) - 5), 2);
}

matrix gf1(matrix x, matrix ud1, matrix ud2) {
	matrix g(2, 1);
	g(0) = 10 * x(0) + 8 * x(1) - 34;
	g(1) = 8 * x(0) + 10 * x(1) - 38;
	return g;
}