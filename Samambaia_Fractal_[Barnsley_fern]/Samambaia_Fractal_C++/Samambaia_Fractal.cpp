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
    Folha(xnew, ynew, 1);
}
void F3(double x, double y) {
    xnew = -0.15*x + 0.28*y;
    ynew = 0.26*x + 0.24*y + 0.44;
    Folha(xnew, ynew, 1);
}
void F4(double x, double y) {
    xnew = 0.85*x + 0.04*y;
    //ynew = -0.04*x + 0.85*y + 1.6;  // Original
    ynew = -0.004*x + 0.85*y + 1.6; // Folhas mais alongada
    Folha(xnew, ynew, 1);
}
void Samambaia_Fractal() {
    srand(time(NULL));
    Folha(0, 0.1, 0);

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
    FILE *r;
    r = fopen("Folha.txt", "a");
    if(op == 0)
    {   fprintf(r, "reset\n");
        //----------------------------------------------
        //fprintf(r, "set title \"Samambaia_Fractal\"\n");
        //fprintf(r, "set nokey\n");
        //fprintf(r, "set xl \"X\"\n");
        //fprintf(r, "set yl \"Y\"\n");
        //----------------------------------------------
        fprintf(r, "set term png size 5000,3750 notransparent\n");
        fprintf(r, "file_out='Folha.png'; set output file_out\n");
        fprintf(r, "unset tics; unset border; unset key\n");
        fprintf(r, "set lmargin 0; set tmargin 0; set rmargin 0; set bmargin 0\n");
        //----------------------------------------------
        fprintf(r, "p[-8.2:8.2][-0:10.8] '-' pt 7 ps 0.1 lc 2\n");
    }
    fprintf(r, "%.20f\t%.20f\n", x, y);
    fclose(r);
}
