/*
 * unittest5.c
 *
 * Mine actions:
 * Trash a copper for a silver
 * Or trash a silver for a gold
 * 
 * unittest5: unittest5.c dominion.o rngs.o
 * 	gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
 * 
 * Note: Much of the below code uses parts of cardtest4.c example from Week 3 module
 * * */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"
void asserttrue (int gameTest, int gameControl)
{
if (gameTest == gameControl)
{
printf("TEST PASSED!\n");
}

else
{
printf("TEST FAILED!\n");
}
}

int main (){

int handpos = 0;
int choice1=0;
int choice2=0;
int choice3=0;
int bonus=0;
int coins=0;

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);
//printf("----------TEST 1: choice1=1.  -1 estate & +4 coins----------");
printf("TEST 1: choice1=1.  -1 estate & +4 coins\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
choice1 = 3;
choice2 = 5;
mineRefactored(thisPlayer, choice1, choice2, &gameTest, handpos);

printf("TEST 1: \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);

printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins));

printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]);

printf("Using Assert True Function...\n");
asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]);
printf("----------\n");

//////////////////////////////////////TEST1
//
/////////////////////////////////////////TEST2

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
choice1 = 1;
choice2 = 6;
//cardEffect(baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
mineRefactored(thisPlayer, choice1, choice2, &gameTest, handpos);

printf("TEST 2: \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);

printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins));

printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]);

printf("Using Assert True Function...\n");
asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]);
printf("----------\n");

return 0;
}
















