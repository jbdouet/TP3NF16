//
//  TP3.c
//  TP3version2
//
//  Created by Jean-Baptiste Douet on 22/04/2015.
//  Copyright (c) 2015 Jean-Baptiste Douet. All rights reserved.
//

#include "TP3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




T_Produit *creerProduit(char *nom, float prix, char qualite, int quantite){
    T_Produit * nouveau;
    nouveau=(T_Produit*)malloc(sizeof(T_Produit));
    if (nouveau!=NULL){
        nouveau->nom=nom;
        nouveau->prix=prix;
        nouveau->qualite=qualite;
        nouveau->quantite=quantite;
        nouveau->suivant=NULL;
    }
    return nouveau;
}


T_Rayon * creerRayon(char *nom){
    T_Rayon * nouveau;
    nouveau=(T_Rayon*)malloc(sizeof(T_Rayon));
    if (nouveau!=NULL){
        nouveau->nom_rayon=nom;
        nouveau->nombre_produits=0;
        nouveau->premier=NULL;
        nouveau->suivant=NULL;
    }
    return nouveau;
}


T_Magasin * creerMagasin(char *nom){
    T_Magasin * nouveau;
    nouveau=(T_Magasin *)malloc(sizeof(T_Magasin));
    if (nouveau!=NULL){
        nouveau->nom=nom;
        nouveau->premier=NULL;
    }
    return nouveau;
}


/*int ajouterProduit(T_Rayon *rayon, T_Produit *produit){
    
    T_Produit *pointeur;
    
    
    if (rayon == NULL){
        return(0);
    }
    
    rayon->premier = pointeur;
    if (pointeur == NULL){
        rayon -> premier = produit;
        rayon -> nombre_produits= rayon ->nombre_produits + 1;
    }
    
    while (( pointeur->suivant != 0 ) && (strcmp(pointeur->nom, produit-> nom)<0)){
        pointeur= pointeur->suivant;
        
    }
    if (strcmp(pointeur->nom, produit-> nom)==0){
        printf ("ce rayon existe deja ! \n");
    }
    else{
        if  (pointeur-> suivant == 0 ){
            pointeur -> suivant = produit;
            rayon->nombre_produits = rayon -> nombre_produits + 1;
        }
        else {
            produit->suivant=pointeur->suivant;
            pointeur->suivant= produit;
            rayon->nombre_produits = rayon -> nombre_produits + 1;
            
            
        }
        
    }
    return 1 ;
}

*/

int ajouterProduit(T_Rayon *rayon, T_Produit *produit){
    T_Produit * actuel, *precedent;
    //Attention close rayon NULL parfois (lors de création)
    if(rayon!=NULL){
        actuel=rayon->premier;
    }
        if (actuel==NULL){
            rayon->premier=produit;
            rayon->nombre_produits=rayon->nombre_produits+1;
        }
        else {
            precedent=NULL;
            while((actuel!=NULL)&&(strcmp(produit->nom, actuel->nom)>0)){
                precedent=actuel;
                actuel=actuel->suivant;
            }
            if(actuel==NULL){
                precedent->suivant=produit;
                rayon->nombre_produits=rayon->nombre_produits+1;
            }
            else {
                if(strcmp(produit->nom, actuel->nom)==0){
                    actuel->quantite=actuel->quantite + produit->quantite;
                    
                    return 0;
                }
                else {
                    if(precedent==NULL){
                        rayon->premier=produit;
                    }
                    else{
                        precedent->suivant=produit;
                    }
                    produit->suivant=actuel;
                    rayon->nombre_produits=rayon->nombre_produits+1;
                }
                
            }
         
        } 
    
    return 1;
}

int ajouterRayon(T_Magasin *magasin, T_Rayon *rayon){
    
    T_Rayon *pointeur;
    
    if (magasin == NULL){
        return 0;
    }
    
    pointeur = magasin -> premier;
    
    if (pointeur == NULL) {
        magasin -> premier = rayon;
        
    }
    else {
        while ( (pointeur-> suivant!= NULL) && (strcmp ( pointeur -> nom_rayon, rayon -> nom_rayon) <0)){
            
            pointeur = pointeur-> suivant;
            
        }
        if (strcmp ( pointeur -> nom_rayon, rayon -> nom_rayon) ==0){
            
            printf(" Le nom du rayon est deja pris");
            return 0;
        }
        else {
            if (pointeur-> suivant== NULL) {
                pointeur -> suivant = rayon;
                
            }
            
            else {
                rayon-> suivant = pointeur -> suivant;
                pointeur -> suivant = rayon;
                
            }
        }
        
        
    }
    return 1 ;
}

void afficherMagasin(T_Magasin *magasin){
    T_Rayon * actuel;
    if(magasin==NULL){
        printf("Le magasin est vide\n");
    }
    else{
        printf("Noms des rayons : \n");
        actuel=magasin->premier;
        printf("----------------------------------------------------------\n");
        printf("Nom \t\t Nombre de produits\n");
        printf("----------------------------------------------------------\n");
        while(actuel!=NULL){
            printf("%s \t %d\n", actuel->nom_rayon, actuel->nombre_produits);
            actuel=actuel->suivant;
        }
    }
}


