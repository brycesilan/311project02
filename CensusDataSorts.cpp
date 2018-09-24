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
void CensusData::insertionSort(int /*type*/) {
  for(int idx=1; idx<data.size(); idx++) {
	  //need to change the variable types (probably to Record*)
    int key=data[idx];
    int idx2=idx-1;
    while(idx2>=0 && data[idx2]>=key) {
      data[idx2+1]=data[idx2];
      idx2--;
    }
    data[idx2+1]=key;
  }
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::mergeSort(int /*type*/) {
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::quickSort(int /*type*/) {
}
