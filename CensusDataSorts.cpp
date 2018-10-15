/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 *         Connor Richards
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"

/**
 * insertionSort
 *
 * @brief
 *    Sorts data using insertion sorting algorithm
 *    by name or population
 *
 * @param int type The sorting type
 *
 * @return nothing
 */
void CensusData::insertionSort(int type) {
  /** if type==0, sort by population */
  if(type==0) {
    /** loops through size of data array */
    for(unsigned int idx=1; idx<data.size(); idx++) {
      /** declare key, indexing var, and keyPtr */
      int key=data[idx]->population;
      int idx2=idx-1;
      Record* keyPtr=data[idx];
      /** loop while item not in place, with comparing pop. */
      while(idx2>=0 && data[idx2]->population>=key) {
        data[idx2+1]=data[idx2];
        idx2--;
      }
      /** replace the keyPtr */
      data[idx2+1]=keyPtr;
    }
  }
  /** if type==1, sort by name */
  else if(type==1) {
    /** loops through size of data array */
    for(unsigned int idx=1; idx<data.size(); idx++) {
      /** declare key, indexing var, and keyPtr */
      string key=*data[idx]->city;
      int idx2=idx-1;
      Record* keyPtr=data[idx];
      /** loop while item not in place, with comparing names */
      while(idx2>=0 && *data[idx2]->city>=key) {
        data[idx2+1]=data[idx2];
        idx2--;
      }
      /** replace the keyPtr */
      data[idx2+1]=keyPtr;
    }
  }
}

/**
 * mergeSort
 *
 * @brief
 *    sorts data using merge sort
 *    algorithm by name or population
 *
 * @param int type The sorting type
 *
 * @return nothing
 */
void CensusData::mergeSort(int type) {
  /** if type==0, sort by pop. */
  if(type==0) {
    /** pass leftBound=0, rightBound=data.size()-1, and sorting type=0 */
    mergeSort(0, data.size()-1, type);
  }
  /** if type==1, sort by name */
  else if(type==1) {
    /** pass leftBound=0, rightBound=data.size()-1, and sorting type=1 */
    mergeSort(0, data.size()-1, type);
  }
}

/**
 * quickSort
 *
 * @brief
 *    sorts data using randomized quicksort
 *    algorithm by name or population
 *
 * @param int type The sorting type
 *
 * @return nothing
 */
void CensusData::quickSort(int type) {
  /** instantiate and seed the random number generator */
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  /** if type==0, sort by population */
  if(type==0) {
    /** pass leftBound=0, rightBound=data.size()-1, type=0(for name sort) */
    /** and seeded generator */
    quickSort(0, data.size()-1, type, generator);
  }
  /** if type==1, sort by name */
  else if(type==1) {
    /** pass leftBound=0, rightBound=data.size()-1, type=1(for pop. sort) */
    /** and seeded generator */
    quickSort(0, data.size()-1, type, generator);
  }
}

/**
 * mergeSort
 *
 * @brief
 *    sorts by recursively calling mergeSort and merge
 *    on two halves of the data set
 *
 * @param int leftBound The left sub-array bound
 * @param int rightBound The right sub-array bound
 * @param int namePopulation The sorting type
 *
 * @return nothing
 */
void CensusData::mergeSort(int leftBound, int rightBound, int namePopulation) {
  /** if not in a base case then sort */
  if(leftBound<rightBound) {
    /** create midPoint var */
    int midPoint = (leftBound+rightBound)/2;
    /** sort left side */
    mergeSort(leftBound, midPoint, namePopulation);
    /** sort right side */
    mergeSort(midPoint+1, rightBound, namePopulation);
    /** merge the two sides */
    merge(leftBound, midPoint, rightBound, namePopulation);
  }
}

/**
 * merge
 *
 * @brief
 *    merges, in order, the left and right
 *    arrays based on passed in bounds
 *
 * @param int leftBound The left sub-array bound
 * @param int midBound The middle sub-array bound
 * @param int rightBound The right sub-array bound
 * @param int namePopulation The sorting type
 *
 * @return nothing
 */
