#include <iostream>
#include <vector>
using namespace std;

//função para imprimir a tabela
void imprimirTabela(const vector<vector<int>>& tabela) {
    for (const auto& linha : tabela) {
        for (int valor : linha) {
            cout << valor << "\t";
        }
        cout << endl;
    }
}

int main() {
    const int NUM_INSERCOES = 10;
    vector<vector<int>> tabela; 

    for (int i = 0; i < NUM_INSERCOES; ++i) {
        int novoValor;
        cout << "Insira um valor: ";
        cin >> novoValor;

        //novo valor da tabela
        tabela.push_back({novoValor});

        cout << "Tabela apos a insercao " << i + 1 << ":" << endl;
        imprimirTabela(tabela);

        //calcular o custo desta inserção 
        int custoInsercao = tabela.size();
        cout << "Custo da insercao " << i + 1 << ": " << custoInsercao << endl;
    }

    //calcula o custo amortizado
    double custoAmortizado = static_cast<double>(tabela.size()) / NUM_INSERCOES;
    cout << "Custo amortizado: " << custoAmortizado << endl;

    return 0;
}