void afficherRayon(T_Rayon *rayon){
    T_Produit * actuel;
    if(rayon==NULL){
        printf("Le rayon est vide\n");
    }
    else{
        printf("Nom des produits: \n");
        actuel=rayon->premier;
        printf("---------------------------------------------------------\n");
        printf("Nom \t\tPrix \tQualité \tQuantité en stock\n");
        printf("---------------------------------------------------------\n");
        while(actuel!=NULL){
            printf("%s \t%.2f \t%c \t\t%d\n", actuel->nom, actuel->prix, actuel->qualite, actuel->quantite);
            actuel=actuel->suivant;
        }
    }
}



int retirerProduit(T_Rayon *rayon, char* nom_produit) {
    
    T_Produit  *pointeur, *precedent;
    
    if (rayon==NULL){
        printf("Rayon est vide\n");
    }
    else{
        pointeur = rayon->premier;
        precedent= NULL;
        
        while(( pointeur !=NULL) && (strcmp ( nom_produit, pointeur->nom)!=0)){
            
            precedent= pointeur;
            pointeur= pointeur->suivant;
            
        }
        if(pointeur==NULL){
            printf("Le produit n'existe pas !\n");
            return 0;
        }
        else {
            if (pointeur->quantite > 0){
                pointeur->quantite=pointeur->quantite - 1;
            }
            else {
                if ((precedent = NULL)){
                    rayon->premier=pointeur->suivant;
                }
                else {
                    precedent->suivant=pointeur->suivant;
                }
            }
        }
        free (pointeur);
        return 1 ;
    }
    return 0;
}





void supprimerRayon(T_Magasin *magasin, char *nom_rayon){
    T_Rayon *actuel, *precedent;
    //T_Produit *pointeur;
    if(magasin==NULL){
        printf("Magasin est vide\n");
    }
    else{
        actuel=magasin->premier;
        precedent=NULL;
        
        while((actuel!=NULL)&&(strcmp(nom_rayon, actuel->nom_rayon)!=0)){
            precedent=actuel;
            actuel=actuel->suivant;
        }
        if(actuel==NULL){
            printf("Le rayon n'existe pas\n");
        }
        else{
        if (precedent == NULL){
            magasin->premier=actuel->suivant;
        }
        else {
            if (actuel->suivant != NULL){
            precedent->suivant=actuel->suivant;
            }
            else { precedent = NULL;
            }
        }
        }
        //faire un free de tous les produits du rayon
       /* pointeur = actuel->premier;
        while((pointeur!=NULL)){
            pointeur=pointeur->suivant;
            free(pointeur);
            
        }*/
        free(actuel);
        free(precedent);
    
    
    }
}
          
          


void rechercheProduits(T_Magasin *magasin, float prix_min, float prix_max){
    T_Rayon * actuel_m;
    T_Produit * actuel_p;
    if(magasin==NULL){
        printf("Le magasin est vide\n");
    }
    else{
        printf("Noms des produits : \n");
        printf("----------------------------------------------------------\n");
        printf("Nom \t Prix \t Qualité \t Quantité en stock \t Rayon\n");
        printf("----------------------------------------------------------\n");
        
        actuel_m=magasin->premier;
        while(actuel_m!=NULL){
            actuel_p=actuel_m->premier;
            while(actuel_p!=NULL){
                if(((actuel_p->prix) >= prix_min)&&((actuel_p->prix) <= prix_max)){
                    printf("%s \t %.2f \t%c \t%d \t%s\n", actuel_p->nom, actuel_p->prix, actuel_p->qualite, actuel_p->quantite, actuel_m->nom_rayon);
                }
                actuel_p=actuel_p->suivant;
            }
            actuel_m=actuel_m->suivant;
        }
    }
}


void traiterListeAchat(T_Magasin *magasin){
    int i, n;
    i=1;
    
    printf("Combien de produits voulez vous acheter ?");
    scanf("%d",n);
    for (i=1; i<n+1; i++){
        T_Produit *produit, *pointeur;
        T_Rayon *rayon, *actuel;
        printf("Choisissez votre produit numero %d et remplissez ses caracteristique \n", i);
        scanf ( "%s%s%d", rayon->nom_rayon, produit->nom, produit->quantite);
        
        actuel= magasin->premier;
        
        while ((actuel!=NULL)&&(strcmp(actuel->nom_rayon, rayon->nom_rayon)!=0)){
            actuel=actuel->suivant;
        }
        if(actuel==NULL){
            printf("Le rayon n'existe pas\n");
            exit(0);
        }
        else{
        
            pointeur =  rayon->premier;
        
            while((pointeur!=NULL)&&(strcmp(produit->nom, pointeur->nom)!=0)){
                pointeur=pointeur->suivant;
            }
            if (pointeur!=NULL){
                printf("Le produit n'existe pas\n");
                exit(0);
            }
            else {
                pointeur->quantite= (pointeur->quantite)-(produit->quantite);
            }
    }
    
}
}


