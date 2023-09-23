#ifndef TEXT_HPP
#define TEXT_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "word.hpp"
#include "utils.hpp"

using namespace std;

class Text{
  private:
    // Número de elementos no heap
    static const int k = 20;
    vector<Word> heap;
    unordered_map <wstring, int> hash; 

  public:
    void fillHash(wchar_t * buffer, vector<wstring> &stopWords);
    void fillHeap();
};

#endif