#include "listarProdutos.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

void ListarProdutos::execute(sql::Connection *con)
{
    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM produtos");
    sql::ResultSet *res = pstmt->executeQuery();
    while (res->next())
    {
        std::cout << "ID: " << res->getInt("id") << ", Nome: " << res->getString("nome")
                  << ", Preço: " << res->getDouble("preco") << std::endl;
    }
    delete res;
    delete pstmt;
}
