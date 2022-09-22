#ifndef RESEAUMAT_HPP
#define RESEAUMAT_HPP

/*!
 * \file reseauMat.hpp
 * \brief Reseau d'objet (Forme Matricielle)
 * \author Thomas CHAZOT, Alexis FERON, Baptiste MARCEL, Clément LAPORTE
 * \date 31/03/2022
 * */

#include <iostream>
#include <string>
#include <vector>
#include "objetMat.hpp"
using namespace std;

// Nombre d'objet dans la matrice
const int NBOBJET=16;

/*!
 * \class ReseauMat
 * \brief Classe représentant un Réseau d'objet (Forme Matricielle)
 * 
 * Cette classe permet la gestion d'un réseau (Forme Matricielle)
 * */
class ReseauMat{
private:
	int **matrice; /*!< Tableau double entrée représentant la matrice*/
	vector<ObjetMat*> obj; /*!< Vecteur de pointeur sur Objet (Forme Matricielle)*/
public:
	/*!
	 * \brief Constructeur (Initialiser à l'aide de NBOJET)
	 * */
	ReseauMat();
	
	/*!
	 * \brief Destructeur
	 * */
	~ReseauMat();

	/*!
	 * \brief Récupère la matrice
	 * \return Tableau double entrée représentant la matrice
	 * */
	int** getMatrice();

	/*!
	 * \brief Récupère un itérateur sur un objet
	 * \return Itérator sur un objet présent dans un vecteur
	 * */
	vector<ObjetMat*>::iterator getItObj();

	/*!
	 * \brief Récupère un vecteur d'objet
	 * \return Vecteur de pointeur sur objet
	 * */
	vector<ObjetMat*> getTabObj();

	/*!
	 * \brief Ajouter un objet dans la matrice
	 * \param o1 Pointeur sur l'objet que l'on va ajouter
	 * */
	void ajouterObj(ObjetMat *o1);

	/*!
	 * \brief Trier la matrice
	 * */
	void trierTab();

	/*!
	 * \brief Ajouter une transformation à un objet
	 * \param o1 Pointeur sur l'objet à qui on ajoute une transformation
	 * \param o2 Pointeur sur l'objet qui devient une transformation
	 * */
	void ajouterTransf(ObjetMat *o1, ObjetMat *o2);

	/*!
	 * \brief Affiche les objets présents dans la matrice
	 * */
	void afficherRes();

	/*!
	 * \brief Affiche la matrice
	 * */
	void afficherMatrice();

	/*!
	 * \brief Supprime la matrice
	 * */
	void supprimerMatrice();

	/*!
 	 * \brief Permet d'afficher les transformations d'un objet dans le réseau
 	 * \param *o Pointeur sur l'objet recherché
 	 * */
	void parcourirRes(ObjetMat *o);

	/*!
	 * \brief Demande à l'utilisateur de choisir un objet
	 * \return Un pointeur sur Objet choisi
	 */
	ObjetMat* choixObjet();
};


#endif