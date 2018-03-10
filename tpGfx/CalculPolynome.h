#define DIM 20
#define DIMM 200
typedef struct point{
	float x,y;
}point;
typedef struct poly{
	int Coeff[DIM];
	int degre,a,b;
}poly;
typedef struct zero{
	point Z[DIMM];
	int nbpt;
}xzero;
typedef struct tableauvar{
	poly polynome,derivee;
	zero P, D;
	var Variation[DIMM];
}tableauvar;
typedef struct var{
	int a, b;
	int forme;
}var;

poly lecturePoly(chaine nomFichier);
void ecritureResultat(chaine nomFichier,tableauvar Premier);
zero evalpoly(poly polynome);
poly deriveePolynome(poly polynome);
zero zeroiterative(zero Y);
tableauvar calcultableau(tableauvar Premier);
