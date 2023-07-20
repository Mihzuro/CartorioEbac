#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco por memoria
#include <locale.h> //biblioteca de alocacao de texto por registro
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criaçao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criaçao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informaçao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza um arquivo e o "a" significa atualizar
	fprintf(file, ","); //coloca uma virgula entre as informações
	fclose(file); //fecha a função
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	

    printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
	
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese_Braszil.1252"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o arquivo\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usúario:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:  ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema. \n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //definindo variaveis
	
	int lacox=1;
	
	for(lacox=1;lacox=1;)
	
   {
   	   system("cls");

	   setlocale(LC_ALL, "Portuguese_Braszil.1252"); //definindo a linguagem
	
	
	   printf("## Cartorio da EBAC ##\n\n"); //inicio do menu
	   printf("## Escolha a opcao de menu desejada ##\n\n");
   	   printf("\t1- Registrar nomes\n");
	   printf("\t2- Consultar os nomes\n");
	   printf("\t3- Deletar os nomes\n\n");
	   printf("Opcao:"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuario
	
	   system("cls"); //responsavel por limpar a tela
	   
	   
	switch(opcao)
	    
	    { 
	       case 1:
	       registro(); //chamada de funções
		   break;
		   
		   case 2: 
		   consultar();
		   break;
		   
		   case 3:  
		   deletar();
		   break;
		   
		   default:printf("Essa opcao nao esta disponivel\n");
		   system("pause");
		   break;
		} //fim da seleção
   }
}
