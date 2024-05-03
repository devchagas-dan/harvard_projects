// CODIGO FINALIZADO - CHECKCS50 OK, FALTA SOMENTE SUBMIT, MAS ANTES DE SUBMIT PASSAR O CHECK NOVAMENTE PARA GARANTIR
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int counter;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int num = hash(word);
    node *p = table[num];
    while (p != NULL)
    {
        if (strcasecmp(p->word, word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % N;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Abrir o arquivo dictionary no formato de leitura "r"
    FILE *ptr = fopen(dictionary, "r");
    // verificar se não retorna NULL
    if (ptr == NULL)
    {
        return false;
    }
    // criar uma função para armazenar as palavras
    char c[LENGTH + 1];

    while (fscanf(ptr, "%s", c) != EOF)
    {
        // criar um ponteiro para node para cada palavra usando malloc
        node *n = malloc(sizeof(node));
        // Verificar se n está retornando NULL
        if (n == NULL)
        {
            return false;
        }
        // Copiar as palavras para dentro do node usando strcpy
        strcpy(n->word, c);
        // chamar a função hash
        int num = hash(c);

        // Conferir que head está apontando para NULL
        if (table[num] == NULL)
        {
            // Apontar temp para NULL
            n->next = NULL;
        }
        // Apontar para o primeiro node da lista vinculada
        else
        {
            n->next = table[num];
        }
        // apontar o header para temp
        table[num] = n;
        // criar um contador de palavras
        counter += 1;
    }
    // Feachar os arquivos que abri (ponteiros)
    fclose(ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *p = table[i];
        while (p)
        {
            node *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    return true;
}
