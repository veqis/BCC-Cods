#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 200
#define TAM_VET 30

enum tipoEndereco { Alameda, Avenida, Praca, Rua, Travessa };
enum tipoContato { Celular, Fixo, Comercial, Pessoal, Fax };
enum tipoSocial { Instagram, Facebook, LinkedIn, outro };


typedef struct agenda {
    char nome [ TAM_NOME ];
    char telefone [ TAM_NOME ];
    char redeSocial [ TAM_NOME ];
    char endereco [ TAM_NOME ];
    char email [ TAM_NOME ];
    char verEnd [ TAM_NOME ];
    char verCon [ TAM_NOME ];
    char verSoci [ TAM_NOME ];
    int numeroCasa, editado;
    enum tipoEndereco tpEnd;
    enum tipoContato tpCon;
    enum tipoSocial tpSoci;
} registro;



//FUNÇÕES PARA ADIÇÃO DE CONTATO
void lerNome ( registro pessoa [ TAM_VET ], int qtdPessoa );
void menuEnd ( registro pessoa [ TAM_VET ], int qtdPessoa );
void lerEnd ( registro pessoa [ TAM_VET ], int qtdPessoa );
void lerNumCasa ( registro pessoa [ TAM_VET ], int qtdPessoa );
void menuCon ( registro pessoa [ TAM_VET ], int qtdPessoa );
void lerCon ( registro pessoa [ TAM_VET ], int qtdPessoa );
void menuSoci ( registro pessoa [ TAM_VET ], int qtdPessoa );
void lerSoci ( registro pessoa [ TAM_VET ], int qtdPessoa );
void lerEmail( registro pessoa [ TAM_VET ], int qtdPessoa );

//FUNÇÕES PARA EDIÇÃO DE DADOS DENTRO DA STRUCT
void capitalizaNomes( registro pessoa [ TAM_VET ], int qtdPessoa ) ;
void editarTelefone ( registro pessoa [ TAM_VET ], int qtdPessoa );
void ordenarNomes ( registro pessoa [ TAM_VET ], int qtdPessoa );
void verificaEmail( registro pessoa [ TAM_VET ], int qtdPessoa );
void editarEnums ( registro pessoa [ TAM_VET ], int qtdPessoa );
char *obterNomeTelefone ( int tpCon );
char *obterNomeEndereco ( int tpEnd );
char *obterNomeSocial ( int tpSoci );

//FUNÇÕES DO MENU
void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void editar ( registro pessoa [ TAM_VET ], int qtdPessoa );
void consultar ( registro pessoa [ TAM_VET ], int qtdPessoa );
void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void imprimeTodos ( registro pessoa [ TAM_VET ], int qtdPessoa );
void salvar ( registro pessoa [ TAM_VET ], int qtdPessoa );
void carregarDados ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void limparTela ( void );
void aguardarParaSeguir ( void );
void verificaArquivo ();


int main()
{
    registro pessoa [ TAM_VET ];

    int menu, qtdPessoa = 0;

    //ESSA FUNÇÃO VERIFICA SE O ARQUIVO DE AGENDA EXISTE PARA EVITAR ERRO DURANTE UMA PRIMEIRA EXECUÇÃO
    verificaArquivo ();

    carregarDados ( pessoa, &qtdPessoa );
    
    do
    {
        printf ( "     AGENDA\n" );
        printf ( "1 - Adicionar pessoas\n" );
        printf ( "2 - Editar contato\n" );
        printf ( "3 - Consutar contato\n");
        printf ( "4 - Remover contato\n" );
        printf ( "5 - Listar contatos\n" );
        printf ( "6 - Salvar\n" );
        printf ( "0 - Finalizar\n" );
        printf ( "Digite sua opcao: " );
        scanf  ( "%i", &menu );

        switch (menu)
        {
        case 0: printf ("Salvando contatos...");
                salvar ( pessoa, qtdPessoa );
        break;

        case 1: addPessoa ( pessoa, &qtdPessoa ); 
                ordenarNomes ( pessoa, qtdPessoa );
        break;

        case 2: editar ( pessoa, qtdPessoa ); break;
        
        case 3: consultar ( pessoa, qtdPessoa ); break;

        case 4: remover ( pessoa, &qtdPessoa ); break;

        case 5: imprimeTodos ( pessoa, qtdPessoa ); break;

        case 6: salvar ( pessoa, qtdPessoa ); break;

        default: printf ( "Opcao invalida!\n" ); break;
        }

        //FUNÇÃO DE LIMPAR TELA
        aguardarParaSeguir ();
    } 
    while (menu != 0);
    
}

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    char continua;
    do
    {
        pessoa [ *qtdPessoa ].editado = 0;

        lerNome ( pessoa, *qtdPessoa );   

        menuEnd ( pessoa, *qtdPessoa );

        lerEnd ( pessoa, *qtdPessoa );

        lerNumCasa ( pessoa, *qtdPessoa );

        menuCon ( pessoa, *qtdPessoa );

        lerCon ( pessoa, *qtdPessoa );

        menuSoci ( pessoa, *qtdPessoa );

        lerSoci ( pessoa, *qtdPessoa );

        lerEmail( pessoa, *qtdPessoa );

        editarTelefone ( pessoa, *qtdPessoa );

        capitalizaNomes ( pessoa, *qtdPessoa );

        editarEnums ( pessoa, *qtdPessoa );

        *qtdPessoa+=1;

        //FILTRO DE ENTRADA 
        printf( "\nDeseja inserir mais uma pessoa? (S/N)\n" );       
        do
        {
            fflush ( stdin );
            continua = tolower ( getchar () );
            if (continua != 'n' && continua != 's')
            {
                printf("\nEntrada invalida, tente novamente: ");
            }
            
        } while (continua != 'n' && continua != 's');
        
    } while (continua != 'n');
    
}

