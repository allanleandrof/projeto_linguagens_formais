#ifndef EXPRESSAOREGULAR_H
#define EXPRESSAOREGULAR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include "automato.h"

using namespace std;

class expressaoRegular {
private:
    vector<string> alfabeto;
    string expressao;
    int estadoId = 0;  // Para gerar novos estados incrementalmente

    // Função auxiliar para criar um novo estado
    string novoEstado();

    // Função auxiliar para criar um AFN básico para um símbolo
    automato afnBasico(char simbolo);

    // Implementação da união (A | B)
    automato unir(const automato& afn1, const automato& afn2);

    // Implementação da concatenação (AB)
    automato concatenar(const automato& afn1, const automato& afn2);

    // Implementação do fechamento de Kleene (A*)
    automato fecharKleene(const automato& afn);

public:
    expressaoRegular();  // Construtor
    
    // Getters e Setters
    vector<string> getAlfabeto() const;
    void setAlfabeto(const vector<string>& novoAlfabeto);

    string getExpressao() const;
    void setExpressao(const string& novaExpressao);

    // Funções principais
    void carregarER(const string& arquivo);  // Função para carregar a expressão regular
    void exibir() const;  // Função para exibir a expressão regular
    void converterAFDparaER(const automato& afd);  // Função para converter AFD para ER
    void simplificaExpressao();  // Função para converter AFD para ER
    automato converterERparaAFN(); // Função para converter ER para AFN
};

#endif
