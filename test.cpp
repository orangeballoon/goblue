/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 2
 * Winter 2025
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();
void test_getName();
void test_getMenuChoice();
    
void startTests() {
    cout << "\nExecuting your test cases\n";
    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();

    

    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "\nNow testing function isMoveGood()\n";
    //valid cases
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'S': Expected: 1, Actual: " << isMoveGood('S') << endl;
    
    //invalid cases
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'x': Expected: 0, Actual: " << isMoveGood('x') << endl;
    cout << "'1': Expected: 0, Actual: " << isMoveGood('1') << endl;
    cout << "'_': Expected: 0, Actual: " << isMoveGood('_') << endl;
    cout << "'?': Expected: 0, Actual: " << isMoveGood('?') << endl;
    cout << "'w': Expected: 0, Actual: " << isMoveGood('w') << endl;
    cout << endl << endl;
    return;
}

void test_isRoundWinner() {
    cout << "Now testing function isRoundWinner()\n";
    //ties
    cout << "move 'r' opponent move 'r' : Expected: 0, Actual: " << isRoundWinner('r', 'r') << endl;
    cout << "move 'p' opponent move 'p' : Expected: 0, Actual: " << isRoundWinner('p', 'p') << endl;
    cout << "move 's' opponent move 's' : Expected: 0, Actual: " << isRoundWinner('s', 's') << endl;
    //wins
    cout << "move 'r' opponent move 's' : Expected: 1, Actual: " << isRoundWinner('r', 's') << endl;
    cout << "move 'p' opponent move 'r' : Expected: 1, Actual: " << isRoundWinner('p', 'r') << endl;
    cout << "move 's' opponent move 'p' : Expected: 1, Actual: " << isRoundWinner('s', 'p') << endl;
    cout << "move 'R' opponent move 's' : Expected: 1, Actual: " << isRoundWinner('R', 's') << endl;
    cout << "move 'r' opponent move 'S' : Expected: 1, Actual: " << isRoundWinner('r', 'S') << endl;
    cout << "move 'S' opponent move 'P' : Expected: 1, Actual: " << isRoundWinner('S', 'P') << endl;
    //loses
    cout << "move 'r' opponent move 'p' : Expected: 0, Actual: " << isRoundWinner('r', 'p') << endl;
    cout << "move 'p' opponent move 's' : Expected: 0, Actual: " << isRoundWinner('p', 's') << endl;
    cout << "move 's' opponent move 'r' : Expected: 0, Actual: " << isRoundWinner('s', 'r') << endl;
    cout << endl << endl;
    return;
}

void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    //with a winning player
    cout << "'Rocky' : Expected: Rocky wins the round!, Actual: ";
    announceRoundWinner("Rocky");
    cout << "'1' : Expected: 1 wins the round!, Actual: ";
    announceRoundWinner("1");
    cout << "'player 2' : Expected: player 2 wins the round!, Actual: ";
    announceRoundWinner("player 2");
    cout << "'Creed' : Expected: Creed wins the round!, Actual: ";
    announceRoundWinner("player Bob");
    cout << "';aksfjbvn' : Expected: ;aksfjbvn wins the round!, Actual: ";
    announceRoundWinner(";aksfjbvn");
    cout << "'winner' : Expected: winner wins the round!, Actual: ";
    announceRoundWinner("winner");
    cout << "'1234567890' : Expected: 1234567890 wins the round!, Actual: ";
    announceRoundWinner("1234567890");
    cout << "'BRICK' : Expected: BRICK wins the round!, Actual: ";
    announceRoundWinner("BRICK");
    cout << "'___' : Expected: ___ wins the round!, Actual: ";
    announceRoundWinner("___");
    //draw
    cout << " '' : Expected: This round is a draw!, Actual: ";
    announceRoundWinner("");
    cout << endl << endl;
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    //with a winning player
    cout << "\n 'Rocky' : Expected: \n Congragulations Rocky! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("name");
    cout << "\n '1' : Expected: \n Congragulations 1! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("1");
    cout << "\n 'player 2' : Expected: \n Congragulations name! \n You won EECS 183 Rock-Paper-Scissors!,\nActual: \n";
    announceWinner("player 2");
    cout << "\n 'Creed' : Expected: \n Congragulations Creed! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("Creed");
    cout << "\n ';aksfjbvn' : Expected: \n Congragulations ;aksfjbvn! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner(";aksfjbvn");
    cout << "\n 'winner' : Expected: \n Congragulations winner! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("winner");
    cout << "\n '1234567890' : Expected: \n Congragulations 1234567890! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("1234567890");
    cout << "\n 'BRICK' : Expected: \n Congragulations BRICK! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("BRICK");
    cout << "\n '___' : Expected: \n Congragulations ___! \n You won EECS 183 Rock-Paper-Scissors!, \nActual: \n";
    announceWinner("___");
    //draw
    cout << "\n '' : Expected: No Winner!, \nActual: \n";
    announceWinner("");
    cout << endl << endl;
    return;
}
