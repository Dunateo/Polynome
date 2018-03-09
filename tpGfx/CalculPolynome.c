#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "CalculPolynome.h"

poly lecturePoly(chaine nomFichier){

	FILE *f;
	int i;
	poly P;
	f=fopen(nomFichier,"rt");
	if(f == NULL)
		return P;
	printf("fichier ouvert les guys\n");
	fscanf(f,"degre: %d\n",&P.degre);
	fscanf(f,"a: %d\n",&P.a);
  fscanf(f,"b: %d\n",&P.b);
	for(i=0;i<P.degre;i++)
	{
		fscanf(f,"c: %d\n",&(P.Coeff[i]));
	}
	fclose(f);
	return P;
}
void ecritureResultat(chaine nomFichier,tableauvar Premier){

  FILE *f;
	int i;
	f=fopen(nomFichier,"wt");
	if(f == NULL)
		return;
  fprintf(f, "Polynome:\n");
	fprintf(f,"degre: %d\n",Premier.polynome.degre);
	fprintf(f,"domaine de définition: (%d,%d)\n",Premier.polynome.a,Premier.polynome.b);
	for(i=0;i<(Premier.polynome.degre);i++)
	{
		fprintf(f,"c[%d]: %d\n",i,(Premier.polynome.Coeff[i]));
	}
  for (int h = 0; h <(Premier.P.nbpt) ; h++) {
    fprintf(f,"zeros: (%f;%f)\n",h,(Premier.P.Z[h].x),(Premier.P.Z[h].y));
  }
  fprintf(f, "Derivee:\n" );
  fprintf(f,"degre: %d\n",Premier.derivee.degre);
	fprintf(f,"domaine de définition: (%d,%d)\n",Premier.derivee.a,Premier.derivee.b);
  for(j=0;j<(Premier.derivee.degre);j++)
	{
		fprintf(f,"c[%d]: %d\n",j,(Premier.derivee.Coeff[j]));
	}
  for (int f = 0; f <(Premier.D.nbpt) ; f++) {
    fprintf(f,"zeros: (%f;%f)\n",f,(Premier.D.Z[f].x),(Premier.D.Z[f].y));
  }

	fclose(f);
}

point evalpoly(poly polynome){
  point Y;
  for (int j = polynome.a;j<= polynome.b; j++)
  {

  	for (int i = 0; i < polynome.degre; i++)
  	{
  		maj= polynome.Coeff[i]*j^i;
  		y = maj + y;

  	}
  	Y.x[j-polynome.a]=j;
  	Y.y[j-polynome.a]=y;
  }
  return Y;
}

poly deriveePolynome(poly polynome){
  poly derivee;
  derivee.degre = polynome.degre-1;
  for (int i = 0; i < polynome.degre; i++) {
    derivee.Coeff[i-1] = polynome.Coeff[i] * i ;
  }
  derivee.a = polynome.a;
  derivee.b = polynome.b;
  return derivee;
}
