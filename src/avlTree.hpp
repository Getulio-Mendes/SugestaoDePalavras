#include <bits/stdc++.h>

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

using namespace std;

class AVLTree{
  private:
    pair<wstring, int> data;
    AVLTree* left;
    AVLTree* right;
    int weight;

  public:
    AVLTree();
    ~AVLTree();

    void insert(AVLTree **t, const pair<wstring, int>& word);

    int getWeight(AVLTree **t);
    int getMaxWeight(int left, int right);

    void rotacaoSimplesDireita(AVLTree **t);
    void rotacaoSimplesEsquerda(AVLTree **t);
    void rotacaoDuplaDireita(AVLTree **t);
    void rotacaoDuplaEsquerda(AVLTree **t);

    void printPosOrdem(AVLTree *t, ofstream& outputFile);
    void printPreOrdem(AVLTree *t, ofstream& outputFile);
    void printInOrdem(AVLTree *t, ofstream& outputFile);
    void print(AVLTree *t, ofstream& outputFile);
    wstring_convert<codecvt_utf8<wchar_t>> converter;
};

#endif