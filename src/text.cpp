#include "text.hpp"

using namespace std;

void Text::fillHash(wchar_t * buffer, vector<wstring> &stopWords){
  
  wstring word;
  while(*buffer){
    
    switch(*buffer){
      // Caso se encontre um caracter de terminação
      case L' ': case L'!': case L'?': case L'.': case L'\n': 
      case L',': case L'(': case L')': case L';': case L'/': 
      case L':': case L'—': case L'"': case L'\'':

        if(!word.empty()){
          // Aplica a função tolower em cada caracter da palavra usando uma lambda function
          transform(word.begin(), word.end(), word.begin(),
            [](wchar_t c){ return std::tolower(c); });

          // Se a palavra não é stopword, soma na frequência
          if(find(stopWords.begin(),stopWords.end(),word) == stopWords.end()){
            this->hash[word]++;
          }

          word.clear();
        }
        break;

      default:
        // Não adiciona somente o '-' como palavra, mas deixa palavras compostas como abaixo-assinado
        if(*buffer == '-' && word.size() == 0){
          break;
        }
        // Adiciona caracteres na palavra
        word += *buffer;
        break;
    }

    // Progride no buffer
    buffer++;
  }
}

void Text::fillHeap(vector<wstring> searchWords){

  for(auto &word : searchWords){
    if(this->hash.find(word) != this->hash.end()){
      this->used = true;
      break;
    }
  }

  // Não cria o heap se caso o texto não contém nenhum das palavras que se deseja pesquisar
  if(!this->used)
    return;
  
  for(auto &pair : this->hash){
    // Adiciona palavras no heap até atingir o valor de k
    if(this->heap.size() < this->k){
      // somente adiciona no heap palavras diferente das que se quer pesquisar
      if(find(searchWords.begin(),searchWords.end(),pair.first) != searchWords.end()){
        this->heap.push_back(Word(pair.first,pair.second));
      }

      // Chama o heapfy somente quando atingir k
      if(this->heap.size() == this->k)
        make_heap(this->heap.begin(), this->heap.end());
    }
    else if(this->heap.size() == this->k){
      // Se a palavra na hash tem a frequencia maior que o ultimo do heap, realiza a troca
      if(pair.second > this->heap[0].getFrequence()){
        this->updateHeap(pair);
      }
    }
  }

  return true;
}

void Text::updateHeap(pair<wstring,int> w){
  pop_heap(this->heap.begin(), this->heap.end());

  // Remove ultimo membro do vetor
  this->heap.pop_back();
  // Adiciona a palavra com a maior frequência
  this->heap.push_back(Word(w.first, w.second));

  // Faz o heap novamente
  push_heap(this->heap.begin(), this->heap.end());
}

bool Text::has(wstring word){
  return this->hash.find(word) != this->hash.end();
}

void Text::fillTrees(){
  // insere nas árvores
  for(auto &Word : this->heap){
    this->bst.insert(Word);
    //this->avl.insert(Word);
    //this->huffman.insert(Word);
  }
}

void Text::print(wstring word, ofstream &output){
  this->bst.print(output);
  //this->avl.print(output);
  //this->huffman.print(output);
}