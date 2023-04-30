//===============================================
// Name        : T-Square.cpp
// Author      : Jonathan Amancio
// Description : T-Square Fractal [2017/07/15];
//===============================================

#include <iostream>
#include <math.h>

#define n_iter 10
#define N  int(pow(4, n_iter-1))    //Numero Total de Pontos;
#define N1 int(pow(4, n_iter-2))

#define Ox 0
#define Oy 0
#define LADO 1

int t = 1;

using namespace std;

struct pt {
    double x;
    double y;
};
void Box(struct pt O, float L) {
    struct pt i = {O.x-0.5*L, O.y-0.5*L};
    struct pt f = {O.x+0.5*L, O.y+0.5*L};

    if( ((O.x>Ox-0.5*LADO) & (O.x<Ox+0.5*LADO)) & ((O.y>Oy-0.5*LADO) & (O.y<Ox+0.5*LADO)) )
    {   if(t==1)
        {   cout<< "@A "<<t<<" @B "<<i.x<<","<<i.y;
            cout<<" to "<<f.x<<","<<f.y<<" @C\n";
            t++;
        }
    }
    else
    {   cout<< "@A "<<t<<" @B "<<i.x<<","<<i.y;
        cout<<" to "<<f.x<<","<<f.y<<" @C\n";
        t++;
    }
}
void Pontos(struct pt V[], struct pt O, float L, int i) {
    float D = 0.5*L;
    V[i  ].x = O.x-D; V[i  ].y = O.y-D;  //inf_esq
    V[i+1].x = O.x-D; V[i+1].y = O.y+D;  //sup_esq
    V[i+2].x = O.x+D; V[i+2].y = O.y-D;  //inf_dir
    V[i+3].x = O.x+D; V[i+3].y = O.y+D;  //sup_dir
}
int main() {
    struct pt V[N];
    struct pt Aux[N1];

    struct pt Origem = {Ox, Oy};
    float lado = LADO;
    int i = 0;
    int p;
    Aux[0] = Origem;

    for(p=0;p<N1;p++)
    {Aux[p].x=0; Aux[p].y=0;}
    for(p=0;p<N;p++)
    {V[p].x=0; V[p].y=0;}

    cout<<"d="<<LADO<<"\n";
    cout<<"set xr[-d:d]\nset yr[-d:d]\n";
    Box(Origem, lado);

    for(int k=2; k<=n_iter; k++)
    {    for(int j=0; j<pow(4,k-2); j++)
        {    Pontos(V, Aux[j], lado, i);
            for(p=0;p<4;p++)
            {Box(V[i+p], lado/2);}
            i+=4;
        }   i=0; lado=lado/2;
        for(p=0;p<N1;p++)
        {Aux[p]=V[p];}
    }
    return 0;
}
