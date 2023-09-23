#include "avlTree.hpp"

AVLTree::AVLTree() {}

AVLTree::~AVLTree() {
    delete this->left;
    delete this->right;
}

void AVLTree::insert(AVLTree **t, const pair<wstring, int> &word) {
  if (*t == nullptr) {
    *t = new AVLTree;
    (*t)->left = nullptr;
    (*t)->right = nullptr;
    (*t)->weight = 0;
    (*t)->data = word;
  } else {
    if (word.second <= (*t)->data.second) {
      insert(&(*t)->left, word);
      if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2) {
        if (word.second <= (*t)->left->data.second)
          rotacaoSimplesDireita(t);
        else
          rotacaoDuplaDireita(t);
      }
    }

    else {
      insert(&(*t)->right, word);
      if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2) {
        if (word.second > (*t)->right->data.second)
          rotacaoSimplesEsquerda(t);
        else
          rotacaoDuplaEsquerda(t);
      }
    }
  }
  (*t)->weight =
      getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

int AVLTree::getWeight(AVLTree **t) {
  if (*t == nullptr)
    return -1;
  return (*t)->weight;
}

int AVLTree::getMaxWeight(int left, int right) {
  if (left > right)
    return left;
  return right;
}

void AVLTree::rotacaoSimplesDireita(AVLTree **t) {
  AVLTree *aux;
  aux = (*t)->left;
  (*t)->left = aux->right;
  aux->right = (*t);
  (*t)->weight =
      getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
  aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
  (*t) = aux;
}

void AVLTree::rotacaoSimplesEsquerda(AVLTree **t) {
  AVLTree *aux;
  aux = (*t)->right;
  (*t)->right = aux->left;
  aux->left = (*t);
  (*t)->weight =
      getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
  aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
  (*t) = aux;
}

void AVLTree::rotacaoDuplaDireita(AVLTree **t) {
  rotacaoSimplesEsquerda(&(*t)->left);
  rotacaoSimplesDireita(t);
}

void AVLTree::rotacaoDuplaEsquerda(AVLTree **t) {
  rotacaoSimplesDireita(&(*t)->right);
  rotacaoSimplesEsquerda(t);
}

void AVLTree::printPosOrdem(AVLTree *t, ofstream &outputFile) {
  if (!(t == nullptr)) {
    printPosOrdem(t->left, outputFile);
    printPosOrdem(t->right, outputFile);
    outputFile << this->converter.to_bytes(this->data.first) << " : " << this->data.second << " | ";
  }
}

void AVLTree::printPreOrdem(AVLTree *t, ofstream &outputFile) {
  if (!(t == nullptr)) {
    outputFile << this->converter.to_bytes(this->data.first) << " : " << this->data.second << " | ";
    printPreOrdem(t->left, outputFile);
    printPreOrdem(t->right, outputFile);
  }
}

void AVLTree::printInOrdem(AVLTree *t, ofstream &outputFile) {
  if (!(t == nullptr)) {
    printInOrdem(t->left, outputFile);
    outputFile << this->converter.to_bytes(this->data.first) << " : " << this->data.second << " | ";
    printInOrdem(t->right, outputFile);
  }
}

void AVLTree::print(AVLTree *t, ofstream &outputFile) {
  outputFile << "\nAVL Tree (Pós-Ordem):\n";
  printPosOrdem(t, outputFile);

  outputFile << "\nAVL Tree (Pré-Ordem):\n";
  printPreOrdem(t, outputFile);

  outputFile << "\nAVL Tree (In-Ordem):\n";
  printInOrdem(t, outputFile);
}