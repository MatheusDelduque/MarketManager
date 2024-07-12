#ifndef IDATABASEOPERATION_H
#define IDATABASEOPERATION_H

#include <cppconn/connection.h>

// Interface para operacoes com o banco de dados
class IDataBaseOperation
{
public:
    // Construtor e destrutor
    virtual ~IDataBaseOperation() {}

    // Executa a operacao no banco de dados
    virtual void execute(sql::Connection *con) = 0;
};

#endif
