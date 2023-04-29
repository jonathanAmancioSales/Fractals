//============================================================================
// Name        : Sierpinski_Triangle.cpp
// Author      : Jonathan Amancio
// Description : Triangulo de Sierpinsk - Remove Triangles method [22.08.2019]
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

float Angulo_Rad(float angulo) {
	return (angulo*M_PI)/180.0;
}
void Triangulo_gnuplot(vector< pair <float,float> > list, float l, int i) {
	ofstream r;
	char str[50];
	sprintf(str,"T_%02d.txt",i);
	r.open(str);

	r<<"L="<<l<<"\n";
	r<<"h=L*sqrt(3)/2.0\n";
	r<<"a=L*sqrt(3)/6.0\n\n";

	r<<"S1=\"set object\"\n";
	r<<"S2=\"polygon from\"\n";
	r<<"S3=\"fc rgb 'black' fillstyle solid noborder\"\n\n";

	for(int j=0; j<list.size(); j++)
	{	r<<"Ox="<<list[j].first<<"; Oy="<<list[j].second<<"; j="<<j+1<<"\n";
		r<<"@S1 j @S2 Ox,Oy+h-a to Ox-0.5*L,Oy-a to Ox+0.5*L,Oy-a to Ox,Oy+h-a\n";
		r<<"@S1 j @S3\n\n";
	}
}
int main(){
	int n_iter=11;
	float r, teta;

	vector< pair <float,float> > new_p;
	vector< pair <float,float> > old_p;

	float Ox=0, Oy=0, L=1;
	new_p.push_back( make_pair(Ox,Oy) );

	Triangulo_gnuplot(new_p,L,0);

	for(int i=1; i<=n_iter; i++)
	{	r=L*sqrt(3)/6.0;
		old_p.clear();
		old_p=new_p;
		new_p.clear();
		for(int j=0; j<old_p.size(); j++)
		{	Ox=old_p[j].first;
			Oy=old_p[j].second;
			teta =Angulo_Rad(90);  new_p.push_back( make_pair(Ox+r*cos(teta),Oy+r*sin(teta)) );
			teta+=Angulo_Rad(120); new_p.push_back( make_pair(Ox+r*cos(teta),Oy+r*sin(teta)) );
			teta+=Angulo_Rad(120); new_p.push_back( make_pair(Ox+r*cos(teta),Oy+r*sin(teta)) );
		}	L=0.5*L;
		Triangulo_gnuplot(new_p,L,i);
	}
	return 0;
}