void CensusData::merge(int leftBound, int midBound, int rightBound, int namePopulation) {
  /** declare/define array sizes for left and right */
  int arrayMark1 = midBound-leftBound+1;
  int arrayMark2 = rightBound-midBound;
  /** create vectors based on the sizes created above */
  vector<Record*> leftArray(arrayMark1);
  vector<Record*> rightArray(arrayMark2);

  /** loop to fill leftArray with proper data */
  for(int idx=0; idx<arrayMark1; idx++) {
    leftArray[idx]=data[leftBound+idx];
  }
  /** loop to fill rightArray with proper data */
  for(int idx=0; idx<arrayMark2; idx++) {
    rightArray[idx]=data[midBound+idx+1];
  }

  /** declare/define indexing ints */
  unsigned int idx1=0, idx2=0;
  /** loop rightBound to leftBound */
  for(int idx=leftBound; idx<=rightBound; idx++) {
    /** merge case that leftArray is all used */
    if(idx1>=leftArray.size()) {
      data[idx]=rightArray[idx2];
      idx2++;
    }
    /** merge case that rightArray is all used */
    else if(idx2>=rightArray.size()) {
      data[idx]=leftArray[idx1];
      idx1++;
    }
    /** merge case that both arrays can be pulled from */
    else {
      /** case of sorting by population */
      if(namePopulation==0) {
        /** compare populations */
        if(leftArray[idx1]->population <= rightArray[idx2]->population) {
          /** if left is smaller take it, increment idx1 */
          data[idx]=leftArray[idx1];
          idx1++;
        }
        else {
          /** if right is smaller take it, increment idx2 */
          data[idx]=rightArray[idx2];
          idx2++;
        }
      }
      /** case of sorting by name */
      else {
        /** compare city names (alphabetical) */
        if(*leftArray[idx1]->city <= *rightArray[idx2]->city) {
          /** if left is smaller take it, increment idx1 */
          data[idx]=leftArray[idx1];
          idx1++;
        }
        else {
          /** if right is smaller take it, increment idx2 */
          data[idx]=rightArray[idx2];
          idx2++;
        }
      }
    }
  }
}

/**
 * quickSort
 *
 * @brief
 *    sorts data by calling randomizedPartition
 *    for a midBound and recursively calls itself
 * 
 * @param int leftBound The left sub-array bound
 * @param int rightBound The right sub-array bound
 * @param int namePopulation The sorting type
 * @param std::default_random_engine generator
 *    The random number generator
 *
 * @return nothing
 */
void CensusData::quickSort(int leftBound, int rightBound, int namePopulation, std::default_random_engine generator) {
  /** checks for base case, of 1 item or less array */
  if(leftBound<rightBound) {
    /** create a midbound by calling randomizedPartition, pass in vars. */
    int midBound=randomizedPartition(leftBound, rightBound, namePopulation, generator);
    /** call quicksort on each sub-array (left/right) */
    quickSort(leftBound, midBound-1, namePopulation, generator);
    quickSort(midBound+1, rightBound, namePopulation, generator);
  }
}

/**
 * randomizedPartition
 *
 * @brief
 *    creates random number between bounds
 *    and switches the last data value with
 *    the random one to avoid worst case sorting
 *
 * @param int leftBound The left sub-array bound
 * @param int rightBound The right sub-array bound
 * @param int namePopulation The sorting type
 * @param std::default_random_engine generator
 *    The random number generator
 *
 * @return int indicating mid-point between two
 *    sorted sub-arrays
 */
int CensusData::randomizedPartition(int leftBound, int rightBound, int namePopulation, std::default_random_engine generator) {
  /** set randomNum to a num. from leftBound to rightBound */
  std::uniform_int_distribution<int> distribution(leftBound,rightBound);
  int randomNum = distribution(generator);
  /** swap data numbers [randomNum] and [rightBound] */
  /** to avoid worst case sorting */
  Record* tmp=data[randomNum];
  data[randomNum]=data[rightBound];
  data[rightBound]=tmp;
  /** return result of partition, pass in left/right/namPop */
  return partition(leftBound, rightBound, namePopulation);
}

/**
 * partition
 *
 * @brief
 *    uses bounds to sort sub-arrays based on
 *    name or population
 *
 * @param int leftBound The left sub-array bound
 * @param int rightBound The right sub-array bound
 * @param int namePopulation The sorting type
 *
 * @return int indicating mid-point betweem two
 *    sorted sub-arrays
 */
int CensusData::partition(int leftBound, int rightBound, int namePopulation) {
  /** create a pivot value (record pointer) */
  Record* pivot=data[rightBound];
  /** create the <= half marker */
  int leftIterator=leftBound-1;
  /** loops for difference between left/right bounds */
  for(int idx=leftBound; idx<=rightBound-1; idx++) {
    /** sort by name */
    if(namePopulation==0) {
      /** compares populations, swap if necessary */
      if(data[idx]->population <= pivot->population) {
        leftIterator++;
        Record* tmp=data[leftIterator];
        data[leftIterator]=data[idx];
        data[idx]=tmp;
      }
    }
    /** sort by population */
    else {
      /** compares city names alphabetically */
      /* swap if necessary */
      if(*data[idx]->city <= *pivot->city) {
        leftIterator++;
        Record* tmp=data[leftIterator];
        data[leftIterator]=data[idx];
        data[idx]=tmp;
      }
    }
  }
  /* swap pivot data with one after the <= half marker */
  Record* tmp=data[leftIterator+1];
  data[leftIterator+1]=data[rightBound];
  data[rightBound]=tmp;
  /* return the <= half marker */
  return leftIterator+1;
}
