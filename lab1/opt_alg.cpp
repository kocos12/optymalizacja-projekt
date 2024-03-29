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

double* expansion2(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		double* p = new double[2] { 0, 0 };
		//Tu wpisz kod funkcji
		int i = 0;
		solution X0, X1, X[3]; //X{ i - 1 ; i ; i + 1 }

		for (int j = 0; j < 3; j ++) {
			matrix tmp(0.);	
			X[j].x = tmp;
			X[j].fit_fun(ff,ud1,ud2);
		}

		matrix mx0(x0);
		X0.x = mx0;
		X1.x = X0.x + d;
		X0.fit_fun(ff, ud1, ud2);
		X1.fit_fun(ff, ud1, ud2);

		if (X1.y == X0.y) {
			p[0] = X1.x(0);
			p[1] = X0.x(0) - d;
			return p;
		}

		if (X1.y > X0.y){
			d = -d;
			X1.x = X0.x + d;
			X0.fit_fun(ff, ud1, ud2);
			X1.fit_fun(ff, ud1, ud2);

			if (X1.y >= X0.y) {
				p[0] = X1.x(0);
				p[1] = X0.x(0) - d;
				return p;
			}
		}

		do {
			if (solution::f_calls > Nmax) {
				throw ("Error");
			}
			i++;
			X[0] = X[1];
			X[1] = X[2];
			X[2].x = X0.x + pow(alpha, i) * d;
			X[2].fit_fun(ff, ud1, ud2);
		} while (X[1].y <= X[2].y || i < 2);

		if (d > 0) {
			p[0] = X[0].x(0);
			p[1] = X[2].x(0);
		}
		else {
			p[0] = X[2].x(0);
			p[1] = X[0].x(0);
		}

		return p;
	}
	catch (string ex_info)
	{
		throw ("double* expansion2(...):\n" + ex_info);
	}
}

