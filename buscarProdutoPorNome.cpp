#include "buscarProdutoPorNome.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

// Metodo que executa a busca de produtos por nome
void BuscarProdutoPorNome::execute(sql::Connection *con)
{
    std::string nome;
    std::cout << std::endl;
    std::cout << "Digite o nome do produto: ";
    std::cin >> nome;

    // Prepara a declaracao SQL para buscar produtos pelo nome
    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM produtos WHERE nome LIKE ?");

    // Define o parametro da declaracao preparada
    pstmt->setString(1, "%" + nome + "%");

    // Executa a consulta e obtem o resultado
    sql::ResultSet *res = pstmt->executeQuery();

    // Verifica se algum produto foi encontrado
    if (!res->next())
    {
        std::cout << std::endl;
        std::cout << "Nenhum produto encontrado com o nome especificado." << std::endl;
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
