/*:
 * cardtest3.c
 * 
 * endTurn function 
 *
 *
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 * 	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
 * 
 * Note: Much of the below code uses parts of cardtest4.c example from Week 3 module
 *
 * * */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "endTurn function"

void asserttrue (int gameTest, int gameControl)
{
printf("Using Assert True Function...\n");

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

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 



int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards

printf("----------Testing Function: %s ----------\n", TESTCARD);
printf("Conditions: numPlayers=2, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");
initializeGame(numPlayers, k, seed, &gameControl);

printf("initializeGame function called...\n");

printf("Player turn:%d, expected:%d\n", gameControl.whoseTurn, 0);
asserttrue(gameControl.whoseTurn, 0);

printf("Number of buys: %d, expected: %d\n", gameControl.numBuys, 1);
asserttrue(gameControl.numBuys, 1);

printf("Number of actions: %d, expected: %d\n", gameControl.numActions, 1);
asserttrue(gameControl.numActions, 1);

printf("Hand count of current player: %d, expected:%d\n", gameControl.handCount[thisPlayer], 5);
asserttrue(gameControl.handCount[thisPlayer], 5);

printf("----------\n");


endTurn(&gameControl);
printf("endTurn function called...\n");
printf("Player turn:%d, expected:%d\n", gameControl.whoseTurn, 1);
asserttrue(gameControl.whoseTurn, 1);
printf("Number of buys: %d, expected: %d\n", gameControl.numBuys, 1);
asserttrue(gameControl.numBuys, 1);

printf("Number of actions: %d, expected: %d\n", gameControl.numActions, 1);
asserttrue(gameControl.numActions, 1);

printf("Hand count of current player: %d, expected:%d\n", gameControl.handCount[thisPlayer], 5);
asserttrue(gameControl.handCount[thisPlayer], 5);

printf("----------\n");

endTurn(&gameControl);
printf("endTurn function called...\n");
printf("Player turn:%d, expected:%d\n", gameControl.whoseTurn, 0);
asserttrue(gameControl.whoseTurn, 0);

printf("Number of buys: %d, expected: %d\n", gameControl.numBuys, 1);
asserttrue(gameControl.numBuys, 1);

printf("Number of actions: %d, expected: %d\n", gameControl.numActions, 1);
asserttrue(gameControl.numActions, 1);

printf("Hand count of current player: %d, expected:%d\n", gameControl.handCount[thisPlayer], 5);
asserttrue(gameControl.handCount[thisPlayer], 5);

return 0;
}