double* expansion3(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		double* p = new double[2] { 0, 0 };
		int i = 0;
		solution X0(x0), X1(x0 + d);
		X0.fit_fun(ff, ud1, ud2);
		X1.fit_fun(ff, ud1, ud2);
		if (X0.y == X1.y)
		{
			p[0] = m2d(X0.x);
			p[1] = m2d(X1.x);
			return p;
		}
		if (X0.y < X1.y)
		{
			d *= -1;
			X1.x = X0.x + d;
			X1.fit_fun(ff, ud1, ud2);
			if (X1.y >= X0.y)
			{
				p[0] = m2d(X1.x);
				p[1] = m2d(X0.x) - d;
				return p;
			}
		}
		solution X2;
		while (true)
		{
			++i;
			X2.x = x0 + pow(alpha, i) * d;
			X2.fit_fun(ff, ud1, ud2);
			if (X2.y >= X1.y || solution::f_calls > Nmax)
				break;
			X0 = X1;
			X1 = X2;
		}
		d > 0 ? p[0] = m2d(X0.x), p[1] = m2d(X2.x) : (p[0] = m2d(X2.x), p[1] = m2d(X0.x));
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
		solution Xopt, XB(x0);
		solution tmp;
		int n = get_dim(XB);
	
		matrix s(s0);
		matrix d = ident_mat(n);

		matrix lambda(n, 1);
		matrix p(n, 1);
		for (int i = 0; i < n; i++) {
			lambda(i) = 0.;
			p(i) = 0.;
		}

		bool czyZmianaBazy = false;
		double maxS;

		//tu wpisz kod funkcji
		int iteracja = 0;
		XB.fit_fun(ff, ud1, ud2);
		do {
			for (int i = 0; i < n; i++)  {
				
				tmp.x = XB.x + s(i) * d[i];
				tmp.fit_fun(ff, ud1, ud2);
				if (tmp.y < XB.y) {
					XB = tmp;
					lambda(i) = lambda(i) + s(i);
					s(i) = alpha * s(i);
				}
				else {
					s(i) = -beta * s(i);
					p(i) = p(i) + 1;
				}
			}

			czyZmianaBazy = true;
			for (int i = 0; i < n; i++) {
				if (lambda(i) == 0 || p(i) == 0) {
					czyZmianaBazy = false;
					break;
				}
			}

			if (czyZmianaBazy) {
				matrix Q(n, n);
				matrix v(n, 1);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j <= i; j++) {
						Q(i, j) = lambda(i);
					}
				}
				Q = d * Q;
				v = Q[0] / norm(Q[0]);
				d.set_col(v, 0);

				for (int i = 1; i < n; i++) {
					matrix tmp(n, 1);
					for (int j = 0; j < i; j++) {
						tmp = tmp + trans(Q[i]) * d[j] * d[j];
					}
					v = (Q[i] - tmp) / norm(Q[i] - tmp);
					d.set_col(v, i);
				}

				lambda = matrix(n, 1);
				p = matrix(n, 1);
				s = matrix(s0);
			}

			maxS = abs(s(0));
			for (int i = 1; i < n; i++) {
				if (maxS < abs(s(i))) maxS = abs(s(i));
			}

			//std::cout << XB.x(0) << " " << XB.x(1) << endl;

			if(solution::f_calls > Nmax || maxS < epsilon) {
				Xopt = XB;
				Xopt.fit_fun(ff, ud1, ud2);
				return Xopt;
			}
			
		} while (true);
		
	}
	catch (string ex_info){
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

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji
		int i = 0;
		int n = get_len(x0);
		solution X0, X1, h;
		X0.x = x0;
		matrix P(n, 2);
		matrix d(n, 1);
		double* ab;

		while(true) {
			//cout << "licznik iteracji i: " << i << endl;
			d = -X0.grad(gf, ud1, ud2);
			if (h0 < 0)
			{
				P.set_col(X0.x, 0);
				P.set_col(d, 1);
				ab = expansion2(ff, 0, 1, 1.2, Nmax, ud1, P);
				h = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, P);
				X1.x = X0.x + h.x * d;

				cout << X1.x(0) << " " << X1.x(1) << endl;
				
			}
			else {
				X1.x = X0.x + h0 * d;
			}
			if (norm(X0.x - X1.x) < epsilon) {
				Xopt = X1;
				//cout << "Jeste tu";
				break;
			}

			if (solution::g_calls > Nmax) {
				Xopt = X1;
				break;
				//throw ("Error: przekroczono Nmax w SD\n");
			}
			
			i++;
			
			X0 = X1;
		}
		Xopt.fit_fun(ff, ud1, ud2);
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
		int i = 0;
		int n = get_len(x0);
		solution X0, X1, h, Xold;
		X0.x = x0;
		matrix P(n, 2);
		matrix d(n, 1);
		matrix dOld(n, 1);
		double* ab;
		double beta;
		d = -X0.grad(gf, ud1, ud2);

		while (true) {
			//cout << "licznik iteracji i: " << i << endl;
			
			if (h0 < 0)
			{
				P.set_col(X0.x, 0);
				P.set_col(d, 1);
				ab = expansion(ff, 0, 1, 1.2, Nmax, ud1, P);
				h = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, P);
				X1.x = X0.x + h.x * d;

				cout << X1.x(0) << " " << X1.x(1) << endl;
			}
			else {
				X1.x = X0.x + h0 * d;
			}
			
			

			if (norm(X0.x - X1.x) < epsilon) {
                Xopt = X1;
				break;
			}

			if (solution::g_calls > Nmax) {
				Xopt = X1;
				break;
				throw ("Error: przekroczono Nmax w CG\n");
				
			}

			i++;
			dOld = d;
			Xold = X0;
			beta = pow(norm(X1.grad(gf, ud1, ud2)), 2) / pow(norm(Xold.grad(gf, ud1, ud2)), 2);
			d = -X1.grad(gf, ud1, ud2) + beta * dOld;
			
			
			X0 = X1;
		}
		Xopt.fit_fun(ff, ud1, ud2);
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
		int i = 0;
		int n = get_len(x0);
		solution X0, X1, h;
		X0.x = x0;
		matrix P(n, 2);
		matrix d(n, 1);
		double* ab;

		while (true) {
			//cout << "licznik iteracji i: " << i << endl;
			d = -inv(X0.hess(Hf, ud1, ud2)) * X0.grad(gf, ud1, ud2);
			if (h0 < 0)
			{
				P.set_col(X0.x, 0);
				P.set_col(d, 1);
				ab = expansion(ff, 0, 1, 1.2, Nmax, ud1, P);
				h = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, P);
				X1.x = X0.x + h.x * d;
			}
			else {
				X1.x = X0.x + h0 * d;
			}
			if (norm(X0.x - X1.x) < epsilon) {
				Xopt = X1;
				break;
			}

			if (solution::g_calls > Nmax) {
				Xopt = X1;
				break;
				throw ("Error: przekroczono Nmax w Newton\n");
			}

			i++;
			cout << X1.x(0) << " " << X1.x(1) << endl;
			X0 = X1;
		}
		Xopt.fit_fun(ff, ud1, ud2);
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
//		double alf = (pow(5, 0.5) - 1) / 2.;
//		matrix alfa (alf);
//		//matrix bb(2, new double[2] {b, 0.});
//		//matrix aa(2, new double[2] {a, 0.});
//		matrix aa(a);
//		matrix bb(b);
//		solution a[2], b[2], c[2], d[2];
//		//matrix tmp(2, new double[2]{ 0,0 });
//		matrix tmp(0);
//		for(int j = 0 ; j < 2; j++){
//			a[j].x = tmp;
//			b[j].x = tmp;
//			c[j].x = tmp;
//			d[j].x = tmp;
//		}
		
