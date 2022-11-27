#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *cliente;
typedef struct {
char nome[100];
int sexo;    //declaração da struct cliente
int cpf;
int idade;
int pacote;
int pontos;
float mensalidade; 
 } dados_cliente; 

dados_cliente dadoscliente, cliente_nulo;
int op, i= 0;         //declaração das variaveis   
int pm =0, pmo=0,qtdcliente=0,cp1=0,tpontos=0;
float per,perpontos, pontos_percentual=0,media_velho;
void abre_arquivo(){
    cliente = fopen("cliente.dat", "r+b");
    if (cliente == NULL)
        cliente = fopen("cliente.dat", "w+b");
}
void percentual(){   //percentual pacotes mulheres
    float per=0;
	rewind(cliente);
    while(feof(cliente)==0){
        fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
        if(dadoscliente.sexo == 1){
            pm = pm+1;          
        }    
        if ((dadoscliente.sexo==1)&&(dadoscliente.pacote==2)){
            pmo = pmo+1;
        }                            
    }
   if((pm!=0)&&(pmo!=0)){
     per = (pmo * 100)/pm;}
    	printf("\nPercentual de mulheres com o pacote ouro: %.2f ",per);
}
void qtdpontos(){      //clientes com mais de 3 pontos 
    rewind (cliente);
    while(feof(cliente)==0){
       	fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       	if(dadoscliente.cpf != 0){   
            qtdcliente = qtdcliente+1;   
		}
        if (dadoscliente.pontos>3){
            cp1 = cp1+1;
        }       
    }
        printf("\nQuantidade de clientes com mais de 3 pontos: %d ",cp1);
}

void percentual_pontos(){ //media da quantidade de pontos 
	rewind (cliente);
    while(feof(cliente)==0){
       	fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       	if(dadoscliente.cpf != 0){ 
		   tpontos = tpontos + dadoscliente.pontos;		       
		}
	}
			
	float pontos_percentual = tpontos/qtdcliente;
	printf("\nMedia de pontos de TV: %.2f", pontos_percentual);	
}

void media_idade(){  //media da mensalidade idosos
	int c_velho=0;
	float valor_idade=0;
	rewind (cliente);
    while(feof(cliente)==0){
       	fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       	if(dadoscliente.cpf != 0){
		   if(dadoscliente.idade>60){
		   		c_velho = c_velho +1;
		   		valor_idade = valor_idade + dadoscliente.mensalidade;	
				   	   	
		   }
		   
		}
	}
	media_velho = valor_idade/c_velho;
	printf("\nMedia da mensalidade dos clientes com mais de 60 anos: R$ %.2f",media_velho);
	
}

void valor_total(){  //valor total da empresa 
	float total_arrecadado;
	rewind (cliente);
    while(feof(cliente)==0){
       	fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       	if(dadoscliente.cpf != 0){
			total_arrecadado = total_arrecadado + dadoscliente.mensalidade;  
		   
		   
	   }
	}
	printf("\nValor total arrecadado pela empresa: %.2f",total_arrecadado);
}





float mens(int x, int y){  //calculo da mensalidade 
    float pt=0;
    float p = 220.00, o = 170.00, s=120.00;
    float p1 =60.00, p2 =40.00, p3 =25.00;
    if (x==1){
        
		if(y>2){
			pt = p + ((p1 * y)*0.85);
		}else{
		pt = p + (p1 * y);
		}
        return pt;
    }else if (x==2){
        if(y>2){
			pt = o + ((p2 * y)*0.85);
		}else{
		pt = o + (p2 * y);
		}
        return pt;
    }else if (x==3){
        if(y>2){
			pt = s + ((p3 * y)*0.85);
		}else{
		pt = s + (p3 * y);
		}

        return pt;
    }
    
}


void pacote1(){
rewind(cliente);
while(feof(cliente)==0){
    fread(&dadoscliente,sizeof(dados_cliente),1,cliente);	
    if(dadoscliente.pacote == 1){
    	printf("\nCliente com pacote Premiun:\n");
        printf("|Nome:%s |CPF: %i|Sexo: %i|Idade: %i|Pacote:%i|Pontos:%i|Mensalidade:%.2f| ", dadoscliente.nome,dadoscliente.cpf, dadoscliente.sexo, dadoscliente.idade,dadoscliente.pacote,dadoscliente.pontos, dadoscliente.mensalidade);   
		fflush(stdin);
    }
}

}
void pacote2(){
rewind(cliente);
while(feof(cliente)==0){
    fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
    if(dadoscliente.pacote == 2){
        printf("\nCliente com pacote Ouro:\n|Nome:%s |CPF: %i|Sexo: %i|Idade: %i|Pacote:%i|Pontos:%i|Mensalidade:%.2f| ", dadoscliente.nome,dadoscliente.cpf, dadoscliente.sexo, dadoscliente.idade,dadoscliente.pacote,dadoscliente.pontos, dadoscliente.mensalidade);   

    }
}

}
void pacote3(){
rewind(cliente);
while(feof(cliente)==0){
    fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
    if(dadoscliente.pacote == 3){
        printf("\nCliente com pacote Standard:\n|Nome:%s |CPF: %i|Sexo: %i|Idade: %i|Pacote:%i|Pontos:%i|Mensalidade:%.2f| ", dadoscliente.nome,dadoscliente.cpf, dadoscliente.sexo, dadoscliente.idade,dadoscliente.pacote,dadoscliente.pontos, dadoscliente.mensalidade);   
		fflush(stdin);
    }
}

}


