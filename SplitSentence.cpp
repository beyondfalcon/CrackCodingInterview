#include "SplitSentence.h"


void SplitSentence::run(){

	int i;
	string input, sentence;
	vector<string> dict_vec;
	vector<string> sentences;
	map<string, bool> used;
	
	//assume the dictionary can cover all candidate words in the input string. 
	char* array[13] = {"a", "at","alice", "bob", "an", "and", "data", "tar", "really", "ally", "cat", "are", "list"};
	vector<char* > temp(array, array + 13);

	for(i = 0; i < 13; ++i){
			
		string t_str(temp[i]);
		dict_vec.push_back(t_str);

	}

	setDescr("Get all possible sentences(composed of words) from an input string. Given a dictionary to check if a substr is a word.");
	sayme();


	input.append("listandatareally");
	cout<<endl<<"Input: "<<input<<endl;
	cout<<"\nOutput: "<<endl;

	if(split(input, sentence, dict_vec, sentences, used) ){
		cout<<"Finished spliting. "<<endl;
		// return;
	}

	//dump_sentences(sentences);

}


void SplitSentence::dump_sentences(vector<string> sentences){

	vector<string>::iterator it = sentences.begin();
	
	while(it != sentences.end() ){
	
		cout<<*it<<endl;
	}

	cout<<endl;
}

// check if the str is a word
bool SplitSentence::isWord(string str, vector<string> dict_vec){

	vector<string>::iterator it = dict_vec.begin();
	for(; it != dict_vec.end(); it++)
		if(*it == str)
			return true;
	
	return false;
}

// Get 1st word from input string, note that it should not be visited twice. That's why we need used. 
// we have tried "an", next time when we see "an", it's used then we need to expand it to "and". 
// We handle the above logic here:
bool SplitSentence::get1stword(string input, vector<string> dict_vec, string &output, map<string, bool> &used){
	
	map<string, bool>::iterator it;
	size_t i, length = input.size();
	for(i = 0; i < length; ++i){
		
		string sub = input.substr(0, i + 1);
		if(isWord(sub, dict_vec) )
			if((it = used.find(sub)) == used.end() ){
				output = sub; // qualified 1st word.
				used[output] = true;
				return true;
			}
	// it's a word but already counted. Then discard it.  

	}
		
	return false;
}

/* main part. Split the input string into a sentence if possible. */
bool SplitSentence::split(string input, string &sentence, vector<string> dict_vec, vector<string> &sentences, map<string, bool> &used){

	static int level = 0;
	level++;
	
	string word1;      //from input string, we need to get the 1st word as substring. 
	string remaining;  // truncate the original string with the 1st word(word1). After we get "an", the remaining is "datareally"
	size_t length_in = input.size();
	size_t length1;
	// string input_orig = input;
	// the end point of the recursion--

	lable:
	if(!get1stword(input, dict_vec, word1, used) ){
		
		// sentence.clear();
		 return false;
	}
	
	if(word1 == input){//Finally we got one sentence. And print it out. 
		
		sentence.append(word1);
		//sentences.push_back(sentence);
		cout<<sentence<<endl<<endl;
		return true;
	}	

	// --the end point of the recursion
	string orig_sent = sentence;
	length1 = word1.size();
	sentence.append(word1 + " ");// We got a candidate word in sentence. 
	
	string orig_word1 = word1;
	remaining = input.substr(length1, length_in - length1);

	if(!split(remaining, sentence, dict_vec, sentences, used) ){
		
		//cannot get the sentence if going on, so need to disgard word1 and try another word1. 
		used[word1] = false;
		size_t pos = sentence.find(word1);
		sentence = sentence.substr(0, pos);
		// split(input, sentence, dict_vec, sentences, used);
		goto lable;
	// backtrace.. remove the word1 and start again..... Note space. 
	}
	else // remaining works. We get the sentence. Then we try alternative sentences. 
	{
	  	size_t pos = sentence.find(orig_word1);
		sentence = sentence.substr(0, pos);

	}

}