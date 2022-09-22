#include "reseau.hpp"
#include <random>
#include<time.h>
using namespace std;



Reseau::Reseau(){}

Reseau::~Reseau(){}

void Reseau::ajouterObj(Objet *o){
	v.insert(v.end(),o);
}

void Reseau::afficherRes(){
	for (Objet *o : v){
		cout << *o << endl;
	}
}

/*!
 * \variable:
 * choix: choix du nom de l'objet
 */ 
Objet* Reseau::choixObjet(){
	string choix;
	afficherRes();
	cout << "\nChoisissez un objet pour parcourir le réseau (stop pour arrêter): ";
	cin >> choix ;
	cout << endl;
	while (choix!="stop"){
		for (Objet *o : v){
			if (o->getNom()==choix){
				return o;
			}
		}
		cout << "Erreur, choissez un objet pour parcourir le réseau (stop pour arrêter): ";
		cin >> choix ;
		cout << endl;
	}
	return nullptr;
}



void parcourirRes(Objet *o){
	if (o->getPasser()==true) return;
	cout << *o << endl;
	if (o->getListe().size()==0) return;
	o->setPasser(true);
	for (Objet *o1 : o->getListe()){
		parcourirRes(o1);
	}
}
