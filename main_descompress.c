//
// Created by edvonaldoh on 30/09/16.
//
#include "helpful_function.h"
#include "helpful_function.c"

int main()
{
    FILE *p_file;// Declarando ponteiro para arquivo
    unsigned char c;// Char sem sinal
    unsigned char name_file[200];
    printf("Digite o nome do arquivo:\n");
    scanf("%s", name_file);
    p_file = fopen(name_file, "rb");// Abrindo arquivo para leitura

    unsigned int number_of_bytes = 0;

    // Contar número de bytes do arquivo
    if( p_file != NULL )// Verifica se p_file é NULL, ou seja, se ele existe
    {
        while ((fscanf(p_file, "%c\n", &c)) != EOF)// Lê até o fim do arquivo - EOF
            number_of_bytes++;// Para cada caractere lido adiciona um ao numero de bytes

        fclose(p_file);// Fecha arquivo após a leitura
        //printf("O arquivo teste.zip tem %d bytes\n\n", number_of_bytes);// Número de bytes do arquivo - independe da extensão
    }
    else
    {
        printf("File does not exist!\n");// Mensagem caso o arquivo não exista - seja NULL
    }

    unsigned char *size_file;// Ponteiro para unsigned char
    size_file = (unsigned char *) malloc((number_of_bytes + 1) * sizeof(char));// Alocando um array de U_CHAR de acordo com o tamanho do arquivo lido
    int i = 0, read_total;// Contador auxiliar

    p_file = fopen(name_file, "rb");// Abrindo arquivo para leitura

    if( p_file != NULL )// Verifica se p_file é NULL, ou seja, se o arquivo existe
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
        printf("File does not exist!\n");// Mensagem caso o arquivo não exista - seja NULL
    }

    //TAMANHO DA ÁRVORE - QTDE. DE NÓS

    unsigned char first_byte_header, secund_byte_header;// Variável para armazenar os 2 primeiros bytes do arquivo
    int vector_of_size_tree[13], size_of_tree = 0;// Vetor onde cada posição é um dígito binário referente ao tamanho da tree; tamanho da tree
    first_byte_header = size_file[0];
    secund_byte_header = size_file[1];// Atribui o segundo byte do cabeçalho para secundo_byte_header


    printf("%c --> %c\n", first_byte_header, size_file[0]);// Conferindo se a atribuição foi correta
    printf("%c --> %c\n\n", secund_byte_header, size_file[1]);// Conferindo se a atribuição foi correta

    for( i = 0; i < 8; i++)// Loop para verificar bit a bit os bits do segundo byte
    {
        if( is_bit_i_set(secund_byte_header, i))// Se o bit é 1 - setado - atribui 1
            vector_of_size_tree[i] = 1;
        else
            vector_of_size_tree[i] = 0;// Se o bit é 0 - não setado - atribui 0;
    }
    for(i = 0; i < 5; i++)// Loop para verificar bit a bit os bits que interessam para o tamanho da árvore
    {
        if( is_bit_i_set(first_byte_header, i))// Se o bit é 1 - está setado - atribui 1
        {
            // Atribuição de 1 na posição i + 8, pois as anteriores já estão ocupadas com resultados da análise do segundo byte
            vector_of_size_tree[i + 8] = 1;
        } else{
            // Atribuição de 1 na posição i + 8, pois as anteriores já estão ocupadas com resultados da análise do segundo byte
            vector_of_size_tree[i + 8] = 0;
        }
    }
    for(i = 8; i < 13; i++)
        printf("%d --> %d\n", i, vector_of_size_tree[i]);
    printf("\n");
    for(i = 0; i < 13; i++)
    {
        //printf("%d --> %d --> %d\n", i, vector_of_size_tree[i], (int) exp2(i));
        //Tamanho da árvore - valor do bit na posição i VEZES 2 elevado a i
        size_of_tree = size_of_tree + (vector_of_size_tree[i] * (int) exp2(i));
    }

    int exp_tree;
    exp_tree = 12;
    printf("Tamanho da árvore é %d\n", size_of_tree);// Tamanho da árvore

    //TAMANHO DO LIXO

    int vector_of_size_trash[3];// Vetor onde cada i do vetor armazena 1 ou 0
    first_byte_header = first_byte_header >> 5;// Desloca 5 bits para a direita
    int size_of_trash = 0;
    for(i = 0; i < 3; i++)// Loop para verificar se o bit da posição da posição i é UM ou ZERO
    {
        if(is_bit_i_set(first_byte_header, i))// Verifica se o bit da posição i é 1
        {
            vector_of_size_trash[i] = 1;// Atribui valor 1 se bit i está setado
        }else {
            vector_of_size_trash[i] = 0;// Atribui valor 0 se bit i não está setado
        }
    }
    for(i = 0; i < 3; i++)
    {
        //printf("%d --> %d --> %d\n", i, vector_of_size_trash[i], (int) exp2(i));
        //Tamanho do lixo - valor do bit na posição i VEZES 2 elevado a i
        size_of_trash = size_of_trash + (vector_of_size_trash[i] * (int) exp2(i));
    }
    printf("O tamanho do lixo é %d\n", size_of_trash);

    free(size_file);// Libera espaço de memória depois do uso
    return 0;
}

