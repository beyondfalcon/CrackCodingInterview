#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <CString>
#include <algorithm>
#include <map>

using namespace std;

//Use ifndef and define to handle this:
//multiple files include one single file, here it is Testcase.h, files for derived classes all include this. 
//We need preprocessing only the first time it is included. Other cases where it is included, it is not preprocessed.  

#ifndef TESTCASE
#define TESTCASE

class Testcase{

public:
	Testcase(){};
	Testcase(string name) {this->tc_name = name;};
	void setDescr(string inDescr);
	void sayme();
	virtual ~Testcase(){};
	virtual void run(); 

protected:

	string tc_name;
	string description;

};
#endif
