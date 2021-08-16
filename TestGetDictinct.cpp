#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

template<class T, class U>
void AssertEqual(const T& t, const U& u)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    throw runtime_error(os.str());
  }
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
	  func();
	  cerr << test_name << " OK" << endl;
	} catch (runtime_error& e) {
	  ++fail_count;
	  cerr << test_name << " fail: " << e.what() << endl;
	}
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

void TestGetDistinctRealCount() 
{
	AssertEqual(GetDistinctRealRootCount(0, 5, 10), 1); 
	AssertEqual(GetDistinctRealRootCount(0, 0, 7), 0); 
	AssertEqual(GetDistinctRealRootCount(2, 1, 3), 0); 
	AssertEqual(GetDistinctRealRootCount(1, 3, 1), 2); 
	AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1); 
}

int main() 
{
	TestRunner tr; 
	tr.RunTest(TestGetDistinctRealCount, "TestGetDistinctRealCount"); 
}

