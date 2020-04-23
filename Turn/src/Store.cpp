#include <iostream>

#include "../include/Common.h"
#include "../include/Store.h"
#include "../include/StoreGreetings.h"
#include "../include/ItemTypes.h"
#include "../include/StoreTypes.h"


using namespace std;
using namespace Common;

const unsigned short arrowsCost = 40;
const unsigned short bombCost = 100;
const unsigned short potionCost = 150;
const unsigned short whetstoneCost = 20;
const unsigned short xattackCost = 200;

//Messages
const string lowCoinsMessage = " Insufficient Coins !";
const string lowItemMessage = " Insufficient Item Amount !";
const string invalidChoice = " Invalid Choice !";
const string invalidAmount = " Invalid Amount ! Choose Between 1 - 9 ! ";

void Store::StoreFront(Player* _Player) {

	unsigned short option = 0;
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
		cout << " ----OPTION----" << endl << endl;
		cout << " 1) Buy Items" << endl;
		cout << " 2) Sell Items" << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		cout << " What would you like to do today? " << endl << endl << " ";
		option = input();
		cout << endl << " ";
		if (option == STORETYPE::BUY) {
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
				cout << " 4) Whetstone\t\t " << whetstoneCost << endl;
				cout << " 5) X-Attack\t\t " << xattackCost << endl << endl;
				cout << " 0) Exit" << endl << endl;
				cout << " ---------------------------------- " << endl << endl;
				cout << " What do you want to buy today?" << endl << endl << " ";
				choice = input();
				cout << endl << " ";
				if (choice > 0 && choice < 6) {
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
					else if (coins < (arrowsCost * amount))
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
					else if (coins < (bombCost * amount))
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
					else if (coins < (potionCost * amount))
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
					else if (coins < (whetstoneCost * amount))
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
				case ITEMTYPE::XATTACK:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (coins < (xattackCost * amount)) {
						cout << amount << lowCoinsMessage << endl;
					}
					else {
						cout << amount << " X-Attack";
						if (amount > 1) {
							cout << "s";
						}
						cout << " purchased !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->AddStoreItemToInventory(ITEMTYPE::XATTACK);
							_Player->LoseCoins(xattackCost);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case 0://Exit Section
					break;
				default:
					cout << invalidChoice << endl;
					Sleep(SLEEP_MS);
				}
			} while (choice);
		}
		else if (option == STORETYPE::SELL) {
			do
			{
				ClearScreen();
				coins = _Player->GetCoins();
				cout << endl << endl;
				_Player->DisplayInventory();
				cout << endl << " Jeremy's Tools Store" << endl;
				cout << " \"" << random_greeting() << "\"" << endl << endl;
				cout << " ----ITEM---------------VALUE------ " << endl << endl;
				cout << " 1) Arrow\t\t " << arrowsCost * .5 << endl;
				cout << " 2) Bomb\t\t " << bombCost * .5 << endl;
				cout << " 3) Potion\t\t " << potionCost * .5 << endl;
				cout << " 4) Whetstone\t\t " << whetstoneCost * .5 << endl;
				cout << " 5) X-Attack\t\t " << xattackCost * .5 << endl << endl;
				cout << " 0) Exit" << endl << endl;
				cout << " ---------------------------------- " << endl << endl;
				cout << " What do you want to sell today?" << endl << endl << " ";
				choice = input();
				cout << endl << " ";
				if (choice > 0 && choice < 6) {
					cout << choice << endl;
					cout << " How many do you want to sell today?" << endl << endl << " ";
					amount = input();
				}
				switch (choice)
				{
				case ITEMTYPE::ARROWS:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (_Player->GetItem(ITEMTYPE::ARROWS) < amount)
					{
						cout << lowItemMessage << endl;
					}
					else
					{
						cout << amount << " Arrow";
						if (amount > 1) {
							cout << "s";
						}
						cout << " sold !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->RemoveStoreItemFromInventory(ITEMTYPE::ARROWS);
							_Player->AddCoins(arrowsCost * .5);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case ITEMTYPE::BOMB:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (_Player->GetItem(ITEMTYPE::BOMB) < amount)
					{
						cout << lowItemMessage << endl;
					}
					else
					{
						cout << amount << " Bomb";
						if (amount > 1) {
							cout << "s";
						}
						cout << " sold !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->RemoveStoreItemFromInventory(ITEMTYPE::BOMB);
							_Player->AddCoins(bombCost * .5);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case ITEMTYPE::POTION:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (_Player->GetItem(ITEMTYPE::POTION) < amount)
					{
						cout << lowItemMessage << endl;
					}
					else
					{
						cout << amount << " Potion";
						if (amount > 1) {
							cout << "s";
						}
						cout << " sold !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->RemoveStoreItemFromInventory(ITEMTYPE::POTION);
							_Player->AddCoins(potionCost * .5);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case ITEMTYPE::WHETSTONE:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (_Player->GetItem(ITEMTYPE::WHETSTONE) < amount)
					{
						cout << lowItemMessage << endl;
					}
					else
					{
						cout << amount << " Whetstone";
						if (amount > 1) {
							cout << "s";
						}
						cout << " sold !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->RemoveStoreItemFromInventory(ITEMTYPE::WHETSTONE);
							_Player->AddCoins(whetstoneCost * .5);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case ITEMTYPE::XATTACK:
					if (amount == 0) {
						cout << invalidAmount << endl;
					}
					else if (_Player->GetItem(ITEMTYPE::XATTACK) < amount) {
						cout << lowItemMessage << endl;
					}
					else {
						cout << amount << " X-Attack";
						if (amount > 1) {
							cout << "s";
						}
						cout << " sold !" << endl;
						for (int i = 0; i < amount; i++) {
							_Player->RemoveStoreItemFromInventory(ITEMTYPE::XATTACK);
							_Player->AddCoins(xattackCost * .5);
						}
					}
					Sleep(SLEEP_MS);
					break;
				case 0://Exit Section
					break;
				default:
					cout << invalidChoice << endl;
					Sleep(SLEEP_MS);
				}
			} while (choice);
		} else if (option == 0) {
			break;//Exit Store
		}
		
	} while (option);
}
