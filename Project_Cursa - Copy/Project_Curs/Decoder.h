#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Decoder
{
public:
	virtual void Encrypt(string filename, string str, int key) = 0;
	virtual void Encrypt_File(string filenameSource, string filenameOutput, int key) = 0;
	virtual string Decode(string filename, int key) = 0;
};
class PrimitiveDecoder:public Decoder
{
public:
	virtual string Decode(string filename, int key)
	{
		ifstream file;
		file.open(filename);


		if (!file.is_open())
			throw new exception("cant open file PrimitiveDecoder::Decode");

		string str = "";
		char ch;
		while ((ch = file.get()) != EOF)
		{
			str += (ch^key);
		}
		file.close();
		return str;
	}
	virtual void Encrypt(string filename, string str, int key)
	{
		ofstream file;
		file.open(filename);


		if (!file.is_open())
			throw new exception("cant open file PrimitiveDecoder::Encrypt");
		for (int i = 0; i < str.size(); i++)
		{
			file << (char)(str[i] ^ key);
		}
	}
	virtual void Encrypt_File(string filenameSource,string filenameOutput, int key)
	{
		ifstream in;
		ofstream out;
		out.open((filenameOutput));
		in.open(filenameSource);
		if ( !in.is_open())
			throw new exception("cant open file PrimitiveDecoder::Encrypt_File");

		char ch;
		while ((ch = in.get()) != EOF)
		{
			out<<(char)(ch^key);
		}
		in.close();
		out.close();
	}
};