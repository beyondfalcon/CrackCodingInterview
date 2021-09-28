#include "CompressNum.h"


// Assume the string input is sorted alphabetically...
// front index and back index. mimic "rm dup", add cnt to obtain the times a char appears.

char * CompressNum::compress(char str[]){

	int len = strlen(str);
	unsigned cnt = 0;
	int front, back, index;
	front = back = 0;
	index = back; // index to set char or number
	

	while(str[front] != '\0'){
		
		//aaabbcddddd->a3b2c1d5		
		if(str[front] == str[back]){
		
			front++;
			cnt++;
		}
		else{
			str[index] = str[back];
			str[index + 1] = '0' + cnt;
			str[index + 2] = str[front];
			index += 2;
			back = front;
			cnt = 0;
		}

	}
	
	str[index] = str[back];
	str[index + 1] = '0' + cnt;
	str[index + 2] = str[front];
	index += 2;
	back = front;
	cnt = 0;

	for(int i = index + 1; i < len; ++i)
		str[i] = '\0';

	return str;
}

void CompressNum::run(){

	cout<<"running test case: "<<this->tc_name<<endl<<endl<<endl;
	setDescr("Compression under this rule: aaabbcccccddddd->a3b2c1d5.");
	sayme();

	char str[] = "aaabbcddddd";
	cout<<str<<endl<<endl;
	cout<<"Output: "<<compress(str)<<endl<<endl<<endl;

}