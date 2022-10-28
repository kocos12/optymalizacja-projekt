#include"opt_alg.h"



double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		double* p = new double[2]{ 0,0 };
		//Tu wpisz kod funkcji
		int i = 0;
		double x1;
		x1 = x0 + d;
		
		if (ff(x1,ud1,ud2) == ff(x0,ud1,ud2)) {
			p[0] = x0;
			p[1] = x1;
			return (p);
		}
		if (ff(x1, ud1, ud2) > ff(x0, ud1, ud2)) {
			d = -d;
			x1 = x0 + d;
			if (ff(x1, ud1, ud2) >= ff(x0, ud1, ud2)) {
				p[0] = x1;
				p[1] = x0-d;
				return (p);
			}
		}

		double xi, xiplus1, ximinus1;
		do {
			if (solution::f_calls > Nmax){
				throw ("Error");
			}
			if (i > 1) {
				ximinus1 = x0 + pow(alpha, i - 2) * d;
			}
			
			xi = x0 + pow(alpha, i-1) * d;
			
			xiplus1 = x0 + pow(alpha, i) * d;
			i++;
			//cout << i << endl;
		} while (ff(xi, ud1, ud2) >= ff(xiplus1, ud1, ud2));

		if (d > 0) {
			p[0] = ximinus1;
			p[1] = xiplus1;
			return p;
		}
		p[0] = xiplus1;
		p[1] = ximinus1;
		return p;
	}
	catch (string ex_info)
	{
		throw ("double* expansion(...):\n" + ex_info);
	}
}

solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
	try
	{
		int n = static_cast<int>(ceil(log2(sqrt(5) * (b - a) / epsilon) / log2((1 + sqrt(5)) / 2)));

		double* A = new double[n];
		double* B = new double[n];
		double* C = new double[n];
		double* D = new double[n];

		double* F = new double[n];
		F[0] = 1;
		F[1] = 1;
		for (int i = 2; i < n ; ++i) {
			F[i] = F[i - 2] + F[i - 1];
		}
		n--;
		cout << "L/epsilon = \t" << (b-a) / epsilon << endl;
		cout << "F[n] = \t" << F[n] << endl;
		
		A[0] = a;
		B[0] = b;
		C[0] = B[0] - (F[n - 1] / F[n]) * (B[0] - A[0]);
		D[0] = A[0] + B[0] - C[0];

		int i;
		for (i = 0; i <= n - 4; ++i)
		{
			//tutaj algorytm
			if (ff(C[i], ud1, ud2) < ff(D[i], ud1, ud2)) {
				A[i + 1] = A[i];
				B[i + 1] = D[i];
			}
			else {
				B[i + 1] = B[i];
				A[i + 1] = C[i];
			}
			C[i + 1] = B[i + 1] - ((F[n - i - 2] / F[n - i - 1]) * (B[i + 1] - A[i + 1]));
			D[i + 1] = A[i + 1] + B[i + 1] - C[i + 1];
		}

		solution opt;
		//cout << i << endl;
		opt.x = C[n - 3];
		opt.y = ff(C[n - 3], ud1, ud2);
		//cout << C[n - 3] << " " << ff(C[n - 3], ud1, ud2) << endl;
		return opt; 
	}
	catch (string ex_info)
	{
		throw ("solution fib(...):\n" + ex_info);
	}
}


solution lag(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, double gamma, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		Xopt.ud = b - a;
		solution A(a), B(b), C, D, D_old(a);
		C.x = (a + b) / 2;
		A.fit_fun(ff, ud1, ud2);
		B.fit_fun(ff, ud1, ud2);
		C.fit_fun(ff, ud1, ud2);
		double l, m;
		while (true)
		{
			l = m2d(A.y * (pow(B.x) - pow(C.x)) + B.y * (pow(C.x) - pow(A.x)) + C.y * (pow(A.x) - pow(B.x)));
			m = m2d(A.y * (B.x - C.x) + B.y * (C.x - A.x) + C.y * (A.x - B.x));
			if (m <= 0)
			{
				Xopt = D_old;
				Xopt.flag = 2;
				return Xopt;
			}
			D.x = 0.5 * l / m;
			D.fit_fun(ff, ud1, ud2);
			if (A.x <= D.x && D.x <= C.x)
			{
				if (D.y < C.y)
				{
					A.x = A.x;
					B.x = C.x;
					C.x = D.x;
				}
				else
				{
					A.x = D.x;
					C.x = C.x;
					B.x = B.x;
				}
			}
			else if (C.x <= D.x && D.x <= B.x)
			{
				if (D.y < C.y)
				{
					A.x = C.x;
					C.x = D.x;
					B.x = B.x;
				}
				else 
				{
					A.x = A.x;
					C.x = C.x;
					B.x = D.x;
				}
			}
			else
			{
				Xopt = D_old;
				Xopt.flag = 2;
				return Xopt;
			}
			Xopt.ud.add_row((B.x - A.x)());
			if (B.x - A.x < epsilon || abs(D.x() - D_old.x()) < gamma)
			{
				Xopt = D;
				Xopt.flag = 0;
				break;
			}
			if (solution::f_calls > Nmax)
			{
				Xopt = D;
				Xopt.flag = 1;
				break;
			}
			D_old = D;
		}
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution lag(...):\n" + ex_info);
	}
}

solution HJ(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution HJ(...):\n" + ex_info);
	}
}

solution HJ_trial(matrix(*ff)(matrix, matrix, matrix), solution XB, double s, matrix ud1, matrix ud2)
{
	try
	{
		//Tu wpisz kod funkcji

		return XB;
	}
	catch (string ex_info)
	{
		throw ("solution HJ_trial(...):\n" + ex_info);
	}
}

solution Rosen(matrix(*ff)(matrix, matrix, matrix), matrix x0, matrix s0, double alpha, double beta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}

solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}

solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution SD(...):\n" + ex_info);
	}
}

solution CG(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution CG(...):\n" + ex_info);
	}
}

solution Newton(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix),
	matrix(*Hf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Newton(...):\n" + ex_info);
	}
}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution golden(...):\n" + ex_info);
	}
}

solution Powell(matrix(*ff)(matrix, matrix, matrix), matrix x0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Powell(...):\n" + ex_info);
	}
}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}
