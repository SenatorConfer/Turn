#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

#include "../include/Common.h"
#include "../include/Player.h"
#include "../include/Console.h"
#include "../include/ItemTypes.h"

using namespace std;
using namespace Common;

#define SKIP_TURN -2

Player::Player(void) 
{
	// Initialize default sounds, attackRange should be 
	// the result range of the ReturnDamage method in the child class
	// Child constructor should call SetSoundInfo with appropriate stuff
	SoundInfo info;
	info.attackRange = std::make_pair(1, 1);
	SetSoundInfo(info);
}

void Player::SaveGame(){

	ofstream WriteData;
	WriteData.open("data.txt");
	if (WriteData.is_open()) {
        	WriteData << player_type << endl 
			<< name << endl
            << gender << endl
			<< level << endl
			<< experience << endl
			<< health << endl
			<< arrows << endl
			<< bombs << endl
			<< potions << endl
			<< whetstones << endl
			<< xAttack << endl
			<< weaponstrength << endl
			<< coins;
    		WriteData.close();
	} else {
		cout << "Error opening savegame data (data.txt)." << endl;
	}
}



void Player::SetPlayerData(){
    // Primarily initializes default values at the beginning of the game.

	ifstream ReadData;
	ReadData.clear();
	ReadData.open("data.txt");
	if (ReadData.is_open())	{
		ReadData >> player_type;
		ReadData.ignore();       // Ignore rest of line ready for getline
		getline(ReadData, name);
		ReadData >> gender;
		ReadData >> level;
		ReadData >> experience;
		ReadData >> health;
		ReadData >> arrows;
		ReadData >> bombs;
		ReadData >> potions;
		ReadData >> whetstones;
		ReadData >> xAttack;
		ReadData >> weaponstrength;
		ReadData >> coins;
		ReadData.close();
 	} else {
		cout << "Error opening savegame data (data.txt)." << endl;
	}
}

int Player::Action(){
    // Returns the amount of attack points the player gives.
    // Also the main battle screen.

    int choice = 0;


    // Displays the inventory.
    DisplayInventory();

    // Gives player a list of moves to choose from.
	cout << "Choose your move:" << endl
		<< "1) Attack" << endl
		<< "2) Risk Attack" << endl
		<< "3) Special Attack" << endl
		<< "4) Bow and Arrow" << endl
		<< "5) Heal" << endl << endl
		<< "6) Use Bomb" << endl
		<< "7) Use Potion" << endl
		<< "8) Use Whetstone" << endl
		<< "9) Use X-Attack" << endl
		<< "0) Get me out of here!" << endl << endl;

	while (true) {
		choice = input();
		int damage = 0;
		// Evaluates player's choice.
		switch (choice) {
		case 0:
			return Flee();
		case 1:
			// Player generically attacks.
			damage = GenericAttack();
			PlayPrimaryAttack(damage);
			AddSpecial();
			return damage;
		case 2:
			// Player takes a risk and attacks.
			damage = RiskAttack();
			PlayPrimaryAttack(damage);
			AddSpecial();
			return damage;
		case 3:
			/*!
				This case works toward User Story C.
				Req 3.0.1 - Implementation of a special attack has been added to the game and is based on the player's class.
				Req 3.0.1.1 - Based on the player's class the special attack will do damage relevant to their class.
				I chose this way of implementation because it was the most native way to implement it into the game while
				looking like the original attack codes.
				Link - github.com/SenatorConfer/Turn/blob/master/Requirements.md
			*/
			// Player uses their special attack
			if (special >= 100) {
				damage = SpecialAttack();
				PlayPrimaryAttack(damage);
				special = 0;
				return damage;
			}
			else {
				cout << "Your special attack is not charged!" << endl;
				Sleep(SLEEP_MS);
				return SKIP_TURN;
			}
		case 4:
			// Player shoots their bow.
			if (arrows > 0)
			{
				PlaySecondaryAttack();
				AddSpecial();
				return BowAndArrow();
			}
			else {
				cout << "No arrows in the inventory!" << endl;
				Sleep(SLEEP_MS);
				return SKIP_TURN;
			}
		case 5:
			// Player heals, no damage is done to enemy.
			PlayHeal();
			Heal();
			return 0;
		case 6:
			// Player throws a bomb.
			// Does not execute if there are no bombs in the inventory.
			if (bombs > 0) {
				AddSpecial();
				return UseBomb();
			}
			else {
				cout << "No bombs in the inventory!" << endl;
				return SKIP_TURN;
			}
		case 7:
			// Player drinks a potion.
			// Does not execute if there are no potions in the inventory.
			if (potions > 0) {
				UsePotion();
				return 0;
			}else {
				cout << "No potions in the inventory!" << endl;
				return SKIP_TURN;
			}
		case 8:
			// Player sharpens their weapon with a whetstone.
			// Does not execute if there are no whetstones in inventory.
			// No damage is done to the enemy.
			if (whetstones > 0) {
				UseWhetstone();
				return 0;
			} else {
				cout << "No whetstones in the inventory!" << endl;
				return SKIP_TURN;
			}
		case 9:
			// Player increases their attack power.
			// Does not execute if there are no X-Attacks in inventory.
			// No damage is done to the enemy.
			if (xAttack > 0) {
				AddXAttack();
				return 0;
			}
			else {
				cout << "No X-Attacks in the inventory!" << endl;
				return SKIP_TURN;
			}
		default:
			// Generically attacks by default if player's choice does not equal above cases.
			return GenericAttack();
		}
	}
}

