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
    mergeSort(0, data.size()-1, 0);
  }
  else if(type==1) {
    mergeSort(0, data.size()-1, 1);
  }
}

void CensusData::quickSort(int type) {
  if(type==0) {
    quickSort(0, data.size()-1);
  }
  else if(type==1) {
    quickSort(0, data.size()-1);
  }
}

// helper data functions --------------------------------------------
//
//
//
void CensusData::mergeSort(int leftBound, int rightBound, int namePopulation) {
  if(leftBound<rightBound) {
    int midPoint = (leftBound+rightBound)/2;
    mergeSort(leftBound, midPoint, namePopulation);
    mergeSort(midPoint+1, rightBound, namePopulation);
    merge(leftBound, midPoint, rightBound, namePopulation);
  }
}

void CensusData::merge(int leftBound, int midBound, int rightBound, int namePopulation) {
  int arrayMark1 = midBound-leftBound+1;
  int arrayMark2 = rightBound-midBound;
  vector<Record*> leftArray(arrayMark1);
  vector<Record*> rightArray(arrayMark2);

  for(int idx=0; idx<arrayMark1; idx++) {
    leftArray[idx]=data[leftBound+idx];
  }
  for(int idx=0; idx<arrayMark2; idx++) {
    rightArray[idx]=data[midBound+idx+1];
  }

  unsigned int idx1=0, idx2=0;
  for(int idx=leftBound; idx<=rightBound; idx++) {
    if(idx1>=leftArray.size()) {
      data[idx]=rightArray[idx2];
      idx2++;
    }
    else if(idx2>=rightArray.size()) {
      data[idx]=leftArray[idx1];
      idx1++;
    }
    else {
      if(namePopulation==0) {
        if(leftArray[idx1]->population <= rightArray[idx2]->population) {
          data[idx]=leftArray[idx1];
          idx1++;
        }
        else {
          data[idx]=rightArray[idx2];
          idx2++;
        }
      }
      else {
        if(*leftArray[idx1]->city <= *rightArray[idx2]->city) {
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
}

void CensusData::quickSort(int leftBound, int rightBound) {
  if(leftBound<rightBound) {
    int midBound=randomizedPartition(leftBound, rightBound);
    quickSort(leftBound, midBound-1);
    quickSort(midBound+1, rightBound);
  }
}

int CensusData::randomizedPartition(int leftBound, int rightBound) {
  int randomNum = rand()%rightBound+leftBound;
  Record* tmp=data[randomNum];
  data[randomNum]=data[rightBound];
  data[rightBound]=tmp;
  return partition(leftBound, rightBound);
}

int CensusData::partition(int leftBound, int rightBound) {
  Record* pivot=data[rightBound];
  int leftIterator=leftBound-1;
  for(int idx=leftBound; idx>=rightBound-1; idx++) {
    if(data[idx]->population <= pivot->population) {
      leftIterator++;
      Record* tmp=data[leftIterator];
      data[leftIterator]=data[rightBound];
      data[rightBound]=tmp;
    }
  }
  Record* tmp=data[leftIterator+1];
  data[leftIterator+1]=data[rightBound];
  data[rightBound]=tmp;
  return leftIterator+1;
}
