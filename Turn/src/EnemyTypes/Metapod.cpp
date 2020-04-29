#include "../../include/EnemyTypes/Metapod.h"
/*!
    This Enemy Class satisfies User Story E.
    Req 5.0 - Implementation of the metapod enemy has been met as you can encounter it during the game.
    Req 5.0.1 - The Metapod has a high defense in that it heals a lot more than normal and also meets that it has no attack.
    Link - github.com/SenatorConfer/Turn/blob/master/Requirements.md
*/
Metapod::Metapod() {
    name = "Metapod";
    ExperienceAmount = 20;
    CoinsDrop = rand() % 50;
}

EnemyType Metapod::GetType() {
    return etMetapod;
}

int Metapod::ReturnDamage() {
    return 0;
}

int Metapod::ReturnRiskAttackDamage() {
    return 0;
}

/*!
    Metapod has only a strong heal.
*/
int Metapod::ReturnHealAmount() {
    return 1 + rand() % 10;
}

std::string Metapod::GetIntro()
{
    return "A familiar battle tone begins...";
}
