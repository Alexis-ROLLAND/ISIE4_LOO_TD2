/**
 *	@file	De.cpp
 * 	@brief 	De class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2025-10
 *
 */
#include "De.hpp"

//----------------------------------------------------------------------------
/**
 * @note    On ne peut qu'initialiser MinValue et Maxvalue car ce sont des
 *          champs "const". Maison veut s'assurer que, quel que soit "l'ordre"
 *          des paramètres la plus petite valeur soit dans MinValue et la plus
 *          grande dans MaxValue.
 *          Faire un if dans le code ne fonctionne pas (ce ne serait pas une
 *          initialisation, mais une affectation), mais il est possible d'intégrer
 *          le test dans l'initialisation en utilisant l'opérateur ternaire.
 *          Les inits ayant été réalisées, on peut gérer l'égalité entre les
 *          paramètres et lever une exception en cas de tentativie de création
 *          de dé à 1 face (min = max).
 */
De::De(uint8_t FirstBoundary, uint8_t SecondBoundary) : MinValue{(FirstBoundary < SecondBoundary) ? FirstBoundary : SecondBoundary}, MaxValue{(FirstBoundary < SecondBoundary) ? SecondBoundary : FirstBoundary}
{
    /** Exception de type "std::domain_error" si les deux bornes sont égales    */
    if (FirstBoundary == SecondBoundary)
        throw std::domain_error("Le nombre de faces ne peut être égal à 1 (FirstBoundary must not be equal to SecondeBoundary).");
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
uint8_t De::Lancer() const noexcept
{
    std::uniform_int_distribution<uint8_t> d{this->MinValue, this->MaxValue}; /** Construction du "vrai générateur" de nombres aléatoires*/
    return d(this->e);
}
//----------------------------------------------------------------------------
std::vector<uint8_t> De::Lancer(uint8_t NbDes) const noexcept
{
    std::vector<uint8_t> Tirage{};

    for (uint8_t i = 0; i < NbDes; ++i)
        Tirage.push_back(this->Lancer());

    return Tirage;
}
//----------------------------------------------------------------------------
