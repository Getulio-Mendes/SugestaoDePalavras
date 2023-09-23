#include "binaryTree.hpp"

BinaryTree::BinaryTree(){
  this->data.setContent(L"NULL");
  this->data.setFrequence(0);
  this->left = nullptr;
  this->right = nullptr;
}

BinaryTree::~BinaryTree(){
  delete this->left;
  delete this->right;
}

bool BinaryTree::empty(){
  if(this->data.getFrequence() == 0){
    return true;
  }
  else{
    return false;
  }
}

void BinaryTree::insert(Word& word){
  if(this->empty()){
    this->data = word;
  }
  else{
    BinaryTree *aux = this;
    
    while(aux != nullptr){
      if(word.getFrequence() < aux->data.getFrequence()){
        if (aux->left == nullptr){
          aux->left = new BinaryTree;
          aux = aux->left;
          aux->data = word;
        }
        aux = aux->left;
      }
      else{
        if (aux->right == nullptr){
          aux->right = new BinaryTree;
          aux = aux->right;
          aux->data = word;
        }
        aux = aux->right;
      }
    }
  }
}

void BinaryTree::printPosOrdem(ofstream& outputFile){
    if(this->left != nullptr)
      this->left->printPosOrdem(outputFile);
    if(this->right != nullptr)
      this->right->printPosOrdem(outputFile);
    
    outputFile << this->converter.to_bytes(this->data.getContent()) << " : " << this->data.getFrequence() << " | " << endl;
}

void BinaryTree::printPreOrdem(ofstream& outputFile){

    outputFile << this->converter.to_bytes(this->data.getContent()) << " : " << this->data.getFrequence() << " | " << endl;
    
    if(this->left != nullptr)
      this->left->printPreOrdem(outputFile);
    if(this->right != nullptr)
      this->right->printPreOrdem(outputFile);
}

void BinaryTree::printInOrdem(ofstream& outputFile){
    
    if(this->left != nullptr)
    this->left->printInOrdem(outputFile);
    
    outputFile << this->converter.to_bytes(this->data.getContent()) << " : " << this->data.getFrequence() << " | " << endl;
    
    if(this->right != nullptr)
    this->right->printInOrdem(outputFile);
}

void BinaryTree::print(ofstream& outputFile)
{
  
  outputFile << "\nBinary Tree (Pós-Ordem):\n";
  this->printPosOrdem(outputFile);

  outputFile << "\nBinary Tree (Pré-Ordem):\n";
  this->printPreOrdem(outputFile);

  outputFile << "\nBinary Tree (In-Ordem):\n";
  this->printInOrdem(outputFile);
}
