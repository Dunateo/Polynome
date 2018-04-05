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
zero calculpixel(zero PointP, tableauvar Premier){
  zero PointPixels;
  PointPixels.nbpt = PointP.nbpt;
  for (int i = 0; i < PointP.nbpt; i++) {
    PointPixels.Z[i].x = 0+(PointP.Z[i].x-Premier.polynome.a)*largeurFenetre()/(Premier.polynome.b-Premier.polynome.a);
    PointPixels.Z[i].y = (hauteurFenetre()/2)+(PointP.Z[i].y-Premier.polynome.c)*(hauteurFenetre()-hauteurFenetre()/2)/(Premier.polynome.d-Premier.polynome.c);

  }

return PointPixels;

}

zero calculPointZero(zero PointP, tableauvar Premier){
  zero PointPixels;
  PointPixels.nbpt = PointP.nbpt;
  for (int i = 0; i < PointP.nbpt; i++) {


        PointPixels.Z[i].x = 0+(PointP.Z[i].x-Premier.polynome.a)*largeurFenetre()/(Premier.polynome.b-Premier.polynome.a);
        PointPixels.Z[i].y = (hauteurFenetre()/2)+(PointP.Z[i].y-Premier.polynome.c)*(hauteurFenetre()-hauteurFenetre()/2)/(Premier.polynome.d-Premier.polynome.c);

}



return PointPixels;

}
void affichagePoint(zero PointPp, zero Pointzero){

  for(int i=0; i< PointPp.nbpt; i++) {

  //  printf("%f  %f\n", PointPp.Z[i].x,PointPp.Z[i].y);
    couleurCourante(138,43,226);
    epaisseurDeTrait(4);
    ligne(PointPp.Z[i].x,PointPp.Z[i].y,PointPp.Z[i+1].x,PointPp.Z[i+1].y);

  }
  for (int j = 0; j < Pointzero.nbpt; j++) {
    couleurCourante(173,255,47);
    epaisseurDeTrait(10);
    point(Pointzero.Z[j].x,Pointzero.Z[j].y);
    couleurCourante(243,23,5);
    epaisseurDeTrait(4);
    ligne(Pointzero.Z[j].x-20,Pointzero.Z[j].y-3,Pointzero.Z[j].x+20,Pointzero.Z[j].y-3);
  }
}

void affichageTableau(tableauvar Premier){
  char nb[5];
  char nb1[5];
  char nb3[5];
  float nt = 3/Premier.D.nbpt;
  float maj;
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

  for (int i = 0; i < Premier.D.nbpt; i++) {
    sprintf(nb3, "%.2f", Premier.D.Z[i].x);
    maj = 2+nt;
    afficheChaine(nb3, 20, (maj)*largeurFenetre()/9, 7*hauteurFenetre()/19);
    couleurCourante(50,50,50);
    afficheChaine("0", 20, (maj)*largeurFenetre()/9, 5*hauteurFenetre()/19);

    nt = maj;
  }
  int j = 0;
  int signe;
  while( j < Premier.D.nbpt+1) {
    maj = 3+nt;
    if(Premier.variation.forme == 1){
      couleurCourante(50,50,50);
      afficheChaine("+", 30, (maj-nt)*largeurFenetre()/9, 5*hauteurFenetre()/19);
      epaisseurDeTrait(4);
      ligne(2*largeurFenetre()/18,0,(maj-nt)*largeurFenetre()/9, 3*hauteurFenetre()/19);
      signe = 0;
    }
    if(Premier.variation.forme == 0){
      couleurCourante(50,50,50);
      afficheChaine("-",30, (maj-nt)*largeurFenetre()/9, 5*hauteurFenetre()/19);
      epaisseurDeTrait(4);
      ligne(2*largeurFenetre()/18,3*hauteurFenetre()/19,(maj-nt)*largeurFenetre()/9,0 );
      signe = 1;
    }
  if(Premier.variation.forme == 2){
    couleurCourante(50,50,50);
    afficheChaine("M", 20, 3*largeurFenetre()/9, 7*hauteurFenetre()/19);
  }
    nt = maj;
    j++;

}

for (int h = 0; h < Premier.D.nbpt+1; h++) {
  maj = 7+nt;
  if(signe == 1){
    couleurCourante(50,50,50);
    afficheChaine("+", 30, (maj-nt)*largeurFenetre()/9, 5*hauteurFenetre()/19);
    epaisseurDeTrait(4);
    ligne(((3+nt)-nt)*largeurFenetre()/9,0,(maj-nt)*largeurFenetre()/9, 3*hauteurFenetre()/19);

  }
  if(signe == 0){
    couleurCourante(50,50,50);
    afficheChaine("-",30, (maj-nt)*largeurFenetre()/9, 5*hauteurFenetre()/19);
    epaisseurDeTrait(4);
    ligne(((3+nt)-nt)*largeurFenetre()/9,3*hauteurFenetre()/19,(maj-nt)*largeurFenetre()/9,0 );
  }
if(signe == 2){
  couleurCourante(50,50,50);
  afficheChaine("M", 20, 3*largeurFenetre()/9, 7*hauteurFenetre()/19);
}
  nt = maj;
}
}
