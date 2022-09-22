/**
 * \file objetMat.hpp
 * \brief fichier de création de la classe Objet et de toutes les fonctions qui vont avec 
 * \Author Alexis Feron, Baptiste Marcel, Thomas Chazot, Clément Laporte
 * \date 04/03/2022
 *  
 * La classe Objet possède 3 attributs: nom qui est le nom de l'objet, transfDirect qui est une liste de pointeur sur Objet qui sont tous les objets accessibles par transformation direct depuis l'objet de base et passer qui est un booléen pour que l'algorithme d'exploration sache quels objets il a déjà exploré.
*/




#ifndef OBJETMAT_HPP
#define OBJETMAT_HPP
#include <iostream>
#include <string>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class ReseauMat;

    /*!
     * \class Objet
     * \brief class représentant un Objet
     */
    class ObjetMat{
        private:
            string nom;  /* nom de l'Objet */
            int num; /* Numéro de l'Objet dans la matrice de réseau */
            bool passer=false; /* Valeur qui permet de savoir si l'algorithme d'implémentation est passé par l'objet */
        
        public:
            /*!
             * \brief constructeur d'Objet
             * \param nom nom de l'objet 
            */
            ObjetMat(string nom);


            /*!
             * \brief constructeur vide d'Objet
             */
            ObjetMat();


            /*!
             * \brief destructeur d'Objet
             */
            ~ObjetMat();



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
             * \brief permet d'obtenir le num d'un Objet
             * \return un string, le num de l'Objet
             */
            int getNum() const;


            /*!
             * \brief permet de changer d'Objet lorsque l'on joue au jeu
             * \return 0 si la liste de l'Objet est vide, 0 si le choix de l'utilisateur est 0, 1 si l'utilisateur a changé d'objet
             */
            int changerObjet(ReseauMat &r);

            


            /*!
             * \brief demande à l'utilisateur de choisir un objet parmi la liste qui d'Objet qui lui est proposé
             * \return un string, le nom de l'Objet qu'a choisit l'utilisateur, "0" si il veut arrêter de jouer
             * 
             */
            int choisirObjet(ReseauMat &r) const;


            /*!
             * \brief permet à l'utilisateur de jouer au jeu en créant différents objets à partir de l'objet avec lequel il a commencé
             */
            void jouer(ReseauMat &r);


            /*!
             * \brief affiche la lsite des transformations d'un Objet
             */
            void afficherTransfoM(ReseauMat &r) const;


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
            bool operator==(const ObjetMat &o) const;

            bool operator<( const ObjetMat &o) const;

            friend ostream& operator<<(ostream &out, const ObjetMat &o);
    };


#endif