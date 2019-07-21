/*:
 * cardtest2.c
 * 
 * shuffle
 *
 *
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 * 	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "shuffle function"

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

int seed = 1000;

int numPlayers = 2;
int thisPlayer=0;
int otherPlayer=1;

struct gameState gameControl;
struct gameState gameTest; 



int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);

memcpy(&gameTest, &gameControl, sizeof(struct gameState));


//shuffle function
shuffle(thisPlayer, &gameTest);

int shuffleReturnValue = shuffle(thisPlayer, &gameTest);

printf("----------Testing Function: %s ----------\n", TESTCARD);
printf("TEST 1: numPlayers=2, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");

printf("Shuffling deck...\n");
printf("The return value of shuffle function...%d", shuffle(thisPlayer, &gameTest));

printf("Return value of shuffle assigned to shuffleReturnValue variable: %d\n", shuffleReturnValue);

printf("Shuffling again...\n");

shuffle(thisPlayer, &gameTest);

shuffleReturnValue = shuffle(thisPlayer, &gameTest);

printf("Return value of shuffle %d\n", shuffleReturnValue);

printf("Drawing a card...\n");

drawCard(thisPlayer, &gameTest);

printf("Shuffling again...");

shuffleReturnValue = shuffle(thisPlayer, &gameTest);

printf("Return value of shuffle: %d\n", shuffleReturnValue);

drawCard(thisPlayer, &gameTest);

shuffleReturnValue = shuffle(thisPlayer, &gameTest);

printf("Value %d,", shuffleReturnValue);



printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameControl.handCount[thisPlayer], 5);

printf("Using Assert True Function...\n");
asserttrue(gameControl.handCount[thisPlayer], 5);
printf("----------\n");




return 0;
}
