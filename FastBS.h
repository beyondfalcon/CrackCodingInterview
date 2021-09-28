#include <iostream>
#include <vector>

using namespace std;

class FastBS{

public:
	FastBS(){};
	~FastBS(){};

	void dumpVec(vector<int> );
	void partition(vector<int> &, size_t , size_t , unsigned int &);
	void run();
	void fast_bit_sort(vector<int> &);

};