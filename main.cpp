#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void insert(int n, int* &heap, int &c);
void print(int* &heap, int &c);
void remove_root(int* &heap);


int main()
{
  int *heap = new int[100];
  char input [10];
  int c = 0;
  cout << "ADD, DELETE, or PRINT" << endl;
  while (strcmp(input, "QUIT") != 0){
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "ADD") == 0){
      cout << "manual(m) or file(f)? ";
      char input2[10];
      cin.get(input2, 10);
      cin.get();
      if (strcmp(input2, "m") == 0){
	int n;
	cout << "What number do you want to add? " << endl;
	cin >> n;
	cin.ignore();
	insert(n, heap, c);
      }
            
    }
    else if (strcmp(input, "print") == 0) {
      print(heap, c);
    }
  }
  
}

void insert (int n, int* & heap, int &c)
{
  heap[c] = n;
  int i = c;
  while (i != 0){
    int parent = floor((i-1)/2);
    if (heap[parent] < heap[i]){
      int temp = heap[parent];
      heap[parent] = heap[i];
      heap[i] = temp;
      i = parent;
    }
    else{
      break;
    }
  }
  c++;
}

void print(int* &heap, int &c)
{
    for (int i = 0; i < c; ++i)
        cout << heap[i] << " ";

    cout << "\n";
}






  
