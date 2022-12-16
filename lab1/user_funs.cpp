#include"user_funs.h"
#include <cmath>
#include <algorithm>

#define M_PI 3.141592

using namespace std;

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
	//return pow((x(0) - 2), 2) + pow((x(1) - 3), 2);
	return (sin(pi * sqrt((x(0) / pi) * (x(0) / pi) + (x(1) / pi) * (x(1) / pi)))) / (pi * sqrt(pow(x(0) / pi, 2) + pow(x(1) / pi, 2)));
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


matrix g1(matrix x)
{
	return ( -1 * x(0) + 1);
}


matrix g2(matrix x) {
	return -1 * x(0) + 1;
}

matrix g3(matrix x, double a) {
	return sqrt(pow(x(0), 2) + pow(x(1), 2)) - a;
}

double zewS(matrix x)
{
	double suma = 0;
	double a = 5;

	if (0 < m2d(g1(x)))
	{
		suma += pow(m2d(g1(x)), 2);
	}

	if(0 < m2d(g2(x))){
		suma +=  pow(m2d(g2(x)), 2);
	}
	
	if (0 < m2d(g3(x,a)))
	{
		suma += pow(m2d(g3(x,a)), 2);
	}

	return suma;
}

double wewS(matrix x){
	double suma = 0;
	double a = 5;
	suma += 1 / m2d(g1(x));
	suma += 1 / m2d(g2(x));
	suma += 1 / m2d(g3(x,a));

	return (-1) * suma;
}

matrix df3(double t, matrix y, matrix ud1, matrix ud2)
{
	double c = 0.47;
	double r = 0.12;
	double m = 0.6;
	double ro = 1.2;
	double g = 9.81;

	double s = M_PI * r * r;
	double Dx = 0.5 * c * ro * s * abs(y(1)) * y(1);
	double Dy = 0.5 * c * ro * s * abs(y(3)) * y(3);
	double Fmx = 3.14 * ro * y(3) + m2d(ud2) * pow(r, 3);
	double Fmy = 3.14 * ro * y(1) + m2d(ud2) * pow(r, 3);

	matrix dY(4,1);

	dY(0) = y(1);
	dY(1) = (-1 * Dy - Fmx) / m;
	dY(2) = y(3);
	dY(3) = (-1 * m * g - Dy - Fmy) / m;

	return dY;
}

matrix fTa(matrix x, matrix ud1, matrix ud2)
{
	double arg = 3.14 + sqrt(pow(x(0) / M_PI, 2) + pow(x(1) / M_PI, 2));
	matrix y = sin(arg) / arg;

	if ((-1) * x(0) + 1 > 0)
		y = y + ud2 * pow((-1) * x(0) + 1, 2);

	if ((-1) * x(0) + 1 > 0)
		y = y + ud2 + pow((-1) * x(0) + 1, 2);

	if(norm(x) - ud1 > 0)
		y = y + ud2 * pow(norm(x) - ud1, 2);

	return y;
}

matrix fR3(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	matrix Y0(4, new double[4]{ 0, x(0),100,0 });
	matrx ud(2, new double[2]{ -2.,13.5 });
	matrix* Y = solve_ode(df3, 0, 0.01, 7, Y0, ud1, ud);
	int n = get_len(Y[0]);
	int i50 = 0;
	int i0 = 0;
	for (int i = 0; i < n; i++) {
		if (abs(Y[1](i, 2) - 50) < abs(Y[1](i50, 2) - 50)) i50 = i;
		if (abs(Y[1](i, 2)) < abs(Y[1](i0, 2))) i0 = i;
	}
	y = -Y[1](i0, 0);
	if (abs(x(0)) - 10 > 0) y = y + (ud2 * pow(abs(x(0)) - 10, 2));
	if (abs(x(1)) - 25 > 0) y = y + (ud2 * pow(abs(x(1)) - 25, 2));
	if (abs(Y[1](i50, 0) - 5) - 1 > 0) y = y + (ud2 * pow(abs(Y[1](i50, 0) - 5) - 1, 2));
	return y;
}


double obliczOdleglosc(double x, double y, double z) {
	return sqrt(pow(x - 0, 2) + pow(y - 0, 2) + pow(z - 0, 2));
}