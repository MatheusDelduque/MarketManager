#include "buscarProdutoPorNome.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

void BuscarProdutoPorNome::execute(sql::Connection *con)
{
    std::string nome;
    std::cout << "Digite o nome do produto: ";
    std::cin >> nome;

    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM produtos WHERE nome LIKE ?");
    pstmt->setString(1, "%" + nome + "%");
    sql::ResultSet *res = pstmt->executeQuery();
    while (res->next())
    {
        std::cout << "ID: " << res->getInt("id") << ", Nome: " << res->getString("nome")
                  << ", Preço: " << res->getDouble("preco") << std::endl;
    }
    delete res;
    delete pstmt;
}
