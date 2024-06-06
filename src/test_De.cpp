
#include <iostream>
#include "De.hpp"


int main(){
    std::println ("-- Test classe Dé --");  /**< Affichage */
    
    /** Test Dé par défaut (D6) - 1 seul tirage  */
    std::println ("-- Test Dé par défaut --");  /**< Affichage */
    De  MonDe_default{};        /**< Création (construction) d'un dé "par défaut" - Utilisation du constructeur par défaut */
    for(int nb=0;nb<10;++nb) std::println("Lancer {0:d} : {1:d}",nb, MonDe_default.Lancer()); /**< Réalisation de 10 lancers. Affichage */

    /** Test Dé par défaut (D6) - Tirage multiple (4 D6)  */
    std::println ( "-- Test Tirage multiple 4 D6 --");   /**< Affichage */
    std::vector<uint8_t> TirageD6{};    /**< Création d'un vector (tableau) de uint8_t appelé TirageD6. Vide pour le moment */
    TirageD6 = MonDe_default.Lancer(4); /**< Appel de la méthode Lancer surchargée. Récupération d'un vector de uint8_t */
    std::print("Résultat tirage de 4 D6 : ");  /**< Affichage */
    for (uint8_t ValeurDe : TirageD6) std::print(" {0:d} ", ValeurDe); /**< Parcours du vector + affichage valeurs */
    std::println(""); /**< Saut de ligne final */

    /** Test Dé quelconque (15 faces, valeurs de 1 à 15) - 1 seul tirage  */
    std::println("-- Test Dé quelconque --");  /**< Affichage */
    De MonDe15{1,15};   /**< Construction d'un Dé à 15 faces. Utilisation du constructeur adapté (uint8_t,uint8_t)*/
    for(int nb=0;nb<10;++nb) std::println("Lancer {0:d} :  {1:d}",nb, MonDe15.Lancer());
    
    /** Test Dé construit à partir d'un typeDe_t (D30) */
    std::println("-- Test Dé construit avec TypeDe_t (D30) --");  /**< Affichage */
    De MonDe30{De::TypeDe_t::D30};   /**< Construction d'un Dé à 30 faces. Utilisation du constructeur adapté (TypeDe_t)*/
    for(int nb=0;nb<10;++nb) std::println("Lancer {0:d} :  {1:d}",nb, MonDe30.Lancer());

    /** Test de la génération d'une exception si min = max */
    try{
        De MonDeCasse(4,4);
    }
    catch(const std::exception &e){
        std::println("Exception occured : {}", e.what());
    }

    /** Test avec objets constants    */
    const De monD12ct{1,12};
    const De monD100ct(De::TypeDe_t::D100);

    std::println("Lancer D12 constant = {0:d}", monD12ct.Lancer());
    std::println("Lancer D100 constant = {0:d}", monD100ct.Lancer());

    return 0;
}
