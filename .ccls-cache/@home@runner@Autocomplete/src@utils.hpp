#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <algorithm>
#include "word.hpp"

using namespace std;

class FileReader {

  public:
    wchar_t* getFileBuffer(locale loc, string name, streampos &size, wchar_t * &buffer);
    vector<wstring> getStopWords(locale loc);
    vector<wstring> getSearchWords(locale loc);
    int getFileNumber();
    string getFileName(int x);
};

streampos getSize(wifstream &stream);

#endif