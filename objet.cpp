#include "objet.hpp"
#include <random>
#include<time.h>
using namespace std;

namespace objet{

    Objet::Objet(string nom_){
         nom = nom_;
    }

    Objet::Objet(){}

    Objet::~Objet(){}

    
    string Objet::getNom() const{
        return nom;
    }

    list<Objet*> Objet::getListe() const{
        return transfDirect;
    }

    void Objet::changerNom(string nouv){
        nom=nouv;
    }

    void Objet::ajouterTransf(Objet *unObjet){
        transfDirect.push_front(unObjet);
    }
    
    void Objet::enleverTransf(Objet  *unObjet){
        transfDirect.remove(unObjet);
    }

    bool Objet::operator==(const objet::Objet &o) const{
        return this->getNom() == o.getNom();
    }

    int aleatoire(int alea){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, alea);
        return distrib(gen);
    }
    /*!
     * variable :
     *  choix : Numéro de l'objet
     */
    int Objet::changerObjet(){
        string choix;
        if (this->transfDirect.size()==0){
            return 0;
        }
        choix=this->choisirObjet();
        for (Objet* i : transfDirect){
            if (choix==i->getNom()){
                nom=i->nom;
                transfDirect=i->transfDirect;
                return 1;
            }
        }
        return 1;
    }


    void Objet::afficherTransfo()const{
        for (objet::Objet* o : getListe() ){
            cout << "\t" <<  o->getNom() << endl;
        }   
    }

    /*!
     * variable :
     *  choix : Numéro de l'objet
     *  reussite : Boolean vérifie la réussite
     * */
    string Objet::choisirObjet() const{
        string choix;
        bool reussite;
        cout << *this << endl;
        afficherTransfo();
        cout << "Quel objet souhaitez vous fabriquez ?" << endl;
        cin >> choix;

        while (reussite==false){

            for ( Objet* i : transfDirect){
                if (i->nom==choix){
                    return choix;
                }
            }
            cout << "Erreur dans la saisie" << endl;
            cout << "Quel objet voulez vous fabriquez ?" << endl;
            cin >> choix;
        }
        return choix;

    }

    /*!
     * variable :
     *  ret : vérifie le code retour
     *  nbr : Nombre de transformation faites dans la partie
     *  alea : Pour random
     * */
    void Objet::jouer(){
        int ret=1, nbr=-1, alea=15;
        while (ret==1 || transfDirect.size()>0){
            ret=changerObjet();
            nbr++;
            /*
            if (aleatoire(alea)==alea){        //Cette partie est uniquement la pour pimenter un peu le jeu
                cout << "Mince alors votre objet s'est cassé \n";
                break;
            }
            */
        }
        cout << "Vous avez fini le jeu avec l'objet " << *this << " en " << nbr  << " coups" << endl;

    }



    bool Objet::getPasser() const{
        return passer;
    }


    void Objet::setPasser(bool b){
        passer=b;
    }


}

ostream& operator<<(ostream& s, const objet::Objet &o){
    s << o.getNom();
    return s;
}


