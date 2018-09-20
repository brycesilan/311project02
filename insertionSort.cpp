#include <iostream>

using namespace std;

void getInput(int &sizeInput, char &caseInput);
void insertionSort(int* sortingArray, int sizeInput);
void printArray(int* sortingArray, int sizeInput);
int* generateArray(int sizeInput, char caseInput);

int main() {
  int* sortingArray;
  int sizeInput;
  char caseInput;

  getInput(sizeInput, caseInput);

  sortingArray=generateArray(sizeInput, caseInput);
  cout << "--- Array has been made, it is: ";
  printArray(sortingArray, sizeInput);

  insertionSort(sortingArray, sizeInput);
  cout << "--- Array has been sorted, it is: ";
  printArray(sortingArray, sizeInput);

  return 0;
}


void getInput(int &sizeInput, char &caseInput) {
  cout << "--- Enter size of array followed by 'b' - best case, 'w' - worst case, or 'a' - average case ---" << endl;
  cin >> sizeInput >> caseInput;
}

void insertionSort(int* sortingArray, int sizeInput) {
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

int* generateArray(int sizeInput, char caseInput) {
  int* thisArray=new int[sizeInput];

  switch (caseInput) {
    case 'b':
      for(int idx=0; idx<=sizeInput; idx++) {
        thisArray[idx]=idx+1;
      }
      break;
    case 'w':
      for(int idx=0; idx<=sizeInput; idx++) {
        if(idx==0) {
          thisArray[idx]=sizeInput;
        }
        else {
          thisArray[idx]=(thisArray[idx-1])-1;
        }
      }
      break;
    case 'a':
      for(int idx=0; idx<=sizeInput; idx++) {
        thisArray[idx]=rand()%sizeInput+1;
      }
      break;
  }

  return thisArray;
}

void printArray(int* sortingArray, int sizeInput) {
  for(int idx=0; idx<sizeInput; idx++) {
    cout << sortingArray[idx] << " ";
  }
  cout << endl;
}
