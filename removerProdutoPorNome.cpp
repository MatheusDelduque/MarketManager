#include "removerProdutoPorNome.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

// Metodo que executa a remocao de produtos por nome
void RemoverProdutoPorNome::execute(sql::Connection *con)
{
    std::string nome;
    std::cout << std::endl;
    std::cout << "Digite o nome do produto a ser removido: ";
    std::cin >> nome;

    // Verifica se existe um produto com o nome especificado
    sql::PreparedStatement *pstmt_check = con->prepareStatement("SELECT COUNT(*) FROM produtos WHERE nome = ?");

    // Define o parametro da declaracao preparada
    pstmt_check->setString(1, nome);

    // Executa a declaracao preparada
    sql::ResultSet *res_check = pstmt_check->executeQuery();

    // Verifica se o nome existe
    res_check->next();
    int count = res_check->getInt(1);

    if (count == 0)
    {
        std::cout << std::endl;
        std::cout << "Nao existe nenhum produto com esse nome." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        // Prepara a declaracao SQL para remover o produto pelo nome
        sql::PreparedStatement *pstmt = con->prepareStatement("DELETE FROM produtos WHERE nome = ?");

        // Define o parâmetro da declaracao preparada
        pstmt->setString(1, nome);

        // Executa a declaracao preparada
        pstmt->executeUpdate();

        // Libera a memoria alocada para a declaracao preparada
        delete pstmt;

        // Exibe uma mensagem de sucesso
        std::cout << std::endl;
        std::cout << "Produto removido com sucesso!" << std::endl;
        std::cout << std::endl;
    }

    // Libera a memoria alocada para a verificacao de existencia
    delete res_check;
    delete pstmt_check;
}
