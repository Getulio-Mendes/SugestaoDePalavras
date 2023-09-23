#include <string>

#ifndef WORD_HPP
#define WORD_HPP

using namespace std;

class Word {
  private:
    wstring content;
    int frequence;

  public:
    Word(wstring content, int frequence);
    wstring getContent();
    int getFrequence();
    bool operator <(const Word &w);
};

#endif  