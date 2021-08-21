#include <iostream> 
#include <set> 
#include <algorithm> 
#include <vector>

using namespace std; 

template <typename T> 
void RemoveDuplicates(vector<T>& elements)
{
	sort(begin(elements), end(elements)); 
	auto it = unique(begin(elements), end(elements)); 
	elements.erase(it, end(elements)); 
}


