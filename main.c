#include "helpful.h"

int main()
{
    int i;
    FILE *p;
    char *name_file;
    unsigned int freq[256] = {0};
    Node *pq_frequency = createPriorityQueue();
    
    p = fopen("teste.txt", "r");
    /*
    *
    *Inserindo o caractere e sua respectiva frequência na fila de prioridade
    *
    */ 
    for (i = 0; i < 256; ++i)
    {
        if(freq[i] > 0)
        {
            //fprintf(pFile, "%c -> %d\n", i, freq[i]);
            insert(pq_frequency, i, freq[i]);
        }

    }
    count(name_file, freq);
    
    print_frequency(freq);

    return 0;
}
