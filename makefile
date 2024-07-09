CC = g++
CFLAGS = -Wall -I/usr/include/cppconn
LDFLAGS = -L/usr/lib -lmysqlcppconn

SRCS = main.cpp adicionarProduto.cpp buscarProdutoPorNome.cpp exibirEstatisticas.cpp listarProdutos.cpp removerProdutoPorNome.cpp
OBJ_DIR = compilados
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

TARGET = dados

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o ./executaveis/$(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o ./executaveis/$(TARGET)