//		b[0].x = bb;
//		a[0].x = aa;
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
//				d[1].x = c[0].x;

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

//			if (solution::f_calls > Nmax) throw("error: przekroczono nmax");

//		} while (b[0].y - a[0].y > epsilon);
		
//		Xopt.x = (a[0].x + b[0].x) / 2;
//		Xopt.fit_fun(ff, ud1, ud2);
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution golden(...):\n" + ex_info);
//	}
//}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		double alfa = (sqrt(5) - 1) / 2;
		solution A, B, C, D;
		A.x = a;
		B.x = b;
		C.x = B.x - alfa * (B.x - A.x);
		C.fit_fun(ff, ud1, ud2);
		D.x = A.x + alfa * (B.x - A.x);
		D.fit_fun(ff, ud1, ud2);
		while (true)
		{
			if (C.y < D.y)
			{
				B = D;
				D = C;
				C.x = B.x - alfa * (B.x - A.x);
				C.fit_fun(ff, ud1, ud2);
			}
			else
			{
				A = C;
				C = D;
				D.x = A.x + alfa * (B.x - A.x);
				D.fit_fun(ff, ud1, ud2);
			}
			if (B.x - A.x < epsilon)
			{
				Xopt.x = (A.x + B.x) / 2.0f;
				Xopt.fit_fun(ff, ud1, ud2);
				Xopt.flag = 0;
				break;
			}
			if (solution::f_calls > Nmax)
			{
				Xopt.x = (A.x + B.x) / 2;
				Xopt.fit_fun(ff, ud1, ud2);
				Xopt.flag = 1;
				break;
			}
		}
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
		double vect1[] = { 1,0 };
		double vect2[] = { 0,1 };
		matrix e1(2, vect1);
		matrix e2(2, vect2);
		matrix e[2] = { e1,e2 };

		int n = get_len(x0);
		
		matrix d = ident_mat(n);
		solution x;
		solution p0, p, h[2];
		
		x.x = x0;
		p0.x = x0;
		p = p0;
		int i = 0;
		matrix P(n, 2);
		double* ab;
	
		do{
			p0 = x;
			for (int j=1; j<=n; j++){

				P.set_col(p.x, 0);
				P.set_col(d[j-1], 1);

				ab = expansion3(ff, 0, 1, 1.2, Nmax, ud1, P);
				h[j-1] = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, P);
				

				p.x = p.x + h[j-1].x * d[j-1];
			}

			if (norm(p.x - x.x) < epsilon) {
				x.fit_fun(ff, ud1, ud2);
				return Xopt = x; 
			}

			for (int i = 0; i < n - 1; ++i) {
				d.set_col(d[i + 1], i);
			}
			d.set_col(p.x - x.x, n - 1);
			P.set_col(p.x, 0);
			P.set_col(d[n-1], 1);

			ab = expansion3(ff, 0, 1, 1.2, Nmax, ud1, P);
			h[0] = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, P);
			p.x = p.x + h[0].x * d[n-1];
			x = p;
			i++;
		} while (solution::f_calls < Nmax);

	}
	catch (string ex_info)
	{
		throw ("solution Powell(...):\n" + ex_info);
	}
}

