#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Question
{
private:
	string question;
	int id;
	vector<string> answers;
public:
	
	Question()
	{
		question = "";
	}

	string getQuestion()
	{
		return this->question;
	}
	void setQuestion(string quest)
	{
		this->question = quest;
	}

	int getId(){ return this->id; }
	void setId(int id){this->id=id; }

	std::vector<string> getAnswers(){ return this->answers; }
	void setAnsewrs(vector<string> answ)
	{ 
		this->answers = answ; 
	}
};