#include <bits/stdc++.h>
using namespace std;

void troca(pair<int,string> &a,pair<int,string> &b) {
    pair<int,string>temp = a;
    a = b;
    b = temp;
}

int metadenum(vector<pair<int,string>> &lista, int low, int high) {
    pair<int,string>pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (lista[j].first <= pivot.first) {
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

int metadechar(vector<pair<int,string>> &lista, int low, int high) {
    pair<int,string>pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (lista[j].second <= pivot.second) {
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

void QuickSortNum(vector<pair<int,string>> &lista, int low, int high) {
    if (low < high) {
        int pi = metadenum(lista, low, high);
        QuickSortNum(lista, low, pi - 1);
        QuickSortNum(lista, pi + 1, high);
    }
}

void QuickSortChar(vector<pair<int,string>> &lista, int low, int high){
      if (low < high) {
        int pi = metadechar(lista, low, high);
        QuickSortChar(lista, low, pi - 1);
        QuickSortChar(lista, pi + 1, high);
      }
}