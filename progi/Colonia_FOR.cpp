#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int NUM_CIDADES = 5;
const int NUM_FORMIGAS = 10;
const int MAX_ITERAÇÕES = 100;
const double ALFA = 1.0;
const double BETA = 5.0;
const double EVAPORACAO = 0.5;
const double Q = 100.0;

struct Cidade {
    double x, y;
};

double distancia(const Cidade& a, const Cidade& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void inicializarFeromonio(vector<vector<double>>& feromonio) {
    for (int i = 0; i < NUM_CIDADES; ++i) {
        for (int j = 0; j < NUM_CIDADES; ++j) {
            feromonio[i][j] = 1.0;
        }
    }
}

int selecionarProximaCidade(int cidadeAtual, const vector<bool>& visitadas, const vector<vector<double>>& feromonio, const vector<vector<double>>& distancias) {
    vector<double> probabilidades(NUM_CIDADES, 0.0);
    double soma = 0.0;
    
    for (int i = 0; i < NUM_CIDADES; ++i) {
        if (!visitadas[i]) {
            probabilidades[i] = pow(feromonio[cidadeAtual][i], ALFA) * pow(1.0 / distancias[cidadeAtual][i], BETA);
            soma += probabilidades[i];
        }
    }

    double limite = ((double)rand() / RAND_MAX) * soma;
    double acumulado = 0.0;

    for (int i = 0; i < NUM_CIDADES; ++i) {
        if (!visitadas[i]) {
            acumulado += probabilidades[i];
            if (acumulado >= limite) {
                return i;
            }
        }
    }
    
    return -1;
}

double calcularCusto(const vector<int>& caminho, const vector<vector<double>>& distancias) {
    double custo = 0.0;
    for (int i = 0; i < NUM_CIDADES - 1; ++i) {
        custo += distancias[caminho[i]][caminho[i + 1]];
    }
    custo += distancias[caminho[NUM_CIDADES - 1]][caminho[0]];
    return custo;
}

void atualizarFeromonio(vector<vector<double>>& feromonio, const vector<vector<int>>& caminhos, const vector<double>& custos) {
    for (int i = 0; i < NUM_CIDADES; ++i) {
        for (int j = 0; j < NUM_CIDADES; ++j) {
            feromonio[i][j] *= (1.0 - EVAPORACAO);
        }
    }

    for (int k = 0; k < NUM_FORMIGAS; ++k) {
        double deposito = Q / custos[k];
        for (int i = 0; i < NUM_CIDADES - 1; ++i) {
            feromonio[caminhos[k][i]][caminhos[k][i + 1]] += deposito;
            feromonio[caminhos[k][i + 1]][caminhos[k][i]] += deposito;
        }
        feromonio[caminhos[k][NUM_CIDADES - 1]][caminhos[k][0]] += deposito;
        feromonio[caminhos[k][0]][caminhos[k][NUM_CIDADES - 1]] += deposito;
    }
}

int main() {
    srand(time(0));

    vector<Cidade> cidades(NUM_CIDADES);
    cidades[0] = {0.0, 0.0};
    cidades[1] = {1.0, 0.0};
    cidades[2] = {1.0, 1.0};
    cidades[3] = {0.0, 1.0};
    cidades[4] = {0.5, 0.5};

    vector<vector<double>> distancias(NUM_CIDADES, vector<double>(NUM_CIDADES, 0.0));
    for (int i = 0; i < NUM_CIDADES; ++i) {
        for (int j = 0; j < NUM_CIDADES; ++j) {
            distancias[i][j] = distancia(cidades[i], cidades[j]);
        }
    }

    vector<vector<double>> feromonio(NUM_CIDADES, vector<double>(NUM_CIDADES, 1.0));
    inicializarFeromonio(feromonio);

    vector<int> melhorCaminho;
    double menorCusto = numeric_limits<double>::infinity();

    for (int iter = 0; iter < MAX_ITERAÇÕES; ++iter) {
        vector<vector<int>> caminhos(NUM_FORMIGAS, vector<int>(NUM_CIDADES, -1));
        vector<double> custos(NUM_FORMIGAS, 0.0);

        for (int k = 0; k < NUM_FORMIGAS; ++k) {
            vector<bool> visitadas(NUM_CIDADES, false);
            int cidadeAtual = rand() % NUM_CIDADES;
            caminhos[k][0] = cidadeAtual;
            visitadas[cidadeAtual] = true;

            for (int passo = 1; passo < NUM_CIDADES; ++passo) {
                int proximaCidade = selecionarProximaCidade(cidadeAtual, visitadas, feromonio, distancias);
                caminhos[k][passo] = proximaCidade;
                visitadas[proximaCidade] = true;
                cidadeAtual = proximaCidade;
            }

            custos[k] = calcularCusto(caminhos[k], distancias);
            if (custos[k] < menorCusto) {
                menorCusto = custos[k];
                melhorCaminho = caminhos[k];
            }
        }

        atualizarFeromonio(feromonio, caminhos, custos);
        cout << "Iteração " << iter + 1 << " - Melhor custo: " << menorCusto << endl;
    }

    cout << "Melhor caminho: ";
    for (int i = 0; i < NUM_CIDADES; ++i) {
        cout << melhorCaminho[i] << " ";
    }
    cout << endl;

    cout << "Menor custo: " << menorCusto << endl;

    return 0;
}
