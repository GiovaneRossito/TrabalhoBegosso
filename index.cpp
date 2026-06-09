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

//1
void leituraCategorias(Categorias categorias[], int &tam){
    cout << "\n--- Cadastrar Nova Categoria ---" << endl;
    int codigoDigitado;
    bool erro;
    do {
        cout << "Digite o codigo da categoria: ";
        cin >> codigoDigitado;
        erro = false;

        if (tam > 0 && codigoDigitado <= categorias[tam - 1].cod) {
            cout << "ERRo O codigo deve ser sequencial e estritamente maior que o ultimo cadastrado e nao pode ser igual" << categorias[tam - 1].cod << endl;
            erro = true;
        }
    } while(erro);

    categorias[tam].cod = codigoDigitado;
    cout << "Digite a descricao da categoria: ";
    getline(cin >> ws, categorias[tam].desc);
    
    tam++;
    cout << "Categoria cadastrada com sucesso!" << endl;
};

//1
void leituraProdutos(Produtos produtos[], int &tam){
    cout << "\n--- Cadastrar Novo Produto ---" << endl;
    
    int codigoDigitado;
    bool erro;

    do {
        cout << "Digite o codigo do produto: ";
        cin >> codigoDigitado;
        erro = false;

        if (tam > 0 && codigoDigitado <= produtos[tam - 1].cod) {
            cout << "ERRO O codigo deve ser sequencial e estritamente maior que o ultimo cadastrado e nao pode ser igual" << produtos[tam - 1].cod << endl;
            erro = true;
        }

    } while(erro);

    produtos[tam].cod = codigoDigitado;
    cout << "Digite a descricao do produto: ";
    getline(cin >> ws, produtos[tam].descricao);
    cout << "Digite o codigo da categoria do produto: ";
    cin >> produtos[tam].codCat;
    cout << "Digite a quantidade em estoque do produto: ";
    cin >> produtos[tam].qntdEstq;
    cout << "Digite o estoque minimo do produto: ";
    cin >> produtos[tam].estqMin;
    cout << "Digite o estoque maximo do produto: ";
    cin >> produtos[tam].estqMax;
    cout << "Digite o preco unitario do produto: ";
    cin >> produtos[tam].precoUni;
    
    tam++;
    cout << "Produto cadastrado com sucesso!" << endl;
};

//2
void leituraClientes(Clientes lista[], int &tam) {
    cout << "\n--- Cadastrar Novo Cliente ---" << endl;
    int codigoDigitado;
    bool erro;

    //2.1
    do {
        cout << "Digite o codigo do cliente: ";
        cin >> codigoDigitado;
        erro = false;

        if (tam > 0 && codigoDigitado <= lista[tam - 1].cod) {
            cout << "ERRO O codigo deve ser sequencial e nao pode ser igual ao ultimo cadastrado: " << lista[tam - 1].cod << endl;
            erro = true;
        }

    } while(erro);

    lista[tam].cod = codigoDigitado;
    cout << "Digite o nome do cliente: ";
    getline(cin >> ws, lista[tam].nome);
    cout << "Digite o endereco do cliente: ";
    getline(cin >> ws, lista[tam].end);
    cout << "Digite o telefone do cliente: ";
    cin >> lista[tam].tel;

    tam++; 
    cout << "Cliente cadastrado" << endl;
};

