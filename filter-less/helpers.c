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
        for (int j = 0; j < width; j++)
        {
            // Extract RGB values
            int rgbValues[3] =
            {
                image[i][j].rgbtBlue,
                image[i][j].rgbtGreen,
                image[i][j].rgbtRed
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Extract RGB values
            int rgbValues[3] =
            {
                image[i][j].rgbtRed,
                image[i][j].rgbtGreen,
                image[i][j].rgbtBlue
            };
            // Convert sepiaRed
            image[i][j].rgbtRed = .393 * rgbValues[0] + .769 * rgbValues[1] + .189 * rgbValues[2];
            image[i][j].rgbtGreen = .349 * rgbValues[0] + .686 * rgbValues[1] + .168 * rgbValues[2];
            image[i][j].rgbtBlue = .272 * rgbValues[0] + .534 * rgbValues[1] + .131 * rgbValues[2];

        }
    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    }
    return;
}

// Reflect image horizontally - swap pixels left to right
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {}
    // }
    return;
}

// Blur image - average pixels with 1 column and 1 row pixels away
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {}
    // }
    return;
}

