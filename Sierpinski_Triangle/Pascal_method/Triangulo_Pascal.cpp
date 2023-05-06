//==================================================================================
// Name        : Triangulo_Pascal.cpp
// Author      : Jonathan Amancio
// Description : Triangulo de Pascal II - o numero N corresponde a linha
//               dos coefc. do binomio de Newton elevado a N; [2015/12/17]
//==================================================================================

#include <iostream>
#include <fstream>

// exibir divisiveis por div:
#define div 4
#define D 767

using namespace std;


int main() {
    int i, j, N;
    cout << "***Triangulo de Pascal***" << endl;

    N = D + 1;
    //float P[N + 1][N + 1];
    long long int P[N + 1][N + 1];

    for(i=0; i<=N; i++)
    {   for(j=0; j<=N; j++)
        {P[i][j] = 0;}
    }

    for(i=1; i<=N; i++)
    {P[i][1] = 1; P[i][i] = 1;}

    if(N > 2)
    {   for(i=3; i<=N; i++)
        {
            for(j = 2; j < i; j++)
            { P[i][j] = P[i-1][j-1] + P[i-1][j]; }
        }
    }

    ofstream result;
    char data[30];
    sprintf(data,"Pontos[%d][%d].txt", div, D);
    result.open(data);

    result << "#D="<<D<<"; div="<<div<<"\n";
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=i; j++)
        {   if(P[i][j]%div == 0) {}
            else { result << (j-1)-0.5*(i-1) << "\t" << -(i-1)<< "\n"; }
        }
    }
    result.close();
    return 0;
}
