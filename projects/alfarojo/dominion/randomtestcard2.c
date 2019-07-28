/*
 * randomtestcard2.c
 *
 * minon actions:
 * +1 Action 
 *
 * Choose one: +2 coins
 * or +4 cards and other player with 5+ cards
 *
 * Bugs:  
 * Bug#1:: if (state->handCount[i] > 5)
 * If the other player has +6 cards they will discard
 *
 * Bug#2 for (int j=0; j < 7; j++)
 * Other player will draw 7 cards
 *
 * randomtestcard2: randomtestcard2 dominion.o rngs.o
 * 	gcc -o randomtestcard2 -g randomtestcard2.c dominon.o rngs.o $(CFLAGS)
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
#define TESTCARD "MINION CARD"

int asserttrue (int gameTest, int gameControl)

{	if (gameTest == gameControl){
	printf("TEST PASSED!\n");
	return 1;
	}
	else{
	printf("TEST FAILED!\n");
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

int k[10] = {adventurer, council_room, feast, tribute, minion, remodel, smithy, village, baron, great_hall};
int coinsBefore;
int coinsAfter;
//initialized with 2 players instead of a random set.

initializeGame(2, k, seed, &gameControl);

//switches to player b
endTurn (&gameControl);

//switches back to player a  this way both players now have 5 cards
endTurn (&gameControl);



int failedTests = 0;
int testScore;
memcpy(&gameTest, &gameControl, sizeof(struct gameState));

begin = clock();
//set to 50000
for (int index = 0; index < 50000; index++)
{
// either 1 or 0
int choice1Random = (rand() % (1-0 +1)) +0;
int choice2Random;
//game does not support choice1 = 1 & choice2 =1

//if choice1Random = 1, then player gets 2 coins.  and choice2Random
//needs to be 0.  vice versa.  but if choice2Random == 1,
//then coins unaffected.  instead card number affected
if (choice1Random == 1)
{
choice2Random = 0;
}

else 
choice2Random = 1;




printf("----------Testing Card: %s ----------\n", TESTCARD);

printf("Function name: minionRefactor()\n");
printf("Dependencies: currentPlayer, choice1, choice2, state, handPos\n");
printf("Iteration: %d\n", index);

coinsBefore= gameTest.coins;

minionRefactor (playerA, choice1Random, choice2Random, &gameTest, 0);
coinsAfter = gameTest.coins;

if (choice1Random == 1)
printf("Player chooses +2 coins.\n");

if (choice1Random ==0)
printf("Player chooses discard their cards and draw +4 cards.  If other player has 5 or more cards they discards and draw +4.\n");

printf("Player turn: %d\n", whoseTurn(&gameTest));

printf("Random choice1: %d\n", choice1Random);
printf("Random choice2: %d\n", choice2Random);

printf( "Hand count of player: %d\n",  gameTest.handCount[playerA]);
if (choice1Random ==2){

testScore =asserttrue(gameTest.handCount[playerA], gameControl.handCount[playerA]-4);
if (testScore == -1)
{
failedTests = -1;
}
}
if (choice1Random ==1)
testScore =asserttrue(gameTest.handCount [playerA], gameControl.handCount[playerA]);
if (testScore == -1)
{
failedTests = -1;
}

printf("Action count of player: %d\n", gameTest.numActions);
testScore=asserttrue(gameTest.numActions, gameControl.numActions+ 1);
if (testScore == -1)
{
failedTests = -1;
}

printf("Coin count of player: %d\n", gameTest.coins);
if (choice1Random == 1)
testScore=asserttrue (gameTest.coins, (gameControl.coins) + 2);
if (testScore == -1)
{
failedTests = -1;
}

if (choice2Random == 1)
testScore=asserttrue(gameTest.coins, (gameControl.coins));
if (testScore == -1)
failedTests = -1;


printf("Discard count of player: %d\n", gameTest.discardCount[playerA]);
if (choice2Random ==1 )
testScore = asserttrue (gameTest.handCount[playerA], 4);
if (testScore == -1)
failedTests =-1;



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
printf("----------Summary for Minion Refactor Function: ----------\n");
//printf("Please see below for statement and branch coverage: \n");
printf("Function name: minionRefactor()\n");
printf("Dependencies: currentPlayer, choice1, choice2, state, handPos\n");

timeUsed = ((double) (finish-begin))/CLOCKS_PER_SEC;
printf("Time for execution of randomtestcard2.c in seconds: %f\n", timeUsed);
printf("TOTAL ITERATIONS: 50000 \n");
printf("TESTS COMPLETED: \n");
if (failedTests == -1)
printf("NOT ALL TESTS PASSED\n");
printf("Please see below for statements and branch coverage: \n");
printf("---------------------------------------------------------\n");

return 0;
}
