#include "Test_Driver.h"

//using namespace std;

int main(int argc, char** argv){

	//cout<<"Test"<<endl;

	Test_Driver *td = new Test_Driver();

	td->run_tests();

	delete td;

	system("Pause");

	return 0;
}