#include "adicionarProduto.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

void AdicionarProduto::execute(sql::Connection *con)
{
    std::string nome;
    double preco;
    std::cout << "Digite o nome do produto: ";
    std::cin >> nome;
    std::cout << "Digite o preço do produto: ";
    std::cin >> preco;

    sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO produtos (nome, preco) VALUES (?, ?)");
    pstmt->setString(1, nome);
    pstmt->setDouble(2, preco);
    pstmt->executeUpdate();
    delete pstmt;

    std::cout << "Produto adicionado com sucesso!" << std::endl;
}
