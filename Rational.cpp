#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
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

void TestDefaultCreation()
{
	Rational rational; 
	AssertEqual(rational.Numerator(), 0); 
	AssertEqual(rational.Denominator(), 1); 
}

void TestWork() 
{
	Rational r(10, 5); 
	AssertEqual(r.Numerator(), 2); 
	AssertEqual(r.Denominator(), 1); 

	Rational k(-1, 8); 
	AssertEqual(k.Numerator(), -1); 
	AssertEqual(k.Denominator(), 8); 

	Rational l(1, -8); 
	AssertEqual(l.Numerator(), -1); 
	AssertEqual(l.Denominator(), 8); 

	Rational u(-2, -3); 
	AssertEqual(u.Numerator(), 2); 
	AssertEqual(u.Denominator(), 3); 

	Rational q(2, 3); 
	AssertEqual(q.Numerator(), 2); 
	AssertEqual(q.Denominator(), 3); 

	Rational t(0, 6); 
	AssertEqual(t.Numerator(), 0); 
	AssertEqual(t.Denominator(), 1); 

}

void AllTestRational()
{
	TestDefaultCreation(); 
	TestWork(); 
}

int main() {
  TestRunner runner;
  runner.RunTest(AllTestRational, "AllTestRational"); 
  return 0;
}
