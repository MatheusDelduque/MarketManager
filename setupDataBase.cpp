#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <iostream>

int main() {
    try {
        // Conectar ao MySQL
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "Password123");

        // Criar um objeto de declaracao
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Criar banco de dados
        stmt->execute("CREATE DATABASE IF NOT EXISTS mercado");

        // Usar o banco de dados criado
        stmt->execute("USE mercado");

        // Criar tabela de produtos
        stmt->execute("CREATE TABLE IF NOT EXISTS produtos ("
                      "id INT AUTO_INCREMENT PRIMARY KEY, "
                      "nome VARCHAR(255) NOT NULL, "
                      "preco DECIMAL(10, 2) NOT NULL, "
                      "quantidade INT NOT NULL)");

        std::cout << "Banco de dados e tabela criados com sucesso!" << std::endl;

        // Fechar a conexao
        con->close();
    } catch (sql::SQLException& e) {
        std::cerr << "Erro de SQL: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
