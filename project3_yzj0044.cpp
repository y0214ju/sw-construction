/*********************************************
@author: Yeonseo Ju (yzj0044)
@version: 10/15/2019
projec3_yzj0044.cpp
I used repl.it to compile this project and modify code with vim
compiled in Windows 10
*********************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int MAX_SIZE = 100;

/*declare user-defined functions*/

bool check_file(string);
/* check file whether it can be opened. 
* @param - string name. */
int readfile(int[], ifstream&);
/* read instream and save elements into a array.
* param- int[], name of array
* param - ifstream, name of input stream*/
void write_file(string, int[], int);
/* write elements of array into outfut file.
* param - string, filename
* param - array. 
* int - size of the array*/

void merge(int[], int[], int n1, int n2, int[]);
/* merge two array into one array in ascending order.
* param 1, 2 - two arrays need to be merged.
* param int n1, n2 - size of two arrays
* param int[] - merged array. */


/* Merge the numbers in two specified files and write all the 
* numbers to a specified third file sorted in ascending order.
* Return: 1 program completed successfully. (int) */
int main() {
   ifstream inStream1;
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];
   int iArray2_size;

   string filename1, filename2, fileOut;
   cout << "*** Welcome to Ju's sorting program ***" << endl;

   do {
	cout << "Enter the first input file name: ";
	cin >> filename1;
  }while(!check_file(filename1));

   // pass the file name as an array of chars to open()(
   // inStream.open(filename);
   inStream1.open((char*)filename1.c_str());

   iArray1_size = readfile(iArray1, inStream1);
   inStream1.close();
   
   cout << "The list of " << iArray1_size << " numbers in the file " << filename1 << " is" << endl;

   for (int i = 0; i < iArray1_size; i++) {
      cout << iArray1[i] << endl;
   }

   do {
      cout << "\nEnter the second input file name: ";
      cin >> filename2;
   } while(!check_file(filename2));

   inStream1.open((char*)filename2.c_str());
   iArray2_size = readfile(iArray2, inStream1);
   inStream1.close(); 
   cout << "The list of " << iArray2_size << " numbers in the file " << filename2 << " is" << endl;

   for (int i = 0; i < iArray2_size; i++) {
      cout << iArray2[i] << endl;
  }
   int iArray3_size = iArray1_size + iArray2_size;
   int iArray3[iArray3_size];

   cout << "The sorted list of " << iArray3_size << " numbers is: ";
   merge(iArray1, iArray2, iArray1_size, iArray2_size, iArray3);
 
   for (int i = 0; i < iArray3_size; i++) {
      cout << iArray3[i] << " ";
   }

   /*Get name of output file. */
   do {
      cout << "\nEnter the output file name: ";
      cin >> fileOut;
   } while(!check_file(fileOut));

   /*Write combined vector to output file.*/
   write_file(fileOut, iArray3, iArray3_size);
   cout << "*** Please check the new file - " << fileOut << "***" << endl;
   cout << "*** Good bye. ***" << endl;

   return 0;
}

bool check_file(string file) {
   ifstream stream;
   stream.open(file.c_str());
   if(stream.fail()) {
      return false;
   }
   stream.close();

   return true;
}

int readfile(int inputArray[], ifstream& inStream) {
   int index = 0;
   inStream >> inputArray[index];
   while (! inStream.eof()) {
      index++;
      inStream >> inputArray[index];
   }
   return index;
}


void write_file(string file, int arr[], int size) {
   ofstream outstream;
   outstream.open(file.c_str());
  
  for (int i = 0; i < size; i++) {
     outstream << arr[i] << endl;
  }
   outstream.close();
}

void merge(int array1[], int array2[], int n1, int n2, int array3[]) {
   int i = 0, j = 0, k = 0;
   while (i < n1 && j < n2) {
      if (array1[i] < array2[j]) {
         array3[k++] = array1[i++];
	 
      } else { 
         array3[k++] = array2[j++];
	 
      }
   }

   while (i < n1) {
      array3[k++] = array1[i++];
  }

   while (j < n2) {
      array3[k++] = array2[j++];
   }
}

