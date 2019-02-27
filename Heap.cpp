/*class Heap: implements heap ADT
 *insert, extract, upheap, and downheap are based on the algorithms in this article:
 *https://en.wikipedia.org/wiki/Binary_heap
 *Author: Grace Hunter
 *Date: 26 February 2019
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include "Heap.h"

using namespace std;

//constructor
Heap::Heap(){
  len = 0;
}

//destructor
Heap::~Heap(){
}

//adds an int at the correct place in heap
int Heap::insert(int i){
  heap[len] = i;   //add to bottom
  upheap(len);     //move up heap to correct location
  len++;           //increase length of heap
  return 0;
}

//remove largest item (root) from heap & return
int Heap::extract(){
  int root = heap[0];       //store value of root
  heap[0] = heap[len - 1];  //grab value from bottom, make it root
  heap[len- 1] = 0;         //delete previous valueso it doesn't interfere later
  len--;
  downheap(0);              //move new root to proper place
  return root;
}

//takes index of int to be moved, swaps with parents unil in correct location
int Heap::upheap(int index){
  //get parent index
  int parent = (index - 1) / 2;
  
  //if greater than parent
  if(heap[index] > heap[parent]){
    //swap
    int temp = heap[parent];
    heap[parent] = heap[index];
    heap[index] = temp;
    index = parent;
  
    //if smaller than other child
    if(heap[index * 2 + 1] > heap[index] || heap[index * 2 + 2] > heap[index]){
      //downheap
      downheap(index);
    }
    //else upheap again
    else{
      upheap(index);
    }
  }
  return 0;
}

int Heap::downheap(int index){
  //get children indeces
  int child1 = index * 2 + 1;
  int child2 = index * 2 + 2;
  
  //if one child is greater
  if(heap[child1] > heap[index]){
    int temp = heap[child1];
    heap[child1] = heap[index];
    heap[index] = temp;
    //downheap again
    downheap(child1);
  }
  //if the other child is greater
  if(heap[child2] > heap[index]){
    int temp = heap[child2];
    heap[child2] = heap[index];
    heap[index] = temp;
    //downheap again
    downheap(child2);
  }
  return 0;
}

//builds the heap from an int array
int Heap::build(int array[100], int size){
  //insert each element in the array
  for(int i = 0; i < size; i++){
    insert(array[i]);
  }
  return 0;
}

//returns value of root
int Heap::peek(){
  return heap[0];
}

//displays tree visually with each level on its own line
int Heap::visualize(){
  int total = 0;
  int numprinted = 0;  //num on level printed
  int level = 0;

  while(total < len){
    //print number
    cout << heap[total] << " ";
    numprinted++;
    total++;

    //if end of level print endl
    if(numprinted == pow(2, level)){
      cout << endl;
      level++;
      numprinted = 0;
    }
  }
  cout << endl;
  return 0;
}

//empty heap in order and print each element 
int Heap::emptyheap(){
  while(len != 0){
    cout << extract() << " ";
  }
  cout << endl;
  return 0;
}
