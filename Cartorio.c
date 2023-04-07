#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das string

int registro() // Fun��o por cadastrar os usu�rios no sistema
{
	// Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // "w" =write/escrever cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s",nome); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s",sobrenome); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cargo); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); // Pausa o sistem at� ter intera��o com usuario
	
}

int consulta() // Fun��o por consultar os usu�rios no sistema
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vari�veis/string
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usuario
	scanf("%s",cpf); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler l� o arquivo
	
	if(file == NULL) // refere-se caso a leitura feita no arquivo seja nulo, n�o encontre a informa��o inserida pelo usuario
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); //O sistema responde informando que � poss�vel localizar o que foi inserido
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
	
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //Fim do menu
		printf("op��o: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();	//consulta fun��es		
			break;
			
			case 3:
			deletar(); //deleta fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o do menu
	
	}
}
