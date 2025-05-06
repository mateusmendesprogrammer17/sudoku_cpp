#include <iostream>
#include <random>
#include <set>
#include <string>
using namespace std;

int sudoku[9][9] = {}; // Inicializa o Sudoku com todas as c�lulas vazias (zero)

bool podeInserir(int linha, int coluna, int numero) {
    // Verifica se o n�mero pode ser inserido na linha
    for (int j = 0; j < 9; j++) {
        if (sudoku[linha][j] == numero) {
            return false;  // N�mero j� existe na linha
        }
    }

    // Verifica se o n�mero pode ser inserido na coluna
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][coluna] == numero) {
            return false;  // N�mero j� existe na coluna
        }
    }

    return true;  // N�mero pode ser inserido
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
                    completo = false;  // H� c�lulas vazias
                    break;
                }
            }
        }

        if (completo) {
            cout << "Parab�ns! Voc� completou o Sudoku!" << endl;
            break; // Finaliza o jogo
        }

        // Solicitar ao jogador a posi��o e o n�mero
        cout << "\nInforme a posi��o (linha e coluna) e o n�mero que deseja inserir: " << endl;
        cout << "Linha (0-8): ";
        cin >> linha;
        cout << "Coluna (0-8): ";
        cin >> coluna;
        cout << "N�mero (1-9): ";
        cin >> numero;

        // Validar a entrada
        if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8 || numero < 1 || numero > 9) {
            cout << "Entrada inv�lida! Tente novamente." << endl;
            continue;  // Pede nova entrada
        }

        // Verificar se a posi��o est� vazia e se o n�mero pode ser inserido
        if (sudoku[linha][coluna] != 0) {
            cout << "Essa c�lula j� est� preenchida! Escolha outra." << endl;
        }
        else if (podeInserir(linha, coluna, numero)) {
            sudoku[linha][coluna] = numero;  // Inserir o n�mero
            cout << "N�mero inserido com sucesso!" << endl;
        }
        else {
            cout << "N�mero n�o pode ser inserido nesta posi��o (violaria regras do Sudoku)." << endl;
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 9);   // Valores de 1 a 9
    uniform_int_distribution<> pos(0, 8);    // �ndices de 0 a 8

    set<pair<int, int>> usadas;

    // Preencher 15 posi��es aleat�rias �nicas
    for (int k = 0; k < 15; ) {
        int i = pos(gen);
        int j = pos(gen);

        if (usadas.count({ i, j }) == 0) {
            sudoku[i][j] = dist(gen);
            usadas.insert({ i, j });
            k++;  // S� incrementa se posi��o for realmente nova
        }
    }

    // Iniciar o jogo
    startGame();

    return 0;
}
