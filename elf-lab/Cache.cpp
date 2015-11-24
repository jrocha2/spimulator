/*
 * DirectMappedCache.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: jbb
 */

#include "Cache.h"

#include "global.h"

Cache::Cache(unsigned logBlockSize_, unsigned logDepth_)
: logBlockSize(logBlockSize_),
  logDepth(logDepth_),
  accesses(0),
  hits(0),
  tagArray(new unsigned [1<<logDepth]),
  validArray(new bool [1<<logDepth])
{ }

Cache::~Cache() {
  delete tagArray;
  delete validArray;
}

bool Cache::checkHit(unsigned addr) {
  unsigned index = (1 << (logDepth + logBlockSize - 1 - logDepth + 1)) - 1;
  index = (addr >> logDepth) & index;

  unsigned tag = (1 << (31 - logDepth + logBlockSize + 1)) - 1;
  tag = (addr >> logDepth + logBlockSize) & tag;

  if (tagArray[index] == tag) {
      hits++;
      accesses++;
      return true;
  } else {
      accesses++;
      tagArray[index] = tag;
      return false;
  }
}

void Cache::printStats() {
  printf("accesses = %u  hits = %u  hit rate = %f\n", accesses, hits, (float) hits/accesses);
}
