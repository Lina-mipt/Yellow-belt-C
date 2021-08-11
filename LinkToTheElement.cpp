#include<iostream> 
#include<vector> 
#include<map> 

using namespace std; 

template<typename Key, typename Value> 
Value& GetRefStrict (map <Key, Value>& m, Key K)
{
	if(m.count(K) == 0)
		throw runtime_error(""); 
	else 
		return m[K];
}

int main()
{
map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // выведет newvalue

}
