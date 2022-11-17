#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *cliente;
typedef struct {
char nome[100];
int sexo;
int cpf;
int idade;
int pacote;
int pontos; 
 } dados_cliente;

dados_cliente dadoscliente, cliente_nulo;
int op, i= 0;
void abre_arquivo();
void cadastro();
void lista();
void remover();
void mostre();
int procura();
void mostre();
void abre_arquivo(){
	cliente = fopen("cliente.dat", "a+b");
}
void cadastro(){
 do{    
        printf("\nDigite o seu primeiro nome: ");
			fflush(stdin);           
		    gets(dadoscliente.nome);
         printf("\nDigite o seu cpf: ");
            scanf("%i", &dadoscliente.cpf);
         printf("\nDigite o seu sexo[1= feminino][2 = masculino]: ");
            scanf("%i", &dadoscliente.sexo);
         printf("\nDigite a sua idade: ");
            scanf("%i", &dadoscliente.idade);
         printf("\nDigite qual pacote voce escolheu(1-Premium/2-Ouro/3-Standard): ");
            scanf("%i", &dadoscliente.pacote);
         printf("\nDigite a quantidade de pontos que voce ira querer na sua casa: ");
            scanf("%i", &dadoscliente.pontos);
         printf("\nDigite 1 para continuar ou outro valor para sair: ");
           scanf("%i", &op);
        fseek(cliente,0,SEEK_SET); 
        fwrite(&dadoscliente, sizeof(dados_cliente),1, cliente);
    }while(op == 1);
       

    }

void lista(){
    	rewind (cliente);
       while(feof(cliente)==0){
       		fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       		if(dadoscliente.cpf != 0){   
            printf("\n");
            printf("|Nome:%s |CPF: %i|Sexo: %i|Idade: %i|Pacote:%i|Pontos:%i|", dadoscliente.nome,dadoscliente.cpf, dadoscliente.sexo, dadoscliente.idade,dadoscliente.pacote,dadoscliente.pontos);
            //fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
        
			}
        }

}

void remover(){
    int cpf, conf, resp, posicao;
    cliente_nulo.cpf = 0;
    //cliente_nulo.pacote = 0;
    do{ 
        printf("\n\nRemover aluno\n\n\n");
        printf("Digite o CPF: ");
        scanf("%d", &cpf);
        posicao = procura(cpf);
        if (posicao == -1){
            printf("\nCliente nao encontrado!!\n");
        }else{
            mostre(posicao);
            printf("\n\nDeseja remover o cliente (1-sim/0-nao)? ");
            scanf("%d", &conf);
            if (conf == 1){
            fseek(cliente,posicao*sizeof(dados_cliente),SEEK_SET);
            fwrite(&cliente_nulo,sizeof(dados_cliente), 1, cliente);
            printf("\n\nCliente removido com sucesso!");
            }
            else{
                printf("\nRemocao cancelada!");
            }
        }    
        printf("\n\n\nDeseja remover outro (1-sim/0-nao)? ");
        scanf("%d", &resp);
    }while (resp ==1);
}

int procura(int pcpf){ 
    int p;
    p = 0;
    rewind(cliente);
    //fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
    while (feof(cliente)==0){ 
    	fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
        if (dadoscliente.cpf ==pcpf)
        return p;
        else{ 
            fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
            p++;
        }
    }
    return -1;
}
void mostre(int pos){ 
    fseek(cliente, pos*sizeof(dados_cliente),SEEK_SET);
    fread(&dadoscliente, sizeof(dados_cliente), 1,cliente);
    printf("\n\n");
    printf("Nome: %-20s \nCPF: %d \n Pacote%d \n", dadoscliente.nome, dadoscliente.cpf, dadoscliente.pacote);
}

void consultar(){
    int resp, matcon, posicao;
    do{ 
        printf("\n\nConsultar Aluno\n\n\n");
        printf("Matricula do aluno: ");
        scanf("%d", &matcon);
        posicao = procura(matcon);
        if (posicao == -1){
        printf("\n\nMatricula nao encontrada!\n\n");
        }else{
        mostre(posicao);
        printf("\n\nDeseja consultar outro (1-sim/0-nao)? ");
        scanf("%d", &resp);
        }
    } while (resp == 1);
}




int main (){
abre_arquivo();
  do{
    

     printf("\n");
        printf ("\t\t\t\t       EMPRESA DE TV     \t\t\t\t\n");
        printf ("\t\t\t===================================\n");
        printf("\t\t\t|\t 1 - Cadastrar Cliente           |\n");
        printf("\t\t\t|\t 2 - Listagem geral              |\n");
        printf("\t\t\t|\t 3 - Relatorio estatistico       |\n");
        printf("\t\t\t|\t 4 - Editar cliente              |\n");
        printf("\t\t\t|\t 5 - Remover cliente             |\n");
        printf("\t\t\t|\t 6 - Listar Clientes Por Pacotes |\n");
        printf("\t\t\t|\t 0 - sair                        |\n");
        printf ("\t\t\t===================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        scanf("%i", &op);
        switch (op){
        case 1:
           cadastro();
            break;
        case 2:
           lista();
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:
           remover();
            break;
        case 6:
           
            break;
         case 0:
         fclose(cliente);
            break;
       
        default:
        printf("Opção invalida");
            break;
        }
 } while (op != 0);
 
}
