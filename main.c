#include <ctype.h> // Biblioteca para usar funções de caracteres
#include <stdbool.h> // Biblioteca para usar tipos booleanos
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings
#include <stdlib.h> 

#define MAX_HOTEIS 2 // Define a quantidade máxima de hotéis
#define MAX_QUARTOS 3 // Define a quantidade máxima de quartos
#define MAX_NOME 150 // Define o tamanho máximo do nome
#define MAX_CPF 11  // Define o tamanho máximo do CPF
#define TAXA_CANCELAMENTO 0.3  // 30% de taxa de cancelamento

// ESTRUTURA PARA ESCOLHAS DO QUARTO
typedef struct
{
    int numero;
    char tipo[20];
    bool disponivel;
    float preco;
    float desconto;
} Quarto;
// ESTRUTURA HOTEIS
typedef struct
{
    char nomeCliente[MAX_NOME];
    char nome[MAX_NOME];
    Quarto quartos[MAX_QUARTOS];
} Hotel;
// FUNÇÃO PARA LER UMA LINHA DE TEXTO DO USUARIO
void ler_texto(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}
// FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
// VALIDAÇÃO NOME
int validarNome(char nomeCliente[MAX_NOME])
{
    if (strlen(nomeCliente) == 0)
    {
        printf("Nome inválido. Por favor, digite um nome.\n");
        return 0;
    }

    return 1;
}
// VALIDAÇÃO CPF
bool validarCPF(const char *cpf)
{
    if (strlen(cpf) != 11)
    {
        printf("CPF inválido. O CPF deve conter 11 dígitos.\n");
        return false;
    }

    /* for (int i = 0; i < 12; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF inválido. Por favor, digite apenas dígitos para o
    CPF.\n"); return false;
        }
    } */
    return true;
}
// VALIDAÇÃO IDADE
int validarIdade(int idade)
{
    if (idade < 0)
    {
        printf("Idade inválida. Por favor, digite uma idade não negativa.\n");
        return 0;#include <ctype.h> // Biblioteca para usar funções de caracteres
#include <stdbool.h> // Biblioteca para usar tipos booleanos
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings
#include <stdlib.h> 

#define MAX_HOTEIS 2 // Define a quantidade máxima de hotéis
#define MAX_QUARTOS 3 // Define a quantidade máxima de quartos
#define MAX_NOME 150 // Define o tamanho máximo do nome
#define MAX_CPF 11  // Define o tamanho máximo do CPF
#define TAXA_CANCELAMENTO 0.3  // 30% de taxa de cancelamento

// ESTRUTURA PARA ESCOLHAS DO QUARTO
typedef struct
{
    int numero;
    char tipo[20];
    bool disponivel;
    float preco;
    float desconto;
} Quarto;
// ESTRUTURA HOTEIS
typedef struct
{
    char nomeCliente[MAX_NOME];
    char nome[MAX_NOME];
    Quarto quartos[MAX_QUARTOS];
} Hotel;
// FUNÇÃO PARA LER UMA LINHA DE TEXTO DO USUARIO
void ler_texto(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}
// FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
// VALIDAÇÃO NOME
int validarNome(char nomeCliente[MAX_NOME])
{
    if (strlen(nomeCliente) == 0)
    {
        printf("Nome inválido. Por favor, digite um nome.\n");
        return 0;
    }

    return 1;
}
// VALIDAÇÃO CPF
bool validarCPF(const char *cpf)
{
    if (strlen(cpf) != 11)
    {
        printf("CPF inválido. O CPF deve conter 11 dígitos.\n");
        return false;
    }

    /* for (int i = 0; i < 12; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF inválido. Por favor, digite apenas dígitos para o
    CPF.\n"); return false;
        }
    } */
    return true;
}
// VALIDAÇÃO IDADE
int validarIdade(int idade)
{
    if (idade < 0)
    {
        printf("Idade inválida. Por favor, digite uma idade não negativa.\n");
        return 0;
    }
    else if (idade < 18)
    {
        printf("Você precisa ser maior de 18 anos para realizar o cadastro.\n");
        return 0;
    }
    return 1;
}
// VALIDAÇÃO NUMEROS DE PESSOAS
int validarNumPessoas(int numPessoas)
{
    if (numPessoas < 0)
    {
        printf("Número de pessoas inválido. Por favor, digite um número não "
               "negativo.\n");
        return 0;
    }
    else if (numPessoas > 6)
    {
        printf("O número máximo de pessoas permitido é 6.\n");
        printf("Tente novamente.\n");
        return 0;
    }
    return 1;
}
// CADASTRO CLIENTE
void validarEntradasCadastroCliente(char nomeCliente[MAX_NOME], char cpf[11], int *idade, int *numPessoas)
{
    int entradaValida = 0;

    while (!entradaValida)
    {
        limpar_entrada();
        printf("Digite o nome do cliente: ");
        ler_texto(nomeCliente, MAX_NOME);
        nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
        entradaValida = validarNome(nomeCliente);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Digite o CPF do cliente: ");
        scanf("%s", cpf);
        limpar_entrada(); // Remove a quebra de linha, se presente
        entradaValida = validarCPF(cpf);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Digite a idade: ");
        scanf("%d", idade);
        limpar_entrada();
        entradaValida = validarIdade(*idade);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Obs: Cada quarto permite um total de 4 pessoas.\n");
        printf("Digite o número de pessoas: ");
        scanf("%d", numPessoas);
        limpar_entrada();
        entradaValida = validarNumPessoas(*numPessoas);
    }
}
// HOTEIS DISPONIVEIS
void listarHoteis(Hotel hoteis[])
{
    printf("Hotéis disponíveis:\n\n");
    for (int i = 0; i < MAX_HOTEIS; i++)
    {
        printf("%d. %s\n", i + 1, hoteis[i].nome);
    }
}
// QUARTOS DISPONIVEIS
void listarQuartos(Hotel hotel)
{
    printf("Quartos disponíveis em %s\n", hotel.nome);
    for (int i = 0; i < MAX_QUARTOS; i++)
    {
        if (hotel.quartos[i].disponivel)
        {
            printf("Número: %d, Tipo: %s, Preço: %.2f, Desconto: %.2f%%\n",
                   hotel.quartos[i].numero, hotel.quartos[i].tipo,
                   hotel.quartos[i].preco, hotel.quartos[i].desconto * 100);
        }
    }
}
// FUNÇÃO PARA VERIFICAR DISPONIBILIDADE DO QUARTO PARA UMA DATA
int verificarDisponibilidadeQuarto(Hotel hotel, int quartoEscolhido, int diaEntrada, int diaSaida)
{
    for (int i = diaEntrada - 1; i < diaSaida; i++)
    {
        if (!hotel.quartos[quartoEscolhido - 1].disponivel)
        {
            printf("Quarto indisponível para as datas especificadas.\n");
            return 0;
        }
    }
    return 1;
}
// FUNÇÃO PARA MODIFICAR DATAS DE ESTADIA
void modificarDatasEstadia(int *diaEntrada, int *diaSaida, int diasPorMes[])
{
    int novoDiaEntrada, novoDiaSaida;
    printf("Digite a nova data de entrada (1-%d): ", *diaSaida);
    scanf("%d", &novoDiaEntrada);
    if (novoDiaEntrada < 1 || novoDiaEntrada > *diaSaida)
    {
        printf("Data de entrada inválida.\n");
        return;
    }

    printf("Digite a nova data de saída (%d-%d): ", novoDiaEntrada,
           diasPorMes[novoDiaEntrada]);
    scanf("%d", &novoDiaSaida);
    if (novoDiaSaida < novoDiaEntrada ||
            novoDiaSaida > diasPorMes[novoDiaEntrada])
    {
        printf("Data de saída inválida.\n");
        return;
    }

    *diaEntrada = novoDiaEntrada;
    *diaSaida = novoDiaSaida;
    printf("Datas de estadia modificadas com sucesso.\n");
}
// FUNÇÃO PARA CANCELAR UMA RESERVA
void cancelarReserva(Hotel *hotel, int quartoEscolhido, int diaEntrada, int diaSaida, float *valorTotalReserva)
{
    for (int i = diaEntrada - 1; i < diaSaida; i++)
    {
        hotel->quartos[quartoEscolhido - 1].disponivel = true;
    }

    // Calcule a taxa de cancelamento
    float taxaCancelamento = *valorTotalReserva * TAXA_CANCELAMENTO;

    // Subtrai a taxa do valor total da reserva
    *valorTotalReserva -= taxaCancelamento;

    printf("Reserva cancelada com sucesso.\nVocê pagará %.2f (30%%) de taxa de cancelamento.\n", taxaCancelamento);
}
// FUNÇÃO PARA VER SE EXISTEM NUMEROS NO CADASTRO DO FUNCIONÃRIO.
int conter_Numeros(const char *st)
{
    for (int i = 0; st[i]; i++)
    {
        if (isdigit(st[i]))
        {
            return 1;
        }
    }
    return 0;
}
// FUNÇÃO PARA GERAR UMA CHAVE PIX ALEATORIA
char *gerarChavePixAleatoria()
{
    static char chavePix[21];  // Tamanho da chave Pix
    const char caracteresValidos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    for (i = 0; i < 20; i++)
    {
        chavePix[i] = caracteresValidos[rand() % (sizeof(caracteresValidos) - 1)];
    }
    chavePix[20] = '\0';  // Adiciona o caractere nulo ao final da string

    return chavePix;
}

// FUNÇÃO PRINCIPAL
int main()
{

    // DEFINIÇÃO DE LOGIN E SENHA
    char login1[] = "admin";
    char senha1[] = "admin";
    char login2[] = "admin123";
    char senha2[] = "admin123";

    char usuario[100], senha[100];
    char sair;

    do
    {
        printf("   *** SEJA BEM VINDO ***\n");
        printf("\n");
        // LOGIN
        while(1){
            printf("---------- Login ----------\n");
            printf("\n");
            printf("Digite o usuário: ");
            scanf("%s", usuario);
            printf("Digite a senha: ");
            scanf("%s", senha);
            if (strcmp(usuario, login1) == 0 && strcmp(senha, senha1) == 0)
            {
                printf("Login realizado com sucesso!\n");
                break;
            }
            else if (strcmp(usuario, login2) == 0 && strcmp(senha, senha2) == 0)
            {
                printf("Login realizado com sucesso!\n");
                break;
            }
            else
            {
                printf("Usuário ou senha incorretos! Tente novamente.\n");
                continue;
            }
        }
        int escolhaHotel;
        int diaEntrada = 0;
        int diaSaida = 0;
        int numPessoas = 0;
        int escolhaQuarto, escolhaQuartoAnterior = -1;

        Hotel hoteis[MAX_HOTEIS];
        strcpy(hoteis[0].nome, "Hotel Transylvania");
        strcpy(hoteis[1].nome, "Hotel Transylvania 2.0");

        for (int i = 0; i < MAX_HOTEIS; i++)
        {
            hoteis[i].quartos[0].numero = 1;
            strcpy(hoteis[i].quartos[0].tipo, "Suite Presidencial");
            hoteis[i].quartos[0].disponivel = true;
            hoteis[i].quartos[0].preco = 300.0;   // Valor da diária
            hoteis[i].quartos[0].desconto = 0.15; // Desconto (15%)

            hoteis[i].quartos[1].numero = 2;
            strcpy(hoteis[i].quartos[1].tipo, "Quarto de Luxo");
            hoteis[i].quartos[1].disponivel = true;
            hoteis[i].quartos[1].preco = 200.0;  // Valor da diária
            hoteis[i].quartos[1].desconto = 0.1; // Desconto (10%)

            hoteis[i].quartos[2].numero = 3;
            strcpy(hoteis[i].quartos[2].tipo, "Quarto Simples");
            hoteis[i].quartos[2].disponivel = true;
            hoteis[i].quartos[2].preco = 100.0;   // Valor da diária
            hoteis[i].quartos[2].desconto = 0.05; // Desconto (5%)
        }

        int opcao;
        int opcao_escolhida;
        int resevado = 0;
        char nomeFuncionario[MAX_NOME];
        char nomeCliente[MAX_NOME];
        char cpfCliente[MAX_CPF];
        int idadeCliente;

        while (1)
        {
            printf("\n\n");
            printf("------ Reservas de Hotéis ------\n\n");

            listarHoteis(hoteis);

            printf("\nEscolha um hotel (1-%d) ou digite 0 para sair: ", MAX_HOTEIS);
            scanf("%d", &escolhaHotel);
            printf("\n");
            if (escolhaHotel == 0)
                {
                    printf("Saindo do sistema.\n");
                    break;
                }
                else if (escolhaHotel < 1 || escolhaHotel > MAX_HOTEIS)
                    {
                        printf("Opção inválida.\n");
                        continue;
                    }

            listarQuartos(hoteis[escolhaHotel - 1]);

            printf("\n");

            do
            {
                printf("Escolha um quarto: ");
                scanf("%d", &escolhaQuarto);
                printf("\n");

                    if (escolhaQuarto < 1 || escolhaQuarto > MAX_QUARTOS ||
                            !hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].disponivel ||
                            escolhaQuarto == escolhaQuartoAnterior)
                    {
                        printf("Quarto indisponível.\n");
                    }
                    else
                    {
                        escolhaQuartoAnterior = escolhaQuarto;
                        break;
                    }
            } while (1);

            int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            char *nomesMeses[] = {"",        "Janeiro",  "Fevereiro", "Março",
                                  "Abril",   "Maio",     "Junho",     "Julho",
                                  "Agosto",  "Setembro", "Outubro",   "Novembro",
                                  "Dezembro"
                                 };

            int mesEscolhido, diaEntrada, diaSaida;

            while (1)
            {
                printf("Meses disponíveis:\n");
                for (int i = 1; i <= 12; i++)
                {
                    printf("%d. %s\n", i, nomesMeses[i]);
                }
                // ESCOLHA DO MES
                printf("\nEscolha o mês (1-12): ");
                scanf("%d", &mesEscolhido);
                printf("Mês escolhido: %s\n", nomesMeses[mesEscolhido]);
                // IF PARA VALIDAR O MES ESCOLHIDO
                if (mesEscolhido < 1 || mesEscolhido > 12)
                    {
                        printf("Escolha um mês válido.\n");
                        printf("\n");
                    }
                    else
                    {
                        break;
                    }
            }

            // Solicitar datas de entrada e saída
            while (1)
            {
                printf("Digite a data de entrada (1-%d): ", diasPorMes[mesEscolhido]);
                scanf("%d", &diaEntrada);

                    if (diaEntrada < 1 || diaEntrada > diasPorMes[mesEscolhido])
                    {
                        printf("Data de entrada inválida. Tente novamente.\n");
                    }
                    else
                    {
                        break;
                    }
            }


            while (1)
            {
                printf("Digite a data de saída (%d-%d): ", diaEntrada, diasPorMes[mesEscolhido]);
                scanf("%d", &diaSaida);

                    if (diaSaida < diaEntrada || diaSaida > nomesMeses[diaEntrada - 1])
                    {
                        printf("Data de saída inválida. Tente novamente.\n");
                    }
                    else
                    {
                        break;
                    }
            }
            int quantidadeDiarias = diaSaida - diaEntrada + 1;

            // CÁLCULO DO PREÇO COM DESCONTO
            float precoQuarto = hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].preco;
            float descontoQuarto = hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].desconto;
            int diasEstadia = diaSaida - diaEntrada + 1;
            float precoTotal = precoQuarto * diasEstadia * (1.0 - descontoQuarto);

            if (verificarDisponibilidadeQuarto(hoteis[escolhaHotel - 1],
                                               escolhaQuarto, diaEntrada, diaSaida))
            {
                printf("Reserva efetuada com sucesso!\n");
                printf("\n");

                if (!resevado)
                {
                    printf(
                        "Você deseja alterar as datas de estadia? (1 - Sim, 0 - Não): ");
                    scanf("%d", &opcao);
                        if (opcao)
                        {
                            modificarDatasEstadia(&diaEntrada, &diaSaida, diasPorMes);
                        }

                    validarEntradasCadastroCliente(nomeCliente, cpfCliente, &idadeCliente, &numPessoas);

                    resevado = 1;
                }

                    printf("\n");
                    printf("Digite o nome do funcionário que fez a reserva: ");
                    fgets(nomeFuncionario, MAX_NOME, stdin);
                    //nome[strcspn(nome, "\n")] = '\0';

                printf("\n");
                printf("Deseja cancelar a reserva? (1 - Sim, 0 - Não): ");
                scanf("%d", &opcao);

                float valorTotalReserva = precoTotal; // Inicializa o valor total da reserva

                if (opcao)
                {
                    cancelarReserva(&hoteis[escolhaHotel - 1], escolhaQuarto, diaEntrada, diaSaida, &valorTotalReserva);
                    resevado = 0;
                }
                else if(opcao && !resevado)
                {
                    printf("Não há nenhuma reserva ativa para cancelar");
                }
            }

            printf("\nDeseja sair do sistema? (1 - Sim, 0 - Não): ");
            scanf("%d", &opcao_escolhida);
            if (opcao_escolhida == 1)
            {
                break;
            }

            int opcaoMenu;
            int opcaoPagamento;
            char *chavePixAleatoria;
            float valorTotal;

            while (1)
            {
                printf("\n======= Menu =======\n");
                printf("1. Informações do Cliente\n");
                printf("2. Informações sobre a Reserva\n");
                printf("3. Pagamento\n");
                printf("4. Sair\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoMenu);

                switch (opcaoMenu)
                {
                case 1:
                    if(resevado)
                    {
                    // Opção 1: Informações do Cliente
                    printf("\n=== Informações do Cliente ===\n");
                    printf("Nome do cliente: %s\n", nomeCliente);
                    printf("CPF do cliente: %s\n", cpfCliente);
                    printf("Idade do cliente: %d\n", idadeCliente);
                    printf("Número de pessoas: %d\n", numPessoas);
                    break;
                    }

                case 2:
                    if(resevado)
                    {
                    // Opção 2: Informações sobre a Reserva
                    printf("\n=== Informações sobre a Reserva ===\n");
                    printf("Nome do funcionário que realizou a reserva: %s\n", nomeFuncionario);
                    printf("Hotel: %s\n", hoteis[escolhaHotel - 1].nome);
                    printf("Quarto: %s\n", hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].tipo);
                    printf("Mês da reserva: %s\n", nomesMeses[mesEscolhido]);
                    printf("Data de entrada: %d\n", diaEntrada);
                    printf("Data de saída: %d\n", diaSaida);
                    printf("Quantidade de diárias: %d\n", quantidadeDiarias);
                    printf("Preço total a pagar: R$ %.2f\n", precoTotal);
                    break;
                    }

                case 3:
                    if(resevado)
                    {
                    // Opção 3: Pagamento
                    printf("\nBem-vindo! Escolha o método de pagamento:\n");
                    printf("1. Pix\n");
                    printf("2. Cartão com 5%% de desconto\n");
                    printf("3. Dinheiro\n");
                    printf("Opção: ");
                    scanf("%d", &opcaoPagamento);
                    }

                    if (opcaoPagamento == 1)
                    {
                        chavePixAleatoria = gerarChavePixAleatoria();
                        printf("valor total: R$ %.2f\n", precoTotal);
                        printf("Efetue o pagamento com Pix utilizando uma das seguintes chaves:\n");
                        printf("1. Chave Aleatória: %s\n", chavePixAleatoria);
                        printf("2. Chave com Email: cristiandurante91@outlook.com\n");
                    }
                    else if (opcaoPagamento == 2)
                    {
                        printf("valor total: R$ %.2f\n", precoTotal);
                        float valorDesconto = precoTotal * 0.05;  // Calcula o valor do desconto (5%)
                        float valorAPagar = precoTotal - valorDesconto;
                        printf("Pagamento com cartão selecionado. Valor a pagar com 5%% de desconto: R$ %.2f\n", valorAPagar);
                    }
                    else if (opcaoPagamento == 3)
                    {
                        printf("valor total: R$ %.2f\n", precoTotal);
                        printf("Pagamento em dinheiro selecionado. Valor a pagar: R$ %.2f\n", valorTotal);
                    }
                    else
                    {
                        printf("Opção Invalida.\n");
                    }
                    break;

                case 4:
                    // Opção 4: Sair
                    printf("Saindo do menu.\n");
                    break;

                default:
                    printf("Opção inválida. Tente novamente.\n");
                }

                if (opcaoMenu == 4)
                {
                    break; // Sai do loop se a opção 4 (Sair) for selecionada
                }
            }


        }

        printf("Obrigado por usar o sistema de reservas de hotéis!\n");

        return 0;
        printf("Deseja fazer um novo login? (1 - Sim, 0 - Não): ");
        limpar_entrada();
        scanf("%c", &sair);
    }
    while (sair == '1');
}

    }
    else if (idade < 18)
    {
        printf("Você precisa ser maior de 18 anos para realizar o cadastro.\n");
        return 0;
    }
    return 1;
}
// VALIDAÇÃO NUMEROS DE PESSOAS
int validarNumPessoas(int numPessoas)
{
    if (numPessoas < 0)
    {
        printf("Número de pessoas inválido. Por favor, digite um número não "
               "negativo.\n");
        return 0;
    }
    else if (numPessoas > 6)
    {
        printf("O número máximo de pessoas permitido é 6.\n");
        printf("Tente novamente.\n");
        return 0;
    }
    return 1;
}
// CADASTRO CLIENTE
void validarEntradasCadastroCliente(char nomeCliente[MAX_NOME], char cpf[11], int *idade, int *numPessoas)
{
    int entradaValida = 0;

    while (!entradaValida)
    {
        limpar_entrada();
        printf("Digite o nome do cliente: ");
        ler_texto(nomeCliente, MAX_NOME);
        nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
        entradaValida = validarNome(nomeCliente);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Digite o CPF do cliente: ");
        scanf("%s", cpf);
        limpar_entrada(); // Remove a quebra de linha, se presente
        entradaValida = validarCPF(cpf);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Digite a idade: ");
        scanf("%d", idade);
        limpar_entrada();
        entradaValida = validarIdade(*idade);
    }

    entradaValida = 0;
    while (!entradaValida)
    {
        printf("Obs: Cada quarto permite um total de 4 pessoas.\n");
        printf("Digite o número de pessoas: ");
        scanf("%d", numPessoas);
        limpar_entrada();
        entradaValida = validarNumPessoas(*numPessoas);
    }
}
// HOTEIS DISPONIVEIS
void listarHoteis(Hotel hoteis[])
{
    printf("Hotéis disponíveis:\n\n");
    for (int i = 0; i < MAX_HOTEIS; i++)
    {
        printf("%d. %s\n", i + 1, hoteis[i].nome);
    }
}
// QUARTOS DISPONIVEIS
void listarQuartos(Hotel hotel)
{
    printf("Quartos disponíveis em %s\n", hotel.nome);
    for (int i = 0; i < MAX_QUARTOS; i++)
    {
        if (hotel.quartos[i].disponivel)
        {
            printf("Número: %d, Tipo: %s, Preço: %.2f, Desconto: %.2f%%\n",
                   hotel.quartos[i].numero, hotel.quartos[i].tipo,
                   hotel.quartos[i].preco, hotel.quartos[i].desconto * 100);
        }
    }
}
// FUNÇÃO PARA VERIFICAR DISPONIBILIDADE DO QUARTO PARA UMA DATA
int verificarDisponibilidadeQuarto(Hotel hotel, int quartoEscolhido, int diaEntrada, int diaSaida)
{
    for (int i = diaEntrada - 1; i < diaSaida; i++)
    {
        if (!hotel.quartos[quartoEscolhido - 1].disponivel)
        {
            printf("Quarto indisponível para as datas especificadas.\n");
            return 0;
        }
    }
    return 1;
}
// FUNÇÃO PARA MODIFICAR DATAS DE ESTADIA
void modificarDatasEstadia(int *diaEntrada, int *diaSaida, int diasPorMes[])
{
    int novoDiaEntrada, novoDiaSaida;
    printf("Digite a nova data de entrada (1-%d): ", *diaSaida);
    scanf("%d", &novoDiaEntrada);
    if (novoDiaEntrada < 1 || novoDiaEntrada > *diaSaida)
    {
        printf("Data de entrada inválida.\n");
        return;
    }

    printf("Digite a nova data de saída (%d-%d): ", novoDiaEntrada,
           diasPorMes[novoDiaEntrada]);
    scanf("%d", &novoDiaSaida);
    if (novoDiaSaida < novoDiaEntrada ||
            novoDiaSaida > diasPorMes[novoDiaEntrada])
    {
        printf("Data de saída inválida.\n");
        return;
    }

    *diaEntrada = novoDiaEntrada;
    *diaSaida = novoDiaSaida;
    printf("Datas de estadia modificadas com sucesso.\n");
}
// FUNÇÃO PARA CANCELAR UMA RESERVA
void cancelarReserva(Hotel *hotel, int quartoEscolhido, int diaEntrada, int diaSaida, float *valorTotalReserva)
{
    for (int i = diaEntrada - 1; i < diaSaida; i++)
    {
        hotel->quartos[quartoEscolhido - 1].disponivel = true;
    }

    // Calcule a taxa de cancelamento
    float taxaCancelamento = *valorTotalReserva * TAXA_CANCELAMENTO;

    // Subtrai a taxa do valor total da reserva
    *valorTotalReserva -= taxaCancelamento;

    printf("Reserva cancelada com sucesso.\nVocê pagará %.2f (30%%) de taxa de cancelamento.\n", taxaCancelamento);
}
// FUNÇÃO PARA VER SE EXISTEM NUMEROS NO CADASTRO DO FUNCIONÃRIO.
int conter_Numeros(const char *st)
{
    for (int i = 0; st[i]; i++)
    {
        if (isdigit(st[i]))
        {
            return 1;
        }
    }
    return 0;
}
// FUNÇÃO PARA GERAR UMA CHAVE PIX ALEATORIA
char *gerarChavePixAleatoria()
{
    static char chavePix[21];  // Tamanho da chave Pix
    const char caracteresValidos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    for (i = 0; i < 20; i++)
    {
        chavePix[i] = caracteresValidos[rand() % (sizeof(caracteresValidos) - 1)];
    }
    chavePix[20] = '\0';  // Adiciona o caractere nulo ao final da string

    return chavePix;
}

