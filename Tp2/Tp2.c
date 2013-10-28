//
//  Tp2.c
//  Tp2
//
//  Created by Aurélien Delon on 2013-10-28.
//  Copyright (c) 2013 Aurélien Delon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module_feu.h"
#include "module_terrain.h"
#include "module_util.h"
#include "graph_io.h"


void afficher_terrain(t_terrain terrain);
void propager_un_feu(t_terrain terrain, int ligne, int colonne);


/* On veut afficher l'état de chaque case */
void afficher_terrain(t_terrain terrain)
{    int ligne;
     int colonne;
     
    for (ligne=0;ligne < LARGEUR_TERRAIN; ligne ++)
    {
        for(colonne=0;colonne < LONGUEUR_TERRAIN; colonne ++)
        {
            if (etat_case(terrain,ligne, colonne)==0)
                dessiner_case(ligne,colonne,VIDE);
            
            else if (etat_case(terrain,ligne,colonne)==1)
                dessiner_case(ligne,colonne,ARBRE);
            
            else if (etat_case(terrain,ligne,colonne)==2)
                dessiner_case(ligne,colonne,FEU);
            
            else
                dessiner_case(ligne,colonne,CENDRES);
        }
    }
    
}

void propager_un_feu(t_terrain terrain,int ligne, int colonne)
{

    int i;
    int j;
    int distance_ligne=0;
    int distance_colonne=0;
    int distance_totale=0;
    
    for (i=ligne;i<ligne+DISTANCE_MAX_PROPAGATION;i++)
         {
             for(j=colonne;j<colonne+DISTANCE_MAX_PROPAGATION;j++)
             {
                 if (terrain[ligne][colonne]==ARBRE)
                 {
                     distance_ligne = i-ligne;
                     distance_colonne = j-colonne;
                     distance_totale = sqrt(((distance_ligne)*(distance_ligne))+((distance_colonne)*(distance_colonne)));
                     
                     if(nb_aleatoire_0_1()<probabilite_propagation_feu(distance_totale))
                     {
                         modifier_etat_case(terrain, i, j, 2);
                     }
                     
             }
                 
             
                 for (i=ligne;i>ligne-DISTANCE_MAX_PROPAGATION;i--)
                 {
                     for(j=colonne;j>colonne-DISTANCE_MAX_PROPAGATION;j--)
                     {
                         if (terrain[ligne][colonne]==ARBRE)
                         {
                             distance_ligne = i-ligne;
                             distance_colonne = j-colonne;
                             distance_totale = sqrt(((distance_ligne)*(distance_ligne))+((distance_colonne)*(distance_colonne)));
                             
                             if(nb_aleatoire_0_1()<probabilite_propagation_feu(distance_totale))
                             {
                                 modifier_etat_case(terrain, i, j, 2);
                             }
                             
                         }

}



