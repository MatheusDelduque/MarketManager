#ifndef BUSCARPRODUTOPORNOME_H
#define BUSCARPRODUTOPORNOME_H

#include "iDataBaseOperation.h"

class BuscarProdutoPorNome : public IDataBaseOperation {
public:
    void execute(sql::Connection* con) override;
};

#endif // BUSCARPRODUTOPORNOME_H
