#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "CalculPolynome.h"

poly lecturePoly(chaine nomFichier){

	FILE *f;
	int i;
	poly P;
	f=fopen(nomFichier,"rt");
	if(f == NULL)
		return P;
	printf("fichier ouvert les guys\n");
	fscanf(f,"degre: %d\n",&(P.degre));
	fscanf(f,"xmin: %f\n",&P.a);
  fscanf(f,"xmax: %f\n",&P.b);
	fscanf(f,"ymin: %f\n",&P.c);
  fscanf(f,"ymax: %f\n",&P.d);
	for(i=0;i<(P.degre+1);i++)
	{
		fscanf(f,"c:%d\n",&(P.Coeff[i]));
	}
	fclose(f);
	return P;
}
void ecritureResultat(chaine nomFichier,tableauvar Premier, zero PointP, zero PointD){

  FILE *f;
	int i;
	f=fopen(nomFichier,"wt");
	if(f == NULL)
		return;
  fprintf(f, "Polynome:\n");
	fprintf(f,"degre: %d\n",Premier.polynome.degre);
	fprintf(f,"domaine de définition: (%.2f,%.2f)\n",Premier.polynome.a,Premier.polynome.b);
	for(i=0;i<(Premier.polynome.degre+1);i++)
	{
		fprintf(f,"c[%d]: %d\n",i,(Premier.polynome.Coeff[i]));
	}
  for (int h = 0; h <(Premier.P.nbpt) ; h++) {
    fprintf(f,"zeros: (%.2f",(Premier.P.Z[h].x));
		fprintf(f, ";%.2f)\n",(Premier.P.Z[h].y));
  }
	fprintf(f,"Les vingts points du polynome:\n");
	for (int g = 0; g<(PointP.nbpt) ; g++) {
    fprintf(f,"(%.2f",(PointP.Z[g].x));
		fprintf(f, ";%.2f)\n",(PointP.Z[g].y));
  }

  fprintf(f, "\nDerivee:\n" );
  fprintf(f,"degre: %d\n",Premier.derivee.degre);
	fprintf(f,"domaine de définition: (%.2f,%.2f)\n",Premier.derivee.a,Premier.derivee.b);
  for(int j=0;j<(Premier.derivee.degre+1);j++)
	{
		fprintf(f,"c[%d]: %d\n",j,(Premier.derivee.Coeff[j]));
	}
  for (int e = 0; e <(Premier.D.nbpt) ; e++) {
    fprintf(f,"zeros: (%.2f;",(Premier.D.Z[e].x));
		fprintf(f,"%.2f)\n",(Premier.D.Z[e].y));
  }
	fprintf(f,"Les vingts points de la derivee:\n");
	for (int ga = 0; ga<(PointD.nbpt) ; ga++) {
    fprintf(f,"(%.2f",(PointD.Z[ga].x));
		fprintf(f, ";%.2f)\n",(PointD.Z[ga].y));
  }

	if(Premier.variation.forme == 1){
		fprintf(f, "\nvariation: croissante sur l'intervalle\n" );
	}
	if(Premier.variation.forme == 0){
		fprintf(f, "\nvariation: decroissante sur l'intervalle\n" );
	}

	fclose(f);
}

float evalpoly(poly polynome, int i, float x){
	float y;
  if(i == 0){
		y = polynome.Coeff[i];
	}
	else{
		y = polynome.Coeff[i]*pow(x,i)+evalpoly(polynome,i-1,x);
	}

  return y;
}

poly deriveePolynome(poly polynome){
  poly derivee;
  derivee.degre = polynome.degre-1;
  for (int i = 0; i < polynome.degre+1; i++) {
    derivee.Coeff[i-1] = polynome.Coeff[i] * i ;
  }
  derivee.a = polynome.a;
  derivee.b = polynome.b;
  return derivee;
}
zero zeroiterative(zero Y , poly polynome){
	zero Zeros;
	int j =0;
	for (int i = 0; i < Y.nbpt; i++) {
		if(Y.Z[i].y == 0){
			Zeros.Z[j].y = Y.Z[i].y;
			Zeros.Z[j].x = Y.Z[i].x;
			j = j+1;
			Zeros.nbpt=1+Zeros.nbpt;
		}

  if(Y.Z[i].y*Y.Z[i+1].y < 0){

		Zeros.Z[j].y=0;
		Zeros.Z[j].x=Y.Z[i].x+0.5;
		Zeros.nbpt=1+Zeros.nbpt;
		j = j+1;

  }

}

return Zeros;
}
//zero zerorecursive(){

//}
tableauvar calcultableau(poly polynome,poly derivee, zero P,zero D, zero PointP){

	tableauvar un;
	un.polynome = polynome;
	un.derivee = derivee;
	un.P = P;
	un.D = D;
	if(PointP.Z[0].y>0){
		un.variation.a = PointP.Z[0].x;
		un.variation.b = un.P.Z[0].x;
		un.variation.forme = 1;
	}
	if(PointP.Z[0].y<0){
		un.variation.a = PointP.Z[0].x;
		un.variation.b = un.P.Z[0].x;
		un.variation.forme = 0;
	}


return un;
}
