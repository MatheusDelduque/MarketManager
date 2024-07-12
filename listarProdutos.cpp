#include "listarProdutos.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

// Metodo que executa a listagem de produtos
void ListarProdutos::execute(sql::Connection *con)
{
    // Prepara a consulta SQL para selecionar todos os produtos
    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM produtos");
    // Executa a consulta e obtem o resultado
    sql::ResultSet *res = pstmt->executeQuery();

    // Verifica se a tabela de produtos esta vazia
    if (!res->next())
    {
        std::cout << "A tabela de produtos esta vazia." << std::endl;
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
