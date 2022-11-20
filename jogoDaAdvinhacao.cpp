#include <iostream>
using namespace std;

int main() {
    cout << "******************************************" << endl;
    cout << "*** Bem-vindos ao jogo da advinhacao!  ***" << endl;
    cout << "******************************************" << endl;
    cout << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char opcao;

    const int NUMERO_SECRETO = 42;

    int chute;
    int tentativas = 0;

    double pontos = 1000;

    bool acertou = false;
    bool menorQueNumeroSecreto;
    bool maiorQueNumeroSecreto;

    while (!acertou) {
        tentativas++;
        cout << "Tentativa: " << tentativas << endl;
        cout << "Qual o seu chute: ";
        cin >> chute;
        cout << endl;

        double pontos_perdidos = (double) abs((chute - NUMERO_SECRETO)) / 2;
        
        pontos -= pontos_perdidos;

        cout << "O valor de seu chute e " << chute << "!" << endl << endl;

        acertou = chute == NUMERO_SECRETO;
        maiorQueNumeroSecreto = chute > NUMERO_SECRETO;
        menorQueNumeroSecreto = chute < NUMERO_SECRETO;

        if (acertou) {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
        } else if (maiorQueNumeroSecreto) {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        } else if (menorQueNumeroSecreto) {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        } else {
            cout << "Digite um valor válido!" << endl;
        }
        cout << endl;
    }

    cout << "FIM!!!" << endl << endl;
    cout << "Voce acertou em " << tentativas << " Tentativas!" << endl << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Voce pontuou " << pontos << " pontos!" << endl;
}