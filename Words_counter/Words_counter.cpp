#include <iostream>
#include <list>
#include <map>
#include <string>
#include "text_manipulation.h"


int main()
{
    text_manipulation text;
    std::string file_name;
    std::cout << "File directory: ";
    std::cin >> file_name;
    text.ReadFile(file_name);
    text.SortWords();
    text.WriteCSV();
    std::cout << "Done!" << std::endl;
    return 0;
}