#include "Test_Driver.h"

void Test_Driver::run_tests(){

	//Testcase *rs = dynamic_cast<Testcase *>(new Rspace("replace space") );
	/*
	Testcase *rs = new Rspace("replace space");
	tc_list.push_back(rs);
	*/	
	Testcase *cn = new CompressNum("compress string with letter and number");
	tc_list.push_back(cn);
	

	Testcase *ss = new SplitSentence("Given a long string, get all sentences. ");
	tc_list.push_back(ss);
		

	//rs->run();
	while(!tc_list.empty() ){
	Testcase *mycase = tc_list.back();
	mycase->run();
	cout<<endl<<"<Done>"<<endl<<endl;
	tc_list.pop_back();
	}

	tc_list.clear();
}