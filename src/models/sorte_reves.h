using namespace std;
/*
Caso seu peão pare na casa Sorte ou Revés, você deve pegar a primeira carta do monte, 
cumprir o que ela indica e a devolver para o final do monte após concluir a tarefa.

Se a carta sorteada informar Habeas Corpus ou Compra Livre, você deve guardá-la para usar depois. 
Ela pode ser utilizada em qualquer momento que você deseja. Após utilizada, 
deve ser retornada ao final do monte.

A carta Habeas Corpus te dá o direito de saída livre da prisão sem a necessidade de tirar 
uma dupla nos dados ou pagar fiança.
*/

typedef struct {
    int tipo; // tipo sorte ou tipo revés 0 -> Perde $, 1 -> Ganha $, 2 -> Habeas Corpus
    
} SORTE_REVES;

SORTE_REVES criar_card_sr(int tipo) {
    SORTE_REVES sr;
    sr.tipo = tipo;
    return sr;
}

/*
LOGO das cartas de Sorte & Revés
*/
void mostrarCard_SR() {
    char card_sr[5][9] = {
        {(char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219},
        {(char) 219, (char) 219, 'S', 'O', 'R', 'T', 'E', (char) 219, (char) 219},
        {(char) 219, (char) 219, ' ', ' ', '&', ' ', ' ', (char) 219, (char) 219},
        {(char) 219, (char) 219, 'R', 'E', 'V', 'E', 'S', (char) 219, (char) 219},
        {(char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219}
    };

    for (int i=0; i<5; i++) {
        cout << endl;
        for (int j=0; j<9; j++) {
            cout << card_sr[i][j];
        }
    }
    cout << endl;
}

/*
Embaralha as cartas do baralho de Sorte & Revés
*/
int embaralhaCartas(vector<SORTE_REVES> &cartas) {
    vector<SORTE_REVES> embaralhado;
    int pos;
    while (!cartas.empty()) {
        pos = randomSortReves(cartas.size());
        embaralhado.push_back(cartas.at(pos));
        cartas.erase(cartas.begin() + pos);
    }
    while (!embaralhado.empty()) {
        pos = randomSortReves(embaralhado.size());
        cartas.push_back(embaralhado.at(pos));
        embaralhado.erase(embaralhado.begin() + pos);
    }
    
    return 1; // Success
}

/*
É chamada para realizar a ação de uma carta Sorte & Revés baseada no seu tipo (0 a 2)
Sendo:

1 - O player vai perder uma quantia randômica de dinheiro
2 - O player vai ganhar uma quantia randômica de dinheiro
3 - O player vai receber um passe Habeas Corpus
*/
void acao_sorteReves(vector<SORTE_REVES> &cartas, vector<PLAYER> &players) {

    mostrarCard_SR();
    cout << cartas.front().tipo << endl;

    if (cartas.front().tipo == 1) {
        long int valor_perde = randint(25);
        valor_perde *= 10000;
        players.front().carteira -= valor_perde;
        cout << "\nPlayer " << players.front().nome << " perdeu $ " << valor_perde << endl;
        cout << "Saldo de " << players.front().nome << ": $ " << players.front().carteira << endl;
    } else if (cartas.front().tipo == 2) {
        long int valor_ganha = randint(25);
        valor_ganha *= 10000;
        players.front().carteira += valor_ganha;
        cout << "\nPlayer " << players.front().nome << " recebeu $ " << valor_ganha << endl;
        cout << "Saldo de " << players.front().nome << ": $ " << players.front().carteira << endl;
    } else if (cartas.front().tipo == 3) {
        players.front().habeas = true;
        cout << "\nPlayer " << players.front().nome << " foi concedido com saida livre da prisao sem a necessidade de pagar dividas!" << endl;
    }
}

/*
Gera uma pilha de cartas Sorte & Revés (não embaralhada)
*/
void loadSorteReves(vector<SORTE_REVES> &cartas, int quant)  {
	for (int i=0; i<quant; i++) {
        SORTE_REVES card;
        card.tipo = randint(4);
        card = criar_card_sr(card.tipo);
		cartas.push_back(card);
	}
}

/*
Essa função não será utilizada ao longo do jogo.
Serve apenas para verificar se as cartas estão sendo geradas de forma aleatória com tipos entre 0 e 2
*/
void mostrarBaralho(vector<SORTE_REVES> &cartas) {
    for (int i=0; i<cartas.size(); i++) {
        cout << "Tipo carta " << (i+1) << ": " << cartas.at(i).tipo << endl;
    }
    cout << endl;
}

void mainSorteReves(vector<PLAYER> &players, vector<SORTE_REVES> &cartas) {
    cout << "Pegue uma carta do baralho de Sorte & Reves!" << endl;
    cout << "Boa sorte......... (ou nao) hahaha!" << endl;
    Sleep(1000);
    acao_sorteReves(cartas, players);
    cout << endl << "\033[31m[!] \033[0;34mEmbaralhando Sorte & Reves!\033[0m\n\n";
    embaralhaCartas(cartas);
}