#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct Categorias{
    int cod;
    string desc;
};

struct Produtos{
    int cod;
    string descricao;
    int codCat;
    int qntdEstq;
    int estqMin;
    int estqMax;
    float precoUni;
};

struct Clientes{
    int cod;
    string nome;
    string end;
    int tel;
};

struct Vendedores{
    int cod;
    string nome;
    int tel;
};

struct Vendas{
    int cod;
    int codCli;
    int codVendedor;
    string data;
};

struct ItensVendas{
    int codVenda;
    int codProd;
    int qntd;
};

void leituraCategorias(Categorias categorias[], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Digite o codigo da categoria: ";
        cin >> categorias[i].cod;
        cout << "Digite a descricao da categoria: ";
        getline(cin >> ws, categorias[i].desc);
    }
};

void leituraProdutos(Produtos produtos[], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Digite o codigo do produto: ";
        cin >> produtos[i].cod;
        cout << "Digite a descricao do produto: ";
        getline(cin >> ws, produtos[i].descricao);
        cout << "Digite o codigo da categoria do produto: ";
        cin >> produtos[i].codCat;
        cout << "Digite a quantidade em estoque do produto: ";
        cin >> produtos[i].qntdEstq;
        cout << "Digite o estoque minimo do produto: ";
        cin >> produtos[i].estqMin;
        cout << "Digite o estoque maximo do produto: ";
        cin >> produtos[i].estqMax;
        cout << "Digite o preço unitario do produto: ";
        cin >> produtos[i].precoUni;
    }
};

//Parte de Clientes 2, 2.1

void leituraClientes(Clientes lista[], int tam) {
    cout << "\n--- Leitura de Clientes ---" << endl;
    for(int i = 0; i < tam; i++) {
        int codigoDigitado;
        bool existe;

        do {
            cout << "Digite o codigo do cliente " << i + 1 << ": ";
            cin >> codigoDigitado;
            existe = false;
            for(int j = 0; j < i; j++) {
                if(lista[j].cod == codigoDigitado) {
                    cout << "ERRO: Codigo de cliente ja existe nesta lista. Digite outro." << endl;
                    existe = true;
                    break;
                }
            }
        } 
        while(existe);

        lista[i].cod = codigoDigitado;
        cout << "Digite o nome do cliente: ";
        getline(cin >> ws, lista[i].nome);
        cout << "Digite o endereco do cliente: ";
        getline(cin >> ws, lista[i].end);
        cout << "Digite o telefone do cliente: ";
        cin >> lista[i].tel;
        cout << "-------------------------------" << endl;
    }
};

void InclusaoClientes(Clientes lista1[], int tam1, Clientes lista2[], int tam2, Clientes listafinal[], int &tamfinal){
    int i = 0;
    int j = 0;
    int k = 0;

    for(;i < tam1 && j < tam2; k++){

        if(lista1[i].cod < lista2[j].cod){
            listafinal[k] = lista1[i];
            i++;
        }
        else if(lista1[i].cod > lista2[j].cod){
            listafinal[k] = lista2[j];
            j++;
        }
        else{
            cout << "Codigo de cliente duplicado: " << lista1[i].cod << "Mantendo o da Base" << endl;
            listafinal[k] = lista1[i];
            i++;
            j++;
        }
    }

    while(i < tam1){
        listafinal[k] = lista1[i];
        i++;
        k++;
    }

    while(j < tam2){
        listafinal[k] = lista2[j];
        j++;
        k++;
    }

    tamfinal = k;
};

void exibirClientes(Clientes listafinal[], int tamfinal){
    cout << "\n--- Lista Final de Clientes ---" << endl;
    for(int i = 0; i < tamfinal; i++){
        cout << "Codigo: " << listafinal[i].cod << endl;
        cout << "Nome: " << listafinal[i].nome << endl;
        cout << "Endereco: " << listafinal[i].end << endl;
        cout << "Telefone: " << listafinal[i].tel << endl;
        cout << "-------------------------------" << endl;
    }
};

