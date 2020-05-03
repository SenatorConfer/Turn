# Test Cases

## User Story A Requirements:

Req. 1.0 - "The game shall include a store that allows users to purchase items"

The git repository already came with a store. However, to test this, I used the option associated with the store in the main menu to make sure I could select it.

Req. 1.0.1 - "The game shall include a store that allows user to purchase in-game items with in-game coins"

The git repository already came with a store that used in-game coins. However, to test this, I purchased random items to make sure the purchase was correct.

Req. 1.0.2 - "The game shall include a store that allows a user to purchase 1-9 of a single item per transaction"

The way to confirm this was to purchase a random amount of a random item multiple times. Each time, assuming they met Req. 1.0.3, the system added the amount of the item requested to the inventory while reducing the number of coins in the inventory.

Req. 1.0.3 - "The game shall not allow a user to purchase an item if they do not have the necessary amount of coins"

The git repository already came with a store that did not allow an item purchase without necessary coins. However, to test this, I purchased a random item a random amount of times (where the final price exceeded coin count) to make sure the feature was implemented correctly.

Req. 1.1 - "The game shall include a store that allows users to sell items"

The way to confirm that this worked was to choose the Store option from the main menu and choose the Sell option from the Store.

Req. 1.1.1 - "The game shall include a store that allows users to sell in-game items for in-game coins"

The way to confirm this was to sell a random item. Each time, assuming they met Req. 1.1.3, the system reduced the amount of the item sold from the inventory while increasing the number of coins in the inventory.

Req. 1.1.2 (Jonathan): The game shall include a store that allows users to sell 1-9 of a single item per transaction

The way to confirm this was to sell a random amount of a random item multiple times. Each time, assuming they met Req. 1.1.3, the system reduced the amount of the item sold from the inventory while increasing the number of coins in the inventory.

Req. 1.1.3 (Jonathan): The game shall not allow a user to sell an item if they do not have the necessary amount of item(s) to sell

To test this, I sold a random item a random amount of times (where the items sold exceeded items in inventory) to make sure the feature was implemented correctly.

## User Story B Requirements:

Req 2.0 - "The game shall implement intellgent AI enemies"

The way to confirm this was added to the game was based off of percent chance that the enemy would never heal when they are at 100%
health. The enemies also would heal more often if they were to go below 50% health. This was accomplished through nested sets of
cases in a if, if else, and else statement.

Req 2.0.1 - "The enemy shall not heal when at full heath"

This was a continuation of Req 2.0 where we had an if statement that determined if the enemy health is equal to 100 then their would
not be a case scenario where the enemy would heal.

Req 2.0.2 - "The enemy AI shall heal more frequently in battle when below 50% health"

This was a continuation of Req 2.0 where we had an if statement that determined if the enemy health is below 50 then the odds that the
random number generator would result in a case that led to a heal was greater.


## User Story C Requirements:

Req 3.0 - "The game shall include multiple player classes"

This can be confirmed when loading the game for the first time without a data file previosuly existing. Once the game starts it will
prompt the user for information about their desired character ex: name, gender, and class confirming the existence of multiple player
classes.

Req 3.0.1 - "The game shall include a special attack in battle for the respective player classes"

During combat the player is shown the health bars of both their player and the enemy. Below the player's health bar there is a special
attack bar. Once that special attack bar/value reaches 100/100 (The bar will be completely red) the player has the ability to activate
their special attack.

Req 3.0.1.1 - "The special attack for the respective player class shall inflict damage relevant to their class."

Once the player has activated the special attack the damage is dependent on the class they have chosen and the damage based off of
that class's generic attack damage is determinant of the class's special attack damage.

Req 3.1 - "The game shall include more player classes than the default class"

This is proven in that by default the only available classes available were the "Debugger", "Healer", "Rogue", "Saitama", and the
"Warrior". If you were to create a character you can see that there is a new "Ranger" class available to be chosen that starts
with additional arrows unlike the other classes.


## User Story D Requirements:

Req. 4.0 - "The game shall implement an armor system"

This can be confirmed by purchasing an X-Defense from the Store.

Req. 4.0.1 - "The game shall implement an armor system that reduces damage dealt to the Player"

The way to confirm this was, while having an X-Defense in the inventory, use it during battle to reduce an Enemy's damage to the Player.

Req. 4.1 - "The X-Attack system shall be an option the player can choose during a fight to increase damage."

This can be confirmed by purchasing an X-Attack from the Store.

Req. 4.1.1 - "The game shall implement an X-Attack System that increases the damage dealt from a Player for a brief time during battle"

The way to confirm this was, while having an X-Attack in the inventory, use it during battle to increase the Player's damage to an Enemy.

## User Story E Requirements:

Req 5.0 - "The game shall include a "Metapod"-type enemy"

This is proven by a luck of the draw. For the time being of this test, any enemy can spawn regardless of the player's level. Once
the player's level dependency has been implemented however the "Metapod" should still spawn at level 1 for confirmation of spawn.

Req 5.0.1 - "The "Metapod"-type enemy shall have a high defense but no attack"

Once the "Metapod" has appeared as the enemy during the battle it will only have the ability to heal and deal no damage to the player.
This was done by restricting the case to only being able to heal.
