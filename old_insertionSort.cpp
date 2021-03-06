#include <iostream>
#include <time.h>

using namespace std;

void getInput(int &sizeInput, char &caseInput);
void insertionSort(int* sortingArray, int sizeInput);
void printArray(int* sortingArray, int sizeInput);
int* generateArray(int sizeInput, char caseInput);

int main() {
  int* sortingArray;
  int sizeInput;
  char caseInput;
  srand(time(NULL));

  getInput(sizeInput, caseInput);
  sortingArray=generateArray(sizeInput, caseInput);
  insertionSort(sortingArray, sizeInput);

  if(sizeInput<=10) {
    printArray(sortingArray, sizeInput);
  }

  delete sortingArray; //can I do this or is a loop needed?

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
    while(idx2>=0 && sortingArray[idx2]>=key) {
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
        thisArray[idx]=rand()%sizeInput+1; //make sure this works (it looks like it does)
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
