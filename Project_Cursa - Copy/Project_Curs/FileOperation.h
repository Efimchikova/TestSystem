#pragma once

#include "Question.h";
#include "Decoder.h"
#include "Variable.h"
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
class FileOperation
{
public:
	static std::vector<Question> loadQuestion(string filename)
	{
		
		int id = 0;
		std::vector<Question> Questions;
		std::ifstream file;
		file.open(filename);
		if (!file.is_open())
			throw new exception("can't open file from FileOperation::loadQuestion");
		while (!file.eof())
		{
			Question tmp;
			string str;
			vector<string> arr;
			char buf[1500];
			file.getline(buf, 1500);

			tmp.setQuestion(std::string(buf));
			tmp.setId(id);

			while ((str != string("&")))
			{
				file.getline(buf, 1500);
				if (string(buf) == "&")
					break;
				arr.push_back(buf);
				
			}
			tmp.setAnsewrs(arr);
			Questions.push_back(tmp);
			id++;
		}

		return Questions;
		
	}

	static set<Variable> loadVariables(string filename)
	{
		std::ifstream file;
		file.open(filename);
		if (!file.is_open())
			throw new exception("can't open file from FileOperation::loadVariables");
		
		
		set<Variable> Set;
		char buf[150];
		while (!file.eof())
		{
			file.getline(buf, 150);
			Variable b;
			
			b.name = string(buf);
			
			string tmp = "";
			while (string(buf) != "&")
			{
				file.getline(buf, 150);
				if (string(buf) == "&")
					break;
				tmp += buf;
			}
			b.output_text = tmp;
			
			Set.insert(b);
		}
		return Set;
	}
	static Variable computeResult(string fileAnswer,Decoder* decoder,
		int key, map<int, char> UserAnswers, set<Variable> variables)
	{
		std::string str = decoder->Decode(fileAnswer, key);
		std::string tmpStr = "";
		std::string typeTest = "";
		int trueAns = 0;
		int allQuestion = 0;

		int pointer = 0;
		for (; pointer < str.size() && str[pointer] != '\n'; pointer++)
		{
		
			typeTest += str[pointer];
		}
				
		
		for (auto it=UserAnswers.begin();pointer < str.size();it++)
		{
			int id = it->first;
			int chosenAns = it->second;
			for (char j = 'A';pointer < str.size(); j++)
			{

				tmpStr.clear();
				for (;pointer < str.size() && str[ pointer] != '\n'; pointer++)
				{
					tmpStr += str[pointer];
				}
				pointer++;
				if (tmpStr == "~")
				{
					allQuestion++;
					break;
				}
				if (j == chosenAns)
				{
					if (tmpStr != "&")
					{
						auto it = std::find_if(variables.begin(), variables.end(), [&](Variable v)
						{
							return v.name == tmpStr;
						});
						if (it != variables.end())
						{
							Variable *v = (Variable*)&(it.operator*());
							v->count++;
							if ( it->name == "True")
							trueAns++;
						}
					}
				}
			}
		}
		Variable itMax = variables.begin().operator*();
		for (auto it = variables.begin(); it != variables.end();it++)
		{
			if (it->count > itMax.count)
				itMax = *it;
		}
		if (typeTest == "point")
		{
			char buf[50];
			std::string out = "Your answered : ";
			out += itoa(trueAns, buf, 10);
			out += " \\ ";
			out += itoa(allQuestion, buf, 10);
			return Variable("True", out);
		}
		return itMax;
	}
	//static 
};