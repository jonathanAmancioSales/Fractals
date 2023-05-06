//==================================================================================
// Name        : Triangulo_Pascal.cpp
// Author      : Jonathan Amancio
// Description : Triangulo de Pascal II - o numero N digitado corresponde a linha
//               dos coefc. do binomio de Newton elevado a N; [2015/12/17]
//==================================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int i, j, N, d;
    int div = 5;    // exibir divisiveis por div;

    cout << "***Triangulo de Pascal***" << endl;
    cout << "Obs: o numero N digitado corresponde a linha dos coefc. do binomio de Newton elevado a N." << endl;
    cout << "Digite um numero: ";
    cin >> d;
    //d = 7;

    while(d < 0)
    {   cout << "O numero deve ser nao-negativo!" << endl;
        cout << "Digite um numero (N >= 0): ";
        cin >> d;
    }

    N = d + 1;

    //float P[N + 1][N + 1];        // so funciona ate 87. // bom ate 22.
    long long int P[N + 1][N + 1];

    for(i=0; i<=N; i++)
    {   for(j=0; j<=N; j++)
        {P[i][j] = 0;}
    }

    for(i=1; i<=N; i++)        //original: for(i=1; i<=N+1; i++)
    {P[i][1] = 1; P[i][i] = 1;}

    if(N > 2)
    {   for(i=3; i<=N; i++)
        {
            for(j = 2; j < i; j++)
            { P[i][j] = P[i-1][j-1] + P[i-1][j]; }
        }
    }

/*  // print:
    for(i=1; i<=N; i++)
    {   for(j=1; j<=i; j++)
        { cout << P[i][j] << "  "; }
        cout << endl;
    }
    for(i=1; i<=N; i++)
    {    for(j=1; j<=i; j++)
        {    if(P[i][j]%2 == 0)
            { cout << ". "; }
            else {  cout << "# "; }
        }    cout << endl;
    }
*/

    ofstream result;
    char data[30];
    sprintf(data,"Pontos[%d][%d].txt", div, d);
    result.open(data);

    result << "#"<<d<<" div-> "<<div<<"\n";
    //result << "#reset\n";
    //result << "set nokey\n";
    //result << "p \"-\" lc 3 pt 9 ps 0.5\n";

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
