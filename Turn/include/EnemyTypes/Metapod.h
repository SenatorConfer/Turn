#ifndef METAPOD_H
#define METAPOD_H

#include "../Enemy.h"


class Metapod : public Enemy {
public:
    Metapod();

    EnemyType GetType() override;
    std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // METAPOD_H
