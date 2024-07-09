#ifndef ADICIONARPRODUTO_H
#define ADICIONARPRODUTO_H

#include "iDataBaseOperation.h"

class AdicionarProduto : public IDataBaseOperation {
public:
    void execute(sql::Connection* con) override;
};

#endif // ADICIONARPRODUTO_H
