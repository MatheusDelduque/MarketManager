#ifndef LISTARPRODUTOS_H
#define LISTARPRODUTOS_H

#include "iDataBaseOperation.h"

// Classe para listar todos os produtos, implementando a interface IDatabaseOperation
class ListarProdutos : public IDataBaseOperation
{
public:
    // Metodo que executa a listagem de produtos
    void execute(sql::Connection *con) override;
};

#endif
