#include "../../include/EnemyTypes/Metapod.h"

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

int Metapod::ReturnHealAmount() {
    return 1 + rand() % 10;
}

std::string Metapod::GetIntro()
{
    return "A familiar battle tone begins...";
}
