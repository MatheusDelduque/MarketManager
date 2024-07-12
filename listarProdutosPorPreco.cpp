#include "listarProdutosPorPreco.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

// Metodo que executa a listagem de produtos por faixa de preco
void ListarProdutosPorPreco::execute(sql::Connection *con)
{
    double precoMin, precoMax;
    std::cout << std::endl;
    std::cout << "Digite o preço mínimo: ";
    std::cin >> precoMin;
    std::cout << "Digite o preço máximo: ";
    std::cin >> precoMax;

    // Prepara a declaracao SQL para buscar produtos dentro da faixa de preco
    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM produtos WHERE preco BETWEEN ? AND ?");

    // Define os parametros da declaracao preparada
    pstmt->setDouble(1, precoMin);
    pstmt->setDouble(2, precoMax);

    // Executa a consulta e obtem o resultado
    sql::ResultSet *res = pstmt->executeQuery();

    // Verifica se algum produto foi encontrado
    if (!res->next())
    {
        std::cout << std::endl;
        std::cout << "Nao ha produtos dentro da faixa de preco especificada." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        // Imprime os dados dos produtos
        do
        {
            std::cout << std::endl;
            std::cout << "ID: " << res->getInt("id") << ", Nome: " << res->getString("nome")
                      << ", Preco: " << res->getDouble("preco") << ", Quantidade: " << res->getInt("quantidade") << std::endl;
            std::cout << std::endl;
        } while (res->next());
    }

    // Libera a memoria alocada para o resultado e a declaracao preparada
    delete res;
    delete pstmt;
}
