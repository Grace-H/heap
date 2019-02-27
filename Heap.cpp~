#include <iostream>
#include <cstring>
#include <cmath>
#include "Heap.h"

using namespace std;

Heap::Heap(){
  len = 0;
}

Heap::~Heap(){
}

int Heap::insert(int i){
  heap[len] = i;
  upheap(len);
  len++;
  return 0;
}

int Heap::extract(){
  int root = heap[0];
  heap[0] = heap[len - 1];
  len--;
  downheap(0);
  return root;
}

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
    downheap[child2];
  }
  return 0;
}

int Heap::build(int array[100], int size){
  //insert each element in the array
  for(int i = 0; i < size; i++){
    insert(array[i]);
  }
  return 0;
}

int Heap::peek(){
  return heap[0];
}

int Heap::visualize(){
  int total = 0;
  int numprinted = 0;  //num on level printed
  int level = 0;

  while(total < len){
    //print number
    cout << heap[total];
    numprinted++;
    
    //if end of level print endl
    if(numprinted == pow(2, level)){
    }
  }
}
