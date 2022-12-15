#include"opt_alg.h"

double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		double* p = new double[3]{ 0,0,0 };
		//Tu wpisz kod funkcji
		int i = 0;
		double x1;
		x1 = x0 + d;
		
		if (ff(x1,ud1,ud2) == ff(x0,ud1,ud2)) {
			p[0] = x0;
			p[1] = x1;
			p[2] += 2;
			return (p);
		}
		if (ff(x1, ud1, ud2) > ff(x0, ud1, ud2)) {
			d = -d;
			x1 = x0 + d;
			p[2] += 2;
			if (ff(x1, ud1, ud2) >= ff(x0, ud1, ud2)) {
				p[0] = x1;
				p[1] = x0-d;
				p[2] += 2;
				return (p);
			}
		}

		double xi, xiplus1 = 0, ximinus1 = 0;
		do {
			if (p[2] > Nmax){
				throw ("Error");
			}
			if (i > 1) {
				ximinus1 = x0 + pow(alpha, i - 2) * d;
			}
			
			xi = x0 + pow(alpha, i-1) * d;
			
			xiplus1 = x0 + pow(alpha, i) * d;
			i++;
			//cout << i << endl;
			p[2] += 2;
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
		solution opt;
		opt.ud = b - a;
		double* A = new double[n];
		double* B = new double[n];
		double* C = new double[n];
		double* D = new double[n];

		double* F = new double[n];
		F[0] = 1.;
		F[1] = 1.;

		int fcalls = 0;

		for (int i = 2; i < n ; ++i) {
			F[i] = F[i - 2] + F[i - 1];
		}
		n--;
		//cout << "L/epsilon = \t" << (b-a) / epsilon << endl;
		//cout << "F[n] = \t" << F[n] << endl;
		
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
			opt.ud.add_row((B[i+1] - A[i+1]));
			C[i + 1] = B[i + 1] - ((F[n - i - 2] / F[n - i - 1]) * (B[i + 1] - A[i + 1]));
			D[i + 1] = A[i + 1] + B[i + 1] - C[i + 1];
			fcalls += 2;
		}

		
		//cout << i << endl;
		opt.x = C[n - 3];
		opt.y = ff(C[n - 3], ud1, ud2);
		opt.f_calls = fcalls;
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
		solution::f_calls = 0;
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
				D_old.fit_fun(ff, ud1, ud2);
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
				D_old.fit_fun(ff, ud1, ud2);
				Xopt = D_old;
				Xopt.flag = 2;
				return Xopt;
			}
			Xopt.ud.add_row((B.x - A.x));
			if (B.x - A.x < epsilon || abs(D.x() - D_old.x()) < gamma)
			{
				D.fit_fun(ff, ud1, ud2);
				Xopt = D;
				Xopt.flag = 0;
				break;
			}
			if (solution::f_calls > Nmax)
			{
				D.fit_fun(ff, ud1, ud2);
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
		solution x(x0);
		solution xB, _xB; //typ solutiom
		//Tu wpisz kod funkcji
		xB = x;
		xB.fit_fun(ff,ud1,ud2);
		do {
			
			x = probuj(ff, xB, s, ud1, ud2);
			if (x.y < xB.y) {
				do {
					_xB = xB;
					xB = x;
					xB.fit_fun(ff, ud1, ud2);
					x.x = (2 * xB.x) - _xB.x;
					x = probuj(ff, x, s, ud1, ud2);
				
					if(solution::f_calls > Nmax) {
						throw ("Error");
					}
					
				} while (x.y < xB.y);
			
			}
			else {
				s = s * alpha;
			}
			if (solution::f_calls>Nmax){
				throw ("Error");
			}
			//cout << xB.x(0) << "\t" << xB.x(1) << endl;
		} while (s >= epsilon);
		Xopt = xB;
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution HJ(...):\n" + ex_info);
	}
}


