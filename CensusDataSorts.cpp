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
    //TODO insertion sort by name
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

// formal parameter name commented out to avoid unused variable warning
void CensusData::mergeSort(int /*type*/) {
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::quickSort(int /*type*/) {
}
