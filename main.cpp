#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//  function prototypes
void insert(int n, int* &heap, int &c);
void print(int* &heap, int &c, int l, int r);
void remove_root(int* &heap, int &c);
void sort_up(int* &heap, int i);
void sort_down(int* &heap, int i, int &c);


int main()
{
  int *heap = new int[100]; // initialize heap as a array of ints
  char input [10];
  int c = 0; //initialize size of heap
  while (strcmp(input, "QUIT") != 0){
    cout << "ADD, DELETE, OR PRINT?" << endl;
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
	  cout << "Added " << num << endl;
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
4	remove_root(heap, c);
      }
      else if (strcmp(input3, "a") == 0){
	while (c != 0){ //continuously remove root until heap is empty
	  remove_root(heap, c);
	}
      }
    }

  }
  
}
void sort_up(int* &heap, int i)
{
  
  if (i == 0){ // base case: stop when at the root
    return;
  }
  else{
    int parent = (i-1)/2;
    if (heap[parent] < heap[i]){ // check if current number is greater than its parent
      // swap child and parent
      int temp = heap[parent];
      heap[parent] = heap[i];
      heap[i] = temp;
      i = parent;
      sort_up(heap, i); // continue sorting with new parent
    }
    else{ //stop when parent is larger than its child
      return;
    }
  }
}

void sort_down(int* &heap, int i, int &c)
{
  int left = (i*2) + 1;
  int right = (i*2) + 2;
  if (left > c || right > c){ // reached a leaf
    return;
  }

  // check which child is larger
  if (heap[left] > heap[right]){ //swap left child with current position
    int temp = heap[i];
    heap[i] = heap[left];
    heap[left] = temp;
    i = left; // set new position to continue sorting down from 
  }
  if (heap[right] > heap[left]){ //swap right child with current position
    int temp2 = heap[i];
    heap[i] = heap[right];
    heap[right] = temp2;
    i = right; //set new position to continue sorting from
  }
  sort_down(heap, i, c);
}

void insert (int n, int* & heap, int &c)
{
  heap[c] = n; // set empty spot to number to be added
  int i = c; // set i to current position
  sort_up(heap, i); // sort up the heap
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
  heap[0] = heap[c-1]; //set root to last number in the heap
  c--; //shrink heap size by 1
  sort_down(heap, 0, c); //sort down the tree
}





  
