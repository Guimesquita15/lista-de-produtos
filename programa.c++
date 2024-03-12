#include <iostream>
#include <vector>
#include <string>

struct Produto {
    std::string nome;
    double preco_compra;
    double preco_venda;
    double lucro;
    int quantidade_comprada;
    int quantidade_vendida;
};

// Função para adicionar um produto ao vetor de produtos
void adicionarProduto(std::vector<Produto>& produtos) {
    Produto novo_produto;
    std::cout << "Digite o nome do produto: ";
    std::cin >> novo_produto.nome;
    std::cout << "Digite o preço de compra do produto: R$";
    std::cin >> novo_produto.preco_compra;
    std::cout << "Digite o preço de venda do produto: R$";
    std::cin >> novo_produto.preco_venda;
    novo_produto.lucro = novo_produto.preco_venda - novo_produto.preco_compra;
    std::cout << "Digite a quantidade comprada do produto: ";
    std::cin >> novo_produto.quantidade_comprada;
    std::cout << "Digite a quantidade vendida do produto: ";
    std::cin >> novo_produto.quantidade_vendida;

    produtos.push_back(novo_produto); // Adiciona o novo produto ao vetor
}

int main() {
    std::vector<Produto> produtos;

    // Adiciona produtos manualmente (pode ser substituído por um loop para adicionar vários produtos)
    adicionarProduto(lapis );
    adicionarProduto(caderno);
    adicionarProduto(borracha);

    // Imprime as informações de cada produto
    std::cout << "Informações dos Produtos:\n";
    for (const auto& produto : produtos) {
        std::cout << "Nome: " << produto.nome << "\n";
        std::cout << "Preço de Compra: R$" << produto.preco_compra << "\n";
        std::cout << "Preço de Venda: R$" << produto.preco_venda << "\n";
        std::cout << "Lucro: R$" << produto.lucro << "\n";
        std::cout << "Quantidade Comprada: " << produto.quantidade_comprada << "\n";
        std::cout << "Quantidade Vendida: " << produto.quantidade_vendida << "\n";
        std::cout << "------------------------\n";
    }

    return 0;
}