//2
void InclusaoClientes(Clientes lista1[], int tam1, Clientes lista2[], int tam2, Clientes listafinal[], int &tamfinal){
    if(tam1 == 0 && tam2 == 0){
        cout << "Nenhum cliente cadastrado para inclusao." << endl;
        tamfinal = 0;
        return;
    }
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

//exibir arquivo final apos inclusao
void exibirClientes(Clientes listafinal[], int tamfinal){
    if(tamfinal == 0){
        cout << "Nenhum cliente cadastrado para inclusao." << endl;
        return;
    }
    cout << "\n--- Lista Final de Clientes ---" << endl;
    for(int i = 0; i < tamfinal; i++){
        cout << "Codigo: " << listafinal[i].cod << endl;
        cout << "Nome: " << listafinal[i].nome << endl;
        cout << "Endereco: " << listafinal[i].end << endl;
        cout << "Telefone: " << listafinal[i].tel << endl;
        cout << "-------------------------------" << endl;
    }
};

//3
void leituraVendedores(Vendedores lista[], int &tam) {
    cout << "\n--- Cadastrar Novo Vendedor ---" << endl;
    
    int codigoDigitado;
    bool erro;
    //3.1
    do {
        cout << "Digite o codigo do vendedor: ";
        cin >> codigoDigitado;
        erro = false;

        if (tam > 0 && codigoDigitado <= lista[tam - 1].cod) {
            cout << "ERRO O codigo deve ser sequencial e nao pode ser igual ao ultimo cadastrado: " << lista[tam - 1].cod << endl;
            erro = true;
        }

    } while(erro);

    lista[tam].cod = codigoDigitado;
    cout << "Digite o nome do vendedor: ";
    getline(cin >> ws, lista[tam].nome);
    cout << "Digite o telefone do vendedor: ";
    cin >> lista[tam].tel;
    cout << "-------------------------------" << endl;
    
    tam++; 
}

//3
void InclusaoVendedores(Vendedores lista1[], int tam1, Vendedores lista2[], int tam2, Vendedores listafinal[], int &tamfinal){
    if(tam1 == 0 && tam2 == 0){
        cout << "Nenhum vendedor cadastrado para inclusao." << endl;
        tamfinal = 0;
        return;
    }
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

//exibir arquivo final apos inclusao
void exibirVendedores(Vendedores listafinal[], int tamfinal){
    if(tamfinal == 0){
        cout << "Nenhum vendedor cadastrado para inclusao." << endl;
        return;
    }
    cout << "\n--- Lista Final de Vendedores ---" << endl;
    for(int i = 0; i < tamfinal; i++){
        cout << "Codigo: " << listafinal[i].cod << endl;
        cout << "Nome: " << listafinal[i].nome << endl;
        cout << "Telefone: " << listafinal[i].tel << endl;
        cout << "-------------------------------" << endl;
    }

};


//4.1
int buscarClientes(Clientes lista[], int tam, int codBuscado){
    if(tam == 0) {
        cout << "Nenhum cliente cadastrado para busca." << endl;
        return -1;
    }
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

//4.2
int buscarVendedores(Vendedores lista[], int tam, int codBuscado){
    if(tam == 0) {
        cout << "Nenhum vendedor cadastrado para busca." << endl;
        return -1;
    }
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

//5.1
int buscarProdutos(Produtos lista[], int tam, int codBuscado){
    if(tam == 0) {
        cout << "Nenhum produto cadastrado no sistema para busca" << endl;
        return -1;
    }
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
    if(tamProdutos == 0) {
        cout << "ERRO: Nenhum produto cadastrado no sistema para ser vendido!" << endl;
        return;
    }
    int codBuscadoProduto = 0;
    int posProduto = 0;

    do {
        //5.1
        cout << "Digite o codigo do produto: ";
        cin >> codBuscadoProduto;
        posProduto = buscarProdutos(listaProdutos, tamProdutos, codBuscadoProduto);
        if(posProduto == -1){
            cout << "Produto nao encontrado. Digite um codigo valido." << endl;
        }
        else{
            cout << "Produto encontrado: " << listaProdutos[posProduto].descricao << endl;
            cout << "Preco unitario: " << listaProdutos[posProduto].precoUni << endl;
            //5.2
            do{
                cout << "Digite a quantidade do produto: ";
                cin >> listaItens[tamItens].qntd;
                if(listaItens[tamItens].qntd > listaProdutos[posProduto].qntdEstq){
                    cout << "ERRO quantidade solicitada excede o estoque disponivel. Estoque atual: " << listaProdutos[posProduto].qntdEstq << endl;
                }
            } while (listaItens[tamItens].qntd > listaProdutos[posProduto].qntdEstq);

            //5.3
            listaItens[tamItens].codVenda = codVendaAtual;
            listaItens[tamItens].codProd = codBuscadoProduto;
            listaProdutos[posProduto].qntdEstq -= listaItens[tamItens].qntd;
            tamItens++;
            cout << "Item adicionado a venda." << endl;
        }
    }
    while (posProduto == -1);
};

//4
void RegistroVenda(Vendas lista[], int &tamVendas, Clientes listaClientes[], int tamClientes, Vendedores listaVendedores[], int tamVendedores, ItensVendas listaItens[], int &tamItens, Produtos listaProdutos[], int tamProdutos){
    if(tamClientes == 0 || tamVendedores == 0) {
        cout << "ERRO Voce precisa cadastrar pelo menos um Cliente e um Vendedor antes de registrar uma venda!" << endl;
        return;
    }
    int codBuscadoCli = 0;
    int codBuscadoVend = 0;
    int posCli = 0;
    int posVend = 0;
    cout << "Digite o codigo da venda: ";
    cin >> lista[tamVendas].cod;
    cout << "Digite a data da venda: ";
    getline(cin >> ws, lista[tamVendas].data);
    do {
        //4.1
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
        //4.2
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
        //4.3
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

//6
void consultarProduto(Produtos lista[], int tam){
    if(tam == 0){
        cout << "Nenhum produto cadastrado para consulta." << endl;
        return;
    }
    int codBuscadoProduto = 0;
    cout << "Digite o codigo do produto: ";
    cin >> codBuscadoProduto;
    int posProduto = buscarProdutos(lista, tam, codBuscadoProduto);
    if(posProduto == -1){
        cout << "Produto nao encontrado. Digite um codigo valido." << endl;
    }
    else{
        //6.1
        cout << "Produto encontrado: " << lista[posProduto].descricao << endl;
        cout << "Preco unitario: " << lista[posProduto].precoUni << endl;
        cout << "Quantidade em estoque: " << lista[posProduto].qntdEstq << endl;
        cout << "Estoque minimo: " << lista[posProduto].estqMin << endl;
        cout << "Estoque maximo: " << lista[posProduto].estqMax << endl;
        cout << "Codigo da categoria: " << lista[posProduto].codCat << endl;
        cout << "Valor Total Estoque: " << lista[posProduto].qntdEstq * lista[posProduto].precoUni << endl;
    }
};

//7
void exibirEstoqueBaixo(Produtos lista[], int tam){
    if(tam == 0){
        cout << "Nenhum produto cadastrado para consulta de estoque baixo." << endl;
        return;
    }
    int qntdComprar = 0;
    float valorComprar = 0.0;
    float valorTotal = 0.0;
    cout << "\n--- Produtos com Estoque Baixo ---" << endl;
    for(int i = 0; i < tam; i++){
        if(lista[i].qntdEstq < lista[i].estqMin){
            //7.1
            cout << "Produto: " << lista[i].descricao << endl;
            cout << "Codigo: " << lista[i].cod << endl;
            cout << "Quantidade em estoque: " << lista[i].qntdEstq << endl;
            cout << "Estoque minimo: " << lista[i].estqMin << endl;
            cout << "Estoque maximo: " << lista[i].estqMax << endl;
            qntdComprar = lista[i].estqMax - lista[i].qntdEstq;
            valorComprar = qntdComprar * lista[i].precoUni;
            cout << "Quantidade a comprar para atingir estoque maximo: " << qntdComprar << endl;
            cout << "Valor total para comprar a quantidade necessaria: " << valorComprar << endl;
            cout << "-------------------------------" << endl;
        }
    }
    //7.2
    for(int i = 0; i < tam; i++){
        if(lista[i].qntdEstq < lista[i].estqMin){
            qntdComprar = lista[i].estqMax - lista[i].qntdEstq;
            valorComprar = qntdComprar * lista[i].precoUni;
            valorTotal += valorComprar;
        }
    }
    cout << "Valor total para comprar todos os produtos: " << valorTotal << endl;
};

//8
void valorTotalVendas(Vendas lista[], ItensVendas listaItens[], int tamVendas, int tamItens, Produtos listaProdutos[], int tamProdutos){
    if(tamVendas == 0){
        cout << "Nenhuma venda registrada." << endl;
        return;
    }
    float valorTotal = 0.0;
    for(int i = 0; i < tamVendas; i++){
        float valorVenda = 0.0;
        for(int j = 0; j < tamItens; j++){
            if(listaItens[j].codVenda == lista[i].cod){
                int posProduto = buscarProdutos(listaProdutos, tamProdutos, listaItens[j].codProd);
                if(posProduto != -1){
                    valorVenda += listaItens[j].qntd * listaProdutos[posProduto].precoUni; //8.1 & 8.2
                }
            }
        }
        cout << "Valor total da venda " << lista[i].cod << ": " << valorVenda << endl;
        valorTotal += valorVenda;
    }
    cout << "Valor total de todas as vendas: " << valorTotal << endl;
};

//9
void exclusao(Clientes lista1[], int tam1, int codExclusao[], int tam2, Clientes listafinal[], int &tamfinal) {
    if (tam1 == 0) {
        cout << "Nenhum cliente cadastrado no sistema para ser excluido." << endl;
        tamfinal = 0;
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;

    for(int l = 0; l < tam2; l++){
        cout << "Digite o codigo para exclusao (finalize com 0) " << ": ";
        cin >> codExclusao[l];
        if(codExclusao[l] == 0) {
            tam2 = l;

            break;
        }
    }

    while(i < tam1 && j < tam2) {
        if(lista1[i].cod < codExclusao[j]) {
            listafinal[k] = lista1[i]; 
            i++;
            k++; 
        }
        else if(lista1[i].cod > codExclusao[j]) {
            cout << "Codigo de exclusao " << codExclusao[j] << " nao encontrado." << endl;
            j++;
        }

        else {
            cout << "Cliente com codigo " << codExclusao[j] << " excluido com sucesso." << endl;
            i++; 
            j++; 
        }
    }

    while(i < tam1) {
        listafinal[k] = lista1[i];
        i++;
        k++;
    }

    tamfinal = k;
}


void carregarDadosIniciais(Categorias categorias[], Produtos produtos[], int &tamProdutos, Clientes cli1[], int &tamCli1, Clientes clifinal[], int &tamfinalCli, Vendedores vend1[], int &tamVend1, Vendedores vendfinal[], int &tamfinalVend) {
    
    categorias[0].cod = 1; categorias[0].desc = "Teste1";
    categorias[1].cod = 2; categorias[1].desc = "Teste2";

    produtos[0].cod = 101; produtos[0].descricao = "Item1";
    produtos[0].codCat = 1; produtos[0].qntdEstq = 5; produtos[0].estqMin = 2; produtos[0].estqMax = 15; produtos[0].precoUni = 20.00;

    produtos[1].cod = 102; produtos[1].descricao = "Item2";
    produtos[1].codCat = 2; produtos[1].qntdEstq = 1; produtos[1].estqMin = 5; produtos[1].estqMax = 20; produtos[1].precoUni = 10.00;
    tamProdutos = 2;

    cli1[0].cod = 1; cli1[0].nome = "Pessoa1"; cli1[0].end = "Rua1, 123"; cli1[0].tel = 99991111;
    cli1[1].cod = 3; cli1[1].nome = "Pessoa2"; cli1[1].end = "Rua2, 123"; cli1[1].tel = 99992222;
    tamCli1 = 2;

    vend1[0].cod = 1; vend1[0].nome = "Alguem1"; vend1[0].tel = 99993333;
    vend1[1].cod = 3; vend1[1].nome = "Alguem2"; vend1[1].tel = 99994444; 
    tamVend1 = 2;

    for(int i = 0; i < tamCli1; i++) clifinal[i] = cli1[i];
    tamfinalCli = tamCli1;

    for(int i = 0; i < tamVend1; i++) vendfinal[i] = vend1[i];
    tamfinalVend = tamVend1;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    //1
    int tamCat = 0;
    int tamProd = 0;
    const int tam = 2;
    Categorias categorias[tam];
    Produtos produtos[tam];
    //2
    Clientes cli1[tam];
    int tamCli1 = 0;
    int tamCli2 = 0;
    Clientes cli2[tam];
    Clientes clifinal[tam * 2];
    int tamfinalCli = 0;
    //3
    Vendedores vend1[tam];
    int tamVend1 = 0;
    int tamVend2 = 0;
    Vendedores vend2[tam];
    Vendedores vendfinal[tam * 2];
    int tamfinalVend = 0;
    //4
    Vendas listaVendas[tam];
    int tamVendas = 0;
    ItensVendas listaItens[tam * 10];
    int tamItens = 0;
    //5
    int opcao;
    //6
    int codExclusao[tam];
    Clientes clifinalExclusao[tam];
    int tamfinalExclusao = 0;

    do {
        cout << "=========================================\n";

        cout << " CADASTROS GERAIS \n";
        cout << "  1. Cadastrar categorias\n";
        cout << "  2. Cadastrar produtos\n\n";

        cout << " GERENCIAR CLIENTES \n";
        cout << "  3. Adicionar clientes Base (Sequencial)\n";
        cout << "  4. Inclusao de novos clientes (Sequencial)\n";
        cout << "  5. Exibir lista final de clientes\n\n";

        cout << " GERENCIAR VENDEDORES \n";
        cout << "  6. Adicionar Vendedores Base (Sequencial)\n";
        cout << "  7. Inclusao de novos vendedores (Sequencial)\n";
        cout << "  8. Exibir lista final de vendedores\n\n";

        cout << " REGISTRO DE VENDAS \n";
        cout << "  9. Registrar venda\n\n";

        cout << " CONSULTAS \n";
        cout << "  10. Consultar produto\n";
        cout << "  11. Exibir produtos com estoque baixo\n";
        cout << "  12. Calcular valor total de vendas\n";
        cout << "  13. Excluir clientes (Sequencial)\n";
        cout << "  14. Carregar dados iniciais para testes\n\n";

        cout << "  0. Sair\n";

        cout << "=========================================\n";
        cout << "Digite a opcao desejada: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            case 1:
                leituraCategorias(categorias, tamCat);
                break;
            case 2:
                leituraProdutos(produtos, tamProd);
                break;
            case 3:
                leituraClientes(cli1, tamCli1);
                break;
            case 4:
                leituraClientes(cli2, tamCli2);
                InclusaoClientes(cli1, tamCli1, cli2, tamCli2, clifinal, tamfinalCli);
                break;
            case 5:
                exibirClientes(clifinal, tamfinalCli);
                break;
            case 6:
                leituraVendedores(vend1, tamVend1);
                break;
            case 7:
                leituraVendedores(vend2, tamVend2);
                InclusaoVendedores(vend1, tamVend1, vend2, tamVend2, vendfinal, tamfinalVend);
                break;
            case 8:
                exibirVendedores(vendfinal, tamfinalVend);
                break;
            case 9:
                RegistroVenda(listaVendas, tamVendas, clifinal, tamfinalCli, vendfinal, tamfinalVend, listaItens, tamItens, produtos, tamProd);
                break;
            case 10:
                consultarProduto(produtos, tamProd);
                break;
            case 11:
                exibirEstoqueBaixo(produtos, tamProd);
                break;
            case 12:
                valorTotalVendas(listaVendas, listaItens, tamVendas, tamItens, produtos, tamProd);
                break;
            case 13:
                exclusao(clifinal, tamfinalCli, codExclusao, tam, clifinalExclusao, tamfinalExclusao);
                exibirClientes(clifinalExclusao, tamfinalExclusao);
                break;
            case 14:
                carregarDadosIniciais(categorias, produtos, tamProd, cli1, tamCli1, clifinal, tamfinalCli, vend1, tamVend1, vendfinal, tamfinalVend);
                break;
            default:
                cout << "Opcao invalida." << endl;
        }

    }
    while (opcao != 0);
    return 0;
};