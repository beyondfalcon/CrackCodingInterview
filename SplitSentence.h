#pragma once
#include "testcase.h"
class SplitSentence : public Testcase
{

	public:
		SplitSentence(string _tc_name):tc_name(_tc_name){}
		virtual ~SplitSentence(void){};
		virtual void run();
		bool split(string , string &, vector<string>, vector<string> &, map<string, bool> &);
		bool get1stword(string input, vector<string> dict_vec, string &output, map<string, bool> &used);
		bool isWord(string str, vector<string> dict_vec);
		void dump_sentences(vector<string> sentences);

	protected:
		string tc_name;
		
};

