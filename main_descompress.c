//
// Created by edvonaldoh on 30/09/16.
//
#include "helpful_function.h"
#include "helpful_function.c"

int main()
{
    FILE *p_file; // Declarando ponteiro para arquivo
    unsigned char c; // Char sem sinal
    unsigned char name_file[200];
    printf("Digite o nome do arquivo:\n");
    scanf("%s", name_file);
    p_file = fopen(name_file, "rb"); // Abrindo arquivo para leitura

    unsigned int number_of_bytes = 0;

    // Contar número de bytes do arquivo
    if( p_file != NULL ) // Verifica se p_file é NULL, ou seja, se ele existe
    {
        while ((fscanf(p_file, "%c\n", &c)) != EOF) // Lê até o fim do arquivo - EOF
            number_of_bytes++; // Para cada caractere lido adiciona um ao numero de bytes

        fclose(p_file); // Fecha arquivo após a leitura
        //printf("O arquivo teste.zip tem %d bytes\n\n", number_of_bytes); // Número de bytes do arquivo - independe da extensão
    }
    else
    {
        printf("File does not exist!\n"); // Mensagem caso o arquivo não exista - seja NULL
    }

    unsigned char *size_file; // Ponteiro para unsigned char
    size_file = (unsigned char *) malloc((number_of_bytes + 1) * sizeof(char)); // Alocando um array de U_CHAR de acordo com o tamanho do arquivo lido
    int i = 0, read_total; // Contador auxiliar

    p_file = fopen(name_file, "rb"); // Abrindo arquivo para leitura

    if( p_file != NULL ) // Verifica se p_file é NULL, ou seja, se o arquivo existe
    {
        // Leitura do arquivo p_file, atribuindo cada byte a posição i de size_file
        // A primeira ocorrência de number_of_bytes representa o tamanho do arquivo - poderia ser sizeof(unsigned char)
        // A segunda ocorrência de number_of_bytes representa a quantidade lida
        // Leitura do arquivo - segundo parâmetro é o tipo do arquivo, o segundo é o numero de bytes
        read_total = fread(size_file, sizeof(unsigned char), number_of_bytes, p_file);
        fclose(p_file);
    }
    else
    {
        printf("File does not exist!\n"); // Mensagem caso o arquivo não exista - seja NULL
    }

    //TAMANHO DO LIXO

    unsigned char first_byte_header; // Char auxiliar para armazenar o primeiro char do cabeçalho
    int vector_of_size_trash[3], size_trash, bit_aux = 7;
    first_byte_header = size_file[0]; // first_byte_header recebe o primeiro byte do cabeçalho


    for( i = 0; i < 3; i++)// Loop para verificar quais bits de first_byte_char têm valor 1
    {
        if( is_bit_i_set(first_byte_header, bit_aux) )// Verifica se o bit da posição i tem valor 1
            vector_of_size_trash[i] = 1;// Se a resposta é positiva, então o valor 1 é colocado na posição i do vector_of_size_trash
        else
            vector_of_size_trash[i] = 0;// Se a resposta é negativa, o valor 0 é colocado na posição i do vector_of_size_trash
        bit_aux--;
    }
    //printf("%c --> %c\n", size_file[0], first_byte_header);
    //printf("3 primeiros bits do lixo:\n");
    //for(i = 0; i < 3; i++)
        //printf("%d --> %d\n", i, vector_of_size_trash[i]);

    int value_trash = 0, exp_trash;
    exp_trash = 2;
    for( i = 0; i < 3; i++)
    {
        value_trash = value_trash + vector_of_size_trash[i] * (int) exp2(exp_trash);
        exp_trash--;
    }
    printf("O tamanho do lixo é %d\n", value_trash);


    //TAMANHO DA ÁRVORE - QTDE. DE NÓS

    unsigned char first_byte_header_aux;
    unsigned char secund_byte_header;
    first_byte_header_aux = first_byte_header << 3;// Desloca 3 bits para a esquerda do primeiro byte

    int vector_of_size_tree[13], size_of_tree = 0;
    //printf("first_byte_header_aux --> %c\n", first_byte_header_aux);

    for( i = 0; i < 5; i++)
    {
        if( is_bit_i_set(first_byte_header_aux, i))//Loop para verificar os 5 ultimos bits
            vector_of_size_tree[i] = 1;// Se estiver setado, valor 1 para vector_of_size_tree
        else
            vector_of_size_tree[i] = 0;// Se não, valor 0 para vector_of_size_tree
    }
    secund_byte_header = size_file[1];// Recebendo o segundo byte do cabeçalho que complementa o tamanho da árvore
    for( i = 0; i < 8; i++)
    {
        if( is_bit_i_set(secund_byte_header, i))// Verifica bit a bit do segundo byte se este está setado
            vector_of_size_tree[i + 5] = 1;// Um para estar setado
        else
            vector_of_size_tree[i + 5] = 0;// Zero para não estar setado
    }
    int exp_tree;
    exp_tree = 12;
    for( i = 0; i < 13; i++)
    {
        size_of_tree = size_of_tree + (vector_of_size_trash[i] * (int) exp2(exp_tree));// Calculando o tamanho da árvore
        exp_tree--;// Decrementa o expoente, que vai de 12 até 0
    }
    printf("Tamanho da árvore é %d\n", size_of_tree);// Tamanho da árvore

    free(size_file); // Libera espaço de memória depois do uso
    return 0;
}
