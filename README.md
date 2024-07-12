# Programa de Gerenciamento de Atletas

Este programa em C++ apresenta o gerenciamento de produtos utilizando o banco de dados MySQL.

## Instalacao Banco de Dados MySQL

**Instalar o MySQL** - **Linux (Ubuntu/Debian)**:

```bash
sudo apt update
sudo apt install mysql-server
sudo systemctl start mysql
sudo systemctl enable mysql
```

2. **Configurar MySQL**
   - Após a instalação, você pode configurar a senha do usuário root:
     ```bash
     sudo mysql_secure_installation
     ```
   - Conecte-se ao MySQL:
     ```bash
     mysql -u root -p
     ```
   - Crie um usuário e um banco de dados para o programa:
     ```sql
     CREATE DATABASE mercado;
     CREATE USER 'usuario'@'localhost' IDENTIFIED BY 'NovaSenha123!';
     GRANT ALL PRIVILEGES ON mercado.* TO 'usuario'@'localhost';
     FLUSH PRIVILEGES;
     ```

## Compilacao

Para compilar o programa, siga os passos abaixo:

1. Certifique-se de ter um compilador C++ instalado no seu sistema.
2. Abra um terminal e navegue ate o diretorio onde se encontra o codigo fonte do programa.
3. Utilize o comando `make` para compilar o programa utilizando o Makefile fornecido.

## Utilização

Para utilizar o programa, siga os passos abaixo:

1. Apos compilar o programa com sucesso, execute o script de configuração do banco de dados: `./executaveis/setupDataBase`
2. Em seguida, execute o programa principal: `./executaveis/dados`
3. Um menu sera aberto para escolha da analise desejada
4. Verifique a saida no terminal para visualizar os resultados da analise.

## Ajustes e Personalização

Caso deseje fazer ajustes no programa ou adicionar novas funcionalidades, voce pode editar o codigo fonte e o Makefile conforme necessario. Apos as alterações, repita os passos de compilacao e utilizacao do programa.
