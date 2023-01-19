#include"user_funs.h"
#include <cmath>
#include <algorithm>
#include <fstream>

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
	double a = 4;

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
	std::cout << t << "\t" << y(0) << "\t" << y(2) << std::endl;
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
	matrix* Y = solve_ode(df3, 0, 0.01, 7, Y0, ud1, x(1));	//solve_ode(ff, t0, dt, tend, Y0 ,ud1, ud2 )
	//cout << *Y << endl;
	//std::cout << "\t" << (*Y)(0) << "\t" << (*Y)(2) << std::endl;
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


	//std::cout << y(0) << std::endl;

	return y;
}

double obliczOdleglosc(double x, double y, double z) {
	return sqrt(pow(x - 0, 2) + pow(y - 0, 2) + pow(z - 0, 2));
}

matrix f4(matrix x, matrix ud1, matrix ud2) // ud2 to P
{
	matrix y;
	if (isnan(ud2(0, 0))) {
		y = pow(x(0) + 2 * x(1) - 7, 2) + pow(2 * x(0) + x(1) - 5, 2);
	}
	else
		y = f4(ud2[0] + x * ud2[1], ud1); 
	return y;
}

matrix gf1(matrix x, matrix ud1, matrix ud2) {
	matrix g(2, 1);
	g(0) = 10 * x(0) + 8 * x(1) - 34;
	g(1) = 8 * x(0) + 10 * x(1) - 38;
	return g;
}

matrix Hf(matrix x, matrix ud1, matrix ud2) {
	matrix H(2, 2); //hesjan
	H(0, 0) = 10;
	H(0, 1) = 8;
	H(1, 0) = 8;
	H(1, 1) = 10;
	return H;
}

matrix fR4(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	int m = 100;
	int n = get_len(x);
	cout << "wartosc n w FR : " << n << endl;
	static matrix X(n, m), Y(1, m);
	ifstream inputX("XData.txt");
	ifstream inputY("YData.txt");
	for (int i = 0; i < m; i++) {
		inputX >> X(0, i);
		inputY >> Y(0, i);
	}
	for (int i = 0; i < m; i++) {
		inputX >> X(1, i);
	}
	for (int i = 0; i < m; i++) {
		inputX >> X(2, i);
	}
	double h;
	y = 0;
	double P = 0;

	for(int i =0;i<m;i++){
		std::cout << "iteracja nr. " << i << " w FR" << std::endl;
		if(i==99) {
			std::cout << "break tutaj\n";
		}
		h = m2d(trans(x) * X[i]);
		h = 1. / (1. + exp(-h));
		y = y - (Y(0, i) * log(h)) - ((1 - Y(0, i)) * log(1 - h));
		if (Y(0, i) == h) P++;
	}
	matrix m_matrix(100.);
	P = P / 100.;
	y = y / m_matrix;
	matrix P_matrix(P);
	y.add_row(P_matrix);

	return y;

}

matrix gfR1(matrix x, matrix ud1, matrix ud2) {
	int n = get_len(x);
	cout << "wartosc n w grad FR : " << n << endl;
	matrix y;
	int m = 100;
	static matrix X(n, m), Y(1, m);
	ifstream inputX("XData.txt");
	ifstream inputY("YData.txt");
	for (int i = 0; i < m; i++) {
		inputX >> X(0, i);
		inputY >> Y(0, i);
	}
	for (int i = 0; i < m; i++) {
		inputX >> X(1, i);
	}
	for (int i = 0; i < m; i++) {
		inputX >> X(2, i);
	}
	double h;
	y = 0;
	matrix g(n, 1);
	for(int i = 0; i < m; i++){
		h = m2d(trans(x) * X[i]);
		h = 1. / (1. + exp(-h));
		g(0) = log(h) - (1 - Y(0, i)) * x(0);
		g(1) = log(h) - (1 - Y(0, i)) * x(1);
		g(2) = log(h) - (1 - Y(0, i)) * x(2);
	}
	matrix m_matrix(100.);
	g = g / m_matrix;
	return g;
}