void Player::UseItem() {
	// Use item from inventory
	int choice = 0;

	while (true) {
		ClearScreen();

		// Displays the inventory.
		DisplayInventory();

		// Gives player a list of moves to choose from.
		cout << "Choose which item use:" << endl
			<< "1) Use Potion" << endl
			<< "2) Use Whetstone" << endl
			<< "0) Quit" << endl << endl;

		choice = input();

		// Evaluates player's choice.
		switch (choice) {
		case 0:
			return;
		case 1:
			// Player drinks a potion.
			// Does not execute if there are no potions in the inventory.
			if (potions > 0) {
				UsePotion();
				Sleep(SLEEP_MS);
			} else {
				cout << "No potions in the inventory!" << endl;
				Sleep(SLEEP_MS);

			}
			break;
		case 2:
			// Player sharpens their weapon with a whetstone.
			// Does not execute if there are no whetstones in inventory.
			// No damage is done to the enemy.
			if (whetstones > 0) {
				UseWhetstone();
				Sleep(SLEEP_MS);
			} else {
				cout << "No whetstones in the inventory!" << endl;
				Sleep(SLEEP_MS);
			}

			break;
		default:
				cout<<"Item not present in the inventory!"<<endl;
 				Sleep(SLEEP_MS);
			break;
		}
	}
}

void Player::AddToInventory(vector<int> drops){
    // Adds items to inventory and prints out what the player received.

    // Adds items received to total items.
    arrows += drops.at(0);
	bombs += drops.at(1);
	potions += drops.at(2);
	whetstones += drops.at(3);
    coins += drops.at(4);


    // Prints number of items received.
	cout << "You have gained: " << endl;
	if (drops[0] > 0)
		cout << "[" << drops.at(0) << "] arrows" << endl;
	if (drops[1] > 0)
		cout << "[" << drops.at(1) << "] bombs" << endl;
	if (drops[2] > 0)
		cout << "[" << drops.at(2) << "] potions" << endl;
	if (drops[3] > 0)
		cout << "[" << drops.at(3) << "] whetstones" << endl;
	if (drops[4] > 0)
         cout << "[" << drops.at(4) << "] coins" << endl;

	cout << endl;
}

void Player::AddStoreItemToInventory(int type) {
	// Adds items bought to total items.
	switch (type)
	{
	case ITEMTYPE::ARROWS:
		++arrows;
		break;
	case ITEMTYPE::BOMB:
		++bombs;
		break;
	case ITEMTYPE::POTION:
		++potions;
		break;
	case ITEMTYPE::WHETSTONE:
		++whetstones;
		break;
	case ITEMTYPE::XATTACK:
		++xAttack;
		break;
	}
}