void cadastro(){  //função de cadastro
 do{    
        printf("\nDigite o seu nome: ");
			fflush(stdin);           
		    //gets(dadoscliente.nome);
        scanf("%s", &dadoscliente.nome);
         printf("\nDigite o seu cpf: ");
            scanf("%i", &dadoscliente.cpf);
         printf("\nDigite o seu sexo[1= feminino][2 = masculino]: ");
            scanf("%i", &dadoscliente.sexo);
            if(dadoscliente.sexo > 2){
            	while(dadoscliente.sexo>2){
            		printf("Sexo nao existente");
            		printf("\nDigite o seu sexo[1= feminino][2 = masculino]: ");
            		scanf("%i", &dadoscliente.sexo);
				}
			}
            
            
         printf("\nDigite a sua idade: ");
            scanf("%i", &dadoscliente.idade);
         printf("\nDigite qual pacote voce escolheu(1-Premium/2-Ouro/3-Standard): ");
            scanf("%i", &dadoscliente.pacote);
        if(dadoscliente.pacote >3){
                while(dadoscliente.pacote>3){
                	printf("Voce digitou um pacote inexistente");
                    printf("\nDigite qual pacote voce escolheu(1-Premium/2-Ouro/3-Standard): ");
            		scanf("%i", &dadoscliente.pacote);
					 }
			}
            
                
         printf("\nDigite a quantidade de pontos que voce ira querer na sua casa: ");
            scanf("%i", &dadoscliente.pontos);
            dadoscliente.mensalidade = mens(dadoscliente.pacote, dadoscliente.pontos);
         printf("\nDigite 1 para continuar ou outro valor para sair: ");
           scanf("%i", &op);
        fseek(cliente,0,SEEK_SET); 
        fwrite(&dadoscliente, sizeof(dados_cliente),1, cliente);
    }while(op == 1);
       

    }

void lista(){ // função de listagem 
    	rewind (cliente);
        while(feof(cliente)==0){
       		fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
       		if(dadoscliente.cpf != 0){   
            printf("\n");
            printf("|Nome:%s |CPF: %i|Sexo: %i|Idade: %i|Pacote:%i|Pontos:%i|Mensalidade: R$%.2f ", dadoscliente.nome,dadoscliente.cpf, dadoscliente.sexo, dadoscliente.idade,dadoscliente.pacote,dadoscliente.pontos, dadoscliente.mensalidade);
            fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
        
			}
        }

}

void mostre(int pos){   //função de mostrar posição
    fseek(cliente, pos*sizeof(dados_cliente),SEEK_SET);
    fread(&dadoscliente, sizeof(dados_cliente), 1,cliente);
    printf("\n\n");
    printf("Nome: %-20s \nCPF: %d \n Pacote%d \n", dadoscliente.nome, dadoscliente.cpf, dadoscliente.pacote);
}
int procura(int pcpf){  //função de procura cliente 
    int p;
    p = 0;
    rewind(cliente);
    //fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
    while (feof(cliente)==0){ 
    	fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
        if (dadoscliente.cpf ==pcpf){
        return p;
        
        }else{ 
            fread(&dadoscliente,sizeof(dados_cliente), 1,cliente);
            p++;
        }
    }
    return -1;
}


void remover(){ //função de remover 
    int xcpf, conf, resp, posicao;
    cliente_nulo.cpf = 0;
    cliente_nulo.pacote = 0;
    cliente_nulo.idade = 0;
    cliente_nulo.mensalidade=0;
    //cliente_nulo.nome = NULL;
    cliente_nulo.pontos=0;
    cliente_nulo.sexo=0;
    do{ 
        printf("\n\nRemover cliente\n\n\n");
        printf("Digite o CPF: ");
        scanf("%d", &xcpf);
        posicao = procura(xcpf);
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


void alterar(){  //função de alterar cliente 
    int cpfalt, conf, resp, posicao;
    do { 
        printf("\n\nAlterar cadastro\n\n\n");
        printf("CPF: ");
        scanf("%d", &cpfalt);
        posicao = procura(cpfalt);
        if (posicao == -1){
            printf("\nCliente nao cadstrado!!\a");
        }else{
            mostre(posicao);
            printf("\n\nAlterar dados do cadastro(1-sim/0-nao)? ");
            scanf("%d", &conf);
            if (conf == 1){ 
                printf("\nNovo cpf: ");
                scanf("%d", &dadoscliente.cpf);
                printf("\nCPF alterado com sucesso! \n\n");
                fseek(cliente,posicao*sizeof(dados_cliente),SEEK_SET);
                fwrite(&dadoscliente,sizeof(dados_cliente), 1,cliente);
                mostre(posicao);
                printf("\nCPF alterado com sucesso!\n");
            }else{
                printf("\n\nAlteracao cancelada!\n\n");
            }
            printf("\n\nDeseja alterar outro (1-sim/0-nao)? ");
            scanf("%d", &resp);
        }
    }while (resp ==1);
}



int main (){ //programa principal 
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
        printf("\t\t\t|\t 7 - sair                        |\n");
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
        	printf("\t\t\trelatorio estatistico da empresa\n");
           	percentual();
           	qtdpontos();
           	percentual_pontos();
           	media_idade();
           	valor_total();
            break;
        case 4:
           	alterar();
            break;
        case 5:
           remover();
            break;
        case 6:
           	pacote1();
           	pacote2();
           	pacote3();
            break;
        case 7:
         	fclose(cliente);
            break;
       
        default:
        printf("Opção invalida");
            break;
        }
 	} while (op != 7);
 
 }



