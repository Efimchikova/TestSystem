#pragma once
#include "Question.h"
#include "Variable.h"
#include "FileOperation.h"
#include <set>
#include <map>
#include <algorithm>
#include <vector>
class Test
{
	map<int, char> UserAnswers;
	vector<bool> isGetAnswer;
	vector<Question> question;
	set<Variable> variables;
	std::string locationQuestion;
	std::string locationVariable;
public:
	Test(std::string locationQuestion, std::string locationVariable)
	{
		this->locationQuestion = locationQuestion;
		this->locationVariable = locationVariable;
	}
	bool isGiveAnswer(int idQuestion)
	{
		return this->isGetAnswer[idQuestion];
	}
	void uploadQuestion()
	{
		string filenameQuesiton = this->locationQuestion;
		string filenameResult = this->locationVariable;
		question = FileOperation::loadQuestion(filenameQuesiton);

		variables = FileOperation::loadVariables(filenameResult);
		isGetAnswer.clear();
		for(int i=0;i<question.size();i++)
			isGetAnswer.push_back(false);
		/*UserAnswers[0] = 'A';
		UserAnswers[1] = 'A';
		UserAnswers[2] = 'A';*/
	}
	map<int, char> getUserAnswers(){ return this->UserAnswers; }
	set<Variable> getVariables(){ return this->variables; }
	bool setAnswerToQuestion(int id,char ans)
	{
		if (id >= question.size())
			return false;
		this->isGetAnswer[id]=true;
		UserAnswers[id] = ans;
		return true;
	}
	Question getQuestion(int id)
	{
		if (id >= question.size())
			throw new exception("out of range Test::getQuestion");

		
		return this->question[id];
	}
	
	int getSize(){ return this->question.size(); }
};