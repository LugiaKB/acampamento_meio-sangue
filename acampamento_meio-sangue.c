#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Arma
{
    char nome[100];
    int dano;
    int id;
};

struct Satiro
{
    char nome[100];
    int idade;
    int id;
    char rank[100];
};

struct Campista 
{
    char nome[100];
    int idade;
    int id;
    int id_pai_divino;
    struct Arma arma;
    struct Satiro satiro;
};

struct Acampamento
{
    struct Campista campista[240];
    int qtd_campistas;
    struct Arma arma[100];
    int qtd_armas;
    struct Satiro satiro[100];
    int qtd_satiros;
};

//Variáveis globais
char chales[12][100] = {{"Zeus"}, {"Hera"}, {"Poseidon"}, {"Demeter"}, {"Ares"}, {"Atena"}, {"Apolo"}, {"Artemis"}, {"Hefesto"}, {"Afrodite"}, {"Hermes"}, {"Dionisio"}};

//Funções
//Create
struct Acampamento CriarAcampamento();
struct Campista CriarCampista(char nome_campista[], int idade_campista, int id_campista, int id_pai, struct Arma arma_campista, struct Satiro satiro_campista);
struct Satiro CriarSatiro(char nome_satiro[], int idade_satiro, int id_satiro, char rank_satiro[]);
struct Arma CriarArma(char nome_arma[], int id_arma, int dano_arma);
int CadastrarCampista(struct Acampamento *acampamento, struct Campista novo_campista);
int CadastrarSatiro(struct Acampamento *acampamento, struct Satiro novo_satiro);
int CadastrarArma(struct Acampamento *acampamento, struct Arma nova_arma);

//Read
int VerDado(struct Acampamento acampamento, char dado[], int index);
int VerTodos(struct Acampamento acampamento, char dado[]);
int VerTodosSimples(struct Acampamento acampamento, char dado[]);

//Update
void AtualizarCampista(struct Acampamento *acampamento, struct Campista campista, int index);
void AtualizarArma(struct Acampamento *acampamento, struct Arma arma, int index);
void AtualizarSatiro(struct Acampamento *acampamento, struct Satiro satiro, int index);

//Delete
void RemoverDado(struct Acampamento *acampamento, char dado[], int index);

