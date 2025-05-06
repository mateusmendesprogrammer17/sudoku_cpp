#include <iostream>
#include <random>
#include <set>
#include <string>
using namespace std;

int sudoku[9][9] = {}; // Inicializa o Sudoku com todas as células vazias (zero)

bool podeInserir(int linha, int coluna, int numero) {
    // Verifica se o número pode ser inserido na linha
    for (int j = 0; j < 9; j++) {
        if (sudoku[linha][j] == numero) {
            return false;  // Número já existe na linha
        }
    }

    // Verifica se o número pode ser inserido na coluna
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][coluna] == numero) {
            return false;  // Número já existe na coluna
        }
    }

    return true;  // Número pode ser inserido
}

void startGame() {
    int linha, coluna, numero;

    while (true) {
        // Imprimir a matriz formatada
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0)
                cout << "------+-------+------\n";

            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0)
                    cout << "| ";
                cout << (sudoku[i][j] ? to_string(sudoku[i][j]) : ".") << " ";
            }
            cout << endl;
        }

        // Verificar se o Sudoku foi completado
        bool completo = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] == 0) {
                    completo = false;  // Há células vazias
                    break;
                }
            }
        }

        if (completo) {
            cout << "Parabéns! Você completou o Sudoku!" << endl;
            break; // Finaliza o jogo
        }

        // Solicitar ao jogador a posição e o número
        cout << "\nInforme a posição (linha e coluna) e o número que deseja inserir: " << endl;
        cout << "Linha (0-8): ";
        cin >> linha;
        cout << "Coluna (0-8): ";
        cin >> coluna;
        cout << "Número (1-9): ";
        cin >> numero;

        // Validar a entrada
        if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8 || numero < 1 || numero > 9) {
            cout << "Entrada inválida! Tente novamente." << endl;
            continue;  // Pede nova entrada
        }

        // Verificar se a posição está vazia e se o número pode ser inserido
        if (sudoku[linha][coluna] != 0) {
            cout << "Essa célula já está preenchida! Escolha outra." << endl;
        }
        else if (podeInserir(linha, coluna, numero)) {
            sudoku[linha][coluna] = numero;  // Inserir o número
            cout << "Número inserido com sucesso!" << endl;
        }
        else {
            cout << "Número não pode ser inserido nesta posição (violaria regras do Sudoku)." << endl;
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 9);   // Valores de 1 a 9
    uniform_int_distribution<> pos(0, 8);    // Índices de 0 a 8

    set<pair<int, int>> usadas;

    // Preencher 15 posições aleatórias únicas
    for (int k = 0; k < 15; ) {
        int i = pos(gen);
        int j = pos(gen);

        if (usadas.count({ i, j }) == 0) {
            sudoku[i][j] = dist(gen);
            usadas.insert({ i, j });
            k++;  // Só incrementa se posição for realmente nova
        }
    }

    // Iniciar o jogo
    startGame();

    return 0;
}
