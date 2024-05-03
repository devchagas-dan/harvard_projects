//ESTA TUDO CORRETO MAS NÃO ESQUECER DE FAZER CHECK50 ANTES DE SUBMIT
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float turn_gray = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            image[i][j].rgbtRed = turn_gray;
            image[i][j].rgbtGreen = turn_gray;
            image[i][j].rgbtBlue = turn_gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

  //sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
        int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
        int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
        int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

        int rgb = 255;


        int smaller1 = (sepiaRed < rgb) ? sepiaRed : rgb;
        int smaller2 = (sepiaGreen < rgb) ? sepiaGreen : rgb;
        int smaller3 = (sepiaBlue < rgb) ? sepiaBlue : rgb;

        image[i][j].rgbtRed = smaller1;
        image[i][j].rgbtGreen = smaller2;
        image[i][j].rgbtBlue = smaller3;

        }
    }
    return;
  }

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap_temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap_temp = image[i][j];
            image[i][j] = image[i][width- j -1];
            image[i][width - j - 1] = swap_temp;
         }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            float c = 0.00;

            for (int x = - 1; x < 2; x++)
            {
                for (int y = - 1; y < 2; y++)
                {
                    int w = i + x;
                    int z = j + y;

                    if (w < 0 || w > (height -1) || z < 0 || z > (width - 1))
                    {
                        continue;
                    }

                    red += image[w][z].rgbtRed;
                    green += image[w][z].rgbtGreen;
                    blue += image[w][z].rgbtBlue;

                    c++;
                }
            }
            temp [i][j].rgbtRed = round(red / c);
            temp [i][j].rgbtGreen = round(green / c);
            temp [i][j].rgbtBlue = round(blue / c);

        }
    }
    // Loop para passar todas as informações que foram guardadas em temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp [i][j];
        }
    }
    return;
}
