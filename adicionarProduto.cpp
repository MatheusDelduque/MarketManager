#include "adicionarProduto.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

// Metodo que executa a adicao de um novo produto
void AdicionarProduto::execute(sql::Connection *con)
{
    std::string nome;
    double preco;
    int quantidade;
    std::cout << std::endl;
    std::cout << "Digite o nome do produto: ";
    std::cin >> nome;
    std::cout << "Digite o preco do produto: ";
    std::cin >> preco;
    std::cout << "Digite a quantidade do produto: ";
    std::cin >> quantidade;

    // Verifica se ja existe um produto com o mesmo nome
    sql::PreparedStatement *pstmt_check = con->prepareStatement("SELECT COUNT(*) FROM produtos WHERE nome = ?");

    // Define o parâmetro da declaracao preparada
    pstmt_check->setString(1, nome);

    // Executa a declaracao preparada
    sql::ResultSet *res_check = pstmt_check->executeQuery();

    // Verifica se o nome existe
    res_check->next();
    int count = res_check->getInt(1);

    if (count > 0)
    {
        std::cout << std::endl;
        std::cout << "Ja existe um produto com esse nome." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        // Prepara a declaracao SQL para inserir um novo produto na tabela
        sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO produtos (nome, preco, quantidade) VALUES (?, ?, ?)");

        // Define os parametros da declaracao preparada
        pstmt->setString(1, nome);
        pstmt->setDouble(2, preco);
        pstmt->setInt(3, quantidade);

        // Executa a declaracao preparada
        pstmt->executeUpdate();

        // Libera a memoria alocada para a declaracao preparada
        delete pstmt;

        // Exibe uma mensagem de sucesso
        std::cout << std::endl;
        std::cout << "Produto adicionado com sucesso!" << std::endl;
        std::cout << std::endl;
    }
    // Libera a memoria alocada para a verificacao de duplicidade
    delete res_check;
    delete pstmt_check;
}
