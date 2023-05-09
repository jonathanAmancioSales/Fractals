//============================================================================
// Name        : Samambaia_Fractal.cpp
// Author      : Jonathan Amancio
// Description : Samambaia Fractal [2016.03.08]
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

#define N 3500000
double xnew, ynew;

void Folha(double x, double y, int op);
void Script();

double RandomNumber(double Min, double Max) {
    return ((double(rand()) / double(RAND_MAX)) * (Max - Min)) + Min;
}
void F1(double x, double y) {
    xnew = 0;
    ynew = 0.16*y;
    Folha(xnew, ynew, 1);
}
void F2(double x, double y) {
    xnew = 0.2*x - 0.26*y;
    ynew = 0.23*x + 0.22*y + 1.6;
    Folha(xnew, ynew, 2);
}
void F3(double x, double y) {
    xnew = -0.15*x + 0.28*y;
    ynew = 0.26*x + 0.24*y + 0.44;
    Folha(xnew, ynew, 3);
}
void F4(double x, double y) {
    xnew = 0.85*x + 0.04*y;
    ynew = -0.004*x + 0.85*y + 1.6;
    Folha(xnew, ynew, 4);
}
void Samambaia_Fractal() {
    srand(time(NULL));
    Folha(0, 0.1, 1);

    for(int i=0; i<=N; i++)
    {   double r = RandomNumber(0,1);
        if( r < 0.15)
        {   if( r < 0.01)
            { F1(xnew, ynew); }
            else
            {   if(r < 0.07)
                { F2(xnew, ynew); }
                else
                { F3(xnew, ynew); }
            }
        }   else { F4(xnew, ynew); }
    }
}
int main() {
    Samambaia_Fractal();
    return 0;
}
void Folha(double x, double y, int op) {
    if(op == 1){
        FILE *r1;
        r1 = fopen("Folha_1.txt", "a");
        fprintf(r1, "%.20f\t%.20f\n", x, y);
        fclose(r1);
    }
    if(op == 2){
        FILE *r2;
        r2 = fopen("Folha_2.txt", "a");
        fprintf(r2, "%.20f\t%.20f\n", x, y);
        fclose(r2);
    }
    if(op == 3){
        FILE *r3;
        r3 = fopen("Folha_3.txt", "a");
        fprintf(r3, "%.20f\t%.20f\n", x, y);
        fclose(r3);
    }
    if(op == 4){
        FILE *r4;
        r4 = fopen("Folha_4.txt", "a");
        fprintf(r4, "%.20f\t%.20f\n", x, y);
        fclose(r4);
    }
}
