/*:
 * cardtest5.c
 * 
 * drawCard function 
 *
 *
 *
 * cardtest5: cardtest5.c dominion.o rngs.o
 * 	gcc -o cardtest5 -g cardtest5.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "drawCard function"

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

int gamePlayers [2] = {thisPlayer, otherPlayer};


int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards

printf("----------Testing Function: %s ----------\n", TESTCARD);
printf("Conditions: numPlayers=2, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");
initializeGame(numPlayers, k, seed, &gameControl);
memcpy (&gameTest, &gameControl, sizeof (struct gameState));

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]);



drawCard(0, &gameTest);
printf("drawCard function called...\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+1);
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+1);

drawCard(0, &gameTest);
printf("drawCard function called...\n");

printf("Hand count = %d, Expected = %d\n", gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+2);
asserttrue(gameTest.handCount[thisPlayer], gameControl.handCount[thisPlayer]+2);













return 0;
}
