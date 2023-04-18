//===========================================
// Name        : Koch_Cesaro_2019_1.0.cpp
// Author      : Jonathan Amancio
// Description : Cesaro Fractal [31.08.2019]
//				 3 pontos independentes;
//===========================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

float Rad(float angulo) {
	return (angulo*M_PI)/180.0;
}
struct Par {
	float x, y;
};
struct Tripleto {
	float x, y, angle;
};
vector< Tripleto > Quadrado(Par O, float L){
	vector< Tripleto > list;
	float x,y;
	x=O.x-0.5*L; y=O.y+0.5*L; list.push_back( {x,y,0} );
	x=O.x+0.5*L; y=O.y+0.5*L; list.push_back( {x,y,-90} );
	x=O.x+0.5*L; y=O.y-0.5*L; list.push_back( {x,y,-180} );
	x=O.x-0.5*L; y=O.y-0.5*L; list.push_back( {x,y,90} );
	x=O.x-0.5*L; y=O.y+0.5*L; list.push_back( {x,y,0} );
	return list;
}
vector< Tripleto > Triangulo(Par O, float L){
	vector< Tripleto > list;
	float x,y;
	float a=L*sqrt(3)/6.0;
	float h=L*sqrt(3)/2.0;
	x=O.x-0.5*L; y=O.y-a; list.push_back( {x,y,60} );
	x=O.x; y=O.y+h-a; list.push_back( {x,y,-60} );
	x=O.x+0.5*L; y=O.y-a; list.push_back( {x,y,180} );
	x=O.x-0.5*L; y=O.y-a; list.push_back( {x,y,60} );
	return list;
}
void Vetores_gnuplot(vector< Tripleto > list,double l,int iter,double angle) {
	ofstream r;
	char str[30];
	sprintf(str,"T_%03.0f_%02d.txt",angle,iter);
	cout<<str;
	r.open(str, ios::app);
	//r.open(str);
	//r<<"A=\"set arrow from\"\n";
	//r<<"B=\"nohead lw 1 lt 3 lc 'black'\"\n\n";
	for(int i=0; i<list.size()-1; i++)
	{	r<<setprecision(26);
		r<<"Xi="<<list[i  ].x<<"; Yi="<<list[i  ].y<<"\n";
		r<<"Xf="<<list[i+1].x<<"; Yf="<<list[i+1].y<<"\n";
		r<<"@A Xi,Yi to Xf,Yf @B\n";
		r<<"\n";
	}
}
int main(int argc, char* argv[]){
	int n_iter=atoi(argv[1]);
	float teta, h, r;
	float d_angle=atof(argv[2]);
	float alfa=90-d_angle/2.0;

	bool save_all=0;	//0->Salvar apenas a ultima iteracao; 1->Salvar todas;

	vector< Tripleto > new_p;
	vector< Tripleto > old_p;

	struct Tripleto p1, p2, p3;

	float Ox=0, Oy=0, L=3;
	float angle_0=0;

	//new_p.push_back( {Ox,Oy,angle_0} );
	//new_p.push_back( {Ox+L*cos(Rad(angle_0)),Oy+L*sin(Rad(angle_0)),angle_0} );
	new_p=Quadrado({Ox,Oy},L);
	//new_p=Triangulo({Ox,Oy},L);
	if(save_all==1) {Vetores_gnuplot(new_p,r,0,d_angle);}

	for(int i=1; i<=n_iter; i++)
	{	r=L/(2.0*(1+sin(Rad(d_angle/2.0))));
		h=r*cos(Rad(d_angle/2.0));
		//cout<<"L,h,r="<<L<<", "<<h<<", "<<r<<"\n";
		old_p.clear(); old_p=new_p; new_p.clear();

		Ox=old_p[0].x; Oy=old_p[0].y;
		new_p.push_back( {Ox,Oy,old_p[0].angle} );

		for(int j=0; j<old_p.size()-1; j++)
		{	Ox=old_p[j].x; Oy=old_p[j].y;
			teta=Rad(old_p[j].angle);

			p1={ Ox+r*cos(teta), Oy+r*sin(teta), old_p[j].angle+alfa };
			new_p.push_back( {p1.x,p1.y,p1.angle} );

			p2.x=Ox+(L/2.0)*cos(teta)+h*cos(teta+Rad(90));
			p2.y=Oy+(L/2.0)*sin(teta)+h*sin(teta+Rad(90));
			p2.angle=old_p[j].angle-alfa;
			new_p.push_back( {p2.x,p2.y,p2.angle} );

			p3.x=Ox+(L-r)*cos(teta);
			p3.y=Oy+(L-r)*sin(teta);
			p3={ p3.x, p3.y, old_p[j].angle };
			new_p.push_back( {p3.x,p3.y,p3.angle} );

			new_p.push_back( {old_p[j+1].x,old_p[j+1].y,old_p[j+1].angle} );
		}	L=r;
		if(save_all==1) {Vetores_gnuplot(new_p,L,i,d_angle);}
	}	if(save_all==0) {Vetores_gnuplot(new_p,L,n_iter,d_angle);}
	return 0;
}
