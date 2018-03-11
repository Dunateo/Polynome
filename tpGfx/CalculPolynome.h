#define DIM 20
#define DIMM 200
typedef char chaine[20];
typedef struct pointt{
	float x,y;
}pointt;
typedef struct var{
	int a, b;
	int forme;
}var;
typedef struct poly{
	int Coeff[DIM];
	float a,b;
	int degre;
}poly;
typedef struct zero{
	pointt Z[DIMM];
	int nbpt;
}zero;
typedef struct tableauvar{
	poly polynome,derivee;
	zero P, D;
	var variation;
}tableauvar;


poly lecturePoly(chaine nomFichier);
void ecritureResultat(chaine nomFichier,tableauvar Premier, zero PointP, zero PointD);
float evalpoly(poly polynome, int i, float x);
poly deriveePolynome(poly polynome);
zero zeroiterative(zero Y , poly polynome);
tableauvar calcultableau(poly polynome,poly derivee, zero P,zero D, zero PointP);