//solution Powell(matrix(*ff)(matrix, matrix, matrix), matrix x0, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		solution Xopt;
//		//Tu wpisz kod funkcji
//		int n = get_len(x0);
//		matrix D = ident_mat(n), A(n, 2);
//		solution X, P, h;
//		X.x = x0;
//		double* ab;
//		while (true)
//		{
//			P = X;
//			for (int i = 0; i < n; ++i)
//			{
//				A.set_col(P.x, 0);
//				A.set_col(D[i], 1);
//				ab = expansion3(ff, 0, 1, 1.2, Nmax, ud1, A);
//				h = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, A);
//				P.x = P.x + h.x * D[i];
//			}
//			if (norm(X.x - P.x) < epsilon) {
//				Xopt = P;
//				Xopt.fit_fun(ff, ud1, ud2);
//				Xopt.flag = 0;
//				break;
//			}
//			if (solution::f_calls > Nmax) {
//				Xopt = P;
//				Xopt.fit_fun(ff, ud1, ud2);
//				Xopt.flag = 1;
//				break;
//			}
//			for (int i = 0; i < n - 1; ++i)
//				D.set_col(D[i + 1], i);
//			D.set_col(P.x - X.x, n - 1);
//			A.set_col(P.x, 0);
//			A.set_col(D[n - 1], 1);
//			ab = expansion3(ff, 0, 1, 1.2, Nmax, ud1, A);
//			h = golden(ff, ab[0], ab[1], epsilon, Nmax, ud1, A);
//			X.x = P.x + h.x * D[n - 1];
//		}
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution Powell(...):\n" + ex_info);
//	}
//}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji
		solution* P = new solution[mi + lambda];
		solution* Pm = new solution[mi];
		matrix IFF(mi, 1);
		matrix tmp = matrix(N,2);
		double r, s, alfa, beta, S_IFF;
		int min;

		for (int i = 0; i < mi; i++) {
			P[i].x = matrix(N, 2);
			for (int j = 0; j < N; j++) {
				P[i].x(j, 0) = (limits(j, 1) - limits(j, 0)) * m2d(rand_mat()) + limits(j, 0);
				P[i].x(j, 1) = sigma0(j);
			}
			if (P[i].fit_fun(ff, ud1, ud2) < epsilon) {
				Xopt = P[i];
				//delete macierz P i Pm
				delete[] P;
				delete[] Pm;
				return Xopt;
			}
		}
		int iteracja = 0;
		while (true) {
			cout << iteracja++ << endl;
			S_IFF = 0.;

			for (int i = 0; i < mi; i++) {
				IFF(i) = 1. / m2d(P[i].y);
				S_IFF += IFF(i);
			}

			for (int i = 0; i < lambda; i++) {
				//double r = m2d(rand_mat());
				r = S_IFF * m2d(rand_mat());
				s = 0.;

				for (int j = 0; j < mi; j++) {
					s += IFF(j);
					if (r <= s) {
						P[mi + i] = P[j];
						break;
					}
				}
			}

			//mutacja
			for (int i = 0; i < lambda; i++) {
				//double alfa, beta, r; //alfa i beta wzory od N zalezne na tablicy byly
				alfa = pow(2. * N, -0.5);
				//beta = pow(2. * N, -0.25);
				beta = pow(2. * pow(N, 0.5), -0.5);
				r = m2d(rand_mat());
				for (int j = 0; j < N; j++) {
					//P[mi + i].x(j, 1) *= exp(alfa * r + beta * m2d(randn_mat()));
					P[mi + i].x(j, 1) *= exp(beta * r + alfa * m2d(randn_mat()));
					P[mi + i].x(j, 0) += P[mi + i].x(j, 1) * m2d(randn_mat());
				}
			}

			//krzyzowanie
			for (int i = 0; i < lambda; i += 2) {
				r = m2d(rand_mat()); // waga
				tmp = P[mi + i].x;
				P[mi + i].x = r * P[mi + i].x + (1 - r) * P[mi + i + 1].x;
				P[mi + i + 1].x = r * P[mi + i + 1].x + (1 - r) * tmp;
			}

			//warunek stopu
			for (int i = 0; i < lambda; i++) {
				if (P[mi + i].fit_fun(ff, ud1, ud2) < epsilon) {
					Xopt = P[mi + i];
					//delete macierz P i Pm
					delete[] P;
					delete[] Pm;
					return Xopt;
				}
			}

			//wybieranie mi najlepiej przystosowanych osobnikow
			for (int i = 0; i < mi; ++i)
			{
				min = 0;
				for (int j = 1; j < mi + lambda ; ++j) {
					if (P[min].y > P[j].y) {
						min = j;
					}
				}
				Pm[i] = P[min] ;
				P[min].y = 1e10;
			}
			for (int i = 0; i < mi; ++i) {
				P[i] = Pm[i];
			}

			if(solution::f_calls > Nmax) {
				Xopt = P[0];
				break;
			}
		}

		delete[] P;
		delete[] Pm;
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}

//solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		solution Xopt;
//		solution* P = new solution[mi + lambda];
//		solution* Pm = new solution[mi];
//		matrix IFF(mi, 1), temp(N, 2);
//		double r, s, s_IFF;
//		double tau = pow(2 * N, -0.5), tau1 = pow(2 * pow(N, 0.5), -0.5);
//		int j_min;
//		for (int i = 0; i < mi; ++i)
//		{
//			P[i].x = matrix(N, 2);
//			for (int j = 0; j < N; ++j)
//			{
//				P[i].x(j, 0) = (limits(j, 1) - limits(j, 0)) * m2d(rand_mat()) + limits(j, 0);
//				P[i].x(j, 1) = sigma0(j);
//			}
//			if (P[i].fit_fun(ff, ud1, ud2) < epsilon)
//			{
//				Xopt = P[i];
//				Xopt.flag = 0;
//				delete[]P;
//				delete[]Pm;
//				return Xopt;
//			}
//		}
//		while (true)
//		{
//			s_IFF = 0;
//			for (int i = 0; i< mi ; ++i)
//			{
//				IFF(i) = 1 / m2d(P[i].y);
//				s_IFF += IFF(i);
//			}
//			for (int i = 0; i<lambda ; ++i)
//			{
//				r = s_IFF * m2d(rand_mat());
//				s = 0;
//					for (int j = 0; j<mi; ++j)
//					{
//						s += IFF(j);
//						if (r<=s )
//						{
//							P[mi + i] = P[j] ;
//							break;
//						}
//					}
//			}
//			for (int i = 0; i< lambda ; ++i)
//			{
//				r = m2d(rand_mat());
//				for (int j = 0; j < N; ++j)
//				{
//					P[mi + i].x(j, 1) *= exp(tau1 * r +tau *m2d(randn_mat()));
//					P[mi + i].x(j, 0) += P[mi + i].x(j, 1) * m2d(randn_mat());
//				}
//			}
//			for (int i = 0; i< lambda; i += 2)
//			{
//				r = m2d(rand_mat());
//				temp = P[mi+i].x ;
//				P[mi + i].x = r * P[mi+i].x + (1-r) * P[mi+i+1].x;
//				P[mi + i + 1].x = r * P[mi+i+1].x + (1-r) * temp;
//			}
//			for (int i = 0; i < lambda; ++i)
//			{
//				if (P[mi+i].fit_fun(ff,ud1, ud2) < epsilon)
//				{
 
//					Xopt = P[mi+i] ;
//					Xopt.flag = 0;
//					delete[]P;
//					delete[]Pm;
//					return Xopt;
//				}
//			}
//			for (int i = 0; i < mi; ++i)
//			{
//				j_min = 0;
//				for (int j = 1; j < mi + lambda ; ++j)
//					if (P[j_min].y > P[j].y )
//						j_min = j;
//				Pm[i] = P[j_min] ;
//				P[j_min].y = 1e10;
//			}
//			for (int i = 0; i < mi; ++i)
//				P[i] = Pm[i];
//			if (solution::f_calls > Nmax)
//			{
//				Xopt = P[0];
//				Xopt.flag = 1;
//				break;
//			}
//		}
//		delete[]P;
//		delete[]Pm;
//		return Xopt;
//	}
//	catch(string ex_info)
//	{
//		throw ("solution EA(...):\n" + ex_info);
//	}
//}