solution probuj(matrix(*ff)(matrix, matrix, matrix),solution xB, double s, matrix ud1, matrix ud2) {
	int n = get_dim(xB);
	double vect1[] = { 1,0 };
	double vect2[] = { 0,1 };

	matrix mvect1(2, vect1);
	matrix mvect2(2, vect2);

	matrix vecTab[] = { mvect1,mvect2 };
	solution X;
	matrix S(s);

	for (int j = 0; j < n; j++)
	{
		
		X.x = xB.x + S * vecTab[j];
		X.fit_fun(ff, ud1, ud2);
		if (X.y < xB.y)
		{
			xB = X;
		}
		else
		{
			X.x = xB.x - S * vecTab[j];
			X.fit_fun(ff, ud1, ud2);

			if (X.y < xB.y)
			{
				xB = X;
			}

		}

	}
	return xB;
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
		int n = 2;
		int i = 0;
		double vect1[] = { 1,0 };
		double vect2[] = { 0,1 };

		matrix mvect1(2, vect1);
		matrix mvect2(2, vect2);
	
		matrix s = s0;
		matrix d[] = { mvect1,mvect2 };
		matrix lambda[] = { 0,0 };
		matrix p[] = { 0,0 };
		matrix xB = x0;
		//tu wpisz kod funkcji
		do {
			bool zmianaBazyKierunkow = false;
			int j;
			for (j = 0; j < n; j++) {
				if(ff(xB +(s * d[j]), 0, 0) < ff(xB, 0, 0)) {
					xB = xB + (s * d[j]);
					lambda[j] = lambda[j] + s;
					s = s * alpha;
				}
				else {
					s = -beta * s;
					p[j] = p[j] + 1;
				}
				if (lambda[j] != 0 && p[j] != 0) zmianaBazyKierunkow = true;
				else zmianaBazyKierunkow = false;
			}

			if(zmianaBazyKierunkow) {
				//zmiana bazy kierunkow
				double q1[] = { m2d(lambda[0]), m2d(lambda[1]) };
				double q2[] = { 0.0, m2d(lambda[1]) };
				matrix mq1(2, q1);
				matrix mq2(2, q2);
				matrix Q[] = { mq1,mq2 };
				Q[0] = Q[0] * d[0];
				Q[1] = Q[1] * d[1];
				matrix v[] = { Q[0], Q[1] };
				matrix vnorm;
				matrix suma = 0;

				matrix qtranstemp = trans(Q[1]);
				suma = suma + qtranstemp * d[1];
	
				suma = suma * d[1];
				v[1] = suma;
				for (j = 0; j < n; j++){
					vnorm[j] = sqrt(m2d(v[j][0] * v[j][0] + v[j][1] * v[j][1]));
					d[j] = v[j]/vnorm[j];

				}
				lambda[j] = 0;
				p[j] = 0;
				s = s0;
			}
			i++;	

			if(solution::f_calls > Nmax) {
				break;
			}

		} while ( i < Nmax);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}

