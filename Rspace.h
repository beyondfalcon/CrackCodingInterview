#include "Testcase.h"

// replace all spaces with %20

class Rspace : public Testcase{

public:

	Rspace(string _tc_name):tc_name(_tc_name){}
	virtual ~Rspace(){};
	virtual void run();
		
protected:

	string tc_name;
	char * replace(char *str, size_t length);
};

