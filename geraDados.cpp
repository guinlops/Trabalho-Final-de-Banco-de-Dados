#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::string geraCPF() {
    // Gera CPF aleatório
    return "0" +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10) +
        std::to_string(rand() % 10);
}

std::string geraNomeAleatorio() {
    // Lista de nomes predefinidos
    std::vector<std::string> nomes = {"João", "Maria", "Pedro", "Ana", "Carlos", "Juliana", "Lucas", "Fernanda", "Rafael", "Camila"};

    // Gera um índice aleatório para selecionar um nome da lista
    int indice = rand() % nomes.size();

    return nomes[indice];
}

std::string geraSobrenomeAleatorio() {
    // Lista de sobrenomes predefinidos
    std::vector<std::string> sobrenomes = {"Silva", "Oliveira", "Pereira", "Lima", "Santos", "Costa", "Rodrigues", "Almeida", "Nascimento", "Ferreira"};

    // Gera um índice aleatório para selecionar um sobrenome da lista
    int indice = rand() % sobrenomes.size();

    return sobrenomes[indice];
}

std::string geraDataAleatoria() {
    // Gera uma data aleatória entre 2000-01-01 e 2023-12-31
    int ano = 2000 + rand() % 24;
    int mes = 1 + rand() % 12;
    int dia = 1 + rand() % 28; // Limitando a 28 para simplificar, considerando todos os meses
    
    return std::to_string(ano) + "-" +
           (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
           (dia < 10 ? "0" : "") + std::to_string(dia);
}

std::string geraNumeroConta() {
    // Gera um número de conta aleatório de 8 dígitos
    return std::to_string(10000000 + rand() % 90000000);
}

std::string geraCepAleatorio() {
    // Gera um CEP aleatório
    return std::to_string(10000 + rand() % 90000) + "-" + std::to_string(100 + rand() % 900);
}

std::string geraRuaAleatoria() {
    // Lista de ruas fictícias
    std::vector<std::string> ruas = {"Rua A", "Rua B", "Rua C", "Rua D", "Rua E", "Rua F", "Rua G", "Rua H", "Rua I", "Rua J"};

    // Gera um índice aleatório para selecionar uma rua da lista
    int indice = rand() % ruas.size();

    return ruas[indice];
}

std::string geraNumCartaoDebitoAleatorio() {
    // Gera um número de cartão de débito fictício
    return "1234" + std::to_string(rand() % 1000) + std::to_string(rand() % 1000) + std::to_string(rand() % 1000);
}

std::string geraDataEmissaoAleatoria() {
    // Gera uma data de emissão aleatória
    return "2022-" + std::to_string(1 + rand() % 12) + "-" + std::to_string(1 + rand() % 28);
}

std::string geraDataValidadeAleatoria() {
    // Gera uma data de validade aleatória após a data de emissão
    int ano = 2023 + rand() % 7;
    int mes = 1 + rand() % 12;
    int dia = 1 + rand() % 28; // Limitando a 28 para simplificar, considerando todos os meses
    
    return std::to_string(ano) + "-" +
           (mes < 10 ? "0" : "") + std::to_string(mes) + "-" +
           (dia < 10 ? "0" : "") + std::to_string(dia);
}

std::string geraSaldoAleatorio() {
    // Gera um saldo aleatório entre 0 e 1000 com duas casas decimais
    double saldo = static_cast<double>(rand() % 100000) / 100.0;
    return std::to_string(saldo);
}

std::string geraStatusAleatorio() {
    // Gera um status aleatório (true ou false)
    return rand() % 2 == 0 ? "true" : "false";
}

int geraCodSegurancaAleatorio() {
    // Gera um código de segurança aleatório de três dígitos
    return rand() % 1000;
}

int main() {
    // Inicializa a semente para geração de números aleatórios
    srand(static_cast<unsigned>(time(0)));

    // Gera dados aleatórios
    std::string cpf = geraCPF();
    std::string p_nome = geraNomeAleatorio();
    std::string u_nome = geraSobrenomeAleatorio();
    std::string cep = geraCepAleatorio();
    int numero = 42;
    std::string rua = geraRuaAleatoria();

    std::string numConta = geraNumeroConta();
    std::string dataAbertura = geraDataAleatoria();
    std::string saldo = geraSaldoAleatorio();

    std::string status = geraStatusAleatorio();
    std::string numCartaoDebito = geraNumCartaoDebitoAleatorio();
    std::string dataValidade = geraDataValidadeAleatoria();
    std::string dataEmissao = geraDataEmissaoAleatoria();
    std::string nomeNoCartao = p_nome + " " + u_nome;
    int codSeguranca = geraCodSegurancaAleatorio();

    double salario = 1000.00;
    std::string dataInicio = geraDataAleatoria();

    std::string numAgencia = "00001";
    std::string cepAgencia = geraCepAleatorio();
    std::string ruaAgencia = geraRuaAleatoria();
    int numeroAgencia = 54;
    int idGerente = 1;

    // Gera comandos SQL
    std::cout << "INSERT INTO PESSOA (CPF, P_NOME, U_NOME, CEP, NUMERO, RUA) VALUES ('" << cpf << "', '" << p_nome << "', '" << u_nome << "', '" << cep << "', " << numero << ", '" << rua << "');\n";
    std::cout << "INSERT INTO CLIENTE (CPF) VALUES ('" << cpf << "');\n";
    std::cout << "INSERT INTO CONTA_POUPANCA (NUM_CONTA_P, DATA_ABERTURA, SALDO, CPF_CLIENTE) VALUES ('" << numConta << "', '" << dataAbertura << "', '" << saldo << "', '" << cpf << "');\n";
    std::cout << "INSERT INTO CARTOES_DE_DEBITO (NUM_CONTA_P, STATUS, NUM_CARTAO_D, DATA_VALIDADE, DATA_EMISSAO, NOME_NO_CARTAO, COD_SEGURANCA) VALUES ('" << numConta << "', " << status << ", '" << numCartaoDebito << "', '" << dataValidade << "', '" << dataEmissao << "', '" << nomeNoCartao << "', " << codSeguranca << ");\n";
    std::cout << "INSERT INTO FUNCIONARIOS (SALARIO, DATA_INICIO, CPF) VALUES ('" << salario << "', '" << dataInicio << "', '" << cpf << "');\n";
    std::cout << "INSERT INTO AGENCIAS (NUMERO_AGENCIA, CEP, RUA, NUMERO, ID_GERENTE) VALUES ('" << numAgencia << "', '" << cepAgencia << "', '" << ruaAgencia << "', " << numeroAgencia << ", " << idGerente << ");\n";
    std::cout << "UPDATE FUNCIONARIOS SET AGENCIA = '" << numAgencia << "' WHERE CPF = '" << cpf << "';\n";

    return 0;
}