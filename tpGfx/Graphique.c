#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "CalculPolynome.h"

void affichageGraphique(tableauvar Premier){
  couleurCourante(50,50,50);
  epaisseurDeTrait(3);
  ligne((0+(0-Premier.polynome.a)*largeurFenetre())/(Premier.polynome.b-Premier.polynome.a),hauteurFenetre()/2,(0+(0-Premier.polynome.a)*largeurFenetre())/(Premier.polynome.b-Premier.polynome.a),hauteurFenetre());
  ligne(0,hauteurFenetre()/2+(0-Premier.polynome.c)*((hauteurFenetre()/2))/(Premier.polynome.d-Premier.polynome.c),largeurFenetre(),hauteurFenetre()/2+(0-Premier.polynome.c)*(hauteurFenetre()/2)/(Premier.polynome.d-Premier.polynome.c));

}

void affichageTableau(tableauvar Premier){
  char nb[5];
  char nb1[5];
  couleurCourante(50,50,50);
  rectangle(0,0,largeurFenetre(),hauteurFenetre()/2);
  couleurCourante(255,255,255);
  rectangle(largeurFenetre()/6,0,largeurFenetre(),hauteurFenetre()/3);
  epaisseurDeTrait(3);
  afficheChaine("x", 20, largeurFenetre()/9, 7*hauteurFenetre()/19);
  afficheChaine("p'(x)", 20, largeurFenetre()/9, 5*hauteurFenetre()/19);
  afficheChaine("p(x)", 20, largeurFenetre()/9, 2*hauteurFenetre()/19);
  ligne(0,4*hauteurFenetre()/19,largeurFenetre(),4*hauteurFenetre());
  sprintf(nb, "%.2f", Premier.polynome.a);
  afficheChaine(nb, 20, 2*largeurFenetre()/9, 7*hauteurFenetre()/19);
  sprintf(nb1, "%.2f", Premier.polynome.b);
  afficheChaine(nb1, 20, 8*largeurFenetre()/9, 7*hauteurFenetre()/19);
}
