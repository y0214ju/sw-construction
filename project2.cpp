#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

/*********************************************************************
 * project2_yzj0044.cpp
 * @author Yeonseo Ju (yzj0044)
 * @version 09202019
 * used Dr. Li's guideline to write basic structure.
 * simulate the duel using strategy 1 and strategy 2 and compare 2 strategy based on Aaron's accuracy.
 * *******************************************************************/

using namespace std;

bool A_alive;
bool B_alive;
bool C_alive;

const int A_PROBABILITY = 33;
const int B_PROBABILITY = 50;
const int C_PROBABILITY = 100;
int probability;
const int TOTAL_RUNS = 10000;

int A_wins1 = 0;
int A_wins2 = 0;
int B_wins = 0;
int C_wins = 0;

//prototype
bool at_least_two_alive(bool& A_alive, bool& B_alive, bool& C_alive) {
   if (A_alive == true && B_alive == true) {
      return true;
   }
   if (B_alive == true && C_alive == true) {
      return true;
   }
   if (C_alive == true && A_alive == true) {
      return true;
   }
   return false; 
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   assert(B_alive || C_alive);
   probability = rand() % 100;
  
   if (C_alive) {
      if(probability <= A_PROBABILITY) {
         C_alive = false;
      }
   }
   else {
      if(probability <= A_PROBABILITY) {
         B_alive = false;
      }
   }
}

void Bob_shoots1(bool& A_alive, bool& C_alive) {
   assert(A_alive || C_alive);
   probability = rand() % 100;
   if (C_alive) {
      if(probability <= B_PROBABILITY) {
         C_alive = false;
      }
   }
   else {
      if(probability <= B_PROBABILITY) {
         A_alive = false;
      }
   }
}

void Charlie_shoots1(bool& A_alive, bool& B_alive){
   assert(A_alive || B_alive);
   if (B_alive) {
      B_alive = false; 
   }
   else {
      A_alive = false;
   }
} 

void Aaron_shoots2(bool& B_alive, bool& C_alive){
   assert(B_alive || C_alive);
   probability = rand() % 100;
   if (B_alive == true && C_alive == true) {
      B_alive = true;
      C_alive = true;
   
   //miss the first shot so no changes in status of B_alive and C_alive
   }
   else if (C_alive) {
      if(probability <= A_PROBABILITY) {
         C_alive = false;
      }
   }
   else {
      if(probability <= A_PROBABILITY) {
         B_alive = false;
      }
   }
}

//Test case for at_least_two_alive() method
void test_at_least_two_alive(){
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive";
   A_alive = true;
   B_alive = true;
   C_alive = true;

   assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive";
   A_alive = false;
   B_alive = true;
   C_alive = true;

   assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive";
   A_alive = true;
   B_alive = false;
   C_alive = true;

   assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead";
   A_alive = true;
   B_alive = true;
   C_alive = false;

   assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive";
   A_alive = false;
   B_alive = false;
   C_alive = true;

   assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead";
   A_alive = false;
   B_alive = true;
   C_alive = false;

   assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead";
   A_alive = true;
   B_alive = false;
   C_alive = false;

   assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";

   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead";
   A_alive = false;
   B_alive = false;
   C_alive = false;

   assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
   cout << "\n\tCase passed ...\n";
}

//Test case for Aaron_shoots1() method
void test_Aaron_shoots1() {
   cout << "Unit Testing 2: Function Aaron_shoots1(B_alive, C_alive)";
   B_alive = true;
   C_alive = true;
   cout << "\n\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots1(B_alive, C_alive);
   assert(true == (B_alive == true));
   cout << "\n\tAaron is shooting at Charlie";

   B_alive = true;
   C_alive = false;
   cout << "\n\tCase 2: Bob alive, Charlie dead";
   Aaron_shoots1(B_alive, C_alive);
   assert(true == (C_alive == false));
   cout << "\n\tAaron is shooting at Bob";

   B_alive = false;
   C_alive = true;
   cout << "\n\tCase 3: Bob dead, Charlie alive";
   Aaron_shoots1(B_alive, C_alive);
   assert(true == (B_alive == false));
   cout << "\n\tAaron is shooting at Charlie\n";


}

