#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <utility>
#include <iostream>
#include <fstream>
#include <queue>

#include "word.hpp"

using namespace std;

class HuffmanTree{
  private:
    Word data;
    int prob;
    HuffmanTree* left;
    HuffmanTree* right;
    wstring_convert<codecvt_utf8<wchar_t>> converter;

    struct comp{
      constexpr bool operator()(HuffmanTree* const& a, HuffmanTree* const& b) const noexcept{
        return a->prob >= b->prob;
      }
    };

  public:

    ~HuffmanTree();
    void create(HuffmanTree*& t, vector<Word>& data);
    void printPosOrdem(HuffmanTree* t, ofstream& outputFile, string code);
    void printPreOrdem(HuffmanTree* t, ofstream& outputFile, string code);
    void printInOrdem(HuffmanTree* t, ofstream& outputFile, string code);
    void print(HuffmanTree* t, ofstream& outputFile);
    void destroy(HuffmanTree* t);
};

#endif