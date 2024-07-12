#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include "iDataBaseOperation.h"
#include "listarProdutos.h"
#include "adicionarProduto.h"
#include "buscarProdutoPorNome.h"
#include "listarProdutosPorPreco.h"
#include "exibirEstatisticas.h"
#include "removerProdutoPorNome.h"

int main()
{
    try
    {
        // Conectar ao MySQL
        sql::Driver *driver = get_driver_instance();
        sql::Connection *con = driver->connect("tcp://127.0.0.1:3306", "usuario", "NovaSenha123!");

        // Seleciona o banco de dados "mercado"
        con->setSchema("mercado");

        int opcao;
        do
        {
            std::cout << "Menu:\n";
            std::cout << "1. Listar todos os produtos\n";
            std::cout << "2. Adicionar um novo produto\n";
            std::cout << "3. Buscar um produto por nome\n";
            std::cout << "5. Exibir estatisticas do inventario\n";
            std::cout << "6. Remover produtos por nome\n";
            std::cout << "7. Listar produtos por faixa de preco\n";
            std::cout << "0. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;

            // Ponteiro para operacao de banco de dados
            IDataBaseOperation *operation = nullptr;

            switch (opcao)
            {
            case 1:
                operation = new ListarProdutos();
                break;
            case 2:
                operation = new AdicionarProduto();
                break;
            case 3:
                operation = new BuscarProdutoPorNome();
                break;
            case 5:
                operation = new ExibirEstatisticas();
                break;
            case 6:
                operation = new RemoverProdutoPorNome();
                break;
            case 7:
                operation = new ListarProdutosPorPreco();
                break;
            case 0:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
            }

            if (operation)
            {
                operation->execute(con);
                delete operation;
            }

        } while (opcao != 0);

        // Fecha a conexao com o banco de dados
        delete con;
    }
    catch (sql::SQLException &e)
    {
        // Captura e exibe qualquer erro SQL que ocorrer durante a execucao
        std::cerr << "Erro de SQL: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}