#include "Testcase.h"


class CompressNum : public Testcase{

public:
	CompressNum(string _tc_name):tc_name(_tc_name){}
	virtual ~CompressNum(){};
	virtual void run();
	
protected:
	string tc_name;
	char * compress(char *str);
};

