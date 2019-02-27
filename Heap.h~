#include <iostream>
#include <cstring>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class Heap{
 public:
  Heap();
  ~Heap();
  int insert(int i);          //add int to heap
  int extract();              //get root, remove root
  int upheap(int index);      //takes index of int to be moved, swaps it with parent until in correct position
  int downheap(int index);    //takes index of int to be moved, swaps it with child until in correct position
  int build(int array[100], int size);    //build heap from array
  int peek();                 //get value root
  int visualize();            //display tree visually in levels
  int print();                //print contents of tree in order
 private:
  int heap[100];             //array for heap
  int len;                   //size of heap
};
