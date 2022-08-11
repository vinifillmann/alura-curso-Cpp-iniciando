#include <iostream>
using namespace std;

int main() {
    cout << "******************************************" << endl;
    cout << "*** Bem-vindos ao jogo da advinhacao!  ***" << endl;
    cout << "******************************************" << endl;
    cout << endl;

    const int NUMERO_SECRETO = 42;

    int chute;
    int tentativas = 0;

    bool acertou;
    bool menorQueNumeroSecreto;
    bool maiorQueNumeroSecreto;

    while (!acertou) {
        tentativas++;
        cout << "Tentativa: " << tentativas << endl;
        cout << "Qual o seu chute: ";
        cin >> chute;
        cout << endl;

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
}