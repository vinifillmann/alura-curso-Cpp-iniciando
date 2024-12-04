#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "";
map<char, bool> chutes;
vector<char> chutes_errados;

bool string_contain_char(char char_to_find, string string_to_search)
{
    // for (int i = 0; i < string_to_search.length(); i++) {
    //     if (string_to_search[i] == toupper(char_to_find)) {
    //         return true;
    //     }
    // }
    for (char letra : string_to_search)
    {
        if (toupper(letra) == toupper(char_to_find))
        {
            return true;
        }
    }
    return false;
}

bool game_was_won(map<char, bool> tries, string secret_word)
{
    for (char secret_char : secret_word)
    {
        if (tries[secret_char] == false)
        {
            return false;
        }
    }
    return true;
}

bool game_was_losed(vector<char> wrong_tries)
{
    return wrong_tries.size() > 5;
}

void print_header()
{
    cout << "*****************************" << endl;
    cout << "****** Jogo da forca! *******" << endl;
    cout << "*****************************" << endl;
    cout << endl;
}

void print_wrong_tries()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl
         << endl;
}

void print_display()
{
    for (char letra : palavra_secreta)
    {
        if (chutes[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl
         << endl;
}

void input_and_procces_user_try()
{
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    cout << endl;

    chutes[chute] = true;

    if (string_contain_char(chute, palavra_secreta))
    {
        cout << "Voce acertou! Seu chute esta na palavra." << endl;
    }
    else
    {
        chutes_errados.push_back(chute);
        cout << "Voce errou! Seu chute nao esta na palavra." << endl;
    }
}

void error_with_archive()
{
    cout << "Nao foi possivel acessar o banco de palavras." << endl;
    exit(0);
}

vector<string> read_archive()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (!arquivo.is_open())
    {
        error_with_archive();
    }
    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    // cout << "O arquivo possui " << quantidade_palavras << "palavras" << endl;

    vector<string> palavras_no_arquivo;

    for (int i = 0; i < quantidade_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_no_arquivo.push_back(palavra_lida);
        // cout << "Na linha " << i << " : " << palavra_lida << endl;
    }

    arquivo.close();
    return palavras_no_arquivo;
}

void pick_secret_word()
{
    vector<string> palavras = read_archive();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void update_archive(vector<string> new_list)
{
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (!arquivo.is_open()) {
        error_with_archive();
    }
    arquivo << new_list.size() << endl;
    for (string word : new_list) {
        arquivo << word << endl;
    }
    arquivo.close();
}

void add_secret_word()
{
    cout << "Digite a nova palavra: (em maiusculo)";
    string nova_palavra;
    cin >> nova_palavra;
    cout << endl;

    vector<string> lista_palavras = read_archive();
    lista_palavras.push_back(nova_palavra);

    update_archive(lista_palavras);
}

int main()
{
    print_header();

    pick_secret_word();

    while (!game_was_won(chutes, palavra_secreta) && !game_was_losed(chutes_errados))
    {

        print_wrong_tries();

        print_display();

        input_and_procces_user_try();
    }

    cout << endl
         << "Fim de jogo!" << endl;

    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (game_was_won(chutes, palavra_secreta))
    {
        cout << "Voce ganhou, Parabens!!!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N)";
        char resposta;
        cin >> resposta;
        resposta = toupper(resposta);
        cout << endl;
        if (resposta == 'S')
        {
            add_secret_word();
        }
    }
    else
    {
        cout << "Voce errou mais de 5 vezes!" << endl;
        cout << "Voce Perdeu, Tente Novamente!" << endl;
    }
}