#include "NeldearMead.h"

double NeldearMead::Fuction(Polyhedron x) {
	symbol_table_t symbol_table;
	for (int i = 0; i < size; i++) {
		symbol_table.add_variable(string("x" + to_string(i+1)), x.j[i]);
	}
	expression_t expression;
	expression.register_symbol_table(symbol_table);
	parser_t parser;
	if (!parser.compile(function, expression))
	{
		throw gcnew System::Exception("Не корректный ввод функции!");
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

void NeldearMead::Method() {
		Max();
		Min();
		Center();
		Reflection();
		if (Fuction(x[size + 3]) <= Fuction(x[xl])) {
			Stretching();
			if (Fuction(x[size + 4]) < Fuction(x[xl])) {
				ChangeH(size + 4);
			}
			else {
				ChangeH((size + 3));
			}
		}
		else {
			if (Fuction(x[size + 3]) > Fuction(x[xg])) {
				if (Fuction(x[size + 3]) > Fuction(x[xh])) {
					Compression();
					if (Fuction(x[size + 5]) > Fuction(x[xh])) {
						Reduction();
					}
					else {
						ChangeH((size + 5));
					}
				}
				else {
					ChangeH((size + 3));
				}
			}
			else {
				ChangeH((size + 3));
			}
		}
		iter++;
}