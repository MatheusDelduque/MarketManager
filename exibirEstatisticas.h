#ifndef EXIBIRESTATISTICAS_H
#define EXIBIRESTATISTICAS_H

#include "iDataBaseOperation.h"

class ExibirEstatisticas : public IDataBaseOperation {
public:
    void execute(sql::Connection* con) override;
};

#endif // EXIBIRESTATISTICAS_H
