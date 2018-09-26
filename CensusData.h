/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int type);               // sorts data using insertionSort
   void mergeSort(int type);                   // sorts data using mergeSort
   void quickSort(int type);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//
  void merge_sort(int leftBound, int rightBound);
  void merge(int leftBound, int midBound, int rightBound);
  void quicksort(int leftBound, int rightBound);
  int partition(int leftBound, int rightBound);
};

#endif // CSCI_311_CENSUSDATA_H
