#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void insert(int n, int* &heap, int &c);
void print(int* &heap, int &c, int l, int r);
void remove_root(int* &heap, int &c);
void sort_up(int* &heap, int i);
void sort_down(int* &heap, int i, int &c);


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

      else if (strcmp(input2, "f") == 0){
	ifstream inputFile("nums.txt");
	int num;
	while (inputFile >> num){
	  insert(num, heap, c);
	}
	inputFile.close();
      }
            
    }
    else if (strcmp(input, "PRINT") == 0) {
      print(heap, c, 0, 0);
    }

    else if (strcmp(input, "DELETE") == 0){
      char input3[10];
      cout << "remove root (r) or all (a)? ";
      cin.get(input3,10);
      cin.get();
      if (strcmp(input3, "r") == 0){
	remove_root(heap, c);
      }
      else if (strcmp(input3, "a") == 0){
	while (c != 0){
	  remove_root(heap, c);
	}
      }
    }

  }
  
}
void sort_up(int* &heap, int i)
{
  
  if (i == 0){
    return;
  }
  else{
    int parent = (i-1)/2;
    if (heap[parent] < heap[i]){
      int temp = heap[parent];
      heap[parent] = heap[i];
      heap[i] = temp;
      i = parent;
      sort_up(heap, i);
    }
    else{
      return;
    }
  }
}

void sort_down(int* &heap, int i, int &c)
{
  int left = (i*2) + 1;
  int right = (i*2) + 2;
  if (left >= c || right >= c){
    return;
  }
  if (heap[left] > heap[right]){
    heap[i] = heap[left];
    i = left;
  }
  if (heap[right] > heap[left]){
    heap[i] = heap[right];
    i = right;
  }
  sort_down(heap, i, c);
}

void insert (int n, int* & heap, int &c)
{
  heap[c] = n;
  int i = c;
  sort_up(heap, i);
  c++;
}

void print(int* &heap, int &c, int i, int depth = 0)
{

  if (i >= c){
    return;
  }

  print(heap,c, 2*i + 2, depth + 1);

  for (int j = 0; j < depth; j++){
    cout << "   ";
  }
  cout << heap[i] << endl;

  print(heap, c, 2*i +1, depth + 1);

}

void remove_root(int* &heap, int &c)
{
  cout << "Removed " << heap[0] << endl;
  heap[0] = heap[c-1];
  c--;
  sort_down(heap, 0, c);
}





  