//extras
void pular();
void menu(char dado[], char opt[]);
void erro();

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct Acampamento meiosangue = CriarAcampamento();
    struct Arma espada = CriarArma("Anaklusmos", 3, 100);
    struct Arma faca = CriarArma("Faca de Bronze", 2, 60);
    struct Arma espada1 = CriarArma("Espada de Bronze", 1, 85);
    struct Arma lanca = CriarArma("Lanca de Prata", 4, 100);
    struct Arma mordecostas = CriarArma("Mordecostas", 5, 130);
    struct Arma katoptris = CriarArma("Katoptris", 6, 75);

    struct Satiro grover = CriarSatiro("Grover Underwood", 32, 1, "Protetor");
    struct Satiro gleeson = CriarSatiro("Gleeson Hedge", 70, 2, "Treinador");

    struct Campista percy = CriarCampista("Percy Jackson", 12, 1, 3, espada, grover);
    struct Campista annabeth = CriarCampista("Annabeth Chase", 12, 2, 6, faca, grover);
    struct Campista luke = CriarCampista("Luke Castellan", 17, 3, 11, mordecostas, grover);
    struct Campista thalia = CriarCampista("Thalia Grace", 15, 4, 1, lanca, grover);
    struct Campista piper = CriarCampista("Piper McLean", 15, 5, 10, katoptris, gleeson);
    
    CadastrarSatiro(&meiosangue, grover);
    CadastrarSatiro(&meiosangue, gleeson);
    CadastrarArma(&meiosangue, espada1);
    CadastrarArma(&meiosangue, faca);
    CadastrarArma(&meiosangue, espada);
    CadastrarArma(&meiosangue, lanca);
    CadastrarArma(&meiosangue, mordecostas);
    CadastrarArma(&meiosangue, katoptris);
    CadastrarCampista(&meiosangue, percy);
    CadastrarCampista(&meiosangue, annabeth);
    CadastrarCampista(&meiosangue, luke);
    CadastrarCampista(&meiosangue, thalia);
    CadastrarCampista(&meiosangue, piper);

    char nome_campista[100], nome_satiro[100], nome_arma[100], rank_satiro[100], check;
    int idade_campista, idade_satiro, dano_arma, pai_divino, id_satiro, id_arma, id_campista;
    struct Satiro novo_satiro;
    struct Arma nova_arma;


    printf("Bem vindo ao Acampamento Meio-Sangue!\n\n");
    printf("Este lugar e um refugio para semideuses: os filhos dos deuses gregos com os humanos.\n");
    printf("Eles tambem sao chamados de meio-sangues.\n");
    pular();
    printf("Aqui, todos os semideuses estao protegidos por nossas barreiras magicas.\n");
    printf("Nossos satiros viajam ao redor do mundo buscando semideuses e trazendo eles em seguranca para o Acampamento.\n");
    printf("Os semideuses ficam separados em diferentes chales, cada um correspondendo ao seu parente divino.\n");
    pular();

    int opt1, opt2, opt3;
    do
    {
        printf("_________ Acampamento Meio-Sangue _________\n");
        printf("_________ Digite a opcao desejada _________\n\n");
        printf("1 - Gerenciar Campistas\n");
        printf("2 - Gerenciar Satiros\n");
        printf("3 - Gerenciar Arsenal\n");
        printf("4 - Sair\n");

        scanf("%i", &opt1);
        system("cls");

        switch (opt1)
        {
            case 1: //campistas
            {
                menu("campista", "");
                scanf("%i", &opt2);
                system("cls");

                switch (opt2)
                {
                    case 1: //criar
                    {
                        printf("Digite o nome do novo campista: ");
                        scanf(" %[^\n]", nome_campista);
                        printf("Qual a idade? ");
                        scanf("%i", &idade_campista);
                        
                        printf("Selecione o numero do chale do parente divino do semideus\n");
                        VerTodosSimples(meiosangue, "chale");
                        scanf("%i", &pai_divino);
                        
                        if (pai_divino <= 12 && pai_divino > 0)
                        {
                            printf("\nSelecione o satiro que trouxe o semideus para o acampamento\n");
                            VerTodosSimples(meiosangue, "satiro");
                            printf("%i. Adicionar outro\n", meiosangue.qtd_satiros + 1);
                            scanf("%i", &id_satiro);

                            if (id_satiro <= meiosangue.qtd_satiros)
                            {
                                printf("\nSelecione a arma escolhida pelo semideus\n");
                                VerTodosSimples(meiosangue, "arma");
                                printf("%i. Adicionar outra\n", meiosangue.qtd_armas + 1);
                                scanf("%i", &id_arma);
                                system("cls");

                                if (id_arma <= meiosangue.qtd_armas)
                                {
                                    CadastrarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, meiosangue.qtd_campistas + 1, pai_divino, meiosangue.arma[id_arma - 1], meiosangue.satiro[id_satiro - 1]));
                                    VerDado(meiosangue, "campista", meiosangue.qtd_campistas - 1);
                                    pular();
                                }
                                else
                                {
                                    printf("Digite o nome da arma: ");
                                    scanf(" %[^\n]", nome_arma);
                                    printf("Digite o dano da arma: ");
                                    scanf("%i", &dano_arma);
                                    system("cls");

                                    nova_arma = CriarArma(nome_arma, meiosangue.qtd_armas + 1, dano_arma);
                                    CadastrarArma(&meiosangue, nova_arma);

                                    CadastrarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, meiosangue.qtd_campistas + 1, pai_divino, nova_arma, meiosangue.satiro[id_satiro - 1]));
                                    VerDado(meiosangue, "campista", meiosangue.qtd_campistas - 1);
                                    pular();
                                }
                            }
                            else
                            {
                                printf("Digite o nome do satiro: ");
                                scanf(" %[^\n]", nome_satiro);
                                printf("Digite a idade real do satiro: ");
                                scanf("%i", &idade_satiro);
                                printf("Qual o cargo do satiro? ");
                                scanf(" %[^\n]", rank_satiro);
                                system("cls");

                                novo_satiro = CriarSatiro(nome_satiro, idade_satiro, meiosangue.qtd_satiros + 1, rank_satiro);
                                CadastrarSatiro(&meiosangue, novo_satiro);

                                printf("\nSelecione a arma escolhida pelo semideus\n");
                                VerTodosSimples(meiosangue, "arma");
                                printf("%i. Adicionar outra\n", meiosangue.qtd_armas + 1);
                                scanf("%i", &id_arma);
                                system("cls");

                                if (id_arma <= meiosangue.qtd_armas)
                                {
                                    CadastrarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, meiosangue.qtd_campistas + 1, pai_divino, meiosangue.arma[id_arma - 1], novo_satiro));
                                    VerDado(meiosangue, "campista", meiosangue.qtd_campistas - 1);
                                    pular();
                                }
                                else
                                {
                                    printf("Digite o nome da arma: ");
                                    scanf(" %[^\n]", nome_arma);
                                    printf("Digite o dano da arma: ");
                                    scanf("%i", &dano_arma);
                                    system("cls");

                                    nova_arma = CriarArma(nome_arma, meiosangue.qtd_armas + 1, dano_arma);
                                    CadastrarArma(&meiosangue, nova_arma);

                                    CadastrarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, meiosangue.qtd_campistas + 1, pai_divino, nova_arma, novo_satiro));
                                    VerDado(meiosangue, "campista", meiosangue.qtd_campistas - 1);
                                    pular();
                                }
                            }
                        }
                        else
                        {
                            printf("Opcao invalida!");
                            pular();
                        }
                        break;
                    }
                    case 2: //visualizar
                    {
                        menu("campista", "vcamp");
                        scanf("%i", &opt3);
                        system("cls");

                        switch (opt3)
                        {
                            case 1:
                            {
                                VerTodos(meiosangue, "campista");
                                pular();
                                break;
                            }
                            case 2:
                            {
                                printf("Digite o numero do campista: ");
                                scanf("%i", &id_campista);

                                if (id_campista > meiosangue.qtd_campistas)
                                {
                                    printf("Campista nao encontrado!\n");
                                }
                                else
                                {
                                    VerDado(meiosangue, "campista", id_campista - 1);
                                }

                                pular();
                                break;
                            }
                            case 3:
                            {
                                printf("Digite o numero do chale: ");
                                scanf("%i", &pai_divino);
                                system("cls");

                                if (pai_divino <= 12)
                                {
                                    int i;
                                    for (i = 0; i < meiosangue.qtd_campistas; i++)
                                    {
                                        if (meiosangue.campista[i].id_pai_divino == pai_divino)
                                        {
                                            VerDado(meiosangue, "campista", i);
                                        }
                                    }
                                    pular();
                                }
                                else
                                {
                                    printf("Chale inexistente!\n");
                                    pular();
                                }
                                break;
                            }
                            
                        }
                        break;
                    }
                    case 3: //editar
                    {
                        printf("Digite o numero do campista que deseja editar: ");
                        scanf("%i", &id_campista);
                        system("cls");

                        if (id_campista <= meiosangue.qtd_campistas)
                        {
                            printf("Digite o novo nome campista: ");
                            scanf(" %[^\n]", nome_campista);
                            printf("A nova idade do campista: ");
                            scanf("%i", &idade_campista);
                            
                            printf("Novo numero do chale\n");
                            VerTodosSimples(meiosangue, "chale");
                            scanf("%i", &pai_divino);

                            if (pai_divino <= 12 && pai_divino > 0)
                            {
                                printf("\nSelecione o novo satiro\n");
                                VerTodosSimples(meiosangue, "satiro");
                                printf("%i. Adicionar outro\n", meiosangue.qtd_satiros + 1);
                                scanf("%i", &id_satiro);

                                if (id_satiro <= meiosangue.qtd_satiros)
                                {
                                    printf("\nSelecione a arma escolhida pelo semideus\n");
                                    VerTodosSimples(meiosangue, "arma");
                                    printf("%i. Adicionar outra\n", meiosangue.qtd_armas + 1);
                                    scanf("%i", &id_arma);
                                    system("cls");

                                    if (id_arma <= meiosangue.qtd_armas)
                                    {
                                        AtualizarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, id_campista, pai_divino, meiosangue.arma[id_arma - 1], meiosangue.satiro[id_satiro - 1]), id_campista - 1);
                                        VerDado(meiosangue, "campista", id_campista - 1);
                                        pular();
                                    }
                                    else
                                    {
                                        printf("Digite o nome da arma: ");
                                        scanf(" %[^\n]", nome_arma);
                                        printf("Digite o dano da arma: ");
                                        scanf("%i", &dano_arma);
                                        system("cls");

                                        nova_arma = CriarArma(nome_arma, meiosangue.qtd_armas + 1, dano_arma);
                                        CadastrarArma(&meiosangue, nova_arma);

                                        AtualizarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, id_campista, pai_divino, nova_arma, meiosangue.satiro[id_satiro - 1]), id_campista - 1);
                                        VerDado(meiosangue, "campista", id_campista - 1);
                                        pular();
                                    }
                                }
                                else
                                {
                                    printf("Digite o nome do satiro: ");
                                    scanf(" %[^\n]", nome_satiro);
                                    printf("Digite a idade real do satiro: ");
                                    scanf("%i", &idade_satiro);
                                    printf("Qual o cargo do satiro? ");
                                    scanf(" %[^\n]", rank_satiro);
                                    system("cls");

                                    novo_satiro = CriarSatiro(nome_satiro, idade_satiro, meiosangue.qtd_satiros + 1, rank_satiro);
                                    CadastrarSatiro(&meiosangue, novo_satiro);

                                    printf("\nSelecione a arma escolhida pelo semideus\n");
                                    VerTodosSimples(meiosangue, "arma");
                                    printf("%i. Adicionar outra\n", meiosangue.qtd_armas + 1);
                                    scanf("%i", &id_arma);
                                    system("cls");

                                    if (id_arma <= meiosangue.qtd_armas)
                                    {
                                        AtualizarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, id_campista, pai_divino, meiosangue.arma[id_arma - 1], novo_satiro), id_campista - 1);
                                        VerDado(meiosangue, "campista", id_campista - 1);
                                        pular();
                                    }
                                    else
                                    {
                                        printf("Digite o nome da arma: ");
                                        scanf(" %[^\n]", nome_arma);
                                        printf("Digite o dano da arma: ");
                                        scanf("%i", &dano_arma);
                                        system("cls");

                                        nova_arma = CriarArma(nome_arma, meiosangue.qtd_armas + 1, dano_arma);
                                        CadastrarArma(&meiosangue, nova_arma);

                                        AtualizarCampista(&meiosangue, CriarCampista(nome_campista, idade_campista, id_campista, pai_divino, nova_arma, novo_satiro), id_campista - 1);
                                        VerDado(meiosangue, "campista", id_campista - 1);
                                        pular();
                                    }
                                }
                            }
                            else
                            {
                                printf("Opcao invalida!");
                                pular();
                            }
                        }
                        else
                        {
                            printf("Campista nao encontrado!");
                        }
                        break;
                    }
                    case 4: //remover
                    {
                        printf("Digite o numero do campista que deseja remover: ");
                        scanf("%i", &id_campista);

                        if (id_campista <= meiosangue.qtd_campistas)
                        {
                            printf("Deseja remover %s? Responda S para sim e N para nao\n", meiosangue.campista[id_campista - 1].nome);
                            int ch;
                            while ((ch = getchar()) != '\n' && ch != EOF)
                                continue;

                            scanf("%c", &check);

                            if (check == 'S')
                            {
                                RemoverDado(&meiosangue, "campista", id_campista - 1);
                                printf("Campista removido!\n");
                                pular();
                            }
                            else
                            {
                                printf("Operacao cancelada!\n");
                                pular();
                            }
                        }
                        else
                        {
                            printf("Campista nao encontrado!\n");
                            pular();
                        }
                        break;
                    }                                                    
                }
                break;
            }
            case 2: //satiros
            {
                menu("satiro", "");
                scanf("%i", &opt2);
                system("cls");

                switch (opt2)
                {
                    case 1: //criar
                    {
                        printf("Digite o nome do satiro: ");
                        scanf(" %[^\n]", nome_satiro);
                        printf("Digite a idade do satiro: ");
                        scanf("%i", &idade_satiro);
                        printf("Digite o cargo do satiro: ");
                        scanf(" %[^\n]", rank_satiro);
                        system("cls");

                        CadastrarSatiro(&meiosangue, CriarSatiro(nome_satiro, idade_satiro, meiosangue.qtd_satiros + 1, rank_satiro));
                        VerDado(meiosangue, "satiro", meiosangue.qtd_satiros - 1);
                        pular();

                        break;
                    }
                    case 2: //visualizar
                    {
                        menu("satiro", "ver");
                        scanf("%i", &opt3);
                        system("cls");

                        if (opt3 <= 3)
                        {
                            switch(opt3)
                            {
                                case 1:
                                {
                                    VerTodos(meiosangue, "satiro");
                                    pular();
                                    break;
                                }
                                case 2:
                                {
                                    printf("Digite o numero do satiro: ");
                                    scanf("%i", &id_satiro);
                                    system("cls");

                                    if (id_satiro <= meiosangue.qtd_satiros)
                                    {
                                        VerDado(meiosangue, "satiro", id_satiro - 1);
                                        pular();
                                    }
                                    else
                                    {
                                        erro();
                                    }
                                    break;
                                }
                            }
                        }
                        else{
                            erro();
                        }
                        break;
                    }
                    case 3: //editar
                    {
                        printf("Digite o numero do satiro que deseja editar: ");
                        scanf("%i", &id_satiro);
                        system("cls");

                        if (id_satiro <= meiosangue.qtd_satiros)
                        {
                            printf("Digite o novo nome do satiro: ");
                            scanf(" %[^\n]", nome_satiro);
                            printf("Digite a nova idade do satiro: ");
                            scanf("%i", &idade_satiro);
                            printf("Digite o novo cargo do satiro: ");
                            scanf(" %[^\n]", rank_satiro);
                            system("cls");

                            AtualizarSatiro(&meiosangue, CriarSatiro(nome_satiro, idade_satiro, id_satiro, rank_satiro), id_satiro - 1);
                            VerDado(meiosangue, "satiro", id_satiro - 1);
                            pular();
                        }
                        else
                        {
                            erro();
                        }

                        break;
                    }
                    case 4:
                    {
                        printf("Digite o numero do satiro que deseja remover: ");
                        scanf("%i", &id_satiro);

                        if (id_satiro <= meiosangue.qtd_satiros)
                        {
                            printf("Deseja remover %s? Responda S para sim e N para não\n", meiosangue.satiro[id_satiro - 1].nome);
                            scanf("%c", &check);
                            if (check == 'S')
                            {
                                RemoverDado(&meiosangue, "satiro", id_satiro - 1);
                                printf("Satiro removido!\n");
                                pular();
                            }
                            else
                            {
                                printf("Operacao cancelada!\n");
                                pular();
                            }
                        }
                        else
                        {
                            printf("Satiro nao encontrado!\n");
                            pular();
                        }
                        break;
                    }
                }
                if (opt2 > 5)
                {
                    erro();
                }
                break;
            }
            case 3: //armas
            {
                menu("arma", "");
                scanf("%i", &opt2);
                system("cls");

                if (opt2 <= 5)
                {
                    switch(opt2)
                    {
                        case 1:
                        {
                            printf("Digite o nome da arma: ");
                            scanf(" %[^\n]", nome_arma);
                            printf("Digite o dano da arma: ");
                            scanf("%i", &dano_arma);
                            system("cls");

                            CadastrarArma(&meiosangue, CriarArma(nome_arma, meiosangue.qtd_armas + 1, dano_arma));
                            VerDado(meiosangue, "arma", meiosangue.qtd_armas - 1);
                            pular();
                            break;
                        }
                        case 2:
                        {
                            menu("arma", "ver");
                            scanf("%i", &opt3);
                            system("cls");

                            if (opt3 <= 3)
                            {
                                switch (opt3)
                                {
                                    case 1:
                                    {
                                        VerTodos(meiosangue, "arma");
                                        pular();
                                        break;
                                    }
                                    case 2:
                                    {
                                        printf("Digite o numero da arma: ");
                                        scanf("%i", &id_arma);
                                        system("cls");

                                        if (id_arma <= meiosangue.qtd_armas)
                                        {
                                            VerDado(meiosangue, "arma", id_arma - 1);
                                            pular();
                                        }
                                        else
                                        {
                                            erro();
                                        }
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                erro();
                            }
                            break;
                        }
                        case 3:
                        {
                            printf("Digite o numero da arma que deseja editar: ");
                            scanf("%i", &id_arma);
                            system("cls");

                            if (id_arma <= meiosangue.qtd_armas)
                            {
                                printf("Digite o novo nome da arma: ");
                                scanf(" %[^\n]", nome_arma);
                                printf("Digite o novo dano da arma: ");
                                scanf("%i", &dano_arma);
                                system("cls");

                                AtualizarArma(&meiosangue, CriarArma(nome_arma, id_arma, dano_arma), id_arma - 1);
                                VerDado(meiosangue, "arma", id_arma- 1);
                                pular();
                            }
                            else
                            {
                                erro();
                            }

                            break;
                        }
                        case 4:
                        {
                            printf("Digite o numero da arma que deseja remover: ");
                            scanf("%i", &id_arma);

                            if (id_arma <= meiosangue.qtd_armas)
                            {
                                printf("Deseja remover %s? Responda S para sim e N para não\n", meiosangue.arma[id_arma - 1].nome);
                                scanf("%c", &check);
                                if (check == 'S')
                                {
                                    RemoverDado(&meiosangue, "arma", id_arma - 1);
                                    printf("Satiro removido!\n");
                                    pular();
                                }
                                else
                                {
                                    printf("Operacao cancelada!\n");
                                    pular();
                                }
                            }
                            else
                            {
                                printf("Satiro nao encontrado!\n");
                                pular();
                            }
                            break;
                        }
                    }
                }
                else{
                    erro();
                }
            }
        }
        if (opt1 > 4)
        {
            erro();
        }
    } while (opt1 != 4);
    
    printf("________________________________________\n\n");
    printf("Desenvolvido por Iury Mikael Sobral dos Santos\n");
    printf("Baseado nos livros de Rick Riordan\n");
    printf("________________________________________\n");


}

