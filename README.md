# Sudoku em C++

Um projeto simples de Sudoku implementado em C++. O objetivo é permitir que o jogador insira números no tabuleiro seguindo as regras básicas do jogo Sudoku.

## 🔧 Funcionalidades

- Geração aleatória de números em 15 posições iniciais.
- Validação de inserções: impede repetição na linha e coluna.
- Impressão formatada do tabuleiro.
- Finalização automática quando todas as células estiverem preenchidas.

## 🧩 Regras do Sudoku (simplificadas)

- Você pode inserir números de 1 a 9.
- Não pode repetir um número na **mesma linha** ou **mesma coluna**.
- O jogo termina automaticamente quando o tabuleiro estiver totalmente preenchido.

## ▶️ Como executar

1. Compile o código com um compilador C++ (como `g++`):
   ```bash
   g++ -o sudoku main.cpp
