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
#include <cstdlib>
#include <cstdio>
#include <ctime>

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void lab6();


int main()
{
	
	try
	{
		//lab1();
		//lab2();
		//lab3();
		lab4();
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
	////testy:
	/*matrix naszMatrix(2, new double[2]{ 1, 1 });
	matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2
	solution naszSolution = sym_NM(f3, naszMatrix, 3, 1, 0.5, 2, 0.5, 0.01, 1000);
	cout << "x1 = " << naszSolution.x(0) << "\tx2 = " << naszSolution.x(1) << "\ty = " << naszSolution.y << endl;*/

	////matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2

	////cout << "\n\n\n\n\n";

	//solution penior = pen(f3, naszMatrix, 3, 2, 0.01, 1000);
	//cout << "x1 = " << penior.x(0) << "\tx2 = " << penior.x(1) << "\ty = " << penior.y << endl;

	//funkcja testowa:
	//srand(time(NULL));
	//double x1[100] = {};
	//double x2[100] = {};
	//matrix x0;
	//double pom[2];
	//double a = 5;

	//for (int i = 0; i < 100; i++) {

	//do{


	//	x1[i] = 5. * ((double)rand() / (double)RAND_MAX) + 1; //od 1 do 6
	//	x2[i] = 5. * ((double)rand() / (double)RAND_MAX) + 1;
	//	//cout << "x1(0) = " << x1[i] << "\tx2(0) = " << x2[i] << endl;

	//	pom[0] = x1[i];
	//	pom[1] = x2[i];
	//	matrix pomMatrix(2, pom);
	//	x0 = pomMatrix;

	//} while (g3(x0, a) > );

	//	solution penalty1 = pen1(f3, x0, 3, 2, 0.01, 1000);
	//	cout << pom[0] << " " << pom[1] << " " << penalty1.x(0) << " " << penalty1.x(1) << " " << g3(x0, a)+a << " " << penalty1.y << " " << penalty1.f_calls << " ";
	//	solution::f_calls = 0;

	//	solution penalty2 = pen2(f3, x0, 3, 2, 0.01, 1000);
	//	cout << penalty2.x(0) << " " << penalty2.x(1) << " " << g3(x0, a)+a << " " << penalty2.y << " " << penalty2.f_calls << endl;
	//	solution::f_calls = 0;

	//	//cout << "x1(0)" << x1[i] <<"\tx2(0) = " << x2[i] << "\tx1 = " << penalty.x(0) << "\tx2 = " << penalty.x(1) << "\tr = " << obliczOdleglosc(penalty.x(0), penalty.x(1), penalty.y(0)) << "\ty = " << penalty.y(0) << "\t" << penalty.f_calls << endl;
	//	//cout << x1[i] <<"\t" << x2[i] << "\t" << penalty.x(0) << "\t" << penalty.x(1) << "\t" << obliczOdleglosc(penalty.x(0), penalty.x(1), penalty.y(0)) << "\t" << penalty.y(0) << "\t" << penalty.f_calls << endl;
		
	//}
	 
	//problem rzeczywisty:
	double pom[] = { 0,0 };
	//double pom[] = { -2,13.5 };
	matrix x0(2, pom);
	solution penalty1 = pen1(fR3, x0, 3, 2, 0.01, 1000);
	cout << pom[0] << " " << pom[1] << " " << penalty1.x(0) << " " << penalty1.x(1) << " "  << penalty1.y << " " << penalty1.f_calls << " ";
	solution::f_calls = 0;

}

void lab4()
{
	solution naszSolution;
	matrix x0(2, 1, -10.);
	ofstream out ("wyniki.txt");
	//funkcja testowa:
	srand(time(NULL));
	double x1[100] = {};
	double x2[100] = {};
	double pom[2];
	double h = -1;
	
	//for (int i = 0; i < 100; i++) {
		//x1[i] = (20. * ((double)rand() / (double)RAND_MAX)) - 10.; //od -10 do 10
		//x2[i] = (20. * ((double)rand() / (double)RAND_MAX)) - 10.;
		 
		 

		//cout << "x1(0) = " << x1[i] << "\tx2(0) = " << x2[i] << endl;

		//pom[0] = -7.14835;
		//pom[1] = 3.83038;
		//matrix pomMatrix(2, pom);
		//x0 = pomMatrix;

		//naszSolution = SD(f4, gf1, x0, h, 0.001, 1000);
		////out << x1[i] << " " << x2[i] << " " << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << solution::f_calls << " " << solution::g_calls << " ";
		//solution::clear_calls();

		//naszSolution = CG(f4, gf1, x0, h, 0.001, 1000);
		//out << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << solution::f_calls << " " << solution::g_calls << " ";
		//solution::clear_calls();

		//naszSolution = Newton(f4, gf1, Hf, x0, h, 0.001, 1000);
		//out << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << solution::f_calls << " " << solution::g_calls << " " << solution::H_calls << endl;
	//solution::clear_calls();

	//}
	//naszSolution = SD(f4, gf1, x0, -1, 0.0001, 1000);
	//naszSolution = CG(f4, gf1, x0, -1, 0.01, 1000);
	//naszSolution = Newton(f4, gf1, Hf, x0, -1, 0.01, 1000);
	//cout << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y << " " << solution::f_calls << " " << solution::g_calls << endl;
	
	//problem rzeczywisty
	double pom2[3] = { 0.,0.,0. };
	matrix teta(3, pom2);
	naszSolution = CG(fR4, gfR1, teta, 0.01, 0.01, 1000);
	cout << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.x(2) << " " << naszSolution.y(0) << " " << naszSolution.y(1) << " " << solution::g_calls << endl;
}

void lab5()
{

}

void lab6()
{

}
