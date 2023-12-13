#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio de criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criacao de variaveis/string
	
	printf("Voce escolheu o registro de nomes!\n\n");
			
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo na pasta "w"significa write
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" e para abrir o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
	
}

int consulta()
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem em portugues

		char cpf[40];
		char conteudo[200];
		
		printf("Voce escolheu consultar os nomes!\n");
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE*file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("\nNao foi possivel abrir o arquivo, nao localizado!");
			printf("\n\n");			
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas sao as informacoes do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
}

int deletar()
{
		printf("Voce escolheu deletar nomes!\n");
				
		char cpf[40];
		
		printf("Digite o CPF do usuario a ser deletado:");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("\nO usuario nao se encontra no sistema!\n\n");
			system("pause");
		}
		
		while(fgets(cpf, 40, file) != NULL)
		{
			printf("\nUsuario deletado com sucesso!");
			printf("%s", cpf);
			printf("\n\n");
			system("pause");
		}
}

int main()
{		
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			
		system("cls");
					
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opçao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema \n");
		printf("\nOpcao desejada:\n"); //Fim do menu
		
			scanf("%d" , &opcao); //armazenando a escolha do usuario
		
		system("cls"); //responsavel por limpar a tela
			
		switch(opcao) //inicio da selecao do menu
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema de cadastro EBAC!\n\n");
			return 0;
			break;
			
			default:
			printf("Essa opcao nao esta disponivel!\n");
			system("pause");
			break;	
		}//fim da selecao		
	
	}
}
	
