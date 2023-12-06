#include "helpers.h"

double average(int arr[], int size)
{
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

void swap(BYTE *a, BYTE *b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Convert image to grayscale - average BGR and set values to ave
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Extract RGB values
            int rgbValues[3] = {image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed};

            // average BGR values of pixels and find average
            int ave = (int) (average(rgbValues, 3) + 0.5);
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
            int sepiaRed = (int) (.393 * originalRed + .769 * originalGreen + .189 * originalBlue + 0.5);
            int sepiaGreen = (int) (.349 * originalRed + .686 * originalGreen + .168 * originalBlue + 0.5);
            int sepiaBlue = (int) (.272 * originalRed + .534 * originalGreen + .131 * originalBlue + 0.5);

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
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j].rgbtRed, &image[i][width - 1 - j].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width - 1 - j].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][width - 1 - j].rgbtBlue);
        }
    }
    return;
}

// Blur image - average pixels with 1 column and 1 row pixels away
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // Declare copy

    // Copy original to copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Apply blur to each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            // find the pixels 1 column and 1 row away and average all of them
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int newI = i + di;
                    int newJ = j + dj;

                    if (newI >= 0 && newI < height && newJ >= 0 && newJ < width)
                    {
                        totalRed += copy[newI][newJ].rgbtRed;
                        totalGreen += copy[newI][newJ].rgbtGreen;
                        totalBlue += copy[newI][newJ].rgbtBlue;
                        count++;
                    }
                }
            }

            // Average of each component
            image[i][j].rgbtRed = (totalRed + count / 2) / count;
            image[i][j].rgbtGreen = (totalGreen + count / 2) / count;
            image[i][j].rgbtBlue = (totalBlue + count / 2) / count;
        }
    }
    return;
}
