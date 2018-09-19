#include <iostream>
#include <vector>

using namespace std;

void getInput(vector<int> &myList);
void insertionSort(vector<int> &myList);
void printVec(vector<int> myList);

int main() {
  vector<int> myList;

  getInput(myList);
  cout << "--- Here is the unsorted list ---" << endl;
  printVec(myList);
  insertionSort(myList);
  cout << "--- Here is the sorted list ---" << endl;
  printVec(myList);

  return 0;
}


void getInput(vector<int> &myList) {
  int input=0;

  cout << "--- Insert numbers into the list, when done, type 999 ---" << endl;
  while(cin >> input) {
    if(input==999) {
      break;
    }
    myList.push_back(input);
  }
}

void insertionSort(vector<int> &myList) {
  for(int idx=1; idx<myList.size(); idx++) {
    int key=myList[idx];
    int idx2=idx-1;
    while(idx2>=0 && myList[idx]>=key) {
      myList[idx2+1]=myList[idx2];
      idx2--;
    }
    myList[idx2+1]=key;
  }
}

void printVec(vector<int> myList) {
  for(int idx=0; idx<myList.size(); idx++) {
    cout << myList[idx] << " ";
  }
  cout << endl;
}
