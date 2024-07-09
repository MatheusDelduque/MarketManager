#include "removerProdutoPorNome.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

void RemoverProdutoPorNome::execute(sql::Connection *con)
{
    std::string nome;
    std::cout << "Digite o nome do produto a ser removido: ";
    std::cin >> nome;

    sql::PreparedStatement *pstmt = con->prepareStatement("DELETE FROM produtos WHERE nome = ?");
    pstmt->setString(1, nome);
    pstmt->executeUpdate();
    delete pstmt;

    std::cout << "Produto removido com sucesso!" << std::endl;
}
