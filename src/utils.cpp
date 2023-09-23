#include "utils.hpp"

using namespace std;

streampos getSize(wifstream &stream){
  // Obtém o tamanho do arquivo
  stream.seekg(0, ios::end);

  streampos size = stream.tellg();
      
  stream.seekg(0, ios::beg);

  return size;
}

string FileReader::getFileName(int x){
  return "./dataset/text" + to_string(x) + ".data";
}

int FileReader::getFileNumber(){

  int i = 0;
  while(1){
    
    wifstream stream(this->getFileName(i+1), ios::binary);

    if(stream.is_open()){
      i++;
    }
    else{
      return i;
    }
  }
}

wchar_t* FileReader::getFileBuffer(locale loc, string name, streampos &size, wchar_t * &buffer){
  
  wifstream stream(name, ios::binary);

  if(!stream.is_open()){
    cerr << "Não foi possível ler o arquivo" << endl;
    exit(1);
  }

  // Seta o locale português UTF-8 para o arquivo
  stream.imbue(loc);

  streampos newSize = getSize(stream);
  if(newSize > size){
    // Cria um buffer do tamanho do arquivo
    delete[] buffer;
    buffer = new wchar_t[size];
  }

  // Joga todo o arquivo para o buffer
  stream.read(buffer,size);

  stream.close();

  return buffer;
}

vector<wstring> FileReader::getStopWords(locale loc){
  vector<wstring> stopwords;
  
  wifstream stream("dataset/stopwords.txt");

  if(!stream.is_open()){
    cerr << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }

  stream.imbue(loc);

  // Consome todas as palavras e as colocas no vetor
  wstring word;
  while (stream >> word){
    stopwords.push_back(word);
  }
  stream.close();

  return stopwords;
}

vector<wstring> FileReader::getSearchWords(locale loc){
  vector<wstring> searchWords;
  
  wifstream stream("dataset/input.txt");

  if(!stream.is_open()){
    cerr << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }
  stream.imbue(loc);

  // Consome todas as palavras e as colocas no vetor
  wstring word;
  while (stream >> word){
    searchWords.push_back(word);
  }
  stream.close();

  return searchWords;
}