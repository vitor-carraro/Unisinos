#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Digite o tamanho da matriz quadrada (n x n): ";
    cin >> n;

    // Declaração da matriz
    vector<vector<int>> matriz(n, vector<int>(n));

    // Leitura da matriz
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Impressão da matriz original (opcional)
    cout << "Matriz digitada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Pegando os elementos acima da diagonal principal
    cout << "Elementos acima da diagonal principal:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Apenas elementos onde j > i
            cout << matriz[i][j] << " ";
        }
    }
    cout << endl;

    // Pegando os elementos acima da diagonal secundária
    cout << "Elementos acima da diagonal secundária:" << endl;
    for (int i = 0; i < n - 1; i++) { // Itera até a penúltima linha
        for (int j = 0; j < n - i - 1; j++) { // Condição para estar acima da diagonal secundária
            cout << matriz[i][j] << " ";
        }
    }
    cout << endl;


    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Digite o tamanho da matriz quadrada (n x n): ";
    cin >> n;

    // Declaração e leitura da matriz
    int matriz[n][n];
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Elementos acima das duas diagonais
    cout << "Elementos acima de ambas as diagonais:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && i + j < n - 1) { // Condição para estar acima das duas diagonais
                cout << matriz[i][j] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}