// FUNÇÃO PRINCIPAL
int main()
{

    // DEFINIÇÃO DE LOGIN E SENHA
    char login1[] = "admin";
    char senha1[] = "admin";
    char login2[] = "admin123";
    char senha2[] = "admin123";

    char usuario[100], senha[100];
    char sair;

    do
    {
        printf("   *** SEJA BEM VINDO ***\n");
        printf("\n");
        // LOGIN
        while(1){
            printf("---------- Login ----------\n");
            printf("\n");
            printf("Digite o usuário: ");
            scanf("%s", usuario);
            printf("Digite a senha: ");
            scanf("%s", senha);
            if (strcmp(usuario, login1) == 0 && strcmp(senha, senha1) == 0)
            {
                printf("Login realizado com sucesso!\n");
                break;
            }
            else if (strcmp(usuario, login2) == 0 && strcmp(senha, senha2) == 0)
            {
                printf("Login realizado com sucesso!\n");
                break;
            }
            else
            {
                printf("Usuário ou senha incorretos! Tente novamente.\n");
                continue;
            }
        }
        int escolhaHotel;
        int diaEntrada = 0;
        int diaSaida = 0;
        int numPessoas = 0;
        int escolhaQuarto, escolhaQuartoAnterior = -1;

        Hotel hoteis[MAX_HOTEIS];
        strcpy(hoteis[0].nome, "Hotel Transylvania");
        strcpy(hoteis[1].nome, "Hotel Transylvania 2.0");

        for (int i = 0; i < MAX_HOTEIS; i++)
        {
            hoteis[i].quartos[0].numero = 1;
            strcpy(hoteis[i].quartos[0].tipo, "Suite Presidencial");
            hoteis[i].quartos[0].disponivel = true;
            hoteis[i].quartos[0].preco = 300.0;   // Valor da diária
            hoteis[i].quartos[0].desconto = 0.15; // Desconto (15%)

            hoteis[i].quartos[1].numero = 2;
            strcpy(hoteis[i].quartos[1].tipo, "Quarto de Luxo");
            hoteis[i].quartos[1].disponivel = true;
            hoteis[i].quartos[1].preco = 200.0;  // Valor da diária
            hoteis[i].quartos[1].desconto = 0.1; // Desconto (10%)

            hoteis[i].quartos[2].numero = 3;
            strcpy(hoteis[i].quartos[2].tipo, "Quarto Simples");
            hoteis[i].quartos[2].disponivel = true;
            hoteis[i].quartos[2].preco = 100.0;   // Valor da diária
            hoteis[i].quartos[2].desconto = 0.05; // Desconto (5%)
        }

        int opcao;
        int opcao_escolhida;
        int resevado = 0;
        char nomeFuncionario[MAX_NOME];
        char nomeCliente[MAX_NOME];
        char cpfCliente[MAX_CPF];
        int idadeCliente;

        while (1)
        {
            printf("\n\n");
            printf("------ Reservas de Hotéis ------\n\n");

            listarHoteis(hoteis);

            printf("\nEscolha um hotel (1-%d) ou digite 0 para sair: ", MAX_HOTEIS);
            scanf("%d", &escolhaHotel);
            printf("\n");
            if (escolhaHotel == 0)
                {
                    printf("Saindo do sistema.\n");
                    break;
                }
                else if (escolhaHotel < 1 || escolhaHotel > MAX_HOTEIS)
                    {
                        printf("Opção inválida.\n");
                        continue;
                    }

            listarQuartos(hoteis[escolhaHotel - 1]);

            printf("\n");

            do
            {
                printf("Escolha um quarto: ");
                scanf("%d", &escolhaQuarto);
                printf("\n");

                    if (escolhaQuarto < 1 || escolhaQuarto > MAX_QUARTOS ||
                            !hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].disponivel ||
                            escolhaQuarto == escolhaQuartoAnterior)
                    {
                        printf("Quarto indisponível.\n");
                    }
                    else
                    {
                        escolhaQuartoAnterior = escolhaQuarto;
                        break;
                    }
            } while (1);

            int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            char *nomesMeses[] = {"",        "Janeiro",  "Fevereiro", "Março",
                                  "Abril",   "Maio",     "Junho",     "Julho",
                                  "Agosto",  "Setembro", "Outubro",   "Novembro",
                                  "Dezembro"
                                 };

            int mesEscolhido, diaEntrada, diaSaida;

            while (1)
            {
                printf("Meses disponíveis:\n");
                for (int i = 1; i <= 12; i++)
                {
                    printf("%d. %s\n", i, nomesMeses[i]);
                }
                // ESCOLHA DO MES
                printf("\nEscolha o mês (1-12): ");
                scanf("%d", &mesEscolhido);
                printf("Mês escolhido: %s\n", nomesMeses[mesEscolhido]);
                // IF PARA VALIDAR O MES ESCOLHIDO
                if (mesEscolhido < 1 || mesEscolhido > 12)
                    {
                        printf("Escolha um mês válido.\n");
                        printf("\n");
                    }
                    else
                    {
                        break;
                    }
            }

            // Solicitar datas de entrada e saída
            while (1)
            {
                printf("Digite a data de entrada (1-%d): ", diasPorMes[mesEscolhido]);
                scanf("%d", &diaEntrada);

                    if (diaEntrada < 1 || diaEntrada > diasPorMes[mesEscolhido])
                    {
                        printf("Data de entrada inválida. Tente novamente.\n");
                    }
                    else
                    {
                        break;
                    }
            }


            while (1)
            {
                printf("Digite a data de saída (%d-%d): ", diaEntrada, diasPorMes[mesEscolhido]);
                scanf("%d", &diaSaida);

                    if (diaSaida < diaEntrada || diaSaida > nomesMeses[diaEntrada - 1])
                    {
                        printf("Data de saída inválida. Tente novamente.\n");
                    }
                    else
                    {
                        break;
                    }
            }
            int quantidadeDiarias = diaSaida - diaEntrada + 1;

            // CÁLCULO DO PREÇO COM DESCONTO
            float precoQuarto = hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].preco;
            float descontoQuarto = hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].desconto;
            int diasEstadia = diaSaida - diaEntrada + 1;
            float precoTotal = precoQuarto * diasEstadia * (1.0 - descontoQuarto);

            if (verificarDisponibilidadeQuarto(hoteis[escolhaHotel - 1],
                                               escolhaQuarto, diaEntrada, diaSaida))
            {
                printf("Reserva efetuada com sucesso!\n");
                printf("\n");

                if (!resevado)
                {
                    printf(
                        "Você deseja alterar as datas de estadia? (1 - Sim, 0 - Não): ");
                    scanf("%d", &opcao);
                        if (opcao)
                        {
                            modificarDatasEstadia(&diaEntrada, &diaSaida, diasPorMes);
                        }

                    validarEntradasCadastroCliente(nomeCliente, cpfCliente, &idadeCliente, &numPessoas);

                    resevado = 1;
                }

                    printf("\n");
                    printf("Digite o nome do funcionário que fez a reserva: ");
                    fgets(nomeFuncionario, MAX_NOME, stdin);
                    //nome[strcspn(nome, "\n")] = '\0';

                printf("\n");
                printf("Deseja cancelar a reserva? (1 - Sim, 0 - Não): ");
                scanf("%d", &opcao);

                float valorTotalReserva = precoTotal; // Inicializa o valor total da reserva

                if (opcao)
                {
                    cancelarReserva(&hoteis[escolhaHotel - 1], escolhaQuarto, diaEntrada, diaSaida, &valorTotalReserva);
                    resevado = 0;
                }
                else if(opcao && !resevado)
                {
                    printf("Não há nenhuma reserva ativa para cancelar");
                }
            }

            printf("\nDeseja sair do sistema? (1 - Sim, 0 - Não): ");
            scanf("%d", &opcao_escolhida);
            if (opcao_escolhida == 1)
            {
                break;
            }

            int opcaoMenu;
            int opcaoPagamento;
            char *chavePixAleatoria;
            float valorTotal;

            while (1)
            {
                printf("\n======= Menu =======\n");
                printf("1. Informações do Cliente\n");
                printf("2. Informações sobre a Reserva\n");
                printf("3. Pagamento\n");
                printf("4. Sair\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoMenu);

                switch (opcaoMenu)
                {
                case 1:
                    if(resevado)
                    {
                    // Opção 1: Informações do Cliente
                    printf("\n=== Informações do Cliente ===\n");
                    printf("Nome do cliente: %s\n", nomeCliente);
                    printf("CPF do cliente: %s\n", cpfCliente);
                    printf("Idade do cliente: %d\n", idadeCliente);
                    printf("Número de pessoas: %d\n", numPessoas);
                    break;
                    }

                case 2:
                    if(resevado)
                    {
                    // Opção 2: Informações sobre a Reserva
                    printf("\n=== Informações sobre a Reserva ===\n");
                    printf("Nome do funcionário que realizou a reserva: %s\n", nomeFuncionario);
                    printf("Hotel: %s\n", hoteis[escolhaHotel - 1].nome);
                    printf("Quarto: %s\n", hoteis[escolhaHotel - 1].quartos[escolhaQuarto - 1].tipo);
                    printf("Mês da reserva: %s\n", nomesMeses[mesEscolhido]);
                    printf("Data de entrada: %d\n", diaEntrada);
                    printf("Data de saída: %d\n", diaSaida);
                    printf("Quantidade de diárias: %d\n", quantidadeDiarias);
                    printf("Preço total a pagar: R$ %.2f\n", precoTotal);
                    break;
                    }

                case 3:
                    if(resevado)
                    {
                    // Opção 3: Pagamento
                    printf("\nBem-vindo! Escolha o método de pagamento:\n");
                    printf("1. Pix\n");
                    printf("2. Cartão com 5%% de desconto\n");
                    printf("3. Dinheiro\n");
                    printf("Opção: ");
                    scanf("%d", &opcaoPagamento);
                    }

                    if (opcaoPagamento == 1)
                    {
                        chavePixAleatoria = gerarChavePixAleatoria();
                        printf("valor total: R$ %.2f\n", precoTotal);
                        printf("Efetue o pagamento com Pix utilizando uma das seguintes chaves:\n");
                        printf("1. Chave Aleatória: %s\n", chavePixAleatoria);
                        printf("2. Chave com Email: cristiandurante91@outlook.com\n");
                    }
                    else if (opcaoPagamento == 2)
                    {
                        printf("valor total: R$ %.2f\n", precoTotal);
                        float valorDesconto = precoTotal * 0.05;  // Calcula o valor do desconto (5%)
                        float valorAPagar = precoTotal - valorDesconto;
                        printf("Pagamento com cartão selecionado. Valor a pagar com 5%% de desconto: R$ %.2f\n", valorAPagar);
                    }
                    else if (opcaoPagamento == 3)
                    {
                        printf("valor total: R$ %.2f\n", precoTotal);
                        printf("Pagamento em dinheiro selecionado. Valor a pagar: R$ %.2f\n", valorTotal);
                    }
                    else
                    {
                        printf("Opção Invalida.\n");
                    }
                    break;

                case 4:
                    // Opção 4: Sair
                    printf("Saindo do menu.\n");
                    break;

                default:
                    printf("Opção inválida. Tente novamente.\n");
                }

                if (opcaoMenu == 4)
                {
                    break; // Sai do loop se a opção 4 (Sair) for selecionada
                }
            }


        }

        printf("Obrigado por usar o sistema de reservas de hotéis!\n");

        return 0;
        printf("Deseja fazer um novo login? (1 - Sim, 0 - Não): ");
        limpar_entrada();
        scanf("%c", &sair);
    }
    while (sair == '1');
}
