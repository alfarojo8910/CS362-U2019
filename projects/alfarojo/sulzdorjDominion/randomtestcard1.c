/*
 * randomtestcard1.c
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
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 * 	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
 * 
 * Note: much of the code below is inspired from Week 3 Module for CS 362 class: testUpdateCoins.c and cardtest4.c 
 * Also inspired by lecture examples: testBuyCard.c and testDrawCard.c
 * To document length of time for time of program, read article at
 * https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "BARON CARD"

int asserttrue (int gameTest, int gameControl)

{	if (gameTest == gameControl){
//	printf("TEST PASSED!\n");
	return 1;
	}
	else{
//	printf("TEST FAILED!\n");
	return -1;
	}		
}

int main (){
srand(time(0));
clock_t begin;
clock_t finish;
double timeUsed;
int seed = 1000;


int playerNumberRandom = (rand() % (4 - 1 +1)) + 1;
int currentPlayerRandom = (rand() % (3-0 +1)) +0;
int playerA = 0;
int playerB = 1;
int playerC = 2;
int playerD = 3;
int estateTally = 0;

struct gameState gameControl;
struct gameState gameTest; 

int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
int coinsBefore;
int coinsAfter;
initializeGame(2, k, seed, &gameControl);
int failedTests = 0;
int testScore;
memcpy(&gameTest, &gameControl, sizeof(struct gameState));

begin = clock();
//set to 50000

printf("----------Testing Card: %s ----------\n", TESTCARD);

//printf("Function name: baronRefactor()\n");
printf("Function name: playBaron()\n");
printf("Dependencies: currentPlayer, choice1, &state\n");


for (int index = 0; index < 50000; index++)
{
int choice1Random = (rand() % (1-0 +1)) +0;
printf("----------Testing Card: %s ----------\n", TESTCARD);

//printf("Function name: baronRefactor()\n");
printf("Function name: playBaronaron()\n");
printf("Dependencies: currentPlayer, choice1, &state\n");
printf("Iteration: %d\n", index);

coinsBefore= gameTest.coins;

//baronRefactor(playerA, choice1Random, &gameTest);
playBaron(&gameTest, playerA, choice1Random);




coinsAfter = gameTest.coins;

if (choice1Random == 1)
printf("Player discards Estate and gets +4 coins if they have any estates.\n");

if (choice1Random ==0)
printf("Player receives: +1 Estate\n");

printf("Player turn: %d\n", whoseTurn(&gameTest));
testScore = asserttrue(whoseTurn(&gameTest), 0);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}



printf("Random choice: %d\n", choice1Random);

printf( "Hand count of player: %d\n",  gameTest.handCount[playerA]);
if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount[playerA], gameControl.handCount[playerA]);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount [playerA], gameControl.handCount[playerA]-1);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Action count of player: %d\n", gameTest.numActions);
testScore=asserttrue(gameTest.numActions, gameControl.numActions--);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Coin count of player: %d\n", gameTest.coins);
if (coinsBefore != coinsAfter)
testScore=asserttrue (gameTest.coins, (gameControl.coins) + 4);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

if (coinsBefore == coinsAfter)
testScore=asserttrue (gameTest.coins, gameControl.coins);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Buy count of player: %d\n", gameTest.numBuys);
testScore=asserttrue(gameTest.numBuys, (gameControl.numBuys)+1);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}

printf("Score for player: %d\n", scoreFor(playerA,&gameTest));

printf("Discard count of player: %d\n", gameTest.discardCount[playerA]);

printf("Supply Count of Estate: %d\n", gameTest.supplyCount[estate]);
if (scoreFor(playerA, &gameTest) == 10)
testScore=asserttrue(gameTest.supplyCount[estate],0);
//testScore = -1;
if (testScore == -1)
{
failedTests = -1;
}


printf("\n");
coinsBefore = 0;
coinsAfter = 0;

if (playerNumberRandom == 2)
{
//switches to player b
endTurn(&gameTest);
//switches back to player a
endTurn(&gameTest);
}

if (playerNumberRandom ==3)
{
//switches to player b
endTurn(&gameTest);
//switches to player c
endTurn(&gameTest);
//switches back to plaeyr a
endTurn(&gameTest);
}
if (playerNumberRandom ==4)
{
//switches to player b
endTurn(&gameTest);
//switches to player c
endTurn(&gameTest);
//switches to player d
endTurn(&gameTest);

//switches back to plaeyr a
endTurn(&gameTest);
}

}
finish = clock();
printf("----------Summary for Baron Refactor Function: ----------\n");
//printf("Function name: baronRefactor()\n");
printf("Function name: playBaron()\n");
printf("Dependencies: currentPlayer, choice1, &state\n");
//printf("Please see below for statements and branch coverage: \n");
timeUsed = ((double) (finish-begin))/CLOCKS_PER_SEC;
printf("Time for execution of randomtestcard1.c in seconds: %f\n", timeUsed);
printf("TOTAL ITERATIONS: 50000 \n");
printf("TESTS COMPLETED: \n");
if (failedTests == -1)
printf("NOT ALL TESTS PASSED\n");
printf("Please see below for statements and branch coverage: \n");
printf("---------------------------------------------------------\n");

return 0;
}
