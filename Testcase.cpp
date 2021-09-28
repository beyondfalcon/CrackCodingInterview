#include "Testcase.h"


void Testcase::run(){

	cout<<"running test case: "<<this->tc_name<<endl<<endl<<endl<<endl;

}


void Testcase::setDescr(string inDescr){


	this->description = inDescr;

}



void Testcase::sayme(){

	//cout<<"running test case: "<<this->tc_name<<endl<<endl<<endl;

	cout<<"Description: \n     "<<description<<endl<<endl;

	//cout<<"Input: ";
}

