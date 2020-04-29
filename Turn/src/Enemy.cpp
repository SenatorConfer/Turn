#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "../include/Common.h"
#include "../include/Enemy.h"
#include "../include/Console.h"

using namespace std;
using namespace Common;


Enemy::Enemy(){
    // Sets up the default variables for the enemy.

    // Sets health to max.
    health = 100;

    // Sets experience amount to 0, just an initialization for the child classes to modify.
    ExperienceAmount = 0;
}

int Enemy::Harden() {
    // Could be changed later into a harden armor action once implemented
    Heal();
    return 0;
}

int Enemy::Action(){
    // Returns damage hit for the player. Uses random number to select enemy's move.
    /*!
    This if statement satisfies User Story B.
    Req 2.0 - Enemies will focus on protecting their own life instead of just attacking once their about to die and are more likely to heal
    Req 2.0.1 - If the Enemy is at full health they will not waste their turn by healing.
    Req 2.0.2 - Once the enemy is below 50 health the odds that they will heal increase and the amount of times they attack lowers.
    Link - github.com/SenatorConfer/Turn/blob/master/Requirements.md
    */
  int selector = rand()%9;
  if (health < 50) {
      switch (selector) {
      case 0: case 1: case 2: 
          // 3/9 chance of risk attacking.
          return RiskAttack();
          break;
      case 3: case 4: case 5: case 6:
          // 4/9 chance of healing.
          Heal();
          return 0;
          break;
      case 7: case 8:
          // 2/9 chance of generically attacking.
          return GenericAttack();
          break;
      default:
          // Returns 0 damage in case selector goes wrong.
          return 0;
          break;
      }
   }
  else if(health >= 100) {
      switch (selector) {
      case 0: case 1: case 2:
          // 3/9 chance of risk attacking.
          return RiskAttack();
          break;
      case 3: case 4: case 5: case 6: case 7: case 8:
          // 6/9 chance of generically attacking.
          return GenericAttack();
          break;
      default:
          // Returns 0 damage in case selector goes wrong.
          return 0;
          break;
      }
  }
  else {
      switch (selector) {
      case 0: case 1:
          // 2/9 chance of risk attacking.
          return RiskAttack();
          break;
      case 2: case 3:
          // 2/9 chance of healing.
          Heal();
          return 0;
          break;
      case 4: case 5: case 6: case 7: case 8:
          // 5/9 chance of generically attacking.
          return GenericAttack();
          break;
      default:
          // Returns 0 damage in case selector goes wrong.
          return 0;
          break;
      }
  }
    
}

void Enemy::DisplayHUD(){
    // Displays the enemy's health bar.
	cout << "\t";
	DisplayHealthBar();
    cout << endl << endl;
}



vector<int> Enemy::GetDrops(){
    // Returns the number of items dropped when the enemy is defeated depending on the item won.
	vector<int> drops;

	for (int i = 0; i < NUM_ITEMS; i++) {
		drops.push_back(ReturnItemDrop(i));
	}

    return drops;
}

int Enemy::ReturnExperience(){
    // Returns the amount of experience the player gets when the enemy dies, or the amount of experience
    // lost if the player dies.
    return ExperienceAmount;
}

int Enemy::GenericAttack(){
    // Returns a generic attack, just a simple attack.

    int damage = ReturnDamage();

    // Prints how much damage the enemy deals to the player.
	ColourPrint(name, Console::DarkGrey);
    cout << " attacks! It deals ";
	ColourPrint(to_string(damage), Console::Red);
    cout << " damage!" << endl << endl;
    return damage;
}

int Enemy::RiskAttack(){
    // Returns a risk attack, having a chance of dealing either very low points or high points.

    int damage = ReturnRiskAttackDamage();

    // Prints how much damage the enemy deals to the player.
	ColourPrint(name, Console::DarkGrey);
    cout << " takes a risk and attacks! It deals ";
	ColourPrint(to_string(damage), Console::Red);
    cout << " damage!" << endl << endl;
    return damage;
}

int Enemy::ReturnItemDrop(int item){
    int ArrowSelector = rand()%6;
    int WhetstoneSelector = rand()%2;
    int PotionSelector = rand()%10;

	/* 
	0	Arrows
	1	Bombs
	2	Potions
	3	Whetstones
	4	Coins
	*/

    switch(item){
    case 0:	// Arrows
        if (ArrowSelector<=1)
            return 0;
        else if (ArrowSelector==2||ArrowSelector==3)
            return 3;
        else
            return 5;
	case 1: case 2:
		if (PotionSelector == 0)
			return 1;
		else if (PotionSelector == 1)
			return 2;
		else
			return 0;
	
    case 3:
        if (WhetstoneSelector==1)
            return 1;
        else
            return 0;
	case 4:
		return CoinsDrop;

    default:
        return 0;
        break;
    }
}

std::string Enemy::GetIntro()
{
	return "A distant noise coming closer...";
}
