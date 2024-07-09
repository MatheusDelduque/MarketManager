#ifndef LISTARPRODUTOS_H
#define LISTARPRODUTOS_H

#include "iDataBaseOperation.h"

class ListarProdutos : public IDataBaseOperation {
public:
    void execute(sql::Connection* con) override;
};

#endif // LISTARPRODUTOS_H