//Parte de Vendedores 3, 3.1

void leituraVendedores(Vendedores lista[], int tam) {
    cout << "\n--- Leitura de Vendedores ---" << endl;
    for(int i = 0; i < tam; i++) {
        int codigoDigitado;
        bool existe;

        do {
            cout << "Digite o codigo do Vendedor " << i + 1 << ": ";
            cin >> codigoDigitado;
            existe = false;
            for(int j = 0; j < i; j++) {
                if(lista[j].cod == codigoDigitado) {
                    cout << "ERRO: Codigo de Vendedor ja existe nesta lista. Digite outro." << endl;
                    existe = true;
                    break;
                }
            }
        } 
        while(existe);

        lista[i].cod = codigoDigitado;
        cout << "Digite o nome do vendedor: ";
        getline(cin >> ws, lista[i].nome);
        cout << "Digite o telefone do vendedor: ";
        cin >> lista[i].tel;
        cout << "-------------------------------" << endl;
    }
};

void InclusaoVendedores(Vendedores lista1[], int tam1, Vendedores lista2[], int tam2, Vendedores listafinal[], int &tamfinal){
    int i = 0;
    int j = 0;
    int k = 0;

    for(;i < tam1 && j < tam2; k++){

        if(lista1[i].cod < lista2[j].cod){
            listafinal[k] = lista1[i];
            i++;
        }
        else if(lista1[i].cod > lista2[j].cod){
            listafinal[k] = lista2[j];
            j++;
        }
        else{
            cout << "Codigo de vendedor duplicado: " << lista1[i].cod << "Mantendo o da Base" << endl;
            listafinal[k] = lista1[i];
            i++;
            j++;
        }
    }

    while(i < tam1){
        listafinal[k] = lista1[i];
        i++;
        k++;
    }

    while(j < tam2){
        listafinal[k] = lista2[j];
        j++;
        k++;
    }

    tamfinal = k;
};

void exibirVendedores(Vendedores listafinal[], int tamfinal){
    cout << "\n--- Lista Final de Vendedores ---" << endl;
    for(int i = 0; i < tamfinal; i++){
        cout << "Codigo: " << listafinal[i].cod << endl;
        cout << "Nome: " << listafinal[i].nome << endl;
        cout << "Telefone: " << listafinal[i].tel << endl;
        cout << "-------------------------------" << endl;
    }

};

//Busca Clientes 4.1

int buscarClientes(Clientes lista[], int tam, int codBuscado){
    int inicio = 0;
    int final = tam - 1;
    int meio = 0;

    while(inicio <= final){
        meio = (inicio + final) / 2;
        if(lista[meio].cod == codBuscado){
            cout << "Cliente encontrado:" << endl;
            cout << "Codigo: " << lista[meio].cod << endl;
            cout << "Nome: " << lista[meio].nome << endl;
            cout << "Endereco: " << lista[meio].end << endl;
            cout << "Telefone: " << lista[meio].tel << endl;
            return meio;
        }
        else if(lista[meio].cod < codBuscado){
            inicio = meio + 1;
        }
        else{
            final = meio - 1;
        }
    }
    cout << "Cliente com codigo " << codBuscado << " nao encontrado." << endl;
    return -1;
};

//Busca Vendedores 4.2

int buscarVendedores(Vendedores lista[], int tam, int codBuscado){
    int inicio = 0;
    int final = tam - 1;
    int meio = 0;

    while(inicio <= final){
        meio = (inicio + final) / 2;
        if(lista[meio].cod == codBuscado){
            cout << "Vendedor encontrado:" << endl;
            cout << "Codigo: " << lista[meio].cod << endl;
            cout << "Nome: " << lista[meio].nome << endl;
            cout << "Telefone: " << lista[meio].tel << endl;
            return meio;
        }
        else if(lista[meio].cod < codBuscado){
            inicio = meio + 1;
        }
        else{
            final = meio - 1;
        }
    }
    cout << "Vendedor com codigo " << codBuscado << " nao encontrado." << endl;
    return -1;
};

