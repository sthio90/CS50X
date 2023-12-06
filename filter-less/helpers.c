#include "helpers.h"

double average(int arr[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    b* = tmp;
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
        int ave = (int)(average(rgbValues, 3) + 0.5);
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
            // Extract original RGB values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Calculate sepia tones
            int sepiaRed = (int)(.393 * originalRed + .769 * originalGreen + .189 * originalBlue + 0.5);
            int sepiaGreen = (int)(.349 * originalRed + .686 * originalGreen + .168 * originalBlue + 0.5);
            int sepiaBlue = (int)(.272 * originalRed + .534 * originalGreen + .131 * originalBlue + 0.5);

            // Clamp values to max 255
            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
        }
    }
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

