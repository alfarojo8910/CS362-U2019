/*
 * unittest3.c
 *
 * Ambassador actions:
 * Return 1 or 2 cards to the Supply.
 * Then each other player gains a copy of it.
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
 * unittest3: unittest3.c dominion.o rngs.o
 * 	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "ambassador"

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
int choice1 = 0;
int choice2=0;
int choice3=0;
int bonus=0;
int coins=0;


int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, ambassador, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

printf("----------Testing Card: %s ----------\n", TESTCARD);



/*
 * NEEDED TO COMMENT OUT TEST1.  Causes an endles loop due to 
 * bugs introduced from Assignment 2.
//****************************TEST1**************************
//return 1 card.  1st card
//
printf("TEST 1: choice1 = 1 choice2=1. -1 handCount for currentPlayer & +1 handCount for OtherPlayer\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
int handpos = 0;
choice1 = 1;
choice2 = 1;
cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);

int returnedCard = 1;

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -returnedCard);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

printf("----------\n");
printf("Hand count for other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer] + returnedCard);
asserttrue(gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer+returnedCard]);
printf("----------\n");
printf("Total supply count = %d, Expected = %d\n", gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);

asserttrue( gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);
  

printf("----------\n");
*/

//****************************TEST2**************************
//return 2 cards.  1st card
//
printf("TEST 2: choice1 = 1 choice2=2. -2 handCount for currentPlayer & +1 handCount for OtherPlayer\n");

//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
int handpos = 0;
choice1 = 1;
choice2 = 2;
//cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//ambassadorRefactor (thisPlayer, choice1, choice2, &gameTest, handpos);
playAmbassador(&gameTest, thisPlayer, handpos, choice1, choice2);


int returnedCard = 1;

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -returnedCard);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

printf("----------\n");
printf("Hand count for other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer] + returnedCard);
asserttrue(gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer+returnedCard]);
printf("----------\n");
printf("Total supply count = %d, Expected = %d\n", gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);

asserttrue( gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);
  

printf("----------\n");

//****************************TEST3**************************
//return 2 cards.  1st card
//
printf("TEST 3: choice1 = 0 choice2=2. -2 handCount for currentPlayer & +1 handCount for OtherPlayer\n");
//will return -1 as handpos==choice1
//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
handpos = 0;
choice1 = 0;
choice2 = 2;
//cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//ambassadorRefactor(thisPlayer, choice1, choice2, &gameTest, handpos);
playAmbassador(&gameTest, thisPlayer, handpos, choice1, choice2);


returnedCard = 1;

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -returnedCard);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

printf("----------\n");
printf("Hand count for other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer] + returnedCard);
asserttrue(gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer+returnedCard]);
printf("----------\n");
printf("Total supply count = %d, Expected = %d\n", gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);

asserttrue( gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);
  


printf("----------\n");

printf("\n");


printf("----------\n");

//****************************TEST4**************************
//return 2 cards.  1st card
//
printf("TEST 4: choice1 = 0 choice2=3. -2 handCount for currentPlayer & +1 handCount for OtherPlayer\n");
//will return -1 as handpos==choice1
//copies the game state to a test case
memcpy(&gameTest, &gameControl, sizeof(struct gameState));
handpos = 0;
choice1 = 0;
choice2 = 3;
//cardEffect(ambassador, choice1, choice2, choice3, &gameTest, handpos, &bonus);
//ambassadorRefactor(thisPlayer, choice1, choice2, &gameTest, handpos);
playAmbassador(&gameTest, thisPlayer, handpos, choice1, choice2);

returnedCard = 1;

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer] -returnedCard);
printf("Using Assert True Function...\n");
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]-returnedCard);

printf("----------\n");
printf("Hand count for other player = %d, Expected = %d\n", gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer] + returnedCard);
asserttrue(gameTest.handCount[otherPlayer], gameControl.handCount[otherPlayer+returnedCard]);
printf("----------\n");
printf("Total supply count = %d, Expected = %d\n", gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);

asserttrue( gameTest.supplyCount[curse] + gameTest.supplyCount[estate]+ gameTest.supplyCount[duchy] + gameTest.supplyCount[province]+ gameTest.supplyCount[copper] + gameTest.supplyCount[silver]+ gameTest.supplyCount[gold], gameControl.supplyCount[curse]+gameControl.supplyCount[estate]+gameControl.supplyCount[duchy]+gameControl.supplyCount[province]+gameControl.supplyCount[copper]+gameControl.supplyCount[silver]+gameControl.supplyCount[gold]+1);
  


printf("----------\n");




return 0;

}

