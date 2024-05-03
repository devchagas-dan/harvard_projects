// VERIFIQUEI COM CHECK50 DEU TUDO CERTINHO, MAS VERIFICAR ANTES DE SUBMIT

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    char *read_file = argv[1];
    FILE *ptr = fopen (read_file, "r");
    if (ptr == NULL)
    {
        printf ("File %s couldn't be opened.\n", read_file);
        return 1;
    }
    // Read header
    WAVHEADER header;
    fread (&header, sizeof(WAVHEADER), 1 , ptr);

    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf ("Input is not a WAV file.\n");
        return 1;
    }
    if (header.audioFormat != 1)
    {
        printf ("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    char *output_file = argv[2];
    FILE *ptr2 = fopen (output_file, "w");
    if (output_file == 0)
    {
        printf ("File %s couldn't be opened.\n", output_file);
        return 1;
    }

    // Write header to file
    fwrite (&header, sizeof (WAVHEADER), 1 , ptr2);

    // Use get_block_size to calculate size of block
    int size = get_block_size (header);

    // Write reversed audio to file
    if (fseek (ptr, size, SEEK_END))
    {
        return 1;
    }
    BYTE buffer [size];
    while (ftell (ptr)- size > sizeof (header))
    {
        if (fseek (ptr, -2 * size, SEEK_CUR))
        {
            return 1;
        }
        fread (buffer, size, 1 , ptr);
        fwrite (buffer, size, 1, ptr2);
    }

    fclose(ptr);
    fclose(ptr2);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}