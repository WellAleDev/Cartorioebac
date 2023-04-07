#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o por cadastrar os usu�rios no sistema
{
	// Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usuario
	scanf("%s", cpf); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // "w" =write/escrever cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usuario
	scanf("%s",nome); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o do usuario
	scanf("%s",sobrenome); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que n�o fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o do usuario
	scanf("%s", cargo); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); // Pausa o sistema at� ter intera��o com usuario
	
}

int consulta() // Fun��o por consultar os usu�rios no sistema
{

	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vari�veis/string
	printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usuario
	scanf("%s",cpf); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler l� o arquivo
	
	if(file == NULL) // refere-se caso a leitura feita no arquivo seja nulo, n�o encontre a informa��o inserida pelo usuario
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); // O sistema responde informando que � poss�vel localizar o que foi inserido
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Fun��o utilizada para quantas vezes for necess�ria para repetir-se uma instru��o (while = Enquanto)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
		printf("\n\n"); // \n utilizado para pular a linha e deixar o programa mais interativo
	}	
	
	system("pause"); // Pausa o sistema at� ter intera��o com usuario
	
}

int deletar () // Fun��o para deletar os usu�rios no sistema
{
	// Inicio cria��o de vari�veis/string
	char cpf[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��o do usuario
	scanf("%s", cpf); // %s utilizado para armazenar a resposta do usu�rio, refere-se a string
	
	remove(cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler l� o arquivo
	
	if(file == NULL) // (If = se) Fun��o utilizada para uma fun��o l�gica, no caso estamos dizendo se a fun��o for nula apresentar a mensagem abaixo.
	{
		printf(" O usu�rio n�o se encontra no sistema!.\n"); // O sistema responde informando que o usuario n�o esta mais cadastrado no banco
		system("pause"); // Pausa o sistema at� ter intera��o com usuario
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
		printf("Escolha a op��o desejada do menu:\n\n"); // Intera��o do sistema com o usuario
		printf("\t1 - Registrar nomes\n"); // Primeira op��o
		printf("\t2 - Consultar nomes\n"); // Segunda op��o
		printf("\t3 - Deletar nomes\n\n"); // Terceira op��o
		printf("\t4 - Sair do sistema\n\n"); // Quarta op��o
		printf("op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls"); // responsavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: // primeiro caso ou primeira op��o
			registro(); //chamada de fun��es
			break; // encerra a execu��o
			
			case 2: // segundo caso ou segunda op��o
			consulta();	//consulta fun��es		
			break; // encerra a execu��o
			
			case 3: // terceiro caso ou terceira op��o
			deletar(); //deleta fun��es
			break; // encerra a execu��o
			
			case 4: // quarto caso ou quarta op��o
			printf("Obrigado por utilizar o sistema!\n"); // O sistema responde agradecendo o usuario por utiliza-lo
			return 0; // utilizado para retornar a 0 ou seja voltar tudo independente da fun��o ou la�o que estiver ativa
			break; // encerra a execu��o
			
			default: // (default = padr�o) - neste caso quando o usuario nao utilizar nenhuma das 4 op��es
			printf("Essa op��o n�o est� dispon�vel!\n"); // O sistema informa que a op��o que o usuario digitou n�o esta disponivel
			system("pause"); // Pausa o sistema at� ter intera��o com usuario
			break; // encerra a execu��o
		} //fim da sele��o do menu
	
	}
}
