/*********************************************
Kod stanowi uzupe³nienie materia³ów do æwiczeñ
w ramach przedmiotu metody optymalizacji.
Kod udostêpniony na licencji CC BY-SA 3.0
Autor: dr in¿. £ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia Górniczo-Hutnicza
*********************************************/

#include"opt_alg.h"

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
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

void lab1()
{
	double* p = expansion(f1,10,1,1.5,1000);
	//cout << p[0] <<" "<< p[1] << endl;
	solution opt = fib(f1, -10, 10, 1e-5);
	//cout << opt.x << " " << opt.y <<solution::f_calls;
	solution optLag = lag(f1, -100, 100, 0.001, 1e-7, 1000);
	cout << optLag.x << " " << optLag.y;
}

void lab2()
{

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
