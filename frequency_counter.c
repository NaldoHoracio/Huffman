#include "frequency_counter.h"

/*
int main()
{
    FILE *p;
    char *name_file;
    unsigned int freq[256] = {0};

    p = fopen("teste.txt", "r");
    
    count(name_file, freq);
    
    print_frequency(freq);

    return 0;
}
*/

void count(char name_file[], unsigned int frequency[256])
{
    FILE *pFile;
    pFile = fopen("teste.txt","r") ;
    char buffer [1024];
    if(pFile != NULL)
    {
        while (!feof(pFile))
        {
            if(fgets (buffer, 1024, pFile) != NULL)
                frequency_path(buffer, frequency);
        } 
        fclose (pFile);
    }
}

void frequency_path(char str[1024], unsigned int array[256])
{
    int i;
    for (i = 0; i < strlen(str); ++i)
        array[str[i]]++;
}

void print_frequency(unsigned int frequency[256])
{
    int i;
    FILE *pFile;
    pFile = fopen("file_of_frequency.txt", "w");
    PriorityQueue *pq_frequency = createPriorityQueue();

    for (i = 0; i < 256; ++i)
    {
        if(frequency[i] > 0)
        {
            fprintf(pFile, "%c -> %d\n", i, frequency[i]);
            insert(pq_frequency, i, freq[i]);
        }
    }
    fclose(pFile);
}
