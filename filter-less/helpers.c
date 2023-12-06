#include "helpers.h"

double average(int arr[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Convert image to grayscale - average BGR and set values to ave
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; j++)
        {
            // Extract RGB values
            int rgbValues[3] =
            {
                image[i][j].rbgtRed,
                image[i][j].rgbtGreen,
                image[i][j].rgbtBlue
            };

        // average BGR values of pixels and find average
        int ave = average(rgbValues, 3);
        // set values to average
        image[i][j].rgbtBlue = ave;
        image[i][j].rgbtGreen = ave;
        image[i][j].rgbtRed = ave;
        }
    }
    return;
}

// Convert image to sepia - convert BGR using formula
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally - swap pixels left to right
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image - average pixels with 1 column and 1 row pixels away
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

