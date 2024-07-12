#include "exibirEstatisticas.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

// Metodo que executa a exibicao de estatisticas dos produtos
void ExibirEstatisticas::execute(sql::Connection *con)
{

    // Prepara a consulta SQL para obter estatisticas dos produtos
    sql::PreparedStatement *pstmt = con->prepareStatement(
        "SELECT COUNT(*), SUM(preco * quantidade), AVG(preco), SUM(quantidade) FROM produtos");

    // Executa a consulta e obtem o resultado
    sql::ResultSet *res = pstmt->executeQuery();

    // Imprime as estatisticas
    if (res->next())
    {
        std::cout << std::endl;
        std::cout << "Numero total de produtos: " << res->getInt(1) << std::endl;
        std::cout << "Valor total em estoque: " << res->getDouble(2) << std::endl;
        std::cout << "Preco medio dos produtos: " << res->getDouble(3) << std::endl;
        std::cout << "Quantidade total em estoque: " << res->getInt(4) << std::endl;
        std::cout << std::endl;
    }

    // Libera a memoria alocada para o resultado e a declaracao preparada
    delete res;
    delete pstmt;
}