matrix f51(double a, matrix x, matrix ud1, matrix ud2){
	return (a * (pow(x(0) - 2., 2) + (pow(x(1) - 2., 2))));
}
matrix f52(double a, matrix x, matrix ud1, matrix ud2){
	return ((1. / a) * (pow(x(0) + 2., 2) + (pow(x(1) + 2., 2))));
}

matrix f5(matrix x, matrix ud1, matrix ud2){
	if (isnan(ud2(0, 0))) {
		matrix y;
		y = matrix(2, new double[2] {0., 0.});
		y(0) = ud1(1) * (pow(x(0) - 2., 2) + (pow(x(1) - 2., 2))); 
		y(1) = (1. / ud1(1)) * (pow(x(0) + 2., 2) + (pow(x(1) + 2., 2)));
		return y;
	}
	else {
		return ud1(0) * f51(ud1(1), ud2[0]+x*ud2[1], ud1) + (1. - ud1(0)) * f52(ud1(1), ud2[0] + x * ud2[1], ud1);
	}
}


matrix ff5R(matrix x, matrix ud1, matrix ud2){
	matrix y;
	if(isnan(ud2(0, 0)))
	{
		y = matrix(3, 1);
		double ro = 7800.;
		double P = 1e3;
		double E = 207e9;
		//masa belki:
		y(0) = ro * x(0) * 3.14 * pow(x(1), 2) / 4.;
		
		//ugiecie belki
		y(1) = 64 * P * pow(x(0), 3) / (3 * E * 3.14 * pow(x(1), 4));
		
		//naprezenie w belce
		y(2) = 32 * P * x(0) / (3.14 * pow(x(1), 3));
	}
	else
	{
		matrix yt;
		matrix xt = ud2[0] + x * ud2[1];
		yt = ff5R(xt, ud1, NAN);
		y = ud1 * (yt(0) - 0.06) / (1.53 - 0.06) + (1 - ud1) * (yt(1) - 5.25e-6) / (0.0032 - 5.25e-6);

		double c = 1e10;
		if (xt(0) < 0.1) y = y + c * (pow(0.1 - xt(0), 2));
		if (xt(0) > 1) y = y + c * (pow(xt(0) - 1, 2));
        if (xt(1) < 0.01) y = y + c * (pow(0.01 - xt(1), 2));
		if (xt(1) > 0.05) y = y + c * (pow(xt(1) - 0.05, 2));
		if (yt(1) > 0.005) y = y + c * (pow(yt(1) - 0.005, 2));
		if (yt(2) > 300e6) y = y + c * (pow(yt(2) - 300e6, 2));
	}
	return y;
}

matrix f6(matrix x, matrix ud1, matrix ud2) {	
	double pi = 3.141592;
	return pow(x(0),2) + pow(x(1),2) - cos(2.5*pi*x(0)) - cos(2.5*pi*x(1)) + 2;
}

matrix df6(double t, matrix Y, matrix ud1, matrix ud2) {
	double m1 = 5., m2 = 5., k1 = 1., k2 = 1., F = 1., b1, b2; //wartosc kiedys sie da jak bedzie potrzebna
	b1 = ud2(0);
	b2 = ud2(1);
	matrix dY(4, 1);
	dY(0) = Y(1);
	dY(1) = (-b1 * Y(1) - b2 * (Y(1) - Y(3)) - k1 * Y(0) - k2 * (Y(0) - Y(2))) / m1;
	dY(2) = Y(3);
	dY(3) = (F + b2 * (Y(1) - Y(3)) + k2 * (Y(0) - Y(2))) / m2;
	return dY;
}

matrix fR6(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	int N = 1001;
	matrix X(N, 2); //do niej wczytac dane z pliku
	ifstream in;
	in.open("polozenia.txt");
	if (!in.good()) exit(100);
	int j = 0;
	while(!in.eof() && j < N) {
		in >> X(j,0);
		in >> X(j,1);
		j++;
	}
	in.close();

	matrix Y0(4, new double[4] {0., 0., 0., 0.});
	matrix* Y = solve_ode(df6, 0, 0.1, 100, Y0, ud1, X[0]);
	y = 0;
	for (int i = 0; i < N; i++) {
		y = y + abs(X(i, 0) - Y[1](i, 0)) + abs(X(i, 1) - Y[1](i, 2));
	}
	y = y / (2 * N);
	return y;
}