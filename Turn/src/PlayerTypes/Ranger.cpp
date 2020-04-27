#include "../../include/PlayerTypes/Ranger.h"

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
