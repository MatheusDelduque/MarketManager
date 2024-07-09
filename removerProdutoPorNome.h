#ifndef REMOVERPRODUTOPORNOME_H
#define REMOVERPRODUTOPORNOME_H

#include "iDataBaseOperation.h"

class RemoverProdutoPorNome : public IDataBaseOperation
{
public:
    void execute(sql::Connection *con) override;
};

#endif // REMOVERPRODUTOPORNOME_H