solution pen1(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		solution Fx;
		Fx.x = x0;
		matrix OldX(0);
		matrix temp(0);
		//Tu wpisz kod funkcji
		int i=0;
		do {
			i++;
			temp(0) = c * zewS(Fx.x);
			Fx.y = Fx.fit_fun(ff, ud1, c) + temp;
			OldX = Fx.x;
			//Fx = sym_NM(f3, Fx.x, 3, 1, 0.5, 2, 0.5, 0.01, 1000);
			Fx = HJ(fR3, Fx.x, 0.5, 0.5, 0.01, 1000, ud1, c);
			c = dc * c;
			//cout <<"tu jest pen: " <<Fx.x << endl;
			if (solution::f_calls > Nmax) {
				throw ("Error");
			}
		} while(norm(Fx.x - OldX) > epsilon);

		Xopt = Fx;

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}
solution pen2(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		solution Fx;
		Fx.x = x0;
		matrix OldX(0);
		matrix temp(0);
		//Tu wpisz kod funkcji
		int i = 0;
		do {
			i++;
			temp(0) = c * wewS(Fx.x);
			Fx.y = Fx.fit_fun(ff, ud1, ud2) + temp;
			OldX = Fx.x;
			//Fx = sym_NM(f3, Fx.x, 3, 1, 0.5, 2, 0.5, 0.01, 1000);
			Fx = HJ(f3, Fx.x, 0.5, 0.5, 0.01, 1000, ud1, ud2);
			c = dc * c;
			//cout <<"tu jest pen: " <<Fx.x << endl;
			if (solution::f_calls > Nmax) {
				throw ("Error");
			}
		} while (norm(Fx.x - OldX) > epsilon);

		Xopt = Fx;

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
		solution Xopt, pSrednie, pOdb, pE, pZ;
		matrix tmp_matrix(2, new double[2]{ 0,0 });
		pSrednie.x = tmp_matrix;
		pOdb.x = tmp_matrix;
		pE.x = tmp_matrix;
		pZ.x = tmp_matrix;
		solution p[3];
		int i_Max, i_Min;
		double vect1[] = { 1,0 };
		double vect2[] = { 0,1 };

		matrix e1(2, vect1);
		matrix e2(2, vect2);

		matrix e[] = { e1,e2 };

		double temp2 = 0;
		double tmp_w1 = 0;
		double tmp_w2 = 0;
		double tmpMax;
		int k = 0;

		matrix temp(2, new double[2] {0, 0});
		matrix tmp_w1_tmp(2, new double[2] {0, 0});
		matrix tmp_w2_tmp(2, new double[2] {0, 0});

		//Tu wpisz kod funkcji
		p[0].x = x0;
		for(int i = 1; i < 3; i++){
			p[i].x = p[0].x + s * e[i-1];
		}

		do {
			for(int i = 0; i < 3; i++){
				p[i].fit_fun(ff, ud1, ud2);
				//cout << p[i].y << "\t";
			}
			//cout << endl;

			i_Max = 0;
			i_Min = 0;
			for (int i = 1;i<3;i++){
				if (p[i].y < p[i-1].y) i_Min = i;
				if (p[i].y > p[i-1].y) i_Max = i;
			}
			

			//pSrednie.y = (p[0].y + p[1].y + p[2].y) / 3;
			for(int i = 0; i<3;i++){
				if(i != i_Max) pSrednie.x = pSrednie.x + ((1 / 2.0) * p[i].x);
			}
			pSrednie.fit_fun(ff, ud1, ud2);

			pOdb.x = pSrednie.x + alpha * (pSrednie.x - p[i_Max].x);
			pOdb.fit_fun(ff, ud1, ud2);

			if (pOdb.y < p[i_Min].y)
			{
				pE.x = pSrednie.x + gamma * (pOdb.x - pSrednie.x);
				pE.fit_fun(ff, ud1, ud2);

				if (pE.y < pOdb.y)
				{
					p[i_Max] = pE;
				}
				else
				{
					p[i_Max] = pOdb;
				}
			}
			else
			{
				if (p[i_Min].y <= pOdb.y && pOdb.y < p[i_Max].y)
				{
					p[i_Max] = pOdb;
				}
				else
				{
					pZ.x = pSrednie.x + (beta * (p[i_Max].x - pSrednie.x));
					pZ.fit_fun(ff, ud1, ud2);

					if (pZ.y > p[i_Max].y)
					{
						for (int i = 0; i < 3; i++)
						{
							//indeks gdzie min
							if (p[i].y != p[i_Min].y)
							{
								p[i].x = delta * (p[i].x + p[i_Min].x);
							}
						}
					}
					else 
					{
						p[i_Max] = pZ;
					}
				}
			}
			if (solution::f_calls > Nmax) {
				throw ("Error");
			}

			//if (k > 10) break;

			//cout << "iteracja nr. " << k << endl;
			//k++;

			if (i_Min != 0) {
				temp = p[i_Min].x - p[0].x;
				temp2 = norm(temp2);
			}
			else temp2 = -100000;
			if (i_Min != 1) {
				tmp_w1_tmp = p[i_Min].x - p[1].x;
				tmp_w1 = norm(tmp_w1_tmp);
			}
			else tmp_w1 = -100000;
			if (i_Min != 2) {
				tmp_w2_tmp = p[i_Min].x - p[2].x;
				tmp_w2 = norm(tmp_w2_tmp);
			}
			else tmp_w2 = -100000;

			
			tmpMax = max(temp2, tmp_w1);
			tmpMax = max(tmp_w1, tmp_w2);
	
		} while (tmpMax > epsilon);
		
		Xopt = p[i_Min];
		Xopt.fit_fun(ff, ud1, ud2);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}

//solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		solution Xopt;
//		//Tu wpisz kod funkcji
//		int i = 0;
//		int n = get_len(x0);
//		solution X0, X1;
//		matrix P(2, new double[2]{ n, 2 }), d;
//		double* ab_db;
//		matrix ab(2, new double[2]{ 0,0 });
//		soultion x[2], h;
//		x[0] = x0;
//		
//		do {
//			d = -1. * gf(x[0], ud1, ud2);
//			P.set_col(x0, 0);
//			P.set_col(d, 1);
//			ab_db = expansion(ff, x(0), d(0), 1.5, Nmax, ud1, ud2);
//			ab[0] = ab_db[0];
//			ab[1] = ab_db[1];
//
//			i++;
//			if (solution::f_calls > Nmax) {
//				throw ("Error");
//			}
//		} while ();
//
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution SD(...):\n" + ex_info);
//	}
//}

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

//solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		solution Xopt;
//		//Tu wpisz kod funkcji
//		int i = 0;
//		double alfa = (pow(5, 0.5) - 1) / 2.;
//		solution a[2], b[2], c[2], d[2];
//		matrix tmp(1, new double[1]{ 0 });
//		for(int j = 0 ; j < 2; j++){
//			a[j].x = tmp;
//			b[j].x = tmp;
//			c[j].x = tmp;
//			d[j].x = tmp;
//		}
		
//		b[0].x = b;
//		c[0].x = b[0].x - alfa * (b[0].x - a[0].x);
//		d[0].x = a[0].x + alfa * (b[0].x - a[0].x);
//		a[0].fit_fun(ff, ud1, ud2);
//		b[0].fit_fun(ff, ud1, ud2);
//		c[0].fit_fun(ff, ud1, ud2);
//		d[0].fit_fun(ff, ud1, ud2);
//		do {
//			if(c[0].y < d[0].y) {
//				a[1].x = a[0].x;
//				b[1].x = d[0].x;
//				c[1].x = b[1].x - alfa * (b[1].x - a[1].x);
//				d[1].x = c[0];
//				a[1].fit_fun(ff, ud1, ud2);
//				b[1].fit_fun(ff, ud1, ud2);
//				c[1].fit_fun(ff, ud1, ud2);
//				d[1].fit_fun(ff, ud1, ud2);
//			}
//			else {
//				a[1].x = c[0].x;
//				b[1].x = b[0].x;
//				c[1].x = d[0].x;
//				d[1].x = a[1].x + alfa * (b[1].x - a[1].x);
//				a[1].fit_fun(ff, ud1, ud2);
//				b[1].fit_fun(ff, ud1, ud2);
//				c[1].fit_fun(ff, ud1, ud2);
//				d[1].fit_fun(ff, ud1, ud2);
//			}
//			a[0] = a[1];
//			b[0] = b[1];
//			c[0] = c[1];
//			d[0] = d[1];
//			i++;
//			if (solution:f_calls > Nmax) throw("error: przekroczono nmax");
//		} while (b[0].y - a[0].y < epsilon);
		
//		Xopt.x = (a[0].x + b[0].x) / 2;
//		Xopt.fit_fun(ff, ud1, ud2);
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution golden(...):\n" + ex_info);
//	}
//}

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
