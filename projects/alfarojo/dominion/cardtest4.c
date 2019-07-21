/*:
 * cardtest4.c
 * 
 * endTurn function 
 *
 *
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 * 	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "getWinners function"

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

printf("Score for player 0: %d\n", scoreFor(thisPlayer, &gameTest));
printf("Score for player 1: %d\n", scoreFor(otherPlayer, &gameTest));
printf("Winner: %d\n", getWinners(gamePlayers, &gameTest));
asserttrue(getWinners(gamePlayers, &gameTest), 0);

printf("----------\n");
printf("Score for player 0: %d\n", scoreFor(thisPlayer, &gameTest));
printf("Score for player 1: %d\n", scoreFor(otherPlayer, &gameTest));
printf("gaineCard function called.  province added to player 1.");

gainCard(province, &gameTest,0, 1);
printf("Score for player 1: %d\n", scoreFor(otherPlayer, &gameTest));
printf("Winner: %d\n", getWinners(gamePlayers, &gameTest));
asserttrue(getWinners(gamePlayers, &gameTest), 1);
printf("----------\n");







return 0;
}
