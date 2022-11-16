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
	try
	{
		lab1();
	}
	catch (string ex_info)
	{
		cerr << "error:\n";
		cerr << ex_info << endl << endl;
	}
	try
	{
		lab2();
	}
	catch (string ex_info)
	{
		cerr << "error:\n";
		cerr << ex_info << endl << endl;
	} 
	system("pause");
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
	double pom[] = { 1,0.5 };
	matrix x0(2, pom);
	solution optHJ = Rosen(f2, x0, 2, 0.5, 1e-3, 1000, 0, 0);
	cout << "wyniki:\nx = " << optHJ.x << "\ty = " << optHJ.y << endl << "f_calls = " << optHJ.f_calls << "\texit flag = " << optHJ.flag << endl;
 
}

void lab3()
{

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
