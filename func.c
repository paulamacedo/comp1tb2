/*	Autores: 	Paula Macedo da Cruz
				
	Data:		19 de Julho de 2016.

	Descrição : Arquivo de implementação das funções descritas no arquivo "func.h".
*/
#include "func.h"

//A função tem como entrada um arquivo e retorna um inteiro. A mesma calcula quantas linhas o arquivo de entrada possui 
// e retorna esse valor
int acha_quant_linhas(FILE* entrada){


	int contador = 0 ;
	int caractere, existe_linhas = 0;
  
  	while((caractere = fgetc(entrada)) != EOF){
    	existe_linhas = 1; // há conteúdo no arquivo
    
    	if(caractere == '\n'){ //se houver quebra de linha, incrementar o contador
      		contador++;             
    	} 
  }

  //Incrementar novamente o contador, pois na última linha não há quebra de linha e o contador não irá ser incrementado.
  	if(existe_linhas){
  		contador++;
  	}
	return contador;//retorna o número de linhas do arquivo
}

//A função tem como argumentos os dois arquivos de entrada, um vetor dinâmico do tipo PRODUTOS e o tamanho desses arquivos.
//A função não retorna nada, apenas lê as informações contidas nos arquivos e as passa para o vetor.
void armazena_dados(FILE* entrada, FILE* entrada2, PRODUTO *produtos, int tamanho){
	
	int i;
	for(i=0; i< tamanho; i++){
		fscanf(entrada,"%d %s", &produtos[i].codigo, produtos[i].descricao);
		printf("PASSOU POR AQUI i %d %d %s\n ", i, produtos[i].codigo, produtos[i].descricao);
	}
	for(i=0; i< tamanho; i++){
		fscanf(entrada2, "%d %f", &produtos[i].codigo, &produtos[i].preco_unitario);
		
	}
}

//A função tem como entrada o vetor dinâmico, o tamanho do mesmo e o codigo a ser buscado.
//Caso a busca seja bem sucedida é retornado um inteiro referente a posição onde encontra-se o código.
//Caso o código não seja encontrado, ou seja, não exista é retornado um número negativo.
int busca_produtos(PRODUTO *produtos, int tamanho, int cod){

	int direita, esquerda, i=0;
	esquerda = 0;
	direita = tamanho-1;
	while(esquerda <= direita) {
		i = (esquerda+direita)/2;
		if(produtos[i].codigo == cod){ 
			return i;
		}
		if(cod > produtos[i].codigo) {
			esquerda = i+1;
		}
		else {
			direita = i-1;
		}	
	}
	return -1;

}

//A função tem como entrada o vetor dinâmico, a posição e a quantidade.
//É retornado o valor total (quantidade*preço unitário)
float calcula_precos(PRODUTO *produtos, int posicao, int quantidade){

	float valor;

	valor = produtos[posicao].preco_unitario * quantidade; 

	return valor; 
	
}	
