#include <iostream>
#include <vector>
using namespace std;

// Função para converter decimal para binário
vector<int> decimalParaBinario(int decimal) {
    vector<int> binario;
    while (decimal > 0) {
        binario.push_back(decimal % 2);
        decimal /= 2;
    }
    return binario;
}

int main() {
    const int NUM_BITS = 3; //número de bits desejado 
    const int NUM_ADICOES = 10;

    int custoTotal = 0;

    for (int i = 0; i < NUM_ADICOES; ++i) {
        //qualquer número decimal (por exemplo, 101)
        int numeroDecimal; //número decimal aqui 
        cin >> numeroDecimal;

        //converte decimal pra binario
        vector<int> numeroBinario = decimalParaBinario(numeroDecimal);

        //calcula custo dessa adição
        int custoAdicao = 0;
        for (int digito : numeroBinario) {
            if (digito == 1) {
                custoAdicao++;
            }
        }

        cout << "Numero decimal: " << numeroDecimal << " (binario: ";
        for (int digito : numeroBinario) {
            cout << digito;
        }
        cout << "), Custo da adio: " << custoAdicao << endl;

        custoTotal += custoAdicao;
    }

    //calcula custo amortizado
    double custoAmortizado = static_cast<double>(custoTotal) / NUM_ADICOES;
    cout << "Custo amortizado: " << custoAmortizado << endl;

    return 0;
}
