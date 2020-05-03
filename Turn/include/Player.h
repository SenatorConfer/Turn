#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Enemy.h"
#include "Sound.h"

class Player : public Entity, public SoundMaker {
    // Contains the functions needed to construct the player's character.
    public:
		Player(void);
		void SaveGame();
		void SetPlayerData();
		void TakeDamage(int damage);
		int Action();
		int UseAttack();
		int UseItem();
		void UseItemNonBattle();
		void AddToInventory(std::vector<int>);
		void AddStoreItemToInventory(int);
		void RemoveStoreItemFromInventory(int);
		void DisplayHUD(Enemy*);
		void DisplaySpecialBar();
		void DisplaySpecial();
		void AddSpecial();
		void ReplenishHealth();
		void AddXAttack();
		void LoseXAttack();
		void AddXDefense();	
		void LoseXDefense();

		void AddExperience(int);
		void LoseExperience(int);
		void AddCoins(int);
		void LoseCoins(int);

		void DisplayInventory();
		int GetCoins();
		int GetItem(int);    
		void SetType(int);
		int GetType();

	private:
		int GenericAttack();
		int RiskAttack();
		int SpecialAttack();
		int BowAndArrow();

		void UseWhetstone();
		void UsePotion();
		int UseBomb();
		void DeductDamage(int&);
		int ReturnBowDamage();
		void WeakenWeapon(int impact);

		int Flee();
		
		void PrintInventoryItem(std::string, int, std::string);
		void PrintXPBar(std::string, int, std::string, std::string, int, std::string);
		void PrintDivider(char, char, std::string);


		int player_type;
		int level;
		int special = 0;
		char gender;
		int experience;
		int whetstones;
		int arrows;
		int potions;
		int bombs;
		int weaponstrength;
		int xAttack; /*!< The amount of the item "X-Attack" that the Player has in his inventory */
		int usedXAttack = 0; /*!< The amount of the item "X-Attack" that the Player has used during battle */
		int xDefense; /*!< The amount of the item "X-Defense" that the Player has in his inventory */
		int usedXDefense = 0; /*!< The amount of the item "X-Defense" that the Player has used during battle */
		int coins;
};

#endif // PLAYER_H
