#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define endl "\n"

// matriz A 10X10
vector<vector<double>> A = {{4, -1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {-1, 4, -1, 0, 0, 0, 0, 0, 0, 0},
                            {0, -1, 4, -1, 0, 0, 0, 0, 0, 0},
                            {0, 0, -1, 4, -1, 0, 0, 0, 0, 0},
                            {0, 0, 0, -1, 4, -1, 0, 0, 0, 0},
                            {0, 0, 0, 0, -1, 4, -1, 0, 0, 0},
                            {0, 0, 0, 0, 0, -1, 4, -1, 0, 0},
                            {0, 0, 0, 0, 0, 0, -1, 4, -1, 0},
                            {0, 0, 0, 0, 0, 0, 0, -1, 4, -1},
                            {0, 0, 0, 0, 0, 0, 0, 0, -1, 4}};

// matriz b 1X10
vector<double> b = {-110, -30, -40, -110, 0, -15, -90, -25, -55, -65};

// Matrizes L e U inicialmente preenchidas com zeros
vector<vector<double>> L(10, vector<double>(10, 0));
vector<vector<double>> U(10, vector<double>(10, 0));

const int n=10;


//---------------------------------------------------------------
// regra de  cramer
double determinante(vector<vector<double>> mt){
    double det = 1.0;
    for(int i = 0; i < n; i++){
        int pivot = i;
        for(int j = i + 1; j < n; j++){
            if(fabs(mt[j][i]) > fabs(mt[pivot][i])){
                pivot = j;
            }
        }
        if(fabs(mt[pivot][i]) < 1e-9) return 0;
        swap(mt[i], mt[pivot]);
        if (i != pivot) det = -det;
        det *= mt[i][i];
        for(int j = i + 1; j < n; j++){
            mt[i][j] /= mt[i][i];
        }
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                mt[j][k] -= mt[j][i] * mt[i][k];
            }
        }
    }
    return det;
}

vector<vector<double>> troca(int col){
    vector<vector<double>> mt = A;
    for(int i = 0; i < n; i++){
        mt[i][col] = b[i];
    }
    return mt;
}
//---------------------------------------------------------------
// fatoracao LU
// Função para decomposição LU (A = LU)
void LU(){
    for(int i = 0; i < n; i++){
        // Preenchendo a matriz U
        for(int j = i; j < n; j++){
            double sum = 0.0;
            for(int k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        // Preenchendo a matriz L
        for(int j = i; j < n; j++){
            if(i == j)
                L[i][i] = 1;  // Diagonal principal da L é 1
            else{
                double sum = 0.0;
                for(int k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

vector<double> forwardSubstitution(){
    vector<double> y(n);
    for(int i = 0; i < n; i++){
        double sum = 0.0;
        for(int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = (b[i] - sum);
    }
    return y;
}

vector<double> backSubstitution(vector<double>& y){
    vector<double> k(n);
    for(int i = n - 1; i >= 0; i--){
        double sum = 0.0;
        for(int j = i + 1; j < n; j++)
            sum += U[i][j] * k[j];
        k[i] = (y[i] - sum) / U[i][i];
    }
    return k;
}
//---------------------------------------------------------------

int main(){

auto start_cramer = high_resolution_clock::now();
    cout<<"Regra de Cramer:"<<endl;
    vector<vector<double>> mt = A;
    double detA = determinante(mt);
    vector<double> x(10);
    for(int i = 0; i < 10; i++){
        vector<vector<double>> Ai = troca(i);
        x[i] = determinante(Ai) / detA;
    }

    cout << "Solucao do sistema:" << endl;
    for(int i = 0; i < 10; i++){
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
auto end_cramer = high_resolution_clock::now();
    duration<double> tempo_cramer = end_cramer - start_cramer;
    cout << "Tempo de execucao (Regra de Cramer): " << tempo_cramer.count() << " segundos" << endl;
    cout<<"---------------------------------------------------"<<endl;
auto start_LU = high_resolution_clock::now();

    cout<<"Fatoracao LU:"<<endl;
    // Fatoração LU
    LU();
    // Resolução de Ly = b
    auto y = forwardSubstitution();
    // Resolução de Ux = y
    auto xx = backSubstitution(y);

    cout << "Solucao do sistema:" << endl;
    for(int i = 0; i < n; i++){
        cout << "x[" << i + 1 << "] = " << xx[i] << endl;
    }
auto end_LU = high_resolution_clock::now();
    duration<double> tempo_LU = end_LU - start_LU;
    cout << "Tempo de execucao (Fatoracao LU): " << tempo_LU.count() << " segundos" << endl;
}