//FUNÇÕES DE LEITURA DE DADOS
//
void lerNome ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nDigite o nome: " );
    fflush ( stdin );
    scanf  ( "%[^\n]", &pessoa[qtdPessoa].nome );  
}

void menuEnd ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nSelecione o tipo de endereco\n" );
    printf ( "0 - Alameda\n" );
    printf ( "1 - Avenida\n" );
    printf ( "2 - Praca\n" );
    printf ( "3 - Rua\n" );
    printf ( "4 - Travessa\n" );
    printf ( "5 - Rodovia\n" );
    scanf ( "%i", &pessoa[qtdPessoa].tpEnd );
}

void lerEnd ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nDigite o endereco: ");
    fflush ( stdin );
    scanf ( "%[^\n]s", &pessoa[qtdPessoa].endereco );
}

void lerNumCasa ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "Digite o numero da casa: " );
    scanf ( "%i", &pessoa[qtdPessoa].numeroCasa );
}

void menuCon ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nSelecione o tipo de telefone\n" );
    printf ( "0 - Celular\n" );
    printf ( "1 - Fixo\n" );
    printf ( "2 - Comercial\n" );
    printf ( "3 - Pessoal\n" );
    printf ( "4 - Fax\n" );
    scanf ( "%i", &pessoa[qtdPessoa].tpCon );
}

void lerCon ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nDigite o numero de telefone: ");
    fflush ( stdin );
    scanf ( "%[^\n]", &pessoa[qtdPessoa].telefone );
}

void menuSoci ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nSelecione o tipo de rede social\n" );
    printf ( "0 - Instagram\n" );
    printf ( "1 - Facebook\n" );
    printf ( "2 - LinkedIn\n" );
    printf ( "3 - outro\n" );
    scanf ( "%i", &pessoa[qtdPessoa].tpSoci );
}

void lerSoci ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "\nDigite a rede social: ");
    fflush ( stdin );
    scanf ( "%[^\n]", &pessoa[qtdPessoa].redeSocial );
}

void lerEmail ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    printf ( "Digite o e-mail ");
    fflush ( stdin );
    scanf ( "%[^\n]", &pessoa[qtdPessoa].email );
    verificaEmail ( pessoa, qtdPessoa );
}

//FUNÇÕES DO MENU
//
void imprimeTodos ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //FUNÇÃO QUE IMPRIME TODAS AS PESSOAS
    for (int i = 0; i < qtdPessoa; i++)
    {
       imprime ( pessoa, i, qtdPessoa );  
    }
}

void imprime ( registro pessoa [ TAM_VET ], int i, int qtdPessoa )
{
    char subContato [ 21 ];
    char subSocial [ 21 ];

    sprintf ( subContato, "%s %s", pessoa[i].verCon, pessoa[i].telefone );
    sprintf ( subSocial, "%s %s", pessoa[i].verSoci, pessoa[i].redeSocial );

    printf ( "| %-15s | %s %-15s %-6i | %-20s | %-20s | %-15s |\n", 
    pessoa[i].nome, 
    pessoa[i].verEnd, 
    pessoa[i].endereco, 
    pessoa[i].numeroCasa, 
    subContato, 
    subSocial, 
    pessoa[i].email );
}

