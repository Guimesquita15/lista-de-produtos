#include <iostream>
#include <iomanip> // Para setw
#include <string>
#include <vector>
using namespace std;

// Estrutura para representar um produto
struct Produto {
    string nome;
    double preco_compra;
    double lucro_porcentagem;
    int quantidade;
};

// Taxa de conversão de real para euro
const double taxa_conversao = 0.15;

// Função para buscar um produto pelo nome
Produto* buscarProduto(vector<Produto>& produtos, string nome_produto) {
    for (auto& produto : produtos) {
        if (produto.nome == nome_produto) {
            return &produto;
        }
    }
    return nullptr;
}

// Função para imprimir os detalhes de uma venda em formato de tabela
void imprimirVendaProduto(Produto* produto, int quantidade_vendida) {
    if (produto != nullptr) {
        if (produto->quantidade >= quantidade_vendida) {
            double lucro = (produto->lucro_porcentagem / 10) * produto->preco_compra * taxa_conversao;
            double valor_venda = produto->preco_compra * taxa_conversao + lucro;
            double total_lucro = (valor_venda - produto->preco_compra * taxa_conversao) * quantidade_vendida;

            cout << "----------------------------------------------" << endl;
            cout << "| " << setw(20) << left << "Nome do Produto";
            cout << "| " << setw(20) << left << "Quantidade Vendida";
            cout << "| " << setw(20) << left << "Valor de Venda Total (em euro)";
            cout << "| " << setw(20) << left << "Lucro Total (em euro)";
            cout << "|" << endl;
            cout << "----------------------------------------------" << endl;

            cout << "| " << setw(20) << left << produto->nome;
            cout << "| " << setw(20) << left << quantidade_vendida;
            cout << "| " << setw(20) << left << "€" << valor_venda * quantidade_vendida;
            cout << "| " << setw(20) << left << "€" << total_lucro;
            cout << "|" << endl;

            cout << "----------------------------------------------" << endl;
        } else {
            cout << "Quantidade insuficiente de " << produto->nome << " em estoque." << endl;
        }
    } else {
        cout << "Produto não encontrado." << endl;
    }
}

// Função para calcular a quantidade a comprar e imprimir em formato de tabela
void calcularQuantidadeComprar(vector<Produto>& produtos) {
    // Imprimindo cabeçalho da tabela
    cout << "---------------------------------------------" << endl;
    cout << "| " << setw(20) << left << "Nome do Produto";
    cout << "| " << setw(30) << left << "Quantidade a comprar";
    cout << "|" << endl;
    cout << "---------------------------------------------" << endl;

    // Iterando sobre os produtos e imprimindo as quantidades recomendadas em tabela
    for (auto& produto : produtos) {
        int quantidade_minima = 300; // Defina a quantidade mínima desejada aqui
        int quantidade_recomendada = quantidade_minima - produto.quantidade;
        cout << "| " << setw(20) << left << produto.nome;
        cout << "| " << setw(30) << left << quantidade_recomendada;
        cout << "|" << endl;
    }
    cout << "---------------------------------------------" << endl;
}

