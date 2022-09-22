#include "objet.hpp"
#include "reseau.hpp"
#include"objetMat.hpp"
#include"reseauMat.hpp"
using namespace objet;

void test(){
    Reseau r;
    Objet *i;
    Objet o1("Pousse");
    Objet o2("Arbre");
    Objet o3("Planche");
    Objet o4("Table");
    Objet o5("Radeau");
    Objet o6("Bouclier");
    Objet o7("Baton");
    Objet o8("Epée");
    Objet o9("Coffre");
    Objet o10("Barrière");
    Objet o11("Tipi");
    Objet o12("Feu");
    Objet o13("Rondin");
    Objet o14("Lance");
    Objet o15("Piège");
    Objet o16("Cure-dent");

    o1.ajouterTransf(&o2);
    o2.ajouterTransf(&o3);
    o2.ajouterTransf(&o13);
    o3.ajouterTransf(&o7);
    o3.ajouterTransf(&o4);
    o4.ajouterTransf(&o5);
    o4.ajouterTransf(&o3);
    o4.ajouterTransf(&o6);
    o5.ajouterTransf(&o4);
    o5.ajouterTransf(&o6);
    o6.ajouterTransf(&o3);
    o7.ajouterTransf(&o12);
    o7.ajouterTransf(&o8);
    o7.ajouterTransf(&o11);
    o8.ajouterTransf(&o9);
    o9.ajouterTransf(&o7);
    o9.ajouterTransf(&o3);
    o10.ajouterTransf(&o8);
    o11.ajouterTransf(&o10);
    o11.ajouterTransf(&o5);
    o13.ajouterTransf(&o14);
    o14.ajouterTransf(&o15);
    o14.ajouterTransf(&o16);
    o15.ajouterTransf(&o13);
    o15.ajouterTransf(&o13);
    r.ajouterObj(&o1);
    r.ajouterObj(&o2);
    r.ajouterObj(&o3);
    r.ajouterObj(&o4);
    r.ajouterObj(&o5);
    r.ajouterObj(&o6);
    r.ajouterObj(&o7);
    r.ajouterObj(&o8);
    r.ajouterObj(&o9);
    r.ajouterObj(&o10);
    r.ajouterObj(&o11);
    r.ajouterObj(&o12);
    r.ajouterObj(&o13);
    r.ajouterObj(&o14);
    r.ajouterObj(&o15);
    r.ajouterObj(&o16);

    cout << "Choisissez un objet pour commencer le jeu:\n" << endl;
    i=r.choixObjet();
    if (i!=NULL){
       i->jouer(); //Décommenter la fonction aléatoire dans jouer pour vraiment jouer au jeu
    }
    cout << "Voici tous les objets que comportent le réseau:\n" << endl;
    i=r.choixObjet();
    if (i!=NULL){
        parcourirRes(i);
    }
}


void testMat(){
    ReseauMat r;
    ObjetMat *i;
    ObjetMat o0("Pousse");
    ObjetMat o1("Arbre");
    ObjetMat o2("Planche");
    ObjetMat o3("Table");
    ObjetMat o4("Radeau");
    ObjetMat o5("Bouclier");
    ObjetMat o6("Baton");
    ObjetMat o7("Epée");
    ObjetMat o8("Coffre");
    ObjetMat o9("Barrière");
    ObjetMat o10("Tipi");
    ObjetMat o11("Feu");
    ObjetMat o12("Rondin");
    ObjetMat o13("Lance");
    ObjetMat o14("Piège");
    ObjetMat o15("Cure-dent");
    r.ajouterObj(&o0);
    r.ajouterObj(&o1);
    r.ajouterObj(&o2);
    r.ajouterObj(&o3);
    r.ajouterObj(&o4);
    r.ajouterObj(&o5);
    r.ajouterObj(&o6);
    r.ajouterObj(&o7);
    r.ajouterObj(&o8);
    r.ajouterObj(&o9);
    r.ajouterObj(&o10);
    r.ajouterObj(&o11);
    r.ajouterObj(&o12);
    r.ajouterObj(&o13);
    r.ajouterObj(&o14);
    r.ajouterObj(&o15);
    r.ajouterTransf(&o0,&o1);
    r.ajouterTransf(&o1,&o2);
    r.ajouterTransf(&o1,&o12);
    r.ajouterTransf(&o2,&o6);
    r.ajouterTransf(&o2,&o3);
    r.ajouterTransf(&o3,&o4);
    r.ajouterTransf(&o3,&o2);
    r.ajouterTransf(&o3,&o5);
    r.ajouterTransf(&o4,&o3);
    r.ajouterTransf(&o4,&o5);
    r.ajouterTransf(&o5,&o2);
    r.ajouterTransf(&o6,&o11);
    r.ajouterTransf(&o6,&o7);
    r.ajouterTransf(&o6,&o10);
    r.ajouterTransf(&o7,&o8);
    r.ajouterTransf(&o8,&o6);
    r.ajouterTransf(&o8,&o2);
    r.ajouterTransf(&o9,&o7);
    r.ajouterTransf(&o10,&o9);
    r.ajouterTransf(&o10,&o4);
    r.ajouterTransf(&o12,&o13);
    r.ajouterTransf(&o13,&o14);
    r.ajouterTransf(&o13,&o15);
    r.ajouterTransf(&o14,&o12);
    cout << "Choisissez un objet pour commencer le jeu:\n" << endl;
    i=r.choixObjet();
    if (i!=NULL){
       i->jouer(r);  //Décommenter la fonction aléatoire dans jouer pour vraiment jouer au jeu
    }
    cout << "Voici tous les objets que comportent le réseau:\n" << endl;
    i=r.choixObjet();
    if (i!=NULL){
        r.parcourirRes(i);
    }

}


int main(){
    //test();
    testMat();
    return 0;
}


