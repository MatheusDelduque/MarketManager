CC = g++
CFLAGS = -Wall -I/usr/include/cppconn
LDFLAGS = -L/usr/lib -lmysqlcppconn

# Fontes e objetos para o programa principal
MAIN_SRCS = main.cpp adicionarProduto.cpp buscarProdutoPorNome.cpp exibirEstatisticas.cpp listarProdutos.cpp removerProdutoPorNome.cpp listarProdutosPorPreco.cpp 
MAIN_OBJS = $(addprefix $(OBJ_DIR)/, $(MAIN_SRCS:.cpp=.o)) 

# Fonte e objeto para setup_database
SETUP_SRC = setupDataBase.cpp
SETUP_OBJ = $(OBJ_DIR)/setupDataBase.o

# Diretórios
OBJ_DIR = compilados
EXEC_DIR = executaveis

# Alvos
TARGET = dados
SETUP_TARGET = setupDataBase

all: $(EXEC_DIR)/$(TARGET) $(EXEC_DIR)/$(SETUP_TARGET)

# Compilar o programa principal
$(EXEC_DIR)/$(TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compilar setup_database
$(EXEC_DIR)/$(SETUP_TARGET): $(SETUP_OBJ)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Compilar objetos
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC_DIR)/$(TARGET) $(EXEC_DIR)/$(SETUP_TARGET)
