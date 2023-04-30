//============================================================================
// Name        : AutomatoCelular.cpp
// Author      : Jonathan Amancio
// Description : [2015.12.17] Regra 90: Triangulo de Sierpinski
//               As regras 18, 22, 26, 82, 146, 154, 210 e 218 tambem geram
//               triângulos de Sierpinski.
//               Variacoes: 60, 102, 126, 150, 182.
//============================================================================

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define f 1
#define n 550*f
#define m 254*f+(2*f-1)
using namespace std;

int Bin(int a, int b, int c) {
    int Nbin;

    Nbin = a*pow(2, 2) + b*pow(2, 1) + c*pow(2, 0);
    return Nbin;
}
int main() {
    int r, b;
    int i, w, k; //parametros
    char c, op = '0';

    cout << "***Cellular Automata***" << endl;
//do{
    int regra[8] = {0}, q = 0, d;
    int v[n] = {0}, A[n] = {0};
    int a = (n -(n%2))/2 -1; v[a] = 1;    // *celula central;

    cout << endl << endl << "Digite a regra desejada (0-255): ";
    cin >> r;
    while(r < 0 || r > 255)
    {
        cout << "Regra Invalida!" << endl;
        cout << "Digite a regra desejada (0-255): ";
        cin >> r;
    }
/*
    cout << "Estado inicial aleatorio (s/n): ";
    cin >> c;
    if(c == 's' || c == 'S')
    {
        cout << "Digite a quantidade de celulas aleatorias: ";
        cin >> w;
        while(w < 2 || w > n-1)
        {
            cout << "Quantidade Invalida!" << endl;
            cout << "Digite a quantidade de celulas aleatorias: ";
            cin >> w;
        }
        for(i = 0; i < w; i++)
        {
            k = rand()%n;    //    gera numero aleatorio de 0 a n;
            v[k] = 1;
        }
    }
*/
//================================================
    d = r;
    while(d > 0)
    {
        regra[q] = d%2; q++;
        d = (d -(d%2))/2; // d <- d div 2;
    }

    cout << "\n\tRegra: " << r << ": ";
    for(i = 7; i >= 0; i--)
        {cout << regra[i];}
    cout << endl << endl;
//================================================

ofstream result ("Pontos.txt");

    for(i = 0; i < n; i++)
    {
        if(v[i] == 0)
            {/*cout << "."*/;}
        else
            {result << i << "\t" << 0 << "\n"; /*cout << "#";*/}
    }

    for(k = 0; k < m; k++)
    {
        for(w = 0; w < n; w++)
            {A[w] = v[w];}

        for(i = 0; i < n; i++)
        {
            if(i == 0 || i == (n-1))
            {
                if(i == 0)
                    {b = Bin(A[n-1], A[i], A[i+1]);}
                else
                    {b = Bin(A[i-1], A[i], A[0]);}
            }
            else
                {b = Bin(A[i-1], A[i], A[i+1]);}
            v[i] = regra[b];
        }
        //cout << endl;
        for(i = 0; i < n; i++)
        {
            if(v[i] == 0)
                {/*cout << "."*/;}
            else
                {/*cout << "#";*/ result << i << "\t" << -(k+1) << "\n";}
        }
    }
//================================================
//}while(op == '0');
    return 0;
}
