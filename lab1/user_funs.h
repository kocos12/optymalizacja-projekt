#pragma once

#include"ode_solver.h"

matrix f1(matrix x, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);
matrix df1(double t, matrix Y, matrix ud1, matrix ud2);
matrix f2(matrix x, matrix ud1, matrix ud2);