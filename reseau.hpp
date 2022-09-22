#ifndef RESEAU_HPP
#define RESEAU_HPP

/*!
 * \file reseau.hpp
 * \brief Reseau d'objet
 * \author Thomas CHAZOT, Alexis FERON, Baptiste MARCEL, Clément LAPORTE
 * \date 31/03/2022
 * */

#include <iostream>
#include <string>
#include <vector>
#include "objet.hpp"
using namespace std;
using namespace objet;

/*!
 * \class Reseau
 * \brief Classe représentant un Réseau d'objet
 * 
 * Cette classe permet la gestion d'un réseau
 * */
class Reseau{
private:
	vector<Objet*> v; /*!< Vecteur de pointeur sur Objet*/
public:
	/*!
	 * \brief Constructeur
	 * */
	Reseau();

	/*!
	 * \brief Destructeur
	 * */
	~Reseau();

	/*!
	 * \brief Ajoute un objet dans le réseau
	 * \param *o Pointeur sur l'objet à ajouter
	 * */
	void ajouterObj(Objet *o);

	/*!
	 * \brief Affiche le réseau
	 * */
	void afficherRes();

	/*!
	 * \brief Demande à l'utilisateur de choisir un objet
	 * \return Un pointeur sur Objet choisi
	 */
	Objet* choixObjet();

};

/*!
 * \brief Permet d'afficher les transformations d'un objet dans le réseau
 * \param *o Pointeur sur l'objet recherché
 * */
void parcourirRes(Objet *o);


#endif