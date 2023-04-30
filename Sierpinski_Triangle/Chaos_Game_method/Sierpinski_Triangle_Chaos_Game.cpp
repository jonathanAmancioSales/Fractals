//============================================================================
// Name        : Sierpinski_Triangle_Chaos_Game.cpp
// Author      : Jonathan Amancio
// Description : Triangulo de Sierpinski (Jogo do Caos) [2015/12/17]
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

#define n 2000000
#define r3_2 sqrt(3)/2

double RandomNumber(double Min, double Max) {
    return ((double(rand()) / double(RAND_MAX)) * (Max - Min)) + Min;
}

int main() {
	int v, i;
	long double x[4], y[4], r;
	long double Xnew, Ynew, Xold, Yold;

	srand(time(NULL));

	x[0] = y[0] = 0; x[1] = 1; y[1] = 0; x[2] = 0.5; y[2] = r3_2;

	r = RandomNumber(0, 1);
	x[3] = 1 - r;

	cout << "r = " << r << endl;

	r = RandomNumber(0, 1);
	double t = 1 - r;
	double w = (60*M_PI)/180;

	if(x[3] < 0.5){ y[3] = x[3] * tan(w) * t; }
	else{ y[3] = (1-x[3])*tan(w)*t; }

	Xold = x[3];
	Yold = y[3];

	ofstream result ("Sierpinski_Triangle_pontos.txt");
	for(i = 0; i <= 3; i++)
	{ result << x[i] << "\t" << y[i] << "\n"; }

	for(i = 4; i < n; i++)
	{
		v = rand()%3;

		Xnew = (Xold + x[v])/2;
		Ynew = (Yold + y[v])/2;
		result << setprecision(20) << Xnew << "\t" << Ynew << "\n";

		Xold = Xnew;
		Yold = Ynew;
	}

	return 0;
}
