#include <string>

#ifndef WORD_HPP
#define WORD_HPP

using namespace std;

class Word {
  private:
    wstring content;
    int frequence;

  public:
    Word();
    Word(wstring content, int frequence);
    wstring getContent();
    int getFrequence();
    void setContent(wstring word);
    void setFrequence(int frequence);
    bool operator <(const Word &w);
};

#endif  