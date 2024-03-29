/*********************************************
Kod stanowi uzupe�nienie materia��w do �wicze�
w ramach przedmiotu metody optymalizacji.
Kod udost�pniony na licencji CC BY-SA 3.0
Autor: dr in�. �ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia G�rniczo-Hutnicza
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
		lab2();
		//lab3();
		//lab4();
		//lab5();
		//lab6();
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
	//	solution optHJ = HJ(f2, x0, krok, 0.5, 1e-3, 1000, 0, 0);	solution optHJ = HJ(f2, x0, krok, 0.5, 1e-3, 1000, 0, 0);
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
	

	////ROSEN:

	//double x1[300], x2[300];
	//ifstream in("rosen.txt");
	//if (!in.good()) exit(69);
	//for (int i = 0; i < 300; i++) {
	//	in >> x1[i];
	//	in >> x2[i];
	//}
	//in.close();

	////tabela 1
	//matrix krok(2, 1);
	//for (int i = 0; i < 300; i++) {
	//	if (i >= 0 && i < 100) {
	//		krok(0) = 0.5;
	//		krok(1) = 0.5;
	//	}
	//	else if (i >= 100 && i < 200) {
	//		krok(0) = 0.25;
	//		krok(1) = 0.25;
	//	}
	//	else {
	//		krok(0) = 0.75;
	//		krok(1) = 0.75;
	//	}
		
	//	matrix x0(2, new double[2] {x1[i], x2[i]});
	//	solution optRosen = Rosen(f2, x0, krok, 2, 0.5, 1e-3, 1000, NAN, NAN);
	//	cout << optRosen.x(0) << " " << optRosen.x(1) << " " << optRosen.y(0) << " " << optRosen.f_calls << endl;
	//	solution::clear_calls();
	//}

	////arkusz wykres
	//matrix krok(2, 1);
	//matrix x0(2, new double[2] {x1[0], x2[0]});
	//krok(0) = 0.5;
	//krok(1) = 0.5;
	//solution optRosen = Rosen(f2, x0, krok, 2, 0.5, 1e-3, 1000, NAN, NAN);

	////funkcja rzeczywista:
	//matrix krok(2, 1);
	//krok(0) = 0.5;
	//krok(1) = 0.5;
	//matrix x0(2, new double[2] {3., 5.});
	//solution wynik = Rosen(fR_lab2, x0, krok, 2, 0.5, 1e-3, 1000, NAN, NAN);
	//std::cout << wynik.x(0) << " " << wynik.x(1) << " " << wynik.y(0) << " " << wynik.f_calls << endl;
	//solution::clear_calls();

	fR_lab2(matrix(2,new double[2]{3.50611,4.76441}), NAN, NAN);

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
	//funkcja testowa:
	//ofstream out("wynikiTestoweLab5.txt");
	//solution naszSolution;
	//double a = 10;
	//double waga = 0.0;
	//matrix ud1(2, new double[2] {waga, a});
	//for (int i = 0; i < 101; i++) {
	//	double x1, x2;
	//	x1 = (20. * ((double)rand() / (double)RAND_MAX)) - 10.; //od -10 do 10
	//	x2 = (20. * ((double)rand() / (double)RAND_MAX)) - 10.;
	//	double pom[2] = { x1,x2 };
	//	matrix x0(2, pom);
	//	ud1(1) = 1.;
	//	naszSolution = Powell(f5, x0, 0.001, 1000, ud1);
	//	cout <<  x1 << " " << x2 << " " << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << naszSolution.y(1) << " " << solution::f_calls << " ";
	//	solution::clear_calls();
	//	ud1(1) = 10.;
	//	naszSolution = Powell(f5, x0, 0.001, 1000, ud1);
	//	cout << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << naszSolution.y(1) << " " << solution::f_calls << " ";
	//	solution::clear_calls();

	//	ud1(1) = 100.;
	//	naszSolution = Powell(f5, x0, 0.001, 1000, ud1);
	//	cout << naszSolution.x(0) << " " << naszSolution.x(1) << " " << naszSolution.y(0) << " " << naszSolution.y(1) << " " << solution::f_calls << endl;
	//	solution::clear_calls();

	//	ud1(0) += 0.01;
	//}


	//problem rzeczywisty:
	ofstream out("wynikiRzeczywisteLab5.txt");
	solution naszSolution;
	double waga = 0.0;
	matrix ud1(2,1);
	for (int i = 0; i < 101; i++) {
		matrix x0(2, 1);
		ud1 = matrix(1, 1, waga);
		double l, d;
		l = (0.9 * ((double)rand() / (double)RAND_MAX)) + 0.1;
		d = (0.04 * ((double)rand() / (double)RAND_MAX)) + 0.01;
		x0(0) = l;
		x0(1) = d;
		naszSolution = Powell(ff5R, x0, 0.001, 1000, ud1);
		cout << 1000 * x0(0) << " " << x0(1) * 1000 << " " << naszSolution.x(0) * 1000 << " " << 1000 * naszSolution.x(1) << " " << naszSolution.y(0) << " " << 1000 * naszSolution.y(1) << " " << " " << solution::f_calls << endl;
		solution::clear_calls();
		waga += 0.01;
	}
}

void lab6()
{
	////funkcja testowa:
	//ofstream out("wyniki_f_testowa_lab6.txt");
	//matrix sigma0 = matrix(2,1);
	//int mi = 20;
	//int N = 2, Nmax = 2000;
	//int lambda = 40;
	//double epsilon = 1e-3;
	//solution EH;
	//matrix limits = matrix(2,2);
	//limits(0,0) = -5.;
	//limits(0,1) = 5.;

	//limits(1,0) = -5.;
	//limits(1,1) = 5.;

	//sigma0(0) = 0.01;
	//sigma0(1) = 0.01;
	//for (int i = 0; i < 100; i++) {
	//	EH = EA(f2, N, limits, mi, lambda, sigma0, epsilon, Nmax);
	//	out << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << " " << solution::f_calls << endl;
	//	solution::clear_calls();		
	//}

	//sigma0(0) = 0.1;
	//sigma0(1) = 0.1;
	//for (int i = 0; i < 100; i++) {
	//	EH = EA(f2, N, limits, mi, lambda, sigma0, epsilon, Nmax);
	//	out << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << " " << solution::f_calls << endl;
	//	solution::clear_calls();		
	//}

	//sigma0(0) = 1.;
	//sigma0(1) = 1.;
	//for (int i = 0; i < 100; i++) {
	//	EH = EA(f2, N, limits, mi, lambda, sigma0, epsilon, Nmax);
	//	out << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << " " << solution::f_calls << endl;
	//	solution::clear_calls();		
	//}

	//sigma0(0) = 10.;
	//sigma0(1) = 10.;
	//for (int i = 0; i < 100; i++) {
	//	EH = EA(f2, N, limits, mi, lambda, sigma0, epsilon, Nmax);
	//	out << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << " " << solution::f_calls << endl;
	//	solution::clear_calls();		
	//}

	//sigma0(0) = 100.;
	//sigma0(1) = 100.;
	//for (int i = 0; i < 100; i++) {
	//	EH = EA(f2, N, limits, mi, lambda, sigma0, epsilon, Nmax);
	//	out << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << " " << solution::f_calls << endl;
	//	solution::clear_calls();		
	//}


	//problem rzeczywisty:
	ofstream out("wyniki_f_rzeczywista_lab6.txt");
	//matrix sigma0 = matrix(2,1);
	//int mi = 20;
	//int N = 2, Nmax = 1000;
	//int lambda = 40;
	//double epsilon = 1e-3;
	//solution EH;
	//matrix limits = matrix(2,2);
	//limits(0,0) = 0.1;
	//limits(0,1) = 3.;
	//limits(1,0) = 0.1;
	//limits(1,1) = 3.;

	//sigma0(0) = 0.01;
	//sigma0(1) = 0.01;
	//EH = EA(fR6,N,limits,mi,lambda,sigma0,epsilon,Nmax);
	//cout << EH.x(0) << " " << EH.x(1) << " " << EH.y(0) << solution::f_calls << endl;

	////symulacja
	matrix b(2,1);
	b(0) = 1.41813;
	b(1) = 0.94702;
	matrix tmp = fR6(b, NAN, NAN);
}
