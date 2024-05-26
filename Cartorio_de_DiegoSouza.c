#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //função responsável por cadastrar os usuários no sistema
{
	char arquivo[40]; //inicio da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:\n"); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado:\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	return 0; //adicionando um retorno ao final da função
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
		system("pause");
		return 1; //adicionando um retorno em caso de erro
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file); //fechando o arquivo após a leitura
	system("pause");
	return 0; //adicionando um retorno ao final da função
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		fclose(file); //fechando o arquivo antes de removê-lo
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
	}
	
	else
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	system("pause");
	return 0; //adicionando um retorno ao final da função
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("### Cartório da EBAC de Diego Souza ###\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite a sua senha:\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
		while (laco)
		{
			system("cls");
			setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
			printf("### Cartório da EBAC de Diego Souza ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
			scanf("%d", &opcao); //armazenando a escolha do usuário
			
			system("cls"); //responsável por limpar a tela
		
			switch(opcao)
			{
				case 1: //inicio da seleção do menu
				registrar(); //chamada de funções
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break; //fim da seleção do menu
			}
		}
	}
	
	else
	{
		printf("Senha incorreta!");
	}
	
	return 0; //adicionando um retorno ao final da função
}
