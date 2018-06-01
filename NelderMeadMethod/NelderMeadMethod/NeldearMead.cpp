#include "NeldearMead.h"

double NeldearMead::Fuction(Polyhedron x) {
	symbol_table_t symbol_table;
	for (int i = 0; i < size; i++) {
		symbol_table.add_variable(string("x" + to_string(i)), x.j[i]);
	}
	expression_t expression;
	expression.register_symbol_table(symbol_table);
	parser_t parser;
	if (!parser.compile(function, expression))
	{
		printf("Compilation error...\n");
		system("pause");
	}
	return static_cast<double>(expression.value());
}

void NeldearMead::Max() {
	xh = 0;
	double fxmax = Fuction(x[xh]);
	for (int i = 1; i <= size; i++) {
		if (fxmax <	Fuction(x[i])) {
			fxmax = Fuction(x[i]);
			xh = i;
		}
	}
	xg = 0;
	double fxg = Fuction(x[xg]);
	for (int i = 1; i <= size; i++) {
		if (fxg < Fuction(x[i]) && i != xh) {
			fxg = Fuction(x[i]);
			xg = i;
		}
	}
}


void NeldearMead::Min() {
	xl = 0;
	double fxmin = Fuction(x[xl]);
	for (int i = 1; i <= size; i++) {
		if (fxmin > Fuction(x[i])) {
			fxmin = Fuction(x[i]);
			xl = i;
		}
	}
}

void NeldearMead::Center() {
	for (int i = 0; i < size; i++) {
		double summ = 0;
		for (int k = 0; k <= size; k++) {
			summ += x[k].j[i];
		}
		x[size + 2].j[i] = double(1) / size*(summ - x[xh].j[i]);
	}
}

void NeldearMead::Reflection() {
	for (int i = 0; i < size; i++) {
		x[size + 3].j[i] = x[size + 2].j[i] + alpha*(x[size + 2].j[i] - x[xh].j[i]);
	};
}

void NeldearMead::Stretching() {
	for (int i = 0; i < size; i++) {
		x[size + 4].j[i] = x[size + 2].j[i] + gamma*(x[size + 3].j[i] - x[size + 2].j[i]);
	};
}

void NeldearMead::Compression() {
	for (int i = 0; i < size; i++) {
		x[size + 5].j[i] = x[size + 2].j[i] + betha*(x[xh].j[i] - x[size + 2].j[i]);
	};
}

void NeldearMead::Reduction() {
	for (int k = 0; k <= size; k++) {
		for (int i = 0; i < size; i++) {
			x[k].j[i] = x[xl].j[i] + 0.5*(x[k].j[i] - x[xl].j[i]);
		}
	}
}

double NeldearMead::Epsilon() {
	double summ = 0;
	double sum = 0;
	for (int k = 0; k <= size; k++) {
		sum += NeldearMead::Fuction(x[k]) / size;
	}
	for (int k = 0; k <= size; k++) {
		//summ += pow(Neldermead::Fuction(x[k])-Neldermead::Fuction(x[size + 2]),2);
		summ += pow(NeldearMead::Fuction(x[k]) - sum, 2) / size;
	}
	return sqrt(summ);
}

void NeldearMead::ChangeH(int k) {
	for (int i = 0; i < size; i++) {
		x[xh].j[i] = x[k].j[i];
	}
}
