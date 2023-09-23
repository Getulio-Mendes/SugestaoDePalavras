#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <fstream>
#include <utility>
#include <codecvt>
#include <locale>

#include "word.hpp"

using namespace std;

class BinaryTree{
  private:
    Word data;
    BinaryTree* left;
    BinaryTree* right;

  public:
    BinaryTree();
    ~BinaryTree();

    void insert(Word& word);
    void printPosOrdem(ofstream& outputFile);
    void printPreOrdem(ofstream& outputFile);
    void printInOrdem(ofstream& outputFile);
    void print(ofstream& outputFile);
    bool empty();
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    
};

#endif