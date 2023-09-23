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

void Text::fillHeap(){
  
  for(auto &pair : this->hash){
      // Adiciona palavras no heap até atingir o valor de k
      if(this->heap.size() < this->k){
        this->heap.push_back(Word(pair.first,pair.second));

        // Chama o heapfy somente quando atingir k
        if(this->heap.size() == this->k)
          make_heap(this->heap.begin(), this->heap.end());
      }
      else if(this->heap.size() == this->k){
        // Se a palavra na hash tem a frequencia maior que o ultimo do heap, realiza a troca
        if(pair.second > this->heap[0].getFrequence()){
          updateHeap(pair,this->heap);
        }
      }
  }
  
}