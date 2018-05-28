#pragma once

#include <string>
#include "exprtk.hpp"

typedef double T; // numeric type (float, double, mpfr etc...)

typedef exprtk::symbol_table<T> symbol_table_t;
typedef exprtk::expression<T>     expression_t;
typedef exprtk::parser<T>             parser_t;
using namespace std;

struct Polyhedron {
	double *j;
};

class NeldearMead {
public:
	int size;
	string function;
	Polyhedron *x;
	int xh;
	int xg;
	int xl;
	double alpha;
	double betha;
	double gamma;
	double tol;
	double Epsilon();
	double Fuction(Polyhedron x);
	void Max();
	void Min();
	void Center();
	void Reflection();
	void Stretching();
	void Compression();
	void Reduction();
	void ChangeH(int k);
};
