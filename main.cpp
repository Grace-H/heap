/*Utilizes Heap class to handle and sort numbers
 *Author: Grace Hunter
 *Date: 26 February 2019
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include "Heap.h"

using namespace std;

int buildheap(Heap* heap, char* nums);

int main(){
  //find if file or command line
  char* filestr = new char[20];
  char* commandstr = new char[20];
  strcpy(filestr, "FILE");
  strcpy(commandstr, "COMMAND");

  char* input = new char[256];
  char* nums = new char[100000];
  
  //keep trying until response recieved
  bool success = false;
  while(!success){
    //get input
    cout << "'COMMAND' line or 'FILE' for input?" << endl;
    cin.get(input, 256);
    cin.get();

    //uppercase
    for(int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }
  
    //create char* from commamd line
    if(strcmp(commandstr, input) == 0){
      success = true;  
      cout << "Enter numbers seperated by spaces: " << endl;
      cin.get(nums, 100000);
      cin.get();
    }
    //create char* from file
    else if(strcmp(filestr, input) == 0){
      success = true;
      cout << "Enter complete file name. Numbers must be seperated by spaces" << endl;
      cin.get(input, 256);
      cin.get();

      //get from file
      ifstream is(input);
      is.get(nums, 100000);
      cout << nums << endl;
      is.close();
    }
    else{
      cout << "not an option" << endl;
    }
  }

  //create heap
  Heap* heap = new Heap(); 
  buildheap(heap, nums);

  //visualize heap
  cout << "Heap visualization: " << endl;
  heap->visualize();

  //output in order
  cout << "Ordered list: " << endl;
  heap->emptyheap();

  //cleanup
  delete [] filestr;
  delete [] nums;
  delete [] input;
  delete [] commandstr;
  delete heap;
  return 0;
}

//creates a heap from a char* array
int buildheap(Heap* heap, char* nums){
  //get token
  int cur = 0;
  char* str;
  str = strtok(nums, " ");
  
  while(str != NULL){
    //convert to int  
    cur = atoi(str);
    //insert into heap  
    heap->insert(cur);
    str = strtok(NULL, " ");
  }
  return 0;
}
