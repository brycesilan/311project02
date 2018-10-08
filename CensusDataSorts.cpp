/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"

// formal parameter name commented out to avoid unused variable warning
void CensusData::insertionSort(int type) {
  if(type==0) {
    for(unsigned int idx=1; idx<data.size(); idx++) {
      int key=data[idx]->population;
      int idx2=idx-1;
      Record* keyPtr=data[idx];
      while(idx2>=0 && data[idx2]->population>=key) {
        data[idx2+1]=data[idx2];
        idx2--;
      }
      data[idx2+1]=keyPtr;
    }
  }
  else if(type==1) {
    for(unsigned int idx=1; idx<data.size(); idx++) {
      string key=*data[idx]->city;
      int idx2=idx-1;
      Record* keyPtr=data[idx];
      while(idx2>=0 && *data[idx2]->city>=key) {
        data[idx2+1]=data[idx2];
        idx2--;
      }
      data[idx2+1]=keyPtr;
    }
  }
}

void CensusData::mergeSort(int type) {
  if(type==0) {
    merge_sort(0, data.size());
  }
  else if(type==1) {
  }
}

//TODO needs to be a randomized quicksort
void CensusData::quickSort(int type) {
  if(type==0) {
  }
  else if(type==1) {
  }
}

// helper data functions --------------------------------------------
void CensusData::merge_sort(int leftBound, int rightBound) {
  if(leftBound<rightBound) {
    int midPoint = (leftBound+rightBound)/2;
    merge_sort(leftBound, midPoint);
    merge_sort(midPoint+1, rightBound);
    merge(leftBound, midPoint, rightBound);
  }
}

void CensusData::merge(int leftBound, int midBound, int rightBound) {
  int arrayMark1 = midBound-leftBound+1;
  int arrayMark2 = rightBound-midBound;
  vector<Record*> leftArray(arrayMark1);
  vector<Record*> rightArray(arrayMark2);

  for(int idx=0; idx<=arrayMark1; idx++) {
    leftArray[idx]=data[leftBound+idx];
  }
  for(int idx=0; idx<=arrayMark2; idx++) {
    rightArray[idx]=data[midBound+idx];
  }

  //TODO pseudocode says to set the last array values to infinity here?

  unsigned int idx1=0, idx2=0;
  for(int idx=leftBound; idx<=rightBound; idx++) {
    if(idx1>leftArray.size()) {
      data[idx]=rightArray[idx2];
      idx2++;
    }
    else if(idx1>rightArray.size()) {
      data[idx]=leftArray[idx1];
      idx1++;
    }
    else {
      if(leftArray[idx1]->population <= rightArray[idx2]->population) {
        data[idx]=leftArray[idx1];
        idx1++;
      }
      else {
        data[idx]=rightArray[idx2];
        idx2++;
      }
    }
  }
}

/*
   void CensusData::quicksort(int leftBound, int rightBound) {
   }

   int CensusData::partition(int leftBound, int rightBound) {
   }
   */
