#include <iostream>

#include "../include/Common.h"
#include "../include/Store.h"
#include "../include/StoreGreetings.h"
#include "../include/ItemTypes.h"


using namespace std;
using namespace Common;

const unsigned short arrowsCost = 40;
const unsigned short bombCost = 100;
const unsigned short potionCost = 150;
const unsigned short whetstoneCost = 20;

//Messages
const string lowCoinsMessage = " Insufficient Coins !";
const string invalidChoice = " Invalid Choice !";
const string invalidAmount = " Invalid Amount ! Choose Between 1 - 9 ! ";

void Store::StoreFront(Player* _Player) {

	unsigned short choice = 0;
	unsigned short coins;
	unsigned short amount = 0;

	do
	{
		ClearScreen();
		coins = _Player->GetCoins();
		cout << endl << endl;
		_Player->DisplayInventory();
		cout << endl << " Jeremy's Tools Store" << endl;
		cout << " \"" << random_greeting() << "\"" << endl << endl;
		cout << " ----ITEM----------------COST------ " << endl << endl;
		cout << " 1) Arrow\t\t " << arrowsCost << endl;
		cout << " 2) Bomb\t\t " << bombCost << endl;
		cout << " 3) Potion\t\t " << potionCost << endl;
		cout << " 4) Whetstone\t\t " << whetstoneCost << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		cout << " What do you want to buy today?" << endl << endl << " ";
		choice = input();
		cout << endl << " ";
		if (choice > 0 && choice < 5) {
			cout << choice << endl;
			cout << " How many do you want to buy today?" << endl << endl << " ";
			amount = input();
		}
		switch (choice)
		{
		case ITEMTYPE::ARROWS:
			if (amount == 0) {
				cout << invalidAmount << endl;
			}
			else if (coins < (arrowsCost*amount))
			{
				cout << lowCoinsMessage << endl;
			}
			else
			{
				cout << amount << " Arrow";
				if (amount > 1) {
					cout << "s";
				}
				cout << " purchased !" << endl;
				for (int i = 0; i < amount; i++) {
					_Player->AddStoreItemToInventory(ITEMTYPE::ARROWS);
					_Player->LoseCoins(arrowsCost);
				}
			}
			Sleep(SLEEP_MS);
			break;
		case ITEMTYPE::BOMB:
			if (amount == 0) {
				cout << invalidAmount << endl;
			}
			else if (coins < (bombCost*amount))
			{
				cout << lowCoinsMessage << endl;
			}
			else
			{
				cout << amount << " Bomb";
				if (amount > 1) {
					cout << "s";
				}
				cout << " purchased !" << endl;
				for (int i = 0; i < amount; i++) {
					_Player->AddStoreItemToInventory(ITEMTYPE::BOMB);
					_Player->LoseCoins(bombCost);
				}
			}
			Sleep(SLEEP_MS);
			break;
		case ITEMTYPE::POTION:
			if (amount == 0) {
				cout << invalidAmount << endl;
			}
			else if (coins < (potionCost*amount))
			{
				cout << lowCoinsMessage << endl;
			}
			else
			{
				cout << amount << " Potion";
				if (amount > 1) {
					cout << "s";
				}
				cout << " purchased !" << endl;
				for (int i = 0; i < amount; i++) {
					_Player->AddStoreItemToInventory(ITEMTYPE::POTION);
					_Player->LoseCoins(potionCost);
				}
			}
			Sleep(SLEEP_MS);
			break;
		case ITEMTYPE::WHETSTONE:
			if (amount == 0) {
				cout << invalidAmount << endl;
			}
			else if (coins < (whetstoneCost*amount))
			{
				cout << amount << lowCoinsMessage << endl;
			}
			else
			{
				cout << amount << " Whetstone";
				if (amount > 1) {
					cout << "s";
				}
				cout << " purchased !" << endl;
				for (int i = 0; i < amount; i++) {
					_Player->AddStoreItemToInventory(ITEMTYPE::WHETSTONE);
					_Player->LoseCoins(whetstoneCost);
				}
			}
			Sleep(SLEEP_MS);
			break;
		case 0://Exit Store
			break;
		default:
			cout << invalidChoice << endl;
			Sleep(SLEEP_MS);
		}
	} while (choice);
}
