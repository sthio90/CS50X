#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // for loop to go through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // if pixel is black
            if(image[i][j].rgbtBlue == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtRed == 0)
            {
                // change pixel to different colour
                image[i][j].rgbtBlue = "ED";
                image[i][j].rgbtGreen = "80";
                image[i][j].rgbtBlue = "FF";
            }
        }
    }
}