//4.3

void RegistroVenda(Vendas lista[], int &tamVendas, Clientes listaClientes[], int tamClientes, Vendedores listaVendedores[], int tamVendedores, ItensVendas listaItens[], int &tamItens, Produtos listaProdutos[], int tamProdutos){
    int codBuscadoCli = 0;
    int codBuscadoVend = 0;
    int posCli = 0;
    int posVend = 0;
    cout << "Digite o codigo da venda: ";
    cin >> lista[tamVendas].cod;
    cout << "Digite a data da venda: ";
    getline(cin >> ws, lista[tamVendas].data);
    do {
        cout << "Digite o codigo do cliente: ";
        cin >> codBuscadoCli;
        posCli = buscarClientes(listaClientes, tamClientes, codBuscadoCli);
        if(posCli == -1){
            cout << "Cliente nao encontrado. Digite um codigo valido." << endl;
        }
        else{
            cout << "Cliente encontrado: " << listaClientes[posCli].nome << endl;
            lista[tamVendas].codCli = codBuscadoCli;
        }

    }
    while (posCli == -1);
    
    do {
        cout << "Digite o codigo do vendedor: ";
        cin >> codBuscadoVend;
        posVend = buscarVendedores(listaVendedores, tamVendedores, codBuscadoVend);
        if(posVend == -1){
            cout << "Vendedor nao encontrado. Digite um codigo valido." << endl;
        }
        else{
            cout << "Vendedor encontrado: " << listaVendedores[posVend].nome << endl;
            lista[tamVendas].codVendedor = codBuscadoVend;
        }
    }
    while (posVend == -1);
    
    char opcao;
    do {
        cout << "Deseja adicionar um item a venda? (S/N): ";
        cin >> opcao;
        if(opcao == 'S' || opcao == 's'){
            incluirItemVenda(listaItens, tamItens, listaProdutos, tamProdutos, lista[tamVendas].cod);
        }
        else if(opcao == 'N' || opcao == 'n'){
            break;
        }
        else{
            cout << "Opcao invalida. Digite S para sim ou N para nao." << endl;
        }
    }
    while (opcao == 'S' || opcao == 's');
    tamVendas++;
};

//busca produtos

int buscarProdutos(Produtos lista[], int tam, int codBuscado){
    int inicio = 0;
    int final = tam - 1;
    int meio = 0;

    while(inicio <= final){
        meio = (inicio + final) / 2;
        if(lista[meio].cod == codBuscado){
            cout << "Produto encontrado:" << endl;
            cout << "Codigo: " << lista[meio].cod << endl;
            cout << "Descricao: " << lista[meio].descricao << endl;
            cout << "Codigo da categoria: " << lista[meio].codCat << endl;
            cout << "Quantidade em estoque: " << lista[meio].qntdEstq << endl;
            cout << "Estoque minimo: " << lista[meio].estqMin << endl;
            cout << "Estoque maximo: " << lista[meio].estqMax << endl;
            cout << "Preco unitario: " << lista[meio].precoUni << endl;
            return meio;
        }
        else if(lista[meio].cod < codBuscado){
            inicio = meio + 1;
        }
        else{
            final = meio - 1;
        }
    }
    cout << "Produto com codigo " << codBuscado << " nao encontrado." << endl;
    return -1;
};

//5

