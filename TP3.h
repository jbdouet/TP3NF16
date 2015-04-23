//
//  TP3.h
//  TP3version2
//
//  Created by Jean-Baptiste Douet on 22/04/2015.
//  Copyright (c) 2015 Jean-Baptiste Douet. All rights reserved.
//

#ifndef TP3version2_TP3_h
#define TP3version2_TP3_h


#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Produit
{	char * nom;
    float prix;
    char qualite;
    int quantite;
    struct Produit * suivant;
} T_Produit;

typedef	struct Rayon
{	char * nom_rayon;
    int nombre_produits;
    T_Produit * premier;
    struct Rayon * suivant;
} T_Rayon;

typedef struct Magasin
{	char * nom;
    T_Rayon * premier;
} T_Magasin;



T_Produit *creerProduit(char *nom, float prix, char qualite, int quantite);
T_Rayon *creerRayon(char *nom);
T_Magasin *creerMagasin(char *nom);
int ajouterProduit(T_Rayon *rayon, T_Produit *produit);
int ajouterRayon(T_Magasin *magasin, T_Rayon *rayon);
void afficherMagasin(T_Magasin *magasin);
void afficherRayon(T_Rayon *rayon);
int retirerProduit(T_Rayon *rayon, char* nom_produit);
void supprimerRayon(T_Magasin *magasin, char *nom_rayon);
void rechercheProduits(T_Magasin *magasin, float prix_min, float prix_max);
void traiterListeAchat(T_Magasin *magasin);
