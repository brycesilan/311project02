#include <iostream>

using namespace std;

void getInput(int* &sortingArray, int sizeInput, char caseInput);
void insertionSort(int* &sortingArray, int sizeInput);
void printArray(int* sortingArray, int sizeInput);
void generateArray(int* &sortingArray, int sizeInput, char caseInput);

int main() {
  int* sortingArray;
  int sizeInput;
  char caseInput;

  getInput(sortingArray, sizeInput, caseInput);
  insertionSort(sortingArray, sizeInput);
  printArray(sortingArray, sizeInput);

  return 0;
}


void getInput(int* &sortingArray, int sizeInput, char caseInput) {
  cout << "--- Enter size of array followed by 'b' - best case, 'w' - worst case, or 'a' - average case ---" << endl;
  cin >> sizeInput >> caseInput;

  sortingArray=new int[sizeInput];
}

void insertionSort(int* &sortingArray, int sizeInput) {
  for(int idx=1; idx<sizeInput; idx++) {
    int key=sortingArray[idx];
    int idx2=idx-1;
    while(idx2>=0 && sortingArray[idx]>=key) {
      sortingArray[idx2+1]=sortingArray[idx2];
      idx2--;
    }
    sortingArray[idx2+1]=key;
  }
}

void printArray(int* sortingArray, int sizeInput) {
  for(int idx=0; idx<sizeInput; idx++) {
    cout << sortingArray[idx] << " ";
  }
  cout << endl;
}

//others made generate array actually return and array pointer
void generateArray(int* &sortingArray, int sizeInput, char caseInput) {
  switch (caseInput) {
    case 'b':
      for(int idx=0; idx<sizeInput; idx++) {
        sortingArray[idx]=idx+1;
      }
      break;
    case 'w':
      for(int idx=sizeInput; idx>=0; idx--) {
        if(idx=sizeInput) {
          sortingArray[idx]=1;
        }
        else {
          sortingArray[idx]=sortingArray[idx+1]+1;
        }
      }
      break;
    case 'a':
      break;
    default:
      cerr << "Error: Invalid case" << endl;
      break;
  }
}
