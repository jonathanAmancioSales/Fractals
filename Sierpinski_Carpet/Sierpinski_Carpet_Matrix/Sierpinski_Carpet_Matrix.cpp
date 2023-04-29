//=========================================================
// Name        : Sierpinski_Carpet_Matrix.cpp
// Author      : Jonathan Amancio
// Description : Carpet de Sierpinsk [Matriz method] (2017/06/13);
//=========================================================

#include <iostream>
#include <math.h>

#define n_iter 6
#define N 729

using namespace std;

void Preencher(double M[][N], double w) {
    for(int i=0; i<N; i++)
    {   for(int j=0; j<N; j++)
        { M[i][j]=w; }
    }
}
void Exibir(double M[][N]) {
    for(int i=N-1; i>=0; i--)
    {   for(int j=0; j<N; j++)
        { cout << M[i][j] << " "; }
        cout << endl;
    }
}
void Zerar_Meio(double M[][N], int i_min, int i_max, int j_min, int j_max) {
    for(int i=i_min; i<i_max; i++)
    {   for(int j=j_min; j<j_max; j++)
        { M[i][j]=0; }
    }
}
int main() {
    double M[N][N] = {0};
    int n, n2;

    Preencher(M, 1);

    n = pow(3,n_iter-1);
    Zerar_Meio(M, n, 2*n, n, 2*n);

    for(int k=2; k<=n_iter; k++)
    {
        n2 = pow(3, n_iter-k);
        for(int i=0; i<pow(3,(k-1)); i++)
        {   for(int j=0; j<pow(3,(k-1)); j++)
            { Zerar_Meio(M, i*n+n2, i*n+2*n2, j*n+n2, j*n+2*n2); }
        }
		n = n2;
    }
    Exibir(M);

    return 0;
}
