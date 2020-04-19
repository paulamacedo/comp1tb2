/*	Autores: 	Paula Macedo da Cruz
				Rodrigo Avelar 
	Data:		19 de Julho de 2016.

	Descrição : Definição do tipo PRODUTO e a declaração das funções envolvidas no programa. 
*/

//Definição do tipo PRODUTO
typedef struct{
	char descricao[50];
	int codigo;
	float preco_unitario; 
}PRODUTO;


//A função tem como entrada um arquivo e retorna um inteiro. A mesma calcula quantas linhas o arquivo de entrada possui 
// e retorna esse valor
int acha_quant_linhas(FILE* entrada);
  
//A função tem como argumentos os dois arquivos de entrada, um vetor dinâmico do tipo PRODUTOS e o tamanho desses arquivos.
//A função não retorna nada, apenas lê as informações contidas nos arquivos e as passa para o vetor.
void armazena_dados(FILE* entrada, FILE* entrada2, PRODUTO * produtos, int tamanho);


//A função tem como entrada o vetor dinâmico, o tamanho do mesmo e o codigo a ser buscado.
//Caso a busca seja bem sucedida é retornado um inteiro referente a posição onde encontra-se o código.
//Caso o código não seja encontrado, ou seja, não exista é retornado um número negativo.
int busca_produtos(PRODUTO *produtos, int tamanho, int codigo);

//A função tem como entrada o vetor dinâmico, a posição e a quantidade.
//É retornado o valor total (quantidade*preço unitário)
float calcula_precos(PRODUTO *produtos, int posicao, int quantidade);
	