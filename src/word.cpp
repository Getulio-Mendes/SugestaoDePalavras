#include "word.hpp"

wstring Word::getContent(){
  return this->content;
}
int Word::getFrequence(){
  return this->frequence;
}
void Word::setContent(wstring content){
  this->content = content;
}
void Word::setFrequence(int frequence){
  this->frequence = frequence;
}

Word::Word(wstring content, int frequence){
  this->content = content;
  this->frequence = frequence;
}
Word::Word(){}

bool Word::operator <(const Word &w){
  return frequence > w.frequence;
}