//Test case for Bob_shoots1() method
void test_Bob_shoots1() {
   cout << "Unit Testing 3: Function Bob_shoots1(A_alive, C_alive)";
   A_alive = true;
   C_alive = true;
   cout << "\n\tCase 1: Aaron alive, Charlie alive";
   Bob_shoots1(A_alive, C_alive);
   assert(true == (A_alive == true));
   cout << "\n\tBob is shooting at Charlie";

   A_alive = true;
   C_alive = false;
   cout << "\n\tCase 2: Aaron alive, Charlie dead";
   Bob_shoots1(A_alive, C_alive);
   assert(true == (C_alive == false));
   cout << "\n\tBob is shooting at Aaron";

   A_alive = false;
   C_alive = true;
   cout << "\n\tCase 3: Aaron dead, Charlie alive";
   Bob_shoots1(A_alive, C_alive);
   assert(true == (A_alive == false));
   cout << "\n\tBob is shooting at Charlie\n";


}
//Test case for Charlie_shoots1() method
void test_Charlie_shoots1() {
   cout << "Unit Testing 4: Function Charlie_shoots1(A_alive, B_alive)";
   A_alive = true;
   B_alive = true;
   cout << "\n\tCase 1: Aaron alive, Bob alive";
   Charlie_shoots1(A_alive,B_alive);
   assert(true == (A_alive == true));
   cout << "\n\tCharlie is shooting at Bob";

   A_alive = true;
   B_alive = false;
   cout << "\n\tCase 2: Aaron alive, Bob dead";
   Charlie_shoots1(A_alive,B_alive);
   assert(true == (B_alive == false));
   cout << "\n\tCharlie is shooting at Aaron";

   A_alive = false;
   B_alive = true;
   cout << "\n\tCase 3: Aaron dead, Bob alive";
   Charlie_shoots1(A_alive,B_alive);
   assert(true == (A_alive == false));
   cout << "\n\tCharlie is shooting at Bob\n";
}
//Test case for Aaron_shoot2() method
void test_Aaron_shoots2() {
   cout << "Unit Testing 5: Function Aaron_shoots2(B_alive, C_alive)"; 

   B_alive = true;
   C_alive = true;
   cout << "\n\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots2(B_alive, C_alive);
   assert(true == (B_alive == true) && (C_alive == true));
   cout << "\n\tAaron intentionally misses his first shot\n"
      << "\tBoth Bob and Charlie are alive.";

   B_alive = true;
   C_alive = false;
   cout << "\n\tCase 2: Bob alive, Charlie dead";
   Aaron_shoots2(B_alive, C_alive);
   assert(true == (C_alive == false));
   cout << "\n\tAaron is shooting at Bob";

   B_alive = false;
   C_alive = true;
   cout << "\n\tCase 3: Bob dead, Charlie alive";
   Aaron_shoots2(B_alive, C_alive);
   assert(true == (B_alive == false));
   cout << "\n\tAaron is shooting at Charlie\n";
}


void Press_any_key() {
   cout << "Press Enter to continue...";
   cin.ignore().get(); // Pause Command for Linux Terminal
}

void duel1(void) {  
   A_alive = true;
   B_alive = true;
   C_alive = true;
   while (at_least_two_alive(A_alive, B_alive, C_alive)){
      if (A_alive) {
         Aaron_shoots1(B_alive, C_alive);
      }
      if (B_alive) {
         Bob_shoots1(A_alive, C_alive);
      }
      if (C_alive){
         Charlie_shoots1(A_alive, B_alive);
      }
   }
   if (C_alive) {
      C_wins++;
   }
   else if (B_alive) {
      B_wins++;
   }
   else {
      A_wins1++;
   }
}


void duel2(void){
   A_alive = true;
   B_alive = true;
   C_alive = true;

   while (at_least_two_alive(A_alive, B_alive, C_alive)){
      if (A_alive) {
         Aaron_shoots2(B_alive, C_alive);
      }
      if (B_alive) {
         Bob_shoots1(A_alive, C_alive);
      }
      if (C_alive){
         Charlie_shoots1(A_alive, B_alive);
      }
   }
   if (C_alive) {
      C_wins++;
   }
   else if (B_alive) {
      B_wins++;
   }
   else {
      A_wins2++;
   }
}

int main() {
   cout << "*** Welcome to Ju's Duel Simulator ***\n";
   srand(time(0));
  
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots1();
   Press_any_key();
   test_Charlie_shoots1();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();

  //starts strategy 1 and runs 10,000 times
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();  
   for (int i =0; i < TOTAL_RUNS; i++) {
      duel1();
   }

   cout << "Aaron won " << A_wins1 << "/10000 duels or " << (double)A_wins1/100 << "%\n"
      << "Bob won " << B_wins <<  "/10000 duels or " << (double)B_wins/100 << "%\n"
      << "Charlie won " << C_wins <<  "/10000 duels or " << (double)C_wins/100 << "%\n"
      << endl;

  //Reintializes variables and starts strategy 2 to run 10,000 times
   B_wins = 0;
   C_wins = 0;

   cout << "Ready to test strategey 2 (run 10000 times):\n";
   Press_any_key();
   for (int i = 0; i < TOTAL_RUNS; i++) {
      duel2();
   }
  
   cout << "Aaron won " << A_wins2 << "/10000 duels or " << (double)A_wins2/100 << "%\n"
      << "Bob won " << B_wins <<  "/10000 duels or " << (double)B_wins/100 << "%\n"
      << "Charlie won " << C_wins <<  "/10000 duels or " <<(double)C_wins/100 << "%\n"
      << endl;

///print a strategy analysis
   if (A_wins1 > A_wins2) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
   return 0;
}