void editar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //FUNÇÃO DE EDITAR CONTATOS

    int menu;
    char continua;
    char busca [50];
    int achou = 0;

    printf("Insira o nome do contato: ");
    fflush(stdin);
    gets( busca );

    for (int i = 0; i < qtdPessoa; i++)
    {
        if( strcmp ( busca, pessoa[i].nome )==0)
        {
            imprime ( pessoa, i, qtdPessoa );
            
            achou = 1;
            
            
            //FILTRO DE ENTRADA 
            printf("Deseja alterar o contato selecionado? (S/N): ");
            do
            {
                fflush ( stdin );
                continua = tolower ( getchar () );
                if (continua != 'n' && continua != 's')
                {
                    printf( "Entrada invalida, tente novamente: " );
                }else if ( continua == 'n' )
                {
                    printf( "Edicao cancelada!" );
                    return 0;
                }
                
            } while ( continua != 'n' && continua != 's' );

           
            //MENU DE EDIÇÃO
            printf ( "Selecione o campo a editar: \n" );
            printf ( "1 - Nome\n" );
            printf ( "2 - Tipo endereco\n" );
            printf ( "3 - Endereco\n");
            printf ( "4 - Numero\n" );
            printf ( "5 - Tipo telefone\n" );
            printf ( "6 - Telefone\n" );
            printf ( "7 - Tipo social\n" );
            printf ( "8 - Rede social\n" );
            printf ( "9 - E-mail\n" );
            printf ( "Digite sua opcao: " );
            scanf  ( "%i", &menu );

            switch (menu)
            {
            case 1: lerNome ( pessoa, i ); break;

            case 2: menuEnd ( pessoa, i ); break;

            case 3: lerEnd ( pessoa, i ); break;

            case 4: lerNumCasa ( pessoa, i ); break;

            case 5: menuCon ( pessoa, i ); break;

            case 6: lerCon ( pessoa, i );
                    pessoa[ i ].editado = 0;
                    break;

            case 7: menuSoci ( pessoa, i ); break;

            case 8: lerSoci ( pessoa, i ); break;

            case 9: lerEmail( pessoa, i ); break;

            default: printf ( "Opcao invalida!\n" ); break;
            }
        }
    }
    if (achou == 0)
    {
        printf("Contato nao encontrado");
    }
}

void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    //FUNÇÃO PARA REMOVER CONTATOS
    char busca [50];
    int achou = 0;
    char continua;

    printf("Insira o nome do contato: ");
    fflush(stdin);
    gets( busca );

    for (int i = 0; i < *qtdPessoa; i++)
    {
        if( strcmp ( busca, pessoa[i].nome )==0)
        {
            imprime ( pessoa, i, *qtdPessoa );

            achou = 1;

            //FILTRAGEM DE ENTRADA E VERIFICASÃO CAJO HAJA ERRO DE SELEÇÃO
            printf("Deseja deletar o contato selecionado? (S/N): ");      
            do
            {
                fflush ( stdin );
                continua = tolower ( getchar () );

                if (continua != 'n' && continua != 's')
                {
                    printf( "Entrada invalida, tente novamente: " );

                }else if ( continua == 'n' )
                {
                    printf( "Remocao cancelada!" );
                    return 0;
                }
                
            } while ( continua != 'n' && continua != 's' );

            //REMOÇÃO DO CONTATO E REALOCAÇÃO DE POSIÇÕES
            for ( int j = i; j <= *qtdPessoa; j++ )
            {
                pessoa[ j ] = pessoa[ j + 1 ];
            }

            (*qtdPessoa)--;
        }
    }
    if (achou == 0)
    {
        printf("Contato nao encontrado");
    }
}

void consultar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //FUNÇÃO QUE BUSCA UM CONTATO ESPECIFICO PELO NOME
    //CASO HAJA MAIS DE UM CONTATO COM O MESMO NOME SÃO IMPRESSOS AMBOS

    char busca [50];
    int achou = 0;

    printf("Insira o nome do contato: ");
    fflush(stdin);
    gets( busca );

    for (int i = 0; i < qtdPessoa; i++)
    {
        if( strcmp ( busca, pessoa[i].nome )==0)
        {
            imprime ( pessoa, i, qtdPessoa );
            
            achou = 1;
        }
    }
    if (achou == 0)
    {
        printf("Contato nao encontrado");
    }

}

