#include "FastBS.h"


void FastBS::dumpVec(vector<int> pv)
{
	vector<int>::iterator it=pv.begin();
	for(; it!= pv.end(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

void FastBS::partition(vector<int> &in, size_t old_low, size_t old_high, unsigned int &mask){

	//cout<<"start recurse"<<endl;	
	if (mask == 0)
		return;//finished all 32 bits calculation

	if(old_low == old_high)
		return;

	mask>>=1;//right shift one if the bit is signed!!
	size_t new_low = old_low;
	size_t new_high = old_high;

	while(new_low < new_high){
    //	dumpVec(in);
	if(in[new_low] & mask){//this position should be 0, but it is 1, then we have to find a higher pation with bit 0 to swap. the higher partition should always have bit 1 so 0 is incorrect. Swap!!
	while( (in[new_high] & mask))
		new_high--;
	//we found one!
	if(new_high > new_low && in[new_high]&mask==0){
		std::swap(in[new_low], in[new_high]);
	}
	
	if(new_low == new_high)	
		break;
	
	}

	new_low++;
	}

	cout<<old_low<<"--"<<new_low<<"--"<<new_high<<"--"<<old_high<<endl;
	dumpVec(in);
	unsigned int premask = mask;
	
	partition(in, new_high, old_high, mask);	
	partition(in, old_low, new_low, premask);
	//premask<<=1;
	
}

void FastBS::fast_bit_sort(vector<int> &in){

	size_t len = in.size();
	size_t lowPtr = 0;
	size_t highPtr = len - 1;
	unsigned int mask = 0x80000000;
	partition(in, lowPtr, highPtr, mask);
	
}


void FastBS::run(){

	int array[15]={-250, 250, 1, 0, -2, -4, 3, -8, 10, 4, -1,  -3, 2, -5, -12};
	vector<int> iarr(array, array + 15);
	//std::swap(iarr[0], iarr[1]);
	fast_bit_sort(iarr);
	dumpVec(iarr);
	
}