void incluirItemVenda(ItensVendas listaItens[], int &tamItens, Produtos listaProdutos[], int tamProdutos, int codVendaAtual){
    int codBuscadoProduto = 0;
    int posVenda = 0;
    int posProduto = 0;

    do {
        cout << "Digite o codigo do produto: ";
        cin >> codBuscadoProduto;
        posProduto = buscarProdutos(listaProdutos, tamProdutos, codBuscadoProduto);
        if(posProduto == -1){
            cout << "Produto nao encontrado. Digite um codigo valido." << endl;
        }
        else{
            //5.1
            cout << "Produto encontrado: " << listaProdutos[posProduto].descricao << endl;
            cout << "Preco unitario: " << listaProdutos[posProduto].precoUni << endl;
            //5.2
            cout << "Digite a quantidade do produto: ";
            cin >> listaItens[tamItens].qntd;
            if(listaItens[tamItens].qntd > listaProdutos[posProduto].qntdEstq){
                cout << "ERRO!! quantidade solicitada excede o estoque disponivel. Estoque atual: " << listaProdutos[posProduto].qntdEstq << endl;
            }
            //5.3
            else{
                listaItens[tamItens].codVenda = codVendaAtual;
                listaItens[tamItens].codProd = codBuscadoProduto;
                listaProdutos[posProduto].qntdEstq -= listaItens[tamItens].qntd;
                tamItens++;
            }
        }
    }
    while (posProduto == -1);
};


int main(){
    setlocale(LC_ALL, "Portuguese");
    //1
    const int tam = 2;
    Categorias categorias[tam];
    Produtos produtos[tam];
    //2
    Clientes cli1[tam];
    Clientes cli2[tam];
    Clientes clifinal[tam * 2];
    int tamfinalCli = 0;
    //3
    Vendedores vend1[tam];
    Vendedores vend2[tam];
    Vendedores vendfinal[tam * 2];
    int tamfinalVend = 0;
    //4
    Vendas listaVendas[tam];
    int tamVendas = 0;
    ItensVendas listaItens[tam * 10];
    int tamItens = 0;
    //5
    Produtos listaProdutos[tam];
    int tamProdutos = 0;
    int opcao;

    do {
        cout << "=========================================\n";

        cout << "[ CADASTROS GERAIS ]\n";
        cout << "  1. Cadastrar categorias\n";
        cout << "  2. Cadastrar produtos\n\n";

        cout << "[ GERENCIAR CLIENTES ]\n";
        cout << "  3. Adicionar clientes Base (Sequencial)\n";
        cout << "  4. Inclusao de novos clientes (Sequencial)\n";
        cout << "  5. Exibir lista final de clientes\n\n";

        cout << "[ GERENCIAR VENDEDORES ]\n";
        cout << "  6. Adicionar Vendedores Base (Sequencial)\n";
        cout << "  7. Inclusao de novos vendedores (Sequencial)\n";
        cout << "  8. Exibir lista final de vendedores\n\n";

        cout << "[ REGISTRO DE VENDAS ]\n";
        cout << "  9. Registrar venda\n\n";


        cout << "  0. Sair\n";

        cout << "=========================================\n";
        cout << "Digite a opcao desejada: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            case 1:
                leituraCategorias(categorias, tam);
                break;
            case 2:
                leituraProdutos(produtos, tam);
                break;
            case 3:
                leituraClientes(cli1, tam);
                break;
            case 4:
                leituraClientes(cli2, tam);
                InclusaoClientes(cli1, tam, cli2, tam, clifinal, tamfinalCli);
                break;
            case 5:
                exibirClientes(clifinal, tamfinalCli);
                break;
            case 6:
                leituraVendedores(vend1, tam);
                break;
            case 7:
                leituraVendedores(vend2, tam);
                InclusaoVendedores(vend1, tam, vend2, tam, vendfinal, tamfinalVend);
                break;
            case 8:
                exibirVendedores(vendfinal, tamfinalVend);
                break;
            case 9:
                RegistroVenda(listaVendas, tamVendas, clifinal, tamfinalCli, vendfinal, tamfinalVend, listaItens, tamItens, listaProdutos, tamProdutos);
                break;
            default:
                cout << "Opcao invalida." << endl;
        }

    }
    while (opcao != 0);
    return 0;
};