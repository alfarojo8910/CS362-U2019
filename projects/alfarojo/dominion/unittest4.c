/*
 * unittest4.c
 *
 * Tribute actions:
 * Player to the left reveals then discards top 2 cards of deck.
 * If card is action +2 actions
 * If treasure card: +2 coins
 * If victory card: +2 cards
 * 
 * unittest1: unittest4.c dominion.o rngs.o
 * 	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "tribute"
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

int extraCoins = 2;
int extraActions =2;
int extraCards =2;

int bonus=0;

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

//0 = treasure

int tributeRevealedCards[2] = {1,1};
int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, tribute, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);

memcpy (&gameTest, &gameControl, sizeof(struct gameState));
tributeRefactor(thisPlayer, otherPlayer, tributeRevealedCards, &gameTest);

//****************************TEST1**************************
printf("TEST 1: tributeRevealedCards[2] = 1 Treasure and 1 Victory Card\n");
printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+extraCoins);

printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins)+extraCoins);

printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

printf("Action Number = %d, expected = %d\n", gameTest.numActions, gameControl.numActions);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numActions, gameControl.numActions);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");



return 0;
}
