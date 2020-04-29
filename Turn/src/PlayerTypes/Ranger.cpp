#include "../../include/PlayerTypes/Ranger.h"
/*!
    This Ranger Player Class works towards Story B.
    Req 3.0 - Along with the multiple player classes that had been added by defualt a new ranger class has been introduced and available to the player.
    Req 3.1 - A new Ranger class has been added to the list of available classes availble to the player.
    This class is unique in relation to the other player classes in that it is the only class that has a special set of starting items. to make
    up for weaker overall stats.
    Link - github.com/SenatorConfer/Turn/blob/master/Requirements.md
    */
Ranger::Ranger(void)
{
    SoundInfo info;
    info.attackRange = std::make_pair(1, 11);
    SetSoundInfo(info);
}

int Ranger::ReturnDamage() {
    return 5 + rand() % 5; // 5 - 10
}

int Ranger::ReturnRiskAttackDamage() {
    int selector = rand() % 2;
    switch (selector) {
    case 0:
        return 1;
        break;
    case 1:
        return 12;
        break;
    default:
        return 0;
        break;
    }
}

int Ranger::ReturnHealAmount() {
    return 5 + rand() % 4; // 5 - 9
}
