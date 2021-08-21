#include <algorithm> 
#include <vector>
#include <iostream>
#include <sstream>
using namespace std; 

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) 

{
  int length = range_end - range_begin;
  if (length < 2) 
	{
    return;
  }
  
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  
  auto mid = elements.begin() + length / 2;
  
  MergeSort(elements.begin(), mid);
  MergeSort(mid, elements.end());
  
  merge(elements.begin(), mid, mid, elements.end(), range_begin);
}
