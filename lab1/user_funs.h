#pragma once

#include"ode_solver.h"


matrix f1(matrix x, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);
matrix df1(double t, matrix Y, matrix ud1, matrix ud2);

matrix f2(matrix x, matrix ud1, matrix ud2);
matrix fR_lab2(matrix x, matrix ud1, matrix ud2);
matrix df_lab2(double t, matrix Y, matrix ud1, matrix ud2);

matrix f3(matrix x, matrix ud1, matrix ud2);
matrix df3(double t, matrix y, matrix ud1, matrix ud2);
matrix fTa(matrix x, matrix ud1, matrix ud2);
matrix fR3(matrix x, matrix ud1, matrix ud2);
double obliczOdleglosc(double x, double y, double z);


matrix f4(matrix x, matrix ud1, matrix = NAN);
matrix gf1(matrix x, matrix ud1, matrix ud2);
matrix Hf(matrix x, matrix ud1, matrix ud2);
matrix fR4(matrix x, matrix ud1, matrix ud2);
matrix gfR1(matrix x, matrix ud1, matrix ud2);

matrix g1(matrix x);
matrix g2(matrix x);
matrix g3(matrix x,  double a);

matrix ff5R(matrix x, matrix ud1, matrix ud2);

double zewS(matrix x);
double wewS(matrix x);

matrix f51(double a, matrix x, matrix ud1, matrix = NAN);
matrix f52(double a, matrix x, matrix ud1, matrix = NAN);
matrix f5(matrix x, matrix ud1, matrix ud2);


matrix df6(double t, matrix Y, matrix ud1, matrix ud2);
matrix fR6(matrix x, matrix ud1, matrix ud2);