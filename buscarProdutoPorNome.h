#ifndef BUSCARPRODUTOPORNOME_H
#define BUSCARPRODUTOPORNOME_H

#include "iDataBaseOperation.h"

// Classe para buscar um produto pelo nome, implementando a interface IDatabaseOperation
class BuscarProdutoPorNome : public IDataBaseOperation
{
public:
    // Metodo que executa a busca de produtos por nome
    void execute(sql::Connection *con) override;
};

#endif
