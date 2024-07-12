#ifndef LISTARPRODUTOSPORMEDICOPRECO_H
#define LISTARPRODUTOSPORMEDICOPRECO_H

#include "iDataBaseOperation.h"

// Classe para listar produtos por faixa de preco, implementando a interface IDatabaseOperation
class ListarProdutosPorPreco : public IDataBaseOperation
{
public:
    // Metodo que executa a listagem de produtos por faixa de preco
    void execute(sql::Connection *con) override;
};

#endif
