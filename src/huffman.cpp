#include "huffman.hpp"

void HuffmanTree::create(HuffmanTree *&t,
                                    vector<Word> &data) {
  priority_queue<HuffmanTree *, vector<HuffmanTree *>, comp> pq;

  for (auto &word : data) {
    HuffmanTree *aux = new HuffmanTree;

    Word data;

    data.setFrequence(word.getFrequence());
    data.setContent(word.getContent());
aux->prob = word.getFrequence();
    aux->data = data;

    aux->left = nullptr;
    aux->right = nullptr;

    pq.push(aux);
  }

  while (pq.size() > 1) {
    HuffmanTree *left = pq.top();
    pq.pop();

    HuffmanTree *right = pq.top();
    pq.pop();

    HuffmanTree *aux = new HuffmanTree;

    aux->prob = left->prob + right->prob;
    aux->left = left;
    aux->right = right;

    pq.push(aux);
  }

  t = pq.top();
}

HuffmanTree::~HuffmanTree() {
  delete this->left;
  delete this->right;
}

void HuffmanTree::printPosOrdem(HuffmanTree *t, ofstream &outputFile,
                                           string code) {
  if (t == nullptr) {
    return;
  }

  printPosOrdem(t->left, outputFile, code + "0");
  printPosOrdem(t->right, outputFile, code + "1");

  if (!t->data.getContent().empty()) {
    outputFile << this->converter.to_bytes(t->data.getContent()) << " : " << t->data.getFrequence()
               << " : " << code << " | " << endl;
  }
}

void HuffmanTree::printPreOrdem(HuffmanTree *t, ofstream &outputFile,
                                           string code) {
  if (t == nullptr) {
    return;
  }

  if (!t->data.getContent().empty()) {
    outputFile << this->converter.to_bytes(t->data.getContent()) << " : " << t->data.getFrequence()
               << " : " << code << " | " << endl;
  }

  printPreOrdem(t->left, outputFile, code + "0");
  printPreOrdem(t->right, outputFile, code + "1");
}

void HuffmanTree::printInOrdem(HuffmanTree *t, ofstream &outputFile,
                                          string code) {
  wstring_convert<codecvt_utf8<wchar_t>> converter;

  if (t == nullptr) {
    return;
  }

  printInOrdem(t->left, outputFile, code + "0");

  if (!t->data.getContent().empty()) {
    outputFile << this->converter.to_bytes(t->data.getContent()) << " : " << t->data.getFrequence()
               << " : " << code << " | " << endl;
  }

  printInOrdem(t->right, outputFile, code + "1");
}

void HuffmanTree::print(HuffmanTree *t, ofstream &outputFile) {
  outputFile << "\nHuffman Tree (Pós-Ordem):\n";
  printPosOrdem(t, outputFile, "");

  outputFile << "\nHuffman Tree (Pré-Ordem):\n";
  printPreOrdem(t, outputFile, "");

  outputFile << "\nHuffman Tree (In-Ordem):\n\n";
  printInOrdem(t, outputFile, "");
}
