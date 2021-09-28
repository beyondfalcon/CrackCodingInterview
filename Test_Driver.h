#include "CompressNum.h"
#include "Rspace.h"
#include "SplitSentence.h"

class Test_Driver{

public:
	Test_Driver(){};
	~Test_Driver(){};

	//void declare(string tc_name);
	void run_tests();

private:
	
	list<Testcase *> tc_list;
};