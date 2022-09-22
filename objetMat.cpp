#include"objetMat.hpp"
#include<random>
#include<time.h>
#include"reseauMat.hpp"
using namespace std;

int nb=0;

	ObjetMat::ObjetMat(string nom_){
         nom = nom_;
         num=nb;
         nb++;
    }

    ObjetMat::ObjetMat(){}

    ObjetMat::~ObjetMat(){}

    string ObjetMat::getNom() const{
        return nom;
    }

    int ObjetMat::getNum() const{
        return num;
    }

    void ObjetMat::changerNom(string nouv){
        nom=nouv;
    }

    /*!
     * variable :
     *  o : Objet qui est récupérer dans le réseau
     * it : Itérateur sur l'objet dans le réseaux
     * choix : numéro de l'objet que l'utilisateur à choisi
     * nbTrans : Vérifie si l'objet possède bien + 1 transformation
     * */
    int ObjetMat::changerObjet(ReseauMat &r){
        ObjetMat *o;
        vector<ObjetMat*>::iterator it=r.getItObj();
        int choix;
        int nbTrans=0;
        for (int i=0; i<NBOBJET; i++){
            if (r.getMatrice()[num][i]==1){
                nbTrans++;
                break;
            }
        }
        if (nbTrans==0) return 0;
        choix=this->choisirObjet(r);
            while (it!=r.getTabObj().end()){
                o=*it;
                if(choix==o->getNum()){
                    nom=o->nom;
                    num=o->num;
                    return 1;
                }
            advance(it, 1);
        }
        return 1;
    }
  
    /*!
     * variable :
     *  choix : Numéro de l'objet choisi
     * *o : Objet récupérer
     * reussite : Boolean pour vérifier la réussite
     * it : Itérateur sur l'objet dans le réseaux
     * */
    int ObjetMat::choisirObjet(ReseauMat &r) const{
        string choix;
        ObjetMat *o;
        bool reussite=false;
        vector<ObjetMat*>::iterator it=r.getItObj();
        cout << *this << endl;
        afficherTransfoM(r);
        cout << "Quel objet souhaitez vous fabriquez ?" << endl;
        cin >> choix;

        while (reussite==false){
            for (int i=0; i<NBOBJET; i++){
                o=*it;
                if (o->getNom()==choix){
                    return o->getNum();
                }
                it++;
            }
            it=r.getItObj();  
            cout << "Erreur dans la saisie" << endl;
            cout << "Quel objet voulez vous fabriquez ?" << endl;
            cin >> choix;
        }
        return num;

    }

    /*!
     * variable :
     * it : Itérateur sur l'objet dans le réseaux
     * */
    void ObjetMat::afficherTransfoM(ReseauMat &r) const{
        vector<ObjetMat*>::iterator it=r.getItObj();
        for (int i=0; i<NBOBJET; i++){
            if (r.getMatrice()[num][i]==1){
                advance(it,i);
                cout << "\t" << **it << endl;
                it=r.getTabObj().begin();
            }
        }
    }

    /*!
     * variable :
     *  ret : vérifie le code retour
     *  nbr : Nombre de transformation faites dans la partie
     *  alea : Pour random
     *  nbTrans : vérifie si l'objet à minimum une transformation
     * */
    void ObjetMat::jouer(ReseauMat &r){
        int ret=1, nbr=-1, alea=15, nbTrans=0;
        for (int i=0; i<NBOBJET; i++){
            if (r.getMatrice()[num][i]==1){
                nbTrans=1;
                break;
            }
        }
        while (ret==1 && nbTrans>0){
            cout << endl;
            ret=changerObjet(r);
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

    bool ObjetMat::getPasser() const{
        return passer;
    }

    void ObjetMat::setPasser(bool b){
        passer=b;
    }

    bool ObjetMat::operator==(const ObjetMat &o) const{
        return this->getNum() == o.getNum();
    }


   
   	
    bool ObjetMat::operator<(const ObjetMat &o) const{
        return this->getNum() < o.getNum();
    }


    ostream& operator<<(ostream &out, const ObjetMat &o){
    	out << o.getNom();
    	return out;
    }


    int aleatoire(int alea){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, alea);
        return distrib(gen);
    }
