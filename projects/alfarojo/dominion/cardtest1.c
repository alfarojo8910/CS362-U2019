/*:
 * cardtest1.c
 * 
 * initializeGame
 *
 *
 *
 * unittest1: cardtest1.c dominion.o rngs.o
 * 	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "initializeGame"

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

struct gameState gameControl;
struct gameState gameTest; 



int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

//initializes a game state and the player cards
initializeGame(numPlayers, k, seed, &gameControl);




printf("----------Testing Function: %s ----------\n", TESTCARD);
printf("TEST 1: numPlayers=2, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameControl.handCount[thisPlayer], 5);

printf("Using Assert True Function...\n");
asserttrue(gameControl.handCount[thisPlayer], 5);
printf("----------\n");

printf("Number of curse cards = %d, Expected = %d\n", gameControl.supplyCount[curse], 10);

printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[curse], 10);


printf("----------\n");

printf("Number of estate cards = %d, Expected = %d\n", gameControl.supplyCount[estate], 8);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[estate], 8);

printf("----------\n");

printf("Number of duchy cards = %d, Expected = %d\n", gameControl.supplyCount[duchy], 8);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[duchy], 8);


printf("----------\n");

printf("Number of province cards = %d, Expected = %d\n", gameControl.supplyCount[province], 8);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[province], 8);

printf("----------\n");

printf("Number of copper cards = %d, Expected = %d\n", gameControl.supplyCount[copper], 46);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[copper], 46);

printf("----------\n");

printf("Number of silver cards = %d, Expected = %d\n", gameControl.supplyCount[silver], 40);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[silver], 40);

printf("----------\n");


printf("Number of gold cards = %d, Expected = %d\n", gameControl.supplyCount[gold], 30);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[gold], 30);

printf("----------\n");


numPlayers=3;
initializeGame(numPlayers, k, seed, &gameControl);


printf("TEST 2: numPlayers=3, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameControl.handCount[thisPlayer], 5);

printf("Using Assert True Function...\n");
asserttrue(gameControl.handCount[thisPlayer], 5);
printf("----------\n");

printf("Number of curse cards = %d, Expected = %d\n", gameControl.supplyCount[curse], 20);

printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[curse], 20);


printf("----------\n");

printf("Number of estate cards = %d, Expected = %d\n", gameControl.supplyCount[estate], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[estate], 12);

printf("----------\n");

printf("Number of duchy cards = %d, Expected = %d\n", gameControl.supplyCount[duchy], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[duchy], 12);


printf("----------\n");

printf("Number of province cards = %d, Expected = %d\n", gameControl.supplyCount[province], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[province], 12);

printf("----------\n");

printf("Number of copper cards = %d, Expected = %d\n", gameControl.supplyCount[copper], 39);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[copper], 39);

printf("----------\n");

printf("Number of silver cards = %d, Expected = %d\n", gameControl.supplyCount[silver], 40);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[silver], 40);

printf("----------\n");


printf("Number of gold cards = %d, Expected = %d\n", gameControl.supplyCount[gold], 30);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[gold], 30);

printf("----------\n");

numPlayers=4;
initializeGame(numPlayers, k, seed, &gameControl);

printf("TEST 3: numPlayers=4, k={adventurer, council_room, feast, gardens, mine, remodel, smith, village, baron, great_hall}, seed=1000, \n");

printf("----------\n");

printf("Hand count = %d, Expected = %d\n", gameControl.handCount[thisPlayer], 5);

printf("Using Assert True Function...\n");
asserttrue(gameControl.handCount[thisPlayer], 5);
printf("----------\n");

printf("Number of curse cards = %d, Expected = %d\n", gameControl.supplyCount[curse], 30);

printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[curse], 30);


printf("----------\n");

printf("Number of estate cards = %d, Expected = %d\n", gameControl.supplyCount[estate], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[estate], 12);

printf("----------\n");

printf("Number of duchy cards = %d, Expected = %d\n", gameControl.supplyCount[duchy], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[duchy], 12);


printf("----------\n");

printf("Number of province cards = %d, Expected = %d\n", gameControl.supplyCount[province], 12);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[province], 12);

printf("----------\n");

printf("Number of copper cards = %d, Expected = %d\n", gameControl.supplyCount[copper], 32);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[copper], 32);

printf("----------\n");

printf("Number of silver cards = %d, Expected = %d\n", gameControl.supplyCount[silver], 40);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[silver], 40);

printf("----------\n");


printf("Number of gold cards = %d, Expected = %d\n", gameControl.supplyCount[gold], 30);
printf("Using Assert True Function...\n");

asserttrue(gameControl.supplyCount[gold], 30);

printf("----------\n");





return 0;

}
