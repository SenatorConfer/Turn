# Test Cases

## User Story A Requirements:



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



## User Story E Requirements:

Req 5.0 - "The game shall include a "Metapod"-type enemy"

This is proven by a luck of the draw. For the time being of this test, any enemy can spawn regardless of the player's level. Once
the player's level dependency has been implemented however the "Metapod" should still spawn at level 1 for confirmation of spawn.

Req 5.0.1 - "The "Metapod"-type enemy shall have a high defense but no attack"

Once the "Metapod" has appeared as the enemy during the battle it will only have the ability to heal and deal no damage to the player.
This was done by restricting the case to only being able to heal.


## User Story F Requirements:



