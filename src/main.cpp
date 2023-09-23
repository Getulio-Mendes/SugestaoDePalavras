#include <iostream>
#include <codecvt>
#include <locale>
#include <algorithm>
#include <vector>
#include <chrono>
#include <unordered_map>

#include "word.hpp"
#include "utils.hpp"
#include "text.hpp"

using namespace std;

int main() {
  // expecifica o locale a ser utilizado assim como a codificação do unicode
  setlocale(LC_ALL, "pt_BR.UTF-8");
  // inicializa o locale com o método de conversão utf-8
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  FileReader fr;
  // vetor de texts inicializado com o número correto de textos
  vector<Text> texts(fr.getFileNumber());
  vector<wstring> stopWords = fr.getStopWords(loc);
  vector<wstring> searchWords = fr.getSearchWords(loc);
  
  auto startTime = chrono::high_resolution_clock::now();
  
  cout << "Os textos a serem lidos são nomeados na forma \"text{n}.data\", onde n é seu número a partir de 1" << endl;

  for(auto &text : texts){
    // Lê o arquivo para a memória (getFile recebe o index da interação)
    wchar_t *buffer = fr.getFileBuffer(loc,fr.getFileName(&text - &texts[0] + 1));

    // preenche a hash do texto
    text.fillHash(buffer,stopWords);
  }
  

  // forma o heap de k elementos na hash de cada arquivo
  for(auto &text: texts){
    text.fillHeap(searchWords);

    // evita o processamento de textos que não contém nenhuma palavra a ser pesquisada
    if(!text.used)
      continue;

    // cria as árvores beando-se no heap
    text.fillTrees();
  }

  ofstream output("dataset/output.txt", ios::binary); 

  wstring_convert<codecvt_utf8<wchar_t>> converter;
  
  for(auto &word : searchWords){

    output << "\t\t\t\t\t----------" << converter.to_bytes(word) << "-------------\n\n" << endl;
    
    for(auto &text : texts){
      output << "\t\t\t" << fr.getFileName(&text - &texts[0]+1) << ":\n" << endl;
      
      // Ignora palavras não present no texto
      if(text.has(word))
        text.print(output);
      else
        output << "Palavra não está no texto" << endl;
    }   
  }
  
  auto finalTime = chrono::high_resolution_clock::now();
  // Calcula e printa o tempo gasto
  auto duration = chrono::duration_cast<chrono::milliseconds>(finalTime - startTime);
  wcout << duration.count() << " ms" << endl;
  
  return 0;
  }
