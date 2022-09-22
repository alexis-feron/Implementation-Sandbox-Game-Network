#include"reseauMat.hpp"

ReseauMat::ReseauMat(){
	matrice=new int*[NBOBJET];
	for (int i = 0; i < NBOBJET; i++){
            matrice[i] = new int[NBOBJET];
    
            for (int j = 0; j < NBOBJET; j++)   {
                  matrice[i][j] = 0;
            }
      }
}



ReseauMat::~ReseauMat(){
	supprimerMatrice();	
}

int** ReseauMat::getMatrice(){
	return matrice;
}


vector<ObjetMat*> ReseauMat::getTabObj(){
	return obj;
}

vector<ObjetMat*>::iterator ReseauMat::getItObj(){
	return obj.begin();
}

/*!
 * variable :
 * 	it : Itérateur pour placer le nouvel objet
 * */
void ReseauMat::ajouterObj(ObjetMat *o){
	auto it=obj.end();
	obj.insert(it, o);
}


void ReseauMat::trierTab(){
	sort(obj.begin(), obj.end(), greater<ObjetMat*>());
}

void ReseauMat::ajouterTransf(ObjetMat *o1, ObjetMat *o2){
	matrice[o1->getNum()][o2->getNum()]=1;
}

void ReseauMat::afficherRes(){
	for (ObjetMat *o : obj){
		cout << *o << endl;
	}
}

void ReseauMat::afficherMatrice(){
	for (int i=0; i<NBOBJET; i++){
		for (int j=0; j<NBOBJET; j++){
			cout << matrice[i][j] << " | ";
		}
		cout << endl;
	}

}


void ReseauMat::supprimerMatrice(){
	for (int i = 0; i < NBOBJET; i++){
            delete [] matrice[i];
    }
    delete [] matrice;
}

/*!
 * variable :
 * 	it : Itérateur pointant sur le début du vecteur
 * 	o1 : Objet suivant
 * */
void ReseauMat::parcourirRes(ObjetMat *o){
	vector<ObjetMat*>::iterator it=obj.begin();
	ObjetMat *o1;
	if (o->getPasser()==true) return;
	o->setPasser(true);
	cout << *o << endl;
	for (int i=0; i<NBOBJET; i++){
        if (matrice[o->getNum()][i]==1){
        	advance(it,i);
        	o1=*it;
            this->parcourirRes(o1);
            it=obj.begin();
        }
    }
}

/*!
 * \variable:
 * choix: choix du nom de l'objet
 */ 

ObjetMat* ReseauMat::choixObjet(){
	string choix;
	afficherRes();
	cout << "\nChoisissez un objet pour parcourir le réseau (stop pour arrêter): ";
	cin >> choix ;
	cout << endl;
	while (choix!="stop"){
		for (ObjetMat *o : obj){
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