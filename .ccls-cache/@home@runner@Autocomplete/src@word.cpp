#include "word.hpp"

wstring Word::getContent(){
  return this->content;
}
int Word::getFrequence(){
  return this->frequence;
}

Word::Word(wstring content, int frequence){
  this->content = content;
  this->frequence = frequence;
}

bool Word::operator <(const Word &w){
  return frequence > w.frequence;
}