#pragma once
#include <iostream>
#include <string>
class Variable
{
public:
	Variable()
	{
		count = 0;
	}
	Variable(std::string name, std::string out) 
	{
		this->name = name;
		this->output_text = out;
		count = 0;
	}
	bool operator<(const Variable& t)const
	{
		return this->name < t.name;
	}

	std::string name;
	int count;
	std::string output_text;


};