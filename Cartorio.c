#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função por cadastrar os usuários no sistema
{
	// Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuario
	scanf("%s", cpf); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // "w" =write/escrever cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuario
	scanf("%s",nome); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuario
	scanf("%s",sobrenome); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,","); // Utilizado para separar cada questionamento por uma virgula, para que não fique tudo grudado
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuario
	scanf("%s", cargo); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	file = fopen(arquivo, "a"); // Abre o arquivo e atualiza o arquivo
	fprintf(file,cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); // Pausa o sistema até ter interação com usuario
	
}

int consulta() // Função por consultar os usuários no sistema
{

	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// Fim da criação de variáveis/string
	printf("Digite o CPF a ser consultado: "); // Coletando informação do usuario
	scanf("%s",cpf); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler lê o arquivo
	
	if(file == NULL) // refere-se caso a leitura feita no arquivo seja nulo, não encontre a informação inserida pelo usuario
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); // O sistema responde informando que é possível localizar o que foi inserido
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Função utilizada para quantas vezes for necessária para repetir-se uma instrução (while = Enquanto)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); // %s utilizado para armazenar a resposta do usuário, refere-se a string
		printf("\n\n"); // \n utilizado para pular a linha e deixar o programa mais interativo
	}	
	
	system("pause"); // Pausa o sistema até ter interação com usuario
	
}

int deletar () // Função para deletar os usuários no sistema
{
	// Inicio criação de variáveis/string
	char cpf[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informação do usuario
	scanf("%s", cpf); // %s utilizado para armazenar a resposta do usuário, refere-se a string
	
	remove(cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // "r" =read/ler lê o arquivo
	
	if(file == NULL) // (If = se) Função utilizada para uma função lógica, no caso estamos dizendo se a função for nula apresentar a mensagem abaixo.
	{
		printf(" O usuário não se encontra no sistema!.\n"); // O sistema responde informando que o usuario não esta mais cadastrado no banco
		system("pause"); // Pausa o sistema até ter interação com usuario
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
		printf("Escolha a opção desejada do menu:\n\n"); // Interação do sistema com o usuario
		printf("\t1 - Registrar nomes\n"); // Primeira opção
		printf("\t2 - Consultar nomes\n"); // Segunda opção
		printf("\t3 - Deletar nomes\n\n"); // Terceira opção
		printf("\t4 - Sair do sistema\n\n"); // Quarta opção
		printf("opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls"); // responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: // primeiro caso ou primeira opção
			registro(); //chamada de funções
			break; // encerra a execução
			
			case 2: // segundo caso ou segunda opção
			consulta();	//consulta funções		
			break; // encerra a execução
			
			case 3: // terceiro caso ou terceira opção
			deletar(); //deleta funções
			break; // encerra a execução
			
			case 4: // quarto caso ou quarta opção
			printf("Obrigado por utilizar o sistema!\n"); // O sistema responde agradecendo o usuario por utiliza-lo
			return 0; // utilizado para retornar a 0 ou seja voltar tudo independente da função ou laço que estiver ativa
			break; // encerra a execução
			
			default: // (default = padrão) - neste caso quando o usuario nao utilizar nenhuma das 4 opções
			printf("Essa opção não está disponível!\n"); // O sistema informa que a opção que o usuario digitou não esta disponivel
			system("pause"); // Pausa o sistema até ter interação com usuario
			break; // encerra a execução
		} //fim da seleção do menu
	
	}
}
