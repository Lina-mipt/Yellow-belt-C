#include <iostream>
#include <sstream> 
#include <vector> 
#include <set> 
#include <algorithm> 
#include <string>
#include <numeric>
using namespace std; 

struct Date
{
	int year; 
	int month; 
	int day; 
};

 struct Earn 
{
	Date first_date; 
	Date last_date; 
	int sum = 0; 
};

struct Query
{
	Date first_date; 
	Date second_date; 
}; 

Date GetDate (const string& date) 
{
	Date new_date; 
	istringstream is(date); 
	string tmp; 
	getline(is, tmp, '-'); 
	new_date.year = stoi(tmp); 
	getline(is, tmp, '-'); 
	new_date.month = stoi(tmp); 
	getline(is, tmp); 
	new_date.day = stoi(tmp); 
	
	return new_date; 
}

Query GetQuery(const string& query)
{
	Query new_query; 
	istringstream is(query);  
	string tmp; 
	is >> tmp; 
	new_query.first_date = GetDate(tmp); 
	is >> tmp; 
	new_query.second_date = GetDate(tmp);

	return new_query; 
}

bool operator < (const Date& first, const Date& second) 
{
	if(first.year < second.year) 
		return true; 
	else 
		return false; 
	
	if(first.month < second.month) 
		return true; 
	else 
		return false; 

	if(first.day < second.day) 
		return true; 
	else 
		return false; 

	return false; 
}

bool operator > (const Date& first, const Date& second) 
{
	if(first.year > second.year) 
		return true; 
	else 
		return false; 
	
	if(first.month > second.month) 
		return true; 
	else 
		return false; 

	if(first.day > second.day) 
		return true; 
	else 
		return false; 

	return false; 
}

bool operator == (const Date& first, const Date& second) 
{ 
	return ((first.year == second.year) && (first.month == second.month) && (first.day == second.day)); 
}


bool operator < (const Earn& first, const Earn& second)
{
	if(first.first_date < second.first_date) 
		return true; 
	else if (first.first_date == second.first_date) 
	{
		if(first.last_date < second.last_date) 
			return true; 
		else 
			return false;
	}
		return false;
} 

int operator + (const Earn& first, const Earn& second) 
{
	return (first.sum + second.sum); 
}

class MyBudget
{
	private: 
		set<Earn> my_budget_; 
	public: 
		void AddRecord(string& record)
		{
			Earn new_one; 
			istringstream is(record); 
			string tmp; 
			is >> tmp; 
			new_one.first_date = GetDate(tmp); 
			is >> tmp; 
			new_one.last_date = GetDate(tmp); 
			is  >> tmp; 
			new_one.sum = stoi(tmp);

			my_budget_.insert(new_one); 
		}

		long ComputeIncome(string& query) 
		{
			Query new_query; 
			new_query = GetQuery(query);
			Date first_d = new_query.first_date; 
			auto first = find_if(begin(my_budget_), end(my_budget_), [first_d](const Earn& rec) 
				{
					return rec.first_date < first_d;
				});
			Date second_d = new_query.second_date; 
			auto second = find_if(begin(my_budget_), end(my_budget_), [second_d](const Earn& rec)
				{
					return rec.last_date > second_d; 
				});
			
			auto Sum = [](int sum, Earn tmp) 
			{
				return move(sum) + tmp.sum; 
			}; 

			long sum = accumulate(first, second, 0, Sum);

			return sum;
		}
}; 

void GetTask(MyBudget& my_budget) 
{
	string tmp; 
	cin >> tmp; 
	if(tmp == "Earn") 
	{
		getline(cin, tmp); 
		my_budget.AddRecord(tmp); 
	}
	else 
	{
		getline(cin, tmp); 
		cout.precision(25); 
		cout <<  my_budget.ComputeIncome(tmp);  
	}
}

int main() 
{
	int quanity_of_query; 
	cin >> quanity_of_query; 
	MyBudget my_budget; 

	for(int i = 0; i < quanity_of_query; i++) 
	{
		GetTask(my_budget);  
	}
}
