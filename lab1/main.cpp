/*********************************************
Kod stanowi uzupe³nienie materia³ów do æwiczeñ
w ramach przedmiotu metody optymalizacji.
Kod udostêpniony na licencji CC BY-SA 3.0
Autor: dr in¿. £ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia Górniczo-Hutnicza
*********************************************/

#include"opt_alg.h"
#include <fstream>

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void lab6();


int main()
{
	//try
	//{
	//	lab1();
	//}
	//catch (string ex_info)
	//{
	//	cerr << "error:\n";
	//	cerr << ex_info << endl << endl;
	//}
	//try
	//{
	//	lab2();
	//}
	//catch (string ex_info)
	//{
	//	cerr << "error:\n";
	//	cerr << ex_info << endl << endl;
	//} 
	try
	{
		lab3();
	}
	catch (string ex_info)
	{
		cerr << "error:\n";
		cerr << ex_info << endl << endl;
	}
	//system("pause");
	return 0;
}

void lab1()
{
	int f;
	double A[300];
	double B[300];
	
	//for (int i = 0; i < 300; i++) {
	//	double alfa;
	//	if (i < 100) {
	//		alfa = 1.5;
	//	}
	//	else if (i >= 100 && i < 200) {
	//		alfa = 2;
	//	}
	//	else {
	//		alfa = 1.69;
	//	}

		//f = (rand() % (100 + 100 + 1) - 100);

		//double* p = expansion(f1, f, 1, alfa, 1000); //1.5, 2, 1.69
		//cout << f << "\t" << p[0] << "\t" << p[1] << "\t" << p[2] << endl;
	//	A[i] = p[0];
    //	B[i] = p[1];

	//}
	//cout << "FIBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
	//for (int i = 0; i < 300; i++) {
	//	solution opt = fib(f1, A[i], B[i], 1e-5);
	//	cout << opt.x << " " << opt.y << " " << opt.f_calls << endl;
	//}
	//cout << "LAGRANGEEEEEEEEEEEEEEEEEEEEEEEEEEE\n";
	//for (int i = 0; i < 300; i++) {
	//	solution optLag = lag(f1, A[i], B[i], 0.0001, 1e-7, 1000);
	//	cout << optLag.x << " " << optLag.y << " " << optLag.f_calls << endl;
	//}
	//cout << "FIBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
	//solution opt = fib(f1, -100, 100, 1e-5);
	////cout << opt.x << " " << opt.y << " " << opt.f_calls << endl;

	//for (int i = 0; i < 100; i++) {
	//	//cout << opt.ud[i] << endl;
	//}

	//cout << "LAGRANGEEEEEEEEEEEEEEEEEEEEEEEEEEE\n";
	//solution optLag = lag(f1, -100, 100, 0.0001, 1e-7, 1000);
	////cout << optLag.x << " " << optLag.y << " " << optLag.f_calls << endl;

	//for (int i = 0; i < 100; i++) {
	//	cout << optLag.ud[i] << endl;
	//}
	//double* p = expansion(fR, 10, 1, 1.5, 1000); //1.5, 2, 1.69
	//cout << p[0] << "\t" << p[1] << "\t" << p[2] << endl;

	//solution opt = fib(fR, 1, 100, 1e-5);
	//cout << opt.x << " " << opt.y << " " << opt.f_calls << endl;

	//solution optLag = lag(fR, 1, 100, 1e-5, 1e-7, 1000);
	//cout << optLag.x << " " << optLag.y << " " << optLag.f_calls << endl;
	//
	//matrix ud1,ud2;
	//matrix xd = fR(opt.x, ud1 , 10);
	//xd = fR(optLag.x, ud1 , 10);

	//cout << xd << endl;
}

void lab2()
{
	//int f;
	//double x1[300];
	//double x2[300];

	//for (int i = 0; i < 300; i++) {
	//	double krok;
	//	if (i < 100) {
	//		krok = 0.5;
	//	}
	//	else if (i >= 100 && i < 200) {
	//		krok = 0.25;
	//	}
	//	else {
	//		krok = 0.75;
	//	}

	//	x1[i] = 2. * ((double)rand() / (double)RAND_MAX) - 1; //od 0 do 1
	//	x2[i] = 2. * ((double)rand() / (double)RAND_MAX) -1;

	//	double pom[] = { x1[i],x2[i] };
	//	matrix x0(2, pom);
	//	solution optHJ = HJ(f2, x0, krok, 0.5, 1e-3, 1000, 0, 0);
	//	//cout << "wyniki:\nx1 = " << optHJ.x(0) << "\tx2 = " << optHJ.x(1) << "\ty = " << optHJ.y << endl << "f_calls = " << optHJ.f_calls << "\texit flag = " << optHJ.flag << endl;
	//	//cout << pom[0] << " " << pom[1] << " " << optHJ.x(0) << " " << optHJ.x(1) << " " << optHJ.y << " " << optHJ.f_calls << endl;
	//	solution::f_calls = 0;
	//}

	//double pom[] = { 0.12, 0.21 };
	//matrix x0(2, pom);
	
	//solution optHJ = HJ(f2, x0, 0.5, 0.5, 1e-3, 1000, 0, 0);

	//double pom[] = {3, 5 };
	//matrix x0(2, pom);

	////solution optHJ = HJ(fR_lab2, x0, 0.5, 0.5, 1e-3, 1000, 0, 0);
	////cout << "\nwyniki:\n" << optHJ.x(0) << "\t" << optHJ.x(1) << "\t" << optHJ.y << endl;// << "f_calls = " << optHJ.f_calls << "\texit flag = " << optHJ.flag << endl;
	//matrix x(2, new double[2]{ 3.8457,4.83594 });
	//matrix wynik = fR_lab2(x, 0, 0);
	//cout << wynik << endl;
 
}

void lab3()
{
	matrix chuj(2, new double[2]{ 1, 1 });
	//matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2
	//solution chujSolution = sym_NM(f3, chuj, 3, 1, 0.5, 2, 0.5, 0.01, 1000);
	//	cout << "x1 = " << chujSolution.x(0) << "\tx2 = " << chujSolution.x(1) << "\ty = " << chujSolution.y << endl;

	//matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2

	cout << "\n\n\n\n\n";

	solution penior = pen(f3, chuj, 3, 2, 0.01, 1000);
	cout << "x1 = " << penior.x(0) << "\tx2 = " << penior.x(1) << "\ty = " << penior.y << endl;
}

void lab4()
{

}

void lab5()
{

}

void lab6()
{

}