//Create
struct Acampamento CriarAcampamento()
{
    struct Acampamento novo_acampamento;
    novo_acampamento.qtd_armas = 0;
    novo_acampamento.qtd_campistas = 0;
    novo_acampamento.qtd_satiros = 0;
    return novo_acampamento;
}

struct Campista CriarCampista(char nome_campista[], int idade_campista, int id_campista, int id_pai, struct Arma arma_campista, struct Satiro satiro_campista)
{
    struct Campista novo_campista;
    strcpy(novo_campista.nome, nome_campista);
    novo_campista.id = id_campista;
    novo_campista.id_pai_divino = id_pai;
    novo_campista.idade = idade_campista;
    novo_campista.arma = arma_campista;
    novo_campista.satiro = satiro_campista;
    return novo_campista;
}

struct Satiro CriarSatiro(char nome_satiro[], int idade_satiro, int id_satiro, char rank_satiro[])
{
    struct Satiro novo_satiro;
    strcpy(novo_satiro.nome, nome_satiro);
    strcpy(novo_satiro.rank, rank_satiro);
    novo_satiro.id = id_satiro;
    novo_satiro.idade = idade_satiro;
    return novo_satiro;    
}

struct Arma CriarArma(char nome_arma[], int id_arma, int dano_arma)
{
    struct Arma nova_arma;
    strcpy(nova_arma.nome, nome_arma);
    nova_arma.id = id_arma;
    nova_arma.dano = dano_arma;
    return nova_arma;
}

