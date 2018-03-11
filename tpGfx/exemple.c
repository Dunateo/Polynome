#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "CalculPolynome.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1080
#define HauteurFenetre 880

// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);

	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);

	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();

	return 0;
}



/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;

	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}

}


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	static chaine ch;
	static poly polynome;
	static poly derivee;
	static zero PointP;
	static zero PointD;
	static zero P;
	static zero D;
	static tableauvar Premier;
	static float x,x2;
	static int i,i2;
	static int j = 0;
	static int l = 0;
	PointP.nbpt = 0;

	/* On va aussi animer une balle traversant l'ecran */


	switch (evenement)
	{
		case Initialisation:

		strcpy(ch,"texte/polynome.txt");
		polynome = lecturePoly(ch);
		printf("test reussi\n" );
		x = polynome.a;
		i = polynome.degre;
		derivee = deriveePolynome(polynome);
		i2 = derivee.degre;
		x2 = derivee.a;
		printf("test reussi1\n" );
		while(j<20){

		PointP.Z[j].y = evalpoly( polynome,i,x);
		PointP.Z[j].x = x;
		x = x+(polynome.b-polynome.a)/20;
		PointP.nbpt =PointP.nbpt+1;
		j++;
	}
	while(l<20){

	PointD.Z[l].y = evalpoly(derivee,i2,x2);
	PointD.Z[l].x = x2;
	x2 = x2+(derivee.b-derivee.a)/20;
	PointD.nbpt =PointD.nbpt+1;
	l++;
}
		printf("test reussi2\n" );
		P = zeroiterative( PointP, polynome);
		printf("test reussi3\n" );
		D = zeroiterative( PointD, derivee);
		printf("test reussi4\n" );
		Premier = calcultableau( polynome, derivee,  P, D, PointP);
		printf("test reussi5\n" );
		ecritureResultat("texte/resultat.txt",Premier, PointP, PointD);



			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;

		case Temporisation:



			rafraichisFenetre();
			break;

		case Affichage:

			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);






		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;

		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:

			break;

		case Souris: // Si la souris est deplacee
			break;

		case Inactivite: // Quand aucun message n'est disponible
			break;

		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran

			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}
