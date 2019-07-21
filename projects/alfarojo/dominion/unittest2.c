/*
 * unittest2.c
 *
 * minion actions:
* +1 Action
 *
 * Choose one: + 2 coins
 * or +4 cards and other player with 5+ cards
 * discards and draws 4 cards
 *
 * Bugs:  
 * Bug#1: if (state->handCount[i] > 5)
 * If the other player as 6+ plus cards they will discard
 *
 * Bug#2: for (int j=0; j < 7; j++).
 * Other player will draw 7 cards
 *
 * unittest2: unittest2.c dominion.o rngs.o
 * 	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "minion"

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
int extraCoins = 0;	//variables related to baron actions
int discardEstate=0;
int gainEstate=0;
int addBuy=0;

int handpos = 0;
int choice1=0;
int choice2=0;
int choice3=0;
int bonus=0;
int coins=0;

int remove1;
int remove2;

int scoreIncrement=0;
int buysDeduct = 0;


int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, minion, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);
//****************************TEST1**************************
printf("TEST 1: choice1=1.  +2 coins +1 action\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
//choice1=1 represents discarding an estate and receiving 4 coins
choice1 = 1;
//cardEffect(minion, choice1, choice2, choice3, &gameTest, handpos, &bonus);
minionRefactor(thisPlayer, choice1, choice2, &gameTest, handpos);
extraCoins=2;
discardEstate=1;
int actionIncrement=1;
printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);

printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins + extraCoins));

printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins + extraCoins));
printf("----------\n");

/*
//printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");
*/
printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));

printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl)-scoreIncrement);
printf("----------\n");

printf("Number of Actions: = %d, expected = %d\n", gameTest.numActions, gameControl.numActions+actionIncrement);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numActions, gameControl.numActions+actionIncrement);
printf("----------\n");






printf("\n");
//****************************TEST2********************************
 printf("TEST 2: choice2=1.  handNum=4.  if other player has 5 cards, discards hand draws 4\n");

memcpy(&gameTest, &gameControl, sizeof(struct gameState));

//choice represents gain an estate
//BUG 2:  supply of estates increments up.  player stat unaffected
//by bug.  supply of estates for game goes up.
choice2=1;
choice1=0;

//cardEffect (minion, choice1, choice2, choice3, &gameTest, handpos, &bonus);
minionRefactor(thisPlayer, choice1, choice2, &gameTest, handpos);


discardEstate =0;
gainEstate = 1;
int drawHand=4;

printf("----------\n");

printf("Hand count of current player = %d, Expected = %d\n", gameTest.handCount[thisPlayer], drawHand);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], drawHand);
printf("----------\n");


printf("----------\n");

printf("Hand count of other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], drawHand);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[otherPlayer], drawHand);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, gameControl.coins);
printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");

/*
printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys);
printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys);
printf("----------\n");
*/
printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl));
printf("----------\n");



printf("Number of Actions: = %d, expected = %d\n", gameTest.numActions, gameControl.numActions+actionIncrement);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numActions, gameControl.numActions+actionIncrement);
printf("----------\n");

return 0;

}

