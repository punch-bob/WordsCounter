#include <string>
#include <list>
#include <iostream>
#include <map>

class text_manipulation
{
public:
	void ReadFile(std::string);
	void DivisionIntoWords(std::string);
	void SortWords();
	void WriteCSV();
private:
	std::map <std::string, int> vocabulary;
	std::list <std::string> words_freq;
	void FillList();
	bool WordCMP(std::string, std::string);
	int words_counter;
};