int CadastrarCampista(struct Acampamento *acampamento, struct Campista novo_campista)
{
    if (acampamento->qtd_campistas < 240)
    {
        acampamento->campista[acampamento->qtd_campistas] = novo_campista;
        acampamento->qtd_campistas++;
        return 0;
    }
    else
    {
        return 1;
    }
}

int CadastrarSatiro(struct Acampamento *acampamento, struct Satiro novo_satiro)
{
    if (acampamento->qtd_satiros < 100)
    {
        acampamento->satiro[acampamento->qtd_satiros] = novo_satiro;
        acampamento->qtd_satiros++;
        return 0;
    }
    else
    {
        return 1;
    }
}

int CadastrarArma(struct Acampamento *acampamento, struct Arma nova_arma)
{
    if (acampamento->qtd_armas < 100)
    {
        acampamento->arma[acampamento->qtd_armas] = nova_arma;
        acampamento->qtd_armas++;
        return 0;
    }
    else
    {
        return 1;
    }
}


//Read
int VerDado(struct Acampamento acampamento, char dado[], int index)
{
    if (strcmp(dado, "campista") == 0)
    {
        if (acampamento.qtd_campistas > 0)
        {
            struct Campista campista = acampamento.campista[index];
            printf("_________ Campista #%i _________\n", campista.id);
            printf("Nome: %s\n", campista.nome);
            printf("Idade: %i anos\n", campista.idade);
            printf("Parente divino: %s\n", chales[campista.id_pai_divino - 1]);
            printf("Chale: %i\n", campista.id_pai_divino);
            printf("Arma escolhida: %s\n", campista.arma.nome);
            printf("Satiro: %s\n", campista.satiro.nome);
            printf("\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "arma") == 0)
    {
        if (acampamento.qtd_armas > 0)
        {
            struct Arma arma = acampamento.arma[index];
            printf("_________ Arma #%i _________\n", arma.id);
            printf("%s\n", arma.nome);
            printf("Dano: %i\n", arma.dano);
            printf("\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "satiro") == 0)
    {
        if (acampamento.qtd_satiros > 0)
        {
            struct Satiro satiro = acampamento.satiro[index];
            printf("_________ Satiro #%i _________\n", satiro.id);
            printf("Nome: %s\n", satiro.nome);
            printf("Idade: %i anos\n", satiro.idade);
            printf("Idade aparente: %i anos\n", satiro.idade/2);
            printf("Cargo: %s\n", satiro.rank);
            printf("\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int VerTodos(struct Acampamento acampamento, char dado[])
{
    int i;
    if (strcmp(dado, "campista") == 0)
    {
        if (acampamento.qtd_campistas > 0)
        {
            for (i = 0; i < acampamento.qtd_campistas; i++)
            {
                VerDado(acampamento, "campista", i);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "arma") == 0)
    {
        if (acampamento.qtd_armas > 0)
        {
            for (i = 0; i < acampamento.qtd_armas; i++)
            {
                VerDado(acampamento, "arma", i);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "satiro") == 0)
    {
        if (acampamento.qtd_satiros > 0)
        {
            for (i = 0; i < acampamento.qtd_satiros; i++)
            {
                VerDado(acampamento, "satiro", i);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int VerTodosSimples(struct Acampamento acampamento, char dado[])
{
    int i;
    if (strcmp(dado, "campista") == 0)
    {
        if (acampamento.qtd_campistas > 0)
        {
            for (i = 0; i < acampamento.qtd_campistas; i++)
            {
                printf("%i. %s\n", acampamento.campista[i].id, acampamento.campista[i].nome);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "arma") == 0)
    {
        if (acampamento.qtd_armas > 0)
        {
            for (i = 0; i < acampamento.qtd_armas; i++)
            {
                printf("%i. %s\n", acampamento.arma[i].id, acampamento.arma[i].nome);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "satiro") == 0)
    {
        if (acampamento.qtd_satiros > 0)
        {
            for (i = 0; i < acampamento.qtd_satiros; i++)
            {
                printf("%i. %s\n", acampamento.satiro[i].id, acampamento.satiro[i].nome);
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(dado, "chale") == 0)
    {
        for (i = 0; i < 12; i++)
            {
                printf("%i. %s\n", i + 1, chales[i]);
            }
            return 0;
    }
}



//Update
void AtualizarCampista(struct Acampamento *acampamento, struct Campista campista, int index)
{
    acampamento->campista[index] = campista;
}

void AtualizarArma(struct Acampamento *acampamento, struct Arma arma, int index)
{
    acampamento->arma[index] = arma;
}

void AtualizarSatiro(struct Acampamento *acampamento, struct Satiro satiro, int index)
{
    acampamento->satiro[index] = satiro;
}

//Delete
void RemoverDado(struct Acampamento *acampamento, char dado[], int index)
{
    int i;
    if (strcmp(dado, "campista") == 0)
    {
        for (i = index; i < acampamento->qtd_campistas; i++)
        {
            acampamento->campista[i] = acampamento->campista[i + 1];
            acampamento->campista[i].id -= 1;
        }
        acampamento->qtd_campistas--;
    }
    else if (strcmp(dado, "arma") == 0)
    {
        for (i = index; i < acampamento->qtd_armas; i++)
        {
            acampamento->arma[i + 1].id = acampamento->arma[i].id;
            acampamento->arma[i] = acampamento->arma[i + 1];
        }
        acampamento->qtd_armas--;
    }
    else if (strcmp(dado, "satiro") == 0)
    {
        for (i = index; i < acampamento->qtd_satiros; i++)
        {
            acampamento->satiro[i + 1].id = acampamento->satiro[i].id;
            acampamento->satiro[i] = acampamento->satiro[i + 1];
        }
        acampamento->qtd_satiros--;
    }
}


//extras
void pular()
{
    system("pause");
    system("cls");
}

void menu(char dado[], char opt[])
{
    if (strcmp(opt, "ver") == 0)
    {
        printf("_________ Visualizar %ss _________\n", dado);
        printf("_________ Digite a opcao desejada _________\n\n");
        printf("1 - Ver todos os %ss\n", dado);
        printf("2 - Buscar %s por numero\n", dado);
        printf("3 - Voltar\n");
    }
    else if (strcmp(opt, "vcamp") == 0)
    {
        printf("_________ Visualizar %ss _________\n", dado);
        printf("_________ Digite a opcao desejada _________\n\n");
        printf("1 - Ver todos os %ss\n", dado);
        printf("2 - Buscar %s por numero\n", dado);
        printf("3 - Visualizar %s por chale\n", dado);
        printf("4 - Voltar\n");
    }
    else
    {
        printf("_________ Gerenciar %ss _________\n", dado);
        printf("_________ Digite a opcao desejada _________\n\n");
        printf("1 - Adicionar %s\n", dado);
        printf("2 - Visualizar %ss\n", dado);
        printf("3 - Editar %s\n", dado);
        printf("4 - Remover %s\n", dado);
        printf("5 - Voltar\n");
    }

}

void erro()
{
    printf("Opcao inexistente!\n");
    pular();
}