void Player::RemoveStoreItemFromInventory(int type) {
	switch (type)
	{
	case ITEMTYPE::ARROWS:
		--arrows;
		break;
	case ITEMTYPE::BOMB:
		--bombs;
		break;
	case ITEMTYPE::POTION:
		--potions;
		break;
	case ITEMTYPE::WHETSTONE:
		--whetstones;
		break;
	case ITEMTYPE::XATTACK:
		--xAttack;
		break;
	}
}

void Player::DisplayHUD(Enemy *_Enemy){
    // Displays player's name and health bar. Enemy object is used to print name on the same line as player name for aesthetics.

    // Prints player's name.
    cout << endl;
	ColourPrint(name, Console::DarkGrey);
    // Tabs to make room for enemy's name.
    if (name.length() > 5){
        cout << "\t\t\t";
    }
    else {
        cout <<" \t\t\t";
    }
    // Prints enemy name.
	ColourPrint(_Enemy->GetName(), Console::DarkGrey);
	cout << endl;
	DisplayHealthBar();
}

void Player::DisplaySpecial() {
	ColourPrint("Special Attack", Console::DarkGrey);
	cout << endl;
	DisplaySpecialBar();
	cout << endl << endl;
}

void Player::DisplaySpecialBar() {
	string specialBar = "        " + to_string(special);

	for (int i = specialBar.length(); i < 20; i++)
		specialBar += " ";

	for (size_t i = 0; i < specialBar.length(); i++) {
		string currentChar = "";
		currentChar += specialBar.at(i);
		if ((i + 1) * 10 <= (size_t)special * 2) {
			ColourPrint(currentChar, Console::Background_Red);
		}
		else {
			ColourPrint(currentChar, Console::Background_Grey);
		}
	}
}

void Player::AddSpecial() {
	if (special == 100) {
		special = 100;
	}
	else {
		special += 25;
	}
}

void Player::ReplenishHealth(){
    // Adds health points after player has defeated an enemy.
	if (health <= 0)
		health = 100;
	else {
		health += 30;
		if (health > 100) health = 100;
	}
}

void Player::AddXAttack() {
	// Adds an X-Attack to player
	usedXAttack += 1;
	xAttack -= 1;
	ColourPrint(name, Console::DarkGrey);
	cout << " used an X-Attack! " << endl;
}

void Player::LoseXAttack() {
	// Clears the used X-Attack from Player after each battle
	usedXAttack = 0;
}

void Player::AddExperience(int xp){
    // Adds points to the player's experience and levels player up.

    // Adds experience from passed in integer to local class variable experience.
    experience += xp;

    // Evaluates if experience is higher than 99, which means a level up is in order.
    if (experience>99) {
        // Experience is set to 0.
        experience = 0;

        // Player is leveled up.
        level+=1;

        // Sets level cap to 50, player cannot level higher than that.
        if (level >= 50) level = 50;

        // Alerts player that they have leveled up.
        cout << "You leveled up! Now you are level " << level << "!" << endl;
        Sleep(SLEEP_MS);
    }
}

void Player::LoseExperience(int xp){
    // Deducts points from the player's experience and de-levels player.

    // Deducts experience from passed in integer to local class variable experience.
    experience -= xp;

    // Evaluates if experience is less than 0.
    if (experience<0){
        // Experience is deducted continuing from the experience which de-leveled the player (hard to explain...)
        experience = 100-(0-experience);

        // De-levels player.
        level-=1;

        // Checks any glitches and sets player level to 1 if level is below 1 or above 50.
        // Also resets experience points.
        if (level<1 || level>50){
            level=1;
            experience = 0;
        }

        // Alerts the player that they have de-leveled.
        else {
            cout << "You de-leveled back to level " << level << "..." << endl;
            Sleep(SLEEP_MS);
        }
    }
}

void Player::AddCoins(int c){
    coins += c;
}

void Player::LoseCoins(int c){
    coins -= c;
    if (coins < 0) coins = 0;
}

void Player::DisplayInventory(){
    // Checks valid weapon strength.
    if (weaponstrength < 0){
        weaponstrength = 0;
    }
    // Simply prints the player's inventory.

    PrintDivider('*', '-', " INVENTORY ");
    PrintXPBar("Level ", level, "", "", experience, "/100 xp");
    PrintDivider('+', '-', "");
    PrintInventoryItem("Arrows: [", arrows, "]");
    PrintInventoryItem("Potions: [", potions, "]");
    PrintInventoryItem("Bombs: [", bombs, "]");
    PrintInventoryItem("Whetstones: [", whetstones, "]");
	PrintInventoryItem("X-Attack: [", xAttack, "]");
    PrintInventoryItem("Weapon strength: [", weaponstrength, "%]");
    PrintInventoryItem("Wealth: [", coins, "] coins");
    PrintDivider('*', '-', "");
}

int Player::GetCoins() {
    return coins;
}

int Player::GetItem(int type) {
	switch (type)
	{
	case ITEMTYPE::ARROWS:
		return arrows;
		break;
	case ITEMTYPE::BOMB:
		return bombs;
		break;
	case ITEMTYPE::POTION:
		return potions;
		break;
	case ITEMTYPE::WHETSTONE:
		return whetstones;
		break;
	case ITEMTYPE::XATTACK:
		return xAttack;
		break;
	}
}

int Player::GenericAttack(){
	int damage = 0;
	if (usedXAttack > 0) {
		damage = ReturnDamage() * 5 * .25 + usedXAttack;
	}
	else {
		damage = ReturnDamage();
	}
    DeductDamage(damage);
	ColourPrint(name, Console::DarkGrey);
    if (gender == 'M')
        cout << " attacks! He deals ";
    else
        cout << " attacks! She deals ";
	ColourPrint(to_string(damage), Console::Red);
    cout << " damage points!" << endl;
    if (damage>0) WeakenWeapon(2);
    return damage;
}

int Player::RiskAttack(){
	int damage = 0;
	if (usedXAttack > 0) {
		damage = ReturnRiskAttackDamage() * 5 * .25 + usedXAttack;
	}
	else {
		damage = ReturnRiskAttackDamage();
	}
    DeductDamage(damage);
	ColourPrint(name, Console::DarkGrey);
    cout << " takes a risk and attack! It deals ";
	ColourPrint(to_string(damage), Console::Red);
    cout << " damage points!" << endl;

    if (damage>0) WeakenWeapon(4);
    return damage;

}

int Player::SpecialAttack() {
	int damage, damage2 = 0;
	if (usedXAttack > 0) {
		damage = ReturnDamage() * 5 * .25 + usedXAttack;
		damage2 = ReturnDamage() * 5 * .25 + usedXAttack;
	}
	else {
		damage = ReturnDamage();
		damage2 = ReturnDamage();
	}
	int damage3 = damage + damage2;
	DeductDamage(damage);
	DeductDamage(damage2);
	ColourPrint(name, Console::DarkGrey);
	if (gender == 'M')
		cout << " throws out a fury of blows! He deals ";
	else
		cout << " throws out a fury of blows! She deals ";
	ColourPrint(to_string(damage), Console::Red);
	cout << " and ";
	ColourPrint(to_string(damage2), Console::Red);
	cout << " damage points!" << endl;
	if (damage > 0 || damage2 > 0) {
		WeakenWeapon(2);
	}
	return damage3;
}

void Player::WeakenWeapon(int impact){
	if (impact >= 0) weaponstrength -= impact + rand() % 5;
	else weaponstrength -= rand() % 5;
	
	if (weaponstrength < 0)
	{
		weaponstrength = 0;
	}
}