void salvar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //FUNÇÃO QUE SALVA TODOS OS CONTATOS INSERIDOS NO ARQUIVO DE AGENDA
    FILE *arquivo = NULL;
    
    arquivo = fopen ( "agenda.csv", "w" );

    if ( !arquivo )
    {
        printf ( "Nao foi possivel abrir o arquivo" );
        return 0;
    }
    
    //LOOP QUE SEGUE POR TODOS OS DADOS DO CONTATO
    for (int i = 0; i < qtdPessoa; i++)
    {
        fprintf ( arquivo, "%s;", pessoa[i].nome );
        fprintf ( arquivo, "%s %s;%i;", pessoa[i].verEnd, pessoa[i].endereco, pessoa[i].numeroCasa );
        fprintf ( arquivo, "%s %s;", pessoa[i].verCon, pessoa[i].telefone );
        fprintf ( arquivo, "%s %s;", pessoa[i].verSoci, pessoa[i].redeSocial  );
        fprintf ( arquivo, "%s;\n", pessoa[i].email );
    }
    
    fclose ( arquivo );
}

void carregarDados ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    //FUNÇÃO DE LEITURA DO ARQUIVO DE AGENDA

  FILE *arquivo;
  arquivo = fopen("agenda.csv", "r");

  int lidos = 0;

  do
  {
    lidos = fscanf ( arquivo," %49[^;];%s %49[^;];%i;%s %49[^;];%s %49[^;];%49[^;];", 
    pessoa[*qtdPessoa].nome,
    pessoa[*qtdPessoa].verEnd,
    pessoa[*qtdPessoa].endereco,
    &pessoa[*qtdPessoa].numeroCasa,
    pessoa[*qtdPessoa].verCon,
    pessoa[*qtdPessoa].telefone,
    pessoa[*qtdPessoa].verSoci,
    pessoa[*qtdPessoa].redeSocial,
    pessoa[*qtdPessoa].email);

    pessoa[*qtdPessoa].editado = 1;

    if ( lidos == 9 )
    {
      *qtdPessoa+=1;
    }
    if ( lidos != 9 && !feof(arquivo) )
    {
      printf ( "ERRO!!!\n" );
      return 1;
    }

  } while ( !feof(arquivo) );

  fclose(arquivo);
}

void verificaArquivo ()
{
    //ESSA FUNÇÃO VERIFICA SE JÁ EXISTE UM ARQUICO DE AGENDA
    //CASO NÃO EXISTA ESSE ARQUIVO ELE CRIA UM PARA EVITAR QUE HAJA ERRO

    FILE *arquivo;
    
    if (arquivo = fopen("agenda.csv", "r")) 
    {
        fclose(arquivo);
    }
    else
    {
        arquivo = fopen ( "agenda.csv", "w" );
        fclose ( arquivo );
    }
    
}

//ESSAS 3 FUNÇÕES PEGAM O VALOR EM INT SELECIONADO DURANTE A CRIAÇÃO DE CONTATO
//E INSEREM A STRING SELECIONADA DENTRO DE UMA STRUCT
char *obterNomeEndereco ( int tpEnd )
{
    const char *nomeEndereco[] =
    {
        "Ala.", "Ave.", "Pra.", "Rua.", "Tra.", "Rod."
    };

    return ( nomeEndereco [ tpEnd ] );
}

char *obterNomeTelefone ( int tpCon )
{
    const char *nomeTelefone[] =
    {
        "Cel.", "Fix.", "Com.", "Pes.", "Fax."
    };

    return ( nomeTelefone [ tpCon ] );
}

char *obterNomeSocial ( int tpSoci )
{
    const char *nomeSocial[] =
    {
        "Ins.", "Fac.", "Lin.", ""
    };

    return ( nomeSocial [ tpSoci ] );
}

void editarEnums ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //ESSA FUNÇÃO PEGA O OUTPUT DAS ANTERIORES E COLOCA DENTRO DE UMA PARTE DO STRUCT
    //ISSO FACILITA A MANUPULAÇÃO DE DADOS QUANDO O ARQUIVO É SALVO E LIDO NOVAMENTE

    sprintf ( pessoa[qtdPessoa].verEnd, "%s", obterNomeEndereco ( pessoa[qtdPessoa].tpEnd ) );
    sprintf ( pessoa[qtdPessoa].verCon, "%s", obterNomeTelefone ( pessoa[qtdPessoa].tpCon ) );
    sprintf ( pessoa[qtdPessoa].verSoci, "%s", obterNomeSocial ( pessoa[qtdPessoa].tpSoci ) );
}

