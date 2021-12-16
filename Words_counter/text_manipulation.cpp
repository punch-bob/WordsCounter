#include <fstream>
#include <iostream>
#include <functional>
#include <list>
#include <map>
#include "text_manipulation.h"

void text_manipulation::DivisionIntoWords(std::string line)
{
	int letter = 0, letter_id = 0;
	std::string new_word;
	for (int i = 0; i <= int(line.size()); i++)
	{
		letter = int(tolower(line[i]));
		if ((letter >= 48 && letter <= 57) || (letter >= 97 && letter <= 122))
		{
			new_word.push_back(char(letter));
		}
		else
		{
			if (!new_word.empty())
			{
				this -> vocabulary[new_word]++;
				this -> words_counter++;
				new_word.clear();
			}
		}
	}
}

void text_manipulation::ReadFile(std::string file_name)
{
	std::ifstream input(file_name);
	do
	{
		std::string line;
		std::getline(input, line);
		DivisionIntoWords(line);
	} while (!input.eof());
}

bool text_manipulation::WordCMP(std::string first, std::string second)
{
	return this -> vocabulary[first] > this -> vocabulary[second];
}

void text_manipulation::FillList()
{
	std::map <std::string, int>::iterator iter = this -> vocabulary.begin();
	for (; iter != this->vocabulary.end(); ++iter)
	{
		this  -> words_freq.push_back(iter -> first);
	}
}

void text_manipulation::SortWords()
{
	text_manipulation::FillList();
	this -> words_freq.sort(std::bind(&text_manipulation::WordCMP, this, std::placeholders::_1, std::placeholders::_2));
}

void text_manipulation::WriteCSV()
{
	std::ofstream outcsv;
	outcsv.open("output.csv");
	outcsv << "Words;Count;Frequency" << std::endl;
	std::list<std::string>::iterator i = this -> words_freq.begin();
	for (i; i != this->words_freq.end(); ++i)
	{
		outcsv << (*i) << ";" << this->vocabulary[*i] << ";" << float(this->vocabulary[*i]) / float(this->words_counter) * 100 << "%" << std::endl;
	}
	outcsv.close();
}
