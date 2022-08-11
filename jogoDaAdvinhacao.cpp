#include <iostream>
using namespace std;

int main() {
    cout << "******************************************" << endl;
    cout << "*** Bem-vindos ao jogo da advinhacao!  ***" << endl;
    cout << "******************************************" << endl;
    cout << endl;

    int numeroSecreto = 42;

    cout << "O numero secreto e " << numeroSecreto << ". Nao conte para ninguem!" << endl << endl;

    int chute;

    cout << "Qual o seu chute: ";
    cin >> chute;

    cout << "O valor de seu chute e " << chute << "!" << endl;

    if (chute == numeroSecreto) {
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
    } else if (chute > numeroSecreto) {
        cout << "Seu chute foi maior que o numero secreto!" << endl;
    } else if (chute < numeroSecreto) {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
    } else {
        cout << "Digite um valor válido" << endl;
    }
}