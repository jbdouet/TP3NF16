//
//  main.c
//  TP3version2
//
//  Created by Jean-Baptiste Douet on 22/04/2015.
//  Copyright (c) 2015 Jean-Baptiste Douet. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TP3.h"


int main(int argc, const char * argv[]) {
/*
    int i;
     T_Produit * gra, *din, *tom;
     T_Rayon * gat, *sou;
     T_Magasin * car;
     
     gra=creerProduit("Granola", 3, 'A',20);
     din=creerProduit("Dinosaure", 5, 'C',3);
     tom=creerProduit("Soupe tomate", 2, 'A',30);
     gat=creerRayon("Sucrerie");
     sou=creerRayon("Soupe");
     car=creerMagasin("Carrefour");
     
    
     i=ajouterRayon(car,gat);
     i=ajouterRayon(car,sou);
     printf(" Réussite de l'ajout du rayon : %d \n",i);
     printf("\n");
     afficherMagasin(car);
    
    
     printf("\n");
     i=ajouterProduit(gat,gra);
     i=ajouterProduit(gat,din);
     i=ajouterProduit(sou,tom);
     printf(" Réussite de l'ajout du produit : %d \n",i);
     afficherRayon(gat);
     afficherRayon(sou);
     printf("\n");
     
     char * n_produit="Granola";
     
     i=retirerProduit(gat, n_produit);
     printf(" Réussite du retrait du produit : %d \n",i);
     printf("\n");
     
     afficherRayon(gat);
     printf("\n");
    
     char * n_rayon="Suc";
     supprimerRayon(car,n_rayon);
     afficherMagasin(car);
    
    
     printf("\n");
     //rechercheProduits(car,2,4);
    
*/
    
    T_Magasin * magasin;
    T_Rayon * rayon;
    T_Produit * produit;
    char nomp;
    char nomr;
    char nomm;
    char qualite;
    float prix;
    int choix_m, prix_min, prix_max, quantite,i ;
    i=0;
    
    printf("--------------------------------------------------------------\n");
    printf("MENU :\n");
    printf("--------------------------------------------------------------\n");
    printf("\t1. \tCréer un magasin \n ");
    printf("\t2. \tAjouter un rayon au magasin \n ");
    printf("\t3. \tAjouter un produit dans un rayon \n ");
    printf("\t4. \tAfficher les rayons du magasin \n");
    printf("\t5. \tAfficher les produits d un rayon \n");
    printf("\t6. \tRetirer un produit \n");
    printf("\t7. \tSupprimer un rayon\n ");
    printf("\t8. \tRechercher un produit par prix \n ");
    printf("\t9. \tQuitter\n");
    printf("--------------------------------------------------------------\n");
    printf("\n");
    
    while (i!=9) {
        
        produit= (T_Produit*) malloc(sizeof(T_Produit));
        nomr = malloc(25*sizeof(char));
        nomp = malloc(25*sizeof(char));
        nomm = malloc(25*sizeof(char));
        
    printf("Entrer le nombre correspondant à l'action désiré\n");
    scanf("%d", &choix_m);
    i=choix_m;
    switch(choix_m){
        case 1 :
            printf("Quel nom souhaitez vous donner à votre magasin ? \n");
            scanf("%s",nomm);
            magasin=creerMagasin(nomm);
            afficherMagasin(magasin);
            break;
            
        case 2 : printf("Quel est le nom du rayon à ajouter ?\n");
            scanf("%s",nomr);
            rayon=creerRayon(nomr);
            if (ajouterRayon(magasin, rayon)){
                afficherMagasin(magasin);
                printf("L'ajout a été effectué\n");
            }
            else{ printf("Il y a eu une erreur");
            }
            break;
            
        case 3 : printf("Quel est le nom du produit à ajouter ? Son prix ? Sa qualité [A|B|C] ? Sa quantité ?\n");
            //scanf("%s%f%c%d",nom, prix, qualite, quantite);
            scanf("%s",nomp);
            scanf("%f",&prix);
            //scanf("%c",&qualite);
            qualite='A';
            scanf("%d",&quantite);
            produit=creerProduit(nomp, prix, qualite, quantite);
            printf("Dans quel rayon voulez vous l'ajouter?\n");
            scanf("%s",rayon);
            if (ajouterProduit(rayon, produit)){
                printf("L'ajout a été effectué\n");
            }
            else{ printf("Il y a eu une erreur\n");
            }
            break;
            
        case 4 : printf("Quel magasin afficher ?\n");
            scanf("%s",nomm);
            //Comment savoir quel magasin associé à ce nom?
            afficherMagasin(magasin);
            break;
            
        case 5 : printf("Quel rayon afficher ?\n");
            scanf("%s",nomr);
            //Comment savoir quel rayon associé à ce nom?
            afficherRayon (rayon);
            break;
            
        case 6 : printf("Quel produit retirer ?\n");
            scanf("%s",nomp);
            // Comment savoir quel produit associé nom ? Dans quel rayon est il ?
            if(retirerProduit(rayon, produit)){
                printf("Le retrait a été effectué\n");
            }
            else{
                printf("Le produit n'a pu être retiré\n");
            }
            break;
            
        case 7 : printf("Quel rayon supprimer ?\n");
            scanf("%s",nomr);
            // Comment savoir quel rayon associé nom ? Dans quel magasin est il ? 
            supprimerRayon(magasin, rayon);				
            break;
            
        case 8 : printf("Quel prix max ? Prix min ?\n");
            scanf("%f%f",&prix_min, &prix_max);
            rechercheProduits(magasin, prix_min, prix_max);
            break;
            
        case 9: exit(0);
            break;
        
        default: { i=9;
            printf("Ce n'est pas un des chiffres proposes, veuillez reessayer");}
           
    }
        
    }
    

    
    return 0;
    
}

