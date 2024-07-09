#ifndef IDATABASEOPERATION_H
#define IDATABASEOPERATION_H

#include <cppconn/connection.h>

class IDataBaseOperation {
public:
    virtual ~IDataBaseOperation() {}
    virtual void execute(sql::Connection* con) = 0;
};

#endif // IDATABASEOPERATION_H
