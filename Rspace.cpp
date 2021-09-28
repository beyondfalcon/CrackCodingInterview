#include "Rspace.h"


char * Rspace::replace(char *instr, size_t length){

	int i, new_length = length;
	for(i = 0; i < length; ++i)
		if(instr[i] == ' ')
			new_length += 2;

	instr[new_length] = '\0';

	//"this is a basic test"
	//->"this is a basic test\0\0\0\0\0\0\0\0-\0"
	//->"this is a basic\0\0\0\0%20test-\0"
	//goes on and on...


	for(i = length - 1; i > 0; i--){
	
		if(instr[i] == ' '){
		
			instr[new_length - 1] = '0';
			instr[new_length - 2] = '2';
			instr[new_length - 3] = '%';
			new_length -= 3;

		}
		else{
		
			instr[new_length - 1] = instr[i];
			new_length--;
		}
	
	
	}

	return instr;
}

void Rspace::run(){

	//cout<<"running test case: "<<this->tc_name<<endl<<endl<<endl;
	setDescr("replace all the spaces with %20. Assume that the original string is long enough.");
	sayme();

	
	vector<string > input_vec;
	vector<string >::iterator s_iter;

	input_vec.push_back("this is a basic test");
	input_vec.push_back("G dont think so      ");
	input_vec.push_back(" G dont think so ");

	cout<<"\nOutput: "<<endl;

	for(s_iter = input_vec.begin(); s_iter != input_vec.end(); ++s_iter){
	
		string that = *s_iter;
		char instr[1024];
		//TODO: encapsulate to resize()...
		//char *instr = (char *)realloc((void *)that.c_str(), that.size() + 128);//make the size of the string big enough for appending %20
		
		memset(instr, 0x0, sizeof(instr));
		memcpy(instr, that.c_str(), that.size() );//size cannot be that of instr, too big. 

		cout<<replace(instr, that.size() )<<endl;
	
	}

	
}