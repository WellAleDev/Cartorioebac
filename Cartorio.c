#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidas das string

int registro() // Função por cadastrar os usuários no sistema
{
	// Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s", cpf); //%s utilizado para armazenar a resposta do usuário, refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // "w" =write/escrever cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s",nome); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s",sobrenome); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s", cargo); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza o arquivo
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); // Pausa o sistem até ter interação com usuario
	
}

int consulta() // Função por consultar os usuários no sistema
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// Fim da criação de variáveis/string
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuario
	scanf("%s",cpf); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler lê o arquivo
	
	if(file == NULL) // refere-se caso a leitura feita no arquivo seja nulo, não encontre a informação inserida pelo usuario
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); //O sistema responde informando que é possível localizar o que foi inserido
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
	
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //Fim do menu
		printf("opção: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();	//consulta funções		
			break;
			
			case 3:
			deletar(); //deleta funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção do menu
	
	}
}
