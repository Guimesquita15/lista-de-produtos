#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição da estrutura de um produto
struct Produto {
    int numero;
    string nome;
    double precoCompra;
    double precoVenda;
    double lucro;
    int stock;
    int quantidadeComprada;
    int quantidadeVendida;
};

// Função para calcular o lucro de um produto
double calcularLucro(const Produto& produto) {
    return produto.precoVenda - produto.precoCompra;
}

// Função para adicionar um produto à lista
void adicionarProduto(vector<Produto>& listaProdutos) {
    Produto novoProduto;
    
    cout << "Digite o número do produto: ";
    cin >> novoProduto.numero;
    cout << "Digite o nome do produto: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoProduto.nome);
    cout << "Digite o preço de compra: ";
    cin >> novoProduto.precoCompra;
    cout << "Digite o preço de venda: ";
    cin >> novoProduto.precoVenda;
    cout << "Digite o número em estoque: ";
    cin >> novoProduto.stock;
    cout << "Digite o número de produtos comprados: ";
    cin >> novoProduto.quantidadeComprada;
    cout << "Digite o número de produtos vendidos: ";
    cin >> novoProduto.quantidadeVendida;
    
    // Calcular o lucro do novo produto
    novoProduto.lucro = calcularLucro(novoProduto);
    
    // Adicionar o novo produto à lista
    listaProdutos.push_back(novoProduto);
    
    cout << "Produto adicionado com sucesso!" << endl;
}

// Função para exibir os detalhes de todos os produtos
void mostrarProdutos(const vector<Produto>& listaProdutos) {
    cout << "Lista de Produtos:" << endl;
    for (const Produto& produto : listaProdutos) {
        cout << "Número do Produto: " << produto.numero << endl;
        cout << "Nome do Produto: " << produto.nome << endl;
        cout << "Preço de Compra: " << produto.precoCompra << endl;
        cout << "Preço de Venda: " << produto.precoVenda << endl;
        cout << "Lucro: " << produto.lucro << endl;
        cout << "Estoque: " << produto.stock << endl;
        cout << "Quantidade Comprada: " << produto.quantidadeComprada << endl;
        cout << "Quantidade Vendida: " << produto.quantidadeVendida << endl;
        cout << "------------------------------------" << endl;
    }
}

int main() {
    vector<Produto> listaProdutos;
    int opcao;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Mostrar Produtos" << endl;
        cout << "0. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(listaProdutos);
                break;
            case 2:
                mostrarProdutos(listaProdutos);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
