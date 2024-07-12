#ifndef EXIBIRESTATISTICAS_H
#define EXIBIRESTATISTICAS_H

#include "iDataBaseOperation.h"

// Classe para exibir estatisticas dos produtos, implementando a interface IDatabaseOperation
class ExibirEstatisticas : public IDataBaseOperation
{
public:
    // Metodo que executa a exibicao de estatisticas
    void execute(sql::Connection *con) override;
};

#endif 