//FUNÇÕES PARA MANIPULAÇÃO DE DADOS DENTRO DA STRUCT
//
void capitalizaNomes ( registro pessoa [ TAM_VET ], int qtdPessoa ) 
{
    //FUNÇÃO QUE SUBSTITUI A PRIMEIRA LETRA DE CADA
    //PALAVRA PELA SUA VERSÃO MAIUSCULA

    for(int i = 0; i < TAM_NOME; i++)
    {
        //capitalizar primeiro nome
        if(i==0) 
        {
        pessoa[qtdPessoa].nome [ i ] = toupper ( pessoa[qtdPessoa].nome [ i ] );
        }

        //capitalizar nomes que antecedem espaço
        if( pessoa[qtdPessoa].nome [i] == ' ') 
        {
        pessoa[qtdPessoa].nome [ i + 1 ] = toupper ( pessoa[qtdPessoa].nome [ i + 1 ] );
        }
    }
}

void ordenarNomes ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //ESSA FUNÇÃO PEGA OS NOMES DE CADA CONTATO
    //E ORGANIZA TODOS POR ORDEM ALFABETICA
    //LEVANDO TODOS OS DADOS DO CONTATO JUNTOS
    
    struct agenda temp;

    for (int i = 0; i < qtdPessoa; i++)
    {
        
        for (int j = i + 1; j < qtdPessoa; j++)
        {
        if (strcmp (pessoa[i].nome, pessoa[j].nome) > 0) 
        {
            temp = pessoa[i];
            pessoa[i] = pessoa[j];
            pessoa[j] = temp;
        }
        }    
    }
}

void verificaEmail ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //ESSA FUNÇÃO VERIFICA SE A STRING DO EMAIL DIGITADO POSSUI @ E PONTO
    //APÓS ISSO ELA VERIFICA SE O @ ESTÁ POSICIONADO ANTAES DO PONTO
    //CASO CONTRÁRIO ELA PEDE PARA QUE SEJA DIGITADO EMAIL NOVAMENTE

    char vrArr[] = "@";
    char vrPnt[] = ".";
    char buscaArr = '@';
    char buscaPont = '.';
    int indexPont;
    int indexArr;


    if (strchr(pessoa[qtdPessoa].email, vrArr[0]) == NULL || strchr(pessoa[qtdPessoa].email, vrPnt[0]) == NULL)
    {
        printf( "\n\nEmail invalido\n\n" );
        lerEmail( pessoa, qtdPessoa );
    }


    const char *arr = strchr(pessoa[qtdPessoa].email, buscaArr);
    if(arr) {
        indexArr = arr - pessoa[qtdPessoa].email;
    }
    const char *pnt = strchr(pessoa[qtdPessoa].email, buscaPont);
    if(pnt) {
        indexPont = pnt - pessoa[qtdPessoa].email;
    }

    if (indexArr > indexPont)
    {
        printf( "\n\nEmail invalido\n\n" );
        lerEmail( pessoa, qtdPessoa );
    }
    return 0;
}

void editarTelefone ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //Funcão que pega o numero de telefone e separa o ddd e cloca a barra entre os numeros 
    //essa função tambem verifica se o cantato já foi editado e não repete o processo
    // 1 = CONTATO JÀ EDITADO ; 0 = CONTATO NÂO EDITADO
    char DDD[3], parte1[6], parte2[6], telefone[20];

    if ( pessoa[ qtdPessoa ].editado == 1  )
    {
        return 0;
    }
    else
    {
        strncpy ( DDD, &pessoa [ qtdPessoa ].telefone [ 0 ], 2 );
        strncpy ( parte1, &pessoa [ qtdPessoa ].telefone [ 2 ], 5 );
        strncpy ( parte2, &pessoa [ qtdPessoa ].telefone [ 7 ], 5 );

        DDD [2] = parte1 [5] = parte2 [5] = '\0';

        sprintf ( telefone, "(%s)%s-%s", DDD, parte1, parte2 );

        strncpy ( pessoa[qtdPessoa].telefone, telefone, 14 );

        pessoa[ qtdPessoa ].editado = 1;
    }


}



//ESSAS DUAS FUNÇÕES SERVEM PARA LIMPAR
//A TELA APÓS CADA OPERAÇÃO DO MENU
void limparTela ( void )
{
    #ifdef __linux__
        system ( "clear" );
    #elif _WIN32
        system ( "cls" );
    #endif
}

void aguardarParaSeguir ( void )
{
    printf ( "\n\nTecle ENTER para continuar..." );
    fflush ( stdin );
    getchar ();
    limparTela ();
}
