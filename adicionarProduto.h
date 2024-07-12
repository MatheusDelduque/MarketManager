#ifndef ADICIONARPRODUTO_H
#define ADICIONARPRODUTO_H

#include "iDataBaseOperation.h"

// Classe para adicionar um novo produto, implementando a interface IDatabaseOperation
class AdicionarProduto : public IDataBaseOperation
{
public:
    // Metodo que executa a adicao de um novo produto
    void execute(sql::Connection *con) override;
};

#endif
