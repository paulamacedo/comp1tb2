/*	Autores: 	Paula Macedo da Cruz
				Rodrigo Avelar 
	Data:		19 de Julho de 2016.

	Descrição : Sistema de cotação de preços, que possui como entrada dois arquivos textos. O primeiro arquivo de entrada contém apenas 
				o código e a descrição, o segundo apresenta o código e o preço unitário de determinado produto. Como saída do programa,
				é retornado uma listagem com Código, descrição, preço unitário, quantidade e o valor total de cada produto pesquisado. 
				Essa listagem é um arquivo em formato csv.
*/

#include <stdio.h>
#include <stdlib.h>
#include "func.c"
#define MAX 50

 
int main(){

	//variáveis de arquivo 
	FILE *entrada, *entrada2, *saida;
	char nome_entrada[MAX], nome_entrada2[MAX], nome_saida[MAX];

	//variáveis de estrutura
	PRODUTO *produtos;
 
	//variáveis de controle do menu
	int cod, posicao, quantidade, opcao = 1, resp = 1; 

 
	//Interação com o usuário 1 - Solicitação do arquivo de entrada 1
	puts("Por favor, entre com o nome do arquivo 1 (codigo e descrição). Lembrando : exemplo.txt");	
	scanf("%s", nome_entrada);

	//Abertura do arquivo para leitura e teste
	entrada = fopen(nome_entrada, "r");
	if(!entrada){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}
	
	//Acha a quantidade de linhas do arquivo
	int tamanho_arq = acha_quant_linhas(entrada);

	
	//Alocação dinâmica de memória para um vetor do tipo PRODUTO e teste  
	produtos = (PRODUTO*)malloc(tamanho_arq * sizeof(PRODUTO));
	if(!produtos){
		puts("Erro! Não foi possível alocar memoria suficiente para este vetor.");
		return 1;
	}
	
	//Interação com o usuário 2 - Solicitação de arquivo de entrada 2
	puts("Por favor, entre com o nome do arquivo 2 (codigo e preço unitário). Lembrando : exemplo.txt");	
	scanf("%s", nome_entrada2);
	
	//Abertura do arquivo para leitura e teste
	entrada2 = fopen(nome_entrada2, "r"); 
	if(!entrada2){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}

	//Armazena os dados provenientes de dois arquivos de entrada numa estrutura do tipo PRODUTO
	armazena_dados(entrada, entrada2, produtos, tamanho_arq);
	
	//Interação com o usuário 3 - MENU
	puts("Vamos começar a nossa busca?"); 
	printf("1 . PARA SIM \n"
			"0 . PARA NÃO \n");
	scanf("%d", &resp);
	if(resp != 1){
		puts("Fim do programa!");
		return 2;
	}

	//Gera um arquivo para escrita e teste
	puts("Digite o nome do arquivo de saída. Lembrando : exemplo.csv");
	scanf("%s", nome_saida);
	saida = fopen(nome_saida, "w");
	if(!saida){
		puts("Erro! Arquivo de saida não pode ser gerado.");
		return 1;	
	}
	fprintf(saida, "CODIGO, DESCRICAO, VALOR UNITARIO, QUANTIDADE, TOTAL \n");

	while(opcao!= 0){		
			puts("Entre com o código do produto e a quantidade ");
			scanf("%d %d", &cod, &quantidade);
			posicao = busca_produtos(produtos, tamanho_arq, cod);
			if(posicao < 0){
				puts("Código não encontrado!");
				continue;			
			}
			float valor;
			//Calcula o preço total de um produto (preço unitário * quantidade)
			valor = calcula_precos(produtos, posicao, quantidade);	
	
			//Escreve no arquivo de saída o resultado das buscas realizadas.
			fprintf(saida, "%d, %s, %.2f, %d, %.2f \n", produtos[posicao].codigo, produtos[posicao].descricao, produtos[posicao].preco_unitario, quantidade, valor);
			printf("Deseja continuar com a busca?\n"
				" 1 . Para continuar\n"
				" 0 . Para encerrar busca e gerar csv\n ");	
			scanf("%d", &opcao);
			if(opcao == 0){
				puts("Seu arquivo de saída já está salvo no seu diretório.");
				puts("Fim do programa!");
			}
	}	
				

	return 0;

}