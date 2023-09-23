#ifndef TEXT_HPP
#define TEXT_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "word.hpp"
#include "utils.hpp"
#include "binaryTree.hpp"

using namespace std;

class Text{
  private:
    // Número de elementos no heap
    static const int k = 20;
    BinaryTree bst;
    vector<Word> heap;
    unordered_map <wstring, int> hash; 

  public:
    bool used;
    void fillHash(wchar_t * buffer, vector<wstring> &stopWords);
    void fillHeap(vector<wstring> searchWords);
    void updateHeap(pair<wstring,int> w);
    void fillTrees();
    bool has(wstring word);
    void print(wstring word, ofstream &output);
};

#endif