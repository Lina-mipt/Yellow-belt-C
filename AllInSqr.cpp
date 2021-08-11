#include<iostream> 
#include<vector>
#include<map> 

using namespace std; 

template<typename T> T Sqr(T& t); 
template <typename First, typename Second> pair<First, Second> Sqr(pair<First, Second>& p); 
template <typename T> vector<T> Sqr(vector<T>& v); 
template <typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value>& m);  

template <typename T> 
T Sqr (T& t) 
{
	return t*t; 
}

template <typename First, typename Second> 
pair<First, Second> Sqr(pair<First, Second>& p) 
{
		p.first = Sqr(p.first);  
		p.second =Sqr(p.second); 
	return p; 
}

template <typename T> 
vector<T> Sqr(vector<T>& v) 
{
	for(auto& i : v) 
		i = Sqr(i);
	return v; 
}

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value>& m) 
{
	for(auto& i : m) 
		i.second = Sqr(i.second); 
	return m; 
}

int main()
{
} 
