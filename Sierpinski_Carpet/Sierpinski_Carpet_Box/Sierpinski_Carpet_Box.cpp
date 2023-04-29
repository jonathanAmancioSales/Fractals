//=========================================================
// Name        : Sierpinski_Carpet_Box.cpp
// Author      : Jonathan Amancio
// Description : Carpete de Sierpinsk (box) [25-26.08.2019]
//=========================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

struct Par {
	float x, y;
};
float Rad(float angulo) {
	return (angulo*M_PI)/180.0;
}
void Box_gnuplot(vector< Par > list, float l, int i) {
	ofstream r;
	char str[30];
	sprintf(str,"T_%02d.txt",i);
	r.open(str, ios::app);

	r<<setprecision(8)<<"L="<<l<<"\n";
	for(int j=0; j<list.size(); j++)
	{	r<<"Ox="<<list[j].x<<"; Oy="<<list[j].y<<"\n";
		r<<"@A Ox,Oy @B L,L @C\n\n";
	}
}
int main(int argc, char* argv[]){
	int n_iter=atoi(argv[1]);
	float r, teta;

	vector< Par > new_p;
	vector< Par > old_p;

	float Ox=0, Oy=0, L=3;
	new_p.push_back( {Ox,Oy} );

	L=L/3.0; Box_gnuplot(new_p,L,n_iter);

	for(int i=2; i<=n_iter; i++)
	{
		old_p.clear(); old_p=new_p; new_p.clear();
		for(int j=0; j<old_p.size(); j++)
		{	Ox=old_p[j].x; Oy=old_p[j].y;
			for(int k=0; k<4; k++)
			{	r=L; teta=Rad(k*90);
				new_p.push_back( { Ox+r*cos(teta), Oy+r*sin(teta) } );
			}
			for(int k=0; k<4; k++)
			{	r=L*sqrt(2); teta=Rad(k*90+45);
				new_p.push_back( { Ox+r*cos(teta), Oy+r*sin(teta) } );
			}
		}	L=L/3.0; Box_gnuplot(new_p,L,n_iter);
	}
	return 0;
}
