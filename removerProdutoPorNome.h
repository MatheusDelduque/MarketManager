#ifndef REMOVERPRODUTOPORNOME_H
#define REMOVERPRODUTOPORNOME_H

#include "iDataBaseOperation.h"

// Classe para remover produtos por nome, implementando a interface IDatabaseOperation
class RemoverProdutoPorNome : public IDataBaseOperation
{
public:
    // Metodo que executa a remocao de um produto pelo nome
    void execute(sql::Connection *con) override;
};

#endif
