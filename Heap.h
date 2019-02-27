/*Header file for class Heap, and implementation of the heap ADT
 *Author: Grace Hunter
 *Date: 26 February 2019
 */

#include <iostream>
#include <cstring>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class Heap{
 public:
  Heap();                     //constructor
  ~Heap();                    //destructor
  int insert(int i);          //add int to heap
  int extract();              //get root, remove root
  int upheap(int index);      //takes index of int to be moved, swaps it with parent until in correct position
  int downheap(int index);    //takes index of int to be moved, swaps it with child until in correct position
  int build(int array[100], int size);    //build heap from array
  int peek();                 //get value root
  int visualize();            //display tree visually in levels
  int emptyheap();            //remove and print contents of heap in order
 private:
  int heap[100];             //array for heap
  int len;                   //size of heap
};

#endif
