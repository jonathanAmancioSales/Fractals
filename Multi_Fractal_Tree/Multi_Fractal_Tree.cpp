//========================================================================
// Name        : Multi_Fractal_Tree.cpp
// Author      : Jonathan Amancio
// Description : [28,29.08.2019] {Iteracao, Angulo e Numero de ramos}
//========================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

struct Tripleto {
	float x, y, rad;
};
float Angulo_Rad(float angulo) {
	return (angulo*M_PI)/180.0;
}
void Circles_gnuplot(vector< Tripleto > list, float l, int i,float angle, int n_ramos) {
	ofstream r;
	char str[30];
	sprintf(str,"T_%03.0f_%02d_%02d.txt",angle,n_ramos,i);
	r.open(str, ios::app);

	r<<setprecision(12)<<"L="<<l/7.0<<"\n";
	//r<<setprecision(12)<<"L="<<l/5.0<<"\n";
	for(int j=0; j<list.size(); j++)
	{	r<<"Ox="<<list[j].x<<"; Oy="<<list[j].y<<"\n";
		r<<"@A Ox,Oy @B L,L @C\n\n";
	}
}
void Vetores_gnuplot(vector< Tripleto > list_i,vector< Tripleto > list_f,float l,int iter,float angle,int n_ramos) {
	ofstream r;
	char str[30];
	sprintf(str,"T_%03.0f_%02d_%02d.txt",angle,n_ramos,iter);
	r.open(str, ios::app);

	//r<<"A=\"set arrow from\"\n";
	//r<<"B=\"nohead lw 1 lt 3 lc 'black'\"\n\n";
	for(int i=0; i<list_i.size(); i++)
	{	r<<"Xi="<<list_i[i].x<<"; Yi="<<list_i[i].y<<"\n";
		for(int j=0; j<n_ramos; j++)
		{	r<<"Xf="<<list_f[n_ramos*i+j].x<<"; Yf="<<list_f[n_ramos*i+j].y<<"\n";
			r<<"@A Xi,Yi to Xf,Yf @B\n";
		}	r<<"\n";
	}
}
int main(int argc, char* argv[]){
	int n_iter =atoi(argv[1]);
	float angle=atof(argv[2]);
	int n_ramos=atoi(argv[3]);
	float r, teta;

	vector< Tripleto > new_p;
	vector< Tripleto > old_p;

	bool OP=0;	//0 -> Vetores; 1 -> Circles;
	float Ox=0, Oy=0, L=1, angle_0=90;
	new_p.push_back( {Ox,Oy,Angulo_Rad(angle_0)} );
	if(OP==1) { Circles_gnuplot(new_p,L*sqrt(3)/3.0,n_iter,angle,n_ramos); }

	for(int i=1; i<=n_iter; i++)
	{	old_p.clear(); old_p=new_p; new_p.clear();
		r=L*sqrt(3)/6.0;
		for(int j=0; j<old_p.size(); j++)
		{	Ox=old_p[j].x; Oy=old_p[j].y;
			angle_0 = old_p[j].rad;

			if((n_ramos%2)!=0)
			{	teta=angle_0;
				new_p.push_back( {Ox+r*cos(teta),Oy+r*sin(teta),teta} );
			}
			for(int k=1; k<=int(n_ramos/2); k++)
			{	teta=angle_0+Angulo_Rad(k*angle);
				new_p.push_back( {Ox+r*cos(teta),Oy+r*sin(teta),teta} );
				teta=angle_0-Angulo_Rad(k*angle);
				new_p.push_back( {Ox+r*cos(teta),Oy+r*sin(teta),teta} );
			}
		}	L=0.5*L;
		if(OP==0) { Vetores_gnuplot(old_p,new_p,L,n_iter,angle,n_ramos); }
		if(OP==1) { Circles_gnuplot(new_p,r,n_iter,angle,n_ramos); }
	}	return 0;
}
