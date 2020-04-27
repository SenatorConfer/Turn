#ifndef RANGER_H
#define RANGER_H

#include "../Player.h"


class Ranger : public Player {
public:
    Ranger(void);
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // RANGER_H
#pragma once
