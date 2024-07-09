#include "exibirEstatisticas.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

void ExibirEstatisticas::execute(sql::Connection *con)
{
    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(*), SUM(preco), AVG(preco) FROM produtos");
    sql::ResultSet *res = pstmt->executeQuery();
    if (res->next())
    {
        std::cout << "Número total de produtos: " << res->getInt(1) << std::endl;
        std::cout << "Valor total em estoque: " << res->getDouble(2) << std::endl;
        std::cout << "Preço médio dos produtos: " << res->getDouble(3) << std::endl;
    }
    delete res;
    delete pstmt;
}
