#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Produto {
    string nome;
    double preco_compra;
    double lucro_porcentagem;
    int quantidade;
};

const double taxa_conversao = 0.15; // Taxa de conversão de real para euro

Produto* buscarProduto(vector<Produto>& produtos, string nome_produto) {
    for (auto& produto : produtos) {
        if (produto.nome == nome_produto) {
            return &produto;
        }
    }
    return nullptr;
}

void venderProduto(Produto* produto, int quantidade_vendida) {
    if (produto != nullptr) {
        if (produto->quantidade >= quantidade_vendida) {
            double lucro = (produto->lucro_porcentagem / 10) * produto->preco_compra * taxa_conversao;
            double valor_venda = produto->preco_compra * taxa_conversao + lucro;
            double total_lucro = (valor_venda - produto->preco_compra * taxa_conversao) * quantidade_vendida;
            produto->quantidade -= quantidade_vendida;
            cout << "Lucro total da venda de " << produto->nome << ": €" << total_lucro << endl;
            cout << "Quantidade vendida: " << quantidade_vendida << ", Valor de venda unitário: €" << valor_venda << endl;
        } else {
            cout << "Quantidade insuficiente de " << produto->nome << " em estoque." << endl;
        }
    } else {
        cout << "Produto não encontrado." << endl;
    }
}
void calcularQuantidadeComprar(vector<Produto>& produtos) {
    for (auto& produto : produtos) {
        int quantidade_minima = 300; // Defina a quantidade mínima desejada aqui
        int quantidade_recomendada = quantidade_minima - produto.quantidade;
        if (quantidade_recomendada > 0) {
            cout << "Produto: " << produto.nome << ", Quantidade a comprar: " << quantidade_recomendada << endl;
        } else {
            cout << "Produto: " << produto.nome << ", Estoque suficiente" << endl;
        }
    }
}


void imprimirInformacoes(vector<Produto>& produtos) {
    for (auto& produto : produtos) {
        double preco_em_euro = produto.preco_compra * taxa_conversao;
        cout << "Nome: " << produto.nome << ", Quantidade em estoque: " << produto.quantidade << ", Preço em euro: €" << preco_em_euro << endl;
    }
}
void finalizarCompra(Produto* produto, int quantidade_vendida, double valor_pago) {
    if (produto != nullptr) {
        double lucro = (produto->lucro_porcentagem / 100) * produto->preco_compra * taxa_conversao;
        double valor_venda_unitario = produto->preco_compra * taxa_conversao + lucro;
        double valor_total = valor_venda_unitario * quantidade_vendida;
        if (valor_pago >= valor_total) {
            double troco = valor_pago - valor_total;
            cout << "Compra finalizada!" << endl;
            cout << "Valor total da compra: €" << valor_total << endl;
            cout << "Valor pago: €" << valor_pago << endl;
            cout << "Troco a entregar: €" << troco << endl;
        } else {
            cout << "Valor insuficiente para realizar a compra." << endl;
        }
    } else {
        cout << "Produto não encontrado." << endl;
    }
}


double calcularLucroTotal(vector<Produto>& produtos) {
    double lucro_total = 0;
    for (auto& produto : produtos) {
        double lucro = (produto.lucro_porcentagem / 100) * produto.preco_compra * taxa_conversao * produto.quantidade;
        lucro_total += lucro;
    }
    return lucro_total;
}

int main() {
    vector<Produto> produtos = {{"caneta", 1.0, 25.0, 150}, {"caderno", 2.0, 30.0, 100}, {"pasta", 3.0, 20.0, 80}, {"lápis", 1.0, 15.0, 250}};
    int opcao;
    do {
       cout << "1. Vender produto" << endl;
        cout << "2. Imprimir quantidade em estoque de todos os produtos (em euro)" << endl;
        cout << "3. Imprimir lucro total da venda de todos os produtos (em euro)" << endl;
        cout << "4. Calcular quantidade a comprar" << endl;
        cout << "5.  Metodo de pagamento do Produto " <<endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        switch (opcao) {
            case 1: {
                string nome_produto;
                int quantidade_vendida;
                cout << "Nome do produto a ser vendido: ";
                cin >> nome_produto;
                Produto* produto = buscarProduto(produtos, nome_produto);
                if (produto != nullptr) {
                    cout << "Quantidade a ser vendida: ";
                    cin >> quantidade_vendida;
                    if (produto->quantidade >= quantidade_vendida) {
                        venderProduto(produto, quantidade_vendida);
                        double valor_total = (produto->preco_compra * taxa_conversao + (produto->lucro_porcentagem / 100) * produto->preco_compra * taxa_conversao) * quantidade_vendida;
                        cout << "Valor total: €" << valor_total << endl;
                    } else {
                        cout << "Quantidade insuficiente em estoque." << endl;
                    }
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            }
            case 2: {
                imprimirInformacoes(produtos);
                break;
            }
            case 3: {
                double lucro_total = calcularLucroTotal(produtos);
                cout << "Lucro total da venda de todos os produtos: €" << lucro_total << endl;
                break;
            }
              case 4: {
                calcularQuantidadeComprar(produtos);
                break;
            }
            case 5: {
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

            
            default: {
                cout << "Opção inválida. Por favor, tente novamente." << endl;
            }
        }
    } while (opcao != 6);

    return 0;
}