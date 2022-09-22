/**
 * \file objet.hpp
 * \brief fichier de création de la classe Objet et de toutes les fonctions qui vont avec 
 * \Author Alexis Feron, Baptiste Marcel, Thomas Chazot, Clément Laporte
 * \date 04/03/2022
 *  
 * La classe Objet possède 3 attributs: nom qui est le nom de l'objet, transfDirect qui est une liste de pointeur sur Objet qui sont tous les objets accessibles par transformation direct depuis l'objet de base et passer qui est un booléen pour que l'algorithme d'exploration sache quels objets il a déjà exploré.
*/




#ifndef OBJET_HPP
#define OBJET_HPP
#include <iostream>
#include <string>
#include <list>

using namespace std;

namespace objet{



    /*!
     * \class Objet
     * \brief class représentant un Objet
     */
    class Objet{
        private:
            string nom;  /*! nom de l'Objet */
            list<Objet*> transfDirect; /*! Liste des transformations directes de l'Objet */
            bool passer=false; /*! Valeur qui permet de savoir si l'algorithme d'implémentation est passé par l'objet */
        
        public:
            /*!
             * \brief constructeur d'Objet
             * \param nom nom de l'objet 
            */
            Objet(string nom);


            /*!
             * \brief constructeur vide d'Objet
             */
            Objet();


            /*!
             * \brief destructeur d'Objet
             */
            ~Objet();


            /*!
             * \brief permet d'ajouter une transformation directe dans la liste de l'objet
             * \param[in] unObjet pointeur sur Objet
             */
            void ajouterTransf(Objet *unObjet);


            /*!
             * \brief permet d'enlever une transformation directe dans la liste d'objet
             * \param[in] unObjet pointeur sur Objet
             */
            void enleverTransf(Objet  *unObjet);


            /*!
             * \brief permet de changer le nom d'un Objet
             * \param nouv un string, le nouveau nom de l'Objet
             */
            void changerNom(string nouv);


            /*!
             * \brief permet d'obtenir le nom d'un Objet
             * \return un string, le nom de l'Objet
             */
            string getNom() const;


            /*!
             * \brief permet d'obtenir la liste des transformations directes d'un Objet
             * \return list<Objet*> la liste liste des transformations directes d'un Objet
             */
            list<Objet*> getListe() const;

            /*!
             * \brief permet de changer d'Objet lorsque l'on joue au jeu
             * \return 0 si la liste de l'Objet est vide, 0 si le choix de l'utilisateur est 0, 1 si l'utilisateur a changé d'objet
             */
            int changerObjet();


            /*!
             * \brief demande à l'utilisateur de choisir un objet parmi la liste qui d'Objet qui lui est proposé
             * \return un string, le nom de l'Objet qu'a choisit l'utilisateur, "0" si il veut arrêter de jouer
             * 
             */
            string choisirObjet() const;


            /*!
             * \brief permet à l'utilisateur de jouer au jeu en créant différents objets à partir de l'objet avec lequel il a commencé
             */
            void jouer();


            /*!
             * \brief affiche la lsite des transformations d'un Objet
             */
            void afficherTransfo() const;

            /*!
             * \brief permet de savoir si l'algorithme d'exploration du réseau est déjà passé par cet Objet
             * \return un bool, true si l'algorithme est déjà passé, false si il n'est pas passé
             */
            bool getPasser() const;

            /*!
             * \brief permet de changer la valeur passer d'un Objet
             * \param b un bool, la nouvelle valeur de passer
             */
            void setPasser(bool b);

            /*!
             * \brief permet de savoir si deux Objets sont égaux
             * \param o une référence sur objet
             * \return un bool, true si les Objets sont égaux, false si ils ne le sont pas
             */
            bool operator==(const objet::Objet &o) const;

    };
}




/*!
 * \brief fonction qui permet de retourner une valeur aléatoire
 * \param alea un int qui sera la valeur maximale que pourra prendre la valeur aléatoire
 * \return un int entre 1 et ale
 */
int aleatoire(int alea);


/*!
 * \brief surcharge de la fonction << qui permet d'afficher un Objet
 * \param s le flot
 * \param o un Objet
 * \return le flot
 */
ostream& operator<<(ostream& s, const objet::Objet &o);



#endif