// Função para imprimir as informações dos produtos em formato de tabela
void imprimirInformacoes(vector<Produto>& produtos) {
    cout << "--------------------------------------------------------" << endl;
    cout << "| Nome\t\t| Quantidade em estoque\t| Preço em euro\t|" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (auto& produto : produtos) {
        double preco_em_euro = produto.preco_compra * taxa_conversao;
        double custo_total = produto.quantidade * preco_em_euro;
        cout << "| " << produto.nome << "\t\t| " << produto.quantidade << "\t\t\t| €" << preco_em_euro << "\t\t|" << endl;
        cout << "| \t\t| \t\t\t| Custo total: €" << custo_total << "\t\t|" << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}

// Função para finalizar uma compra e imprimir os detalhes em formato de tabela
void finalizarCompra(Produto* produto, int quantidade_vendida, double valor_pago) {
    cout << "--------------------------------------" << endl;
    cout << "| " << setw(20) << left << "Descrição";
    cout << "| " << setw(20) << left << "Quantidade";
    cout << "| " << setw(20) << left << "Preço unitário";
    cout << "| " << setw(20) << left << "Valor total";
    cout << "| " << setw(20) << left << "Troco";
    cout << "|" << endl;
    cout << "--------------------------------------" << endl;

    if (produto != nullptr) {
        double lucro = (produto->lucro_porcentagem / 100) * produto->preco_compra * taxa_conversao;
        double valor_venda_unitario = produto->preco_compra * taxa_conversao + lucro;
        double valor_total = valor_venda_unitario * quantidade_vendida;

        if (valor_pago >= valor_total) {
            double troco = valor_pago - valor_total;
            cout << "| " << setw(20) << left << produto->nome;
            cout << "| " << setw(20) << left << quantidade_vendida;
            cout << "| " << setw(20) << left << "€" << valor_venda_unitario;
            cout << "| " << setw(20) << left << "€" << valor_total;
            cout << "| " << setw(20) << left << "€" << troco;
            cout << "|" << endl;

            cout << "--------------------------------------" << endl;
            cout << "Compra finalizada!" << endl;
        } else {
            cout << "| " << setw(20) << left << produto->nome;
            cout << "| " << setw(20) << left << quantidade_vendida;
            cout << "| " << setw(20) << left << "€" << valor_venda_unitario;
            cout << "| " << setw(20) << left << "€" << valor_total;
            cout << "| " << setw(20) << left << "Valor insuficiente";
            cout << "|" << endl;

            cout << "--------------------------------------" << endl;
        }
    } else {
        cout << "| " << setw(20) << left << "Produto não encontrado";
        cout << "|" << setw(19) << left << "";
        cout << "|" << setw(19) << left << "";
        cout << "|" << setw(19) << left << "";
        cout << "|" << setw(19) << left << "";
        cout << "|" << endl;

        cout << "--------------------------------------" << endl;
    }
}

// Função para imprimir a tabela de produtos
void imprimirTabelaProdutos(const vector<Produto>& produtos) {
    // Imprimir cabeçalho da tabela
    cout << "Produto       | Preço de Compra (em Euro) | Lucro (%) | Quantidade em Estoque" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    // Imprimir os dados de cada produto
    for (const auto& produto : produtos) {
        cout << produto.nome << "   | " << produto.preco_compra << "                       | " << produto.lucro_porcentagem << "       | " << produto.quantidade << endl;
    }
}

// Função para imprimir o lucro total de todos os produtos
void imprimirLucroTotal(vector<Produto>& produtos) {
    cout << "--------------------------------------" << endl;
    cout << "| " << setw(20) << left << "Nome";
    cout << "| " << setw(20) << left << "Lucro Total (em euro)";
    cout << "|" << endl;
    cout << "--------------------------------------" << endl;

    for (auto& produto : produtos) {
        double lucro = (produto.lucro_porcentagem / 100) * produto.preco_compra * taxa_conversao * produto.quantidade;
        cout << "| " << setw(20) << left << produto.nome;
        cout << "| " << setw(20) << left << "€" << lucro;
        cout << "|" << endl;
    }

    cout << "--------------------------------------" << endl;
}

// Função principal
int main() {
    // Criando alguns produtos para teste
    vector<Produto> produtos = {{"caneta", 1.0, 25.0, 150}, {"caderno", 2.0, 30.0, 100}, {"pasta", 3.0, 20.0, 80}, {"lápis", 1.0, 15.0, 250}};
    int opcao;
    do {
         // Imprimir cabeçalho da tabela
    cout << "Produto       | Preço de Compra (em Euro) | Lucro (%) | Quantidade em Estoque" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    // Imprimir os dados de cada produto
    cout << "Caneta        | 1.00                       | 25.0      | 150" << endl;
    cout << "Caderno       | 2.00                       | 30.0      | 100" << endl;
    cout << "Pasta         | 3.00                       | 20.0      | 80" << endl;
    cout << "Lápis         | 1.00                       | 15.0      | 250" << endl;
        // Imprimir menu
        cout << "-------------------------------------------------------------" << endl;
        cout << "|   1   |   Vender produto                                    |" << endl;
        cout << "|   2   |   Imprimir quantidade em estoque de todos os produtos (em euro) |" << endl;
        cout << "|   3   |   Imprimir lucro total da venda de todos os produtos (em euro) |" << endl;
        cout << "|   4   |   Calcular quantidade a comprar                     |" << endl;
        cout << "|   5   |   Metodo de pagamento do Produto                    |" << endl;
        cout << "|   6   |   Sair do programa                                  |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        // Executar a opção escolhida
        switch (opcao) {
            case 1: {
                // Vender produto
                string nome_produto;
                int quantidade_vendida;
                cout << "Nome do produto a ser vendido: ";
                cin >> nome_produto;
                Produto* produto = buscarProduto(produtos, nome_produto);
                if (produto != nullptr) {
                    cout << "Quantidade a ser vendida: ";
                    cin >> quantidade_vendida;
                    imprimirVendaProduto(produto, quantidade_vendida);
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            }
            case 2: {
                // Imprimir quantidade em estoque de todos os produtos
                imprimirInformacoes(produtos);
                break;
            }
            case 3: {
                // Imprimir lucro total da venda de todos os produtos
                imprimirLucroTotal(produtos);
                break;
            }
            case 4: {
                // Calcular quantidade a comprar
                calcularQuantidadeComprar(produtos);
                break;
            }
            case 5: {
                // Metodo de pagamento do Produto
                string nome_produto;
                int quantidade_vendida;
                double valor_pago;
                cout << "Nome do produto a ser vendido: ";
                cin >> nome_produto;
                Produto* produto = buscarProduto(produtos, nome_produto);
                if (produto != nullptr) {
                    cout << "Quantidade a ser vendida: ";
                    cin >> quantidade_vendida;
                    cout << "Valor pago: €";
                    cin >> valor_pago;
                    finalizarCompra(produto, quantidade_vendida, valor_pago);
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            }
            case 6: {
                // Sair do programa
                cout << "Saindo do programa..." << endl;
                break;
            }
            default: {
                cout << "Opção inválida. Por favor, tente novamente." << endl;
            }
        }
    } while (opcao != 6);

    return 0;
}