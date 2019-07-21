/*
 * unittest1.c
 *
 * Baron actions:
 * +1 Buy
 * You may discard an Estate for +4 coins
 * If you don't, gain an Estate
 *
 * Bugs:  
 * Bug#1: decrease the buy number by 1.  
 * Bug code: state->numBuys--
 * Previous code: state->numBuys++
 *
 * Bug#2: Increment estates by 1.
 * Bug code: state->supplyCount[estate]++
 * Previous code: state->supplyCount[estate]--
 *
 *
 *
 *
 * unittest1: unittest1.c dominion.o rngs.o
 * 	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "baron"

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

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);
//BUG1: PLAYER BUY DECREASES BY 1 NO MATTER WHAT CHOICE IS SELECTED.
//****************************TEST1**************************
printf("TEST 1: choice1=1.  -1 estate & +4 coins & +1 buys & +1 supplyCount for estate\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
//choice1=1 represents discarding an estate and receiving 4 coins
choice1 = 1;
//cardEffect(baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
baronRefactor(thisPlayer, choice1, &gameTest);


extraCoins=4;
discardEstate=1;

int buysDeduct=1;
int scoreIncrement = 1;
printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -discardEstate);

printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-discardEstate);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, (gameControl.coins + extraCoins));

printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins + extraCoins));
printf("----------\n");

printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys+buysDeduct);

printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys+buysDeduct);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl)-scoreIncrement);

printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl)-scoreIncrement);
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]+discardEstate);

printf("Using Assert True Function...\n");
asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]+discardEstate);
printf("----------\n");






printf("\n");
//****************************TEST2********************************
 printf("TEST 2: choice1=0.  +1 estate & +1 buys.  -1 estates for supplyCount for estate\n");

memcpy(&gameTest, &gameControl, sizeof(struct gameState));

//choice represents gain an estate
//BUG 2:  supply of estates increments up.  player stat unaffected
//by bug.  supply of estates for game goes up.
choice1=0;

//cardEffect (baron, choice1, choice2, choice3, &gameTest, handpos, &bonus);
baronRefactor(thisPlayer, choice1, &gameTest);

discardEstate =0;
gainEstate = 1;

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] + discardEstate);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+discardEstate);
printf("----------\n");

printf("Coins =%d, expected = %d\n", gameTest.coins, gameControl.coins);
printf("Using Assert True Function...\n");
asserttrue(gameTest.coins, (gameControl.coins));
printf("----------\n");
//due to bug#1 buy number = -1.
printf("Buy Number = %d, expected = %d\n", gameTest.numBuys, gameControl.numBuys+buysDeduct);
printf("Using Assert True Function...\n");
asserttrue(gameTest.numBuys, gameControl.numBuys+buysDeduct);
printf("----------\n");

printf("Score for Player = %d, expected = %d\n", scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl)+gainEstate);
printf("Using Assert True Function...\n");
asserttrue(scoreFor(thisPlayer, &gameTest), scoreFor(thisPlayer, &gameControl)+scoreIncrement);
printf("----------\n");

printf("Supply Count of Estates = %d, expected = %d\n", gameTest.supplyCount[estate], gameControl.supplyCount[estate]- gainEstate);

printf("Using Assert True Function...\n");
asserttrue(gameTest.supplyCount[estate], gameControl.supplyCount[estate]-gainEstate);
printf("----------\n");

printf(">>>>>>>>>> Testing complete %s <<<<<<<<<< \n\n", TESTCARD);



return 0;

}