int Player::BowAndArrow(){
    int damage = ReturnBowDamage();
	ColourPrint(name, Console::DarkGrey);
    if (gender == 'M')
        cout << " shoots his bow! He deals ";
    else
        cout << " shoots her bow! She deals ";
	Console::GetInstance().SetColour(Console::EColour::Red);
    cout << damage;
	Console::GetInstance().SetColour(Console::EColour::Default);
    cout << " damage points!" << endl;
    return damage;
}

void Player::UseWhetstone(){
    weaponstrength=100;
	ColourPrint(name, Console::DarkGrey);
    if (gender == 'M')
        cout << " sharpened his weapon!" << endl;
    else
        cout << " sharpened her weapon!" << endl;
    whetstones--;
}

void Player::UsePotion(){
    health=100;
	ColourPrint(name, Console::DarkGrey);
    cout << " drank a healing potion!" << endl;
    potions--;
}

int Player::UseBomb(){
	ColourPrint(name, Console::DarkGrey);
    cout << " hurls a bomb! It deals ";
	ColourPrint("50", Console::Red);
	cout << " damage points!" << endl;

	bombs--;
    return 50;
}

void Player::DeductDamage(int &damage){
    if (weaponstrength<=75&&weaponstrength>50)
        damage-=1;
    else if (weaponstrength<=50&&weaponstrength>30)
        damage-=4;
    else if (weaponstrength<=30&&weaponstrength>20)
        damage-=5;
    else if (weaponstrength<=20&&weaponstrength>10)
        damage-=6;
    else if (weaponstrength<=10)
        damage-=7;
    if (damage<0)
        damage=0;
}

void Player::SetType(int type) {
	player_type = type;
}

int Player::GetType() {
	return player_type;
}

int Player::ReturnBowDamage(){
    if (arrows < 1)
        return 0;
    arrows--;
    return 10+rand()%6; // 10 - 15
}

int Player::Flee(){
	ColourPrint(name, Console::DarkGrey);
    cout << " chooses to flee!" << endl;
    return -1;
}

void Player::PrintInventoryItem(string preText, int itemCount, string postText)
{
	int countLength = 0, countCopy = itemCount;
	// Calculate length of itemCount
	do {
		countLength++;
		countCopy /= 10;
	} while (countCopy);

	// Subtract space used in line (4 spaces for front and back dash/space combos, length of start and end text, length of itemCount) from the total available width
	int freeSpace = 35 - 4 - preText.length() - postText.length() - countLength;

	// Create a string with the appropriate number of spaces to make the line meet required width
	string spaces(freeSpace, ' ');

	// Print the line
	cout << "| " << preText << itemCount << postText << spaces << " |" << endl;
}

void Player::PrintXPBar(string preText1, int level, string postText1, string preText2, int experience, string postText2)
{
	int countLength = 0, levelCopy = level, experienceCopy = experience;
	// Calculate length of level and experience
	do {
		countLength++;
		levelCopy /= 10;
	} while (levelCopy);
	do {
		countLength++;
		experienceCopy /= 10;
	} while (experienceCopy);

	// Subtract space used in line (4 spaces for front and back dash/space combos, length of start and end text, length of level and experience) from the total available width
	int freeSpace = 35 - 4 - preText1.length() - postText1.length() - preText2.length() - postText2.length()- countLength;

	// Create a string with the appropriate number of spaces to make the line meet required width
	string spaces(freeSpace, ' ');

	// Print the line
	cout << "| " << preText1 << level << postText1 << spaces << preText2 << experience << postText2 << " |" << endl;
}

void Player::PrintDivider(char edge, char filler, string centerText)
{
	int countLength = 0;

	// Subtract space used in line (2 spaces for edge symbols, length of centerText) from the total available width
	int freeSpace = 35 - 2 - centerText.length();
	int frontSpace = freeSpace/2;
	int rearSpace = freeSpace - frontSpace;

	// Create a the front and rear filler string
	string frontFiller(frontSpace, filler);
	string rearFiller(rearSpace, filler);

	// Print the line
	cout << edge << frontFiller << centerText << rearFiller << edge << endl;
}
