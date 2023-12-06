#include "bmp.h"

// Convert image to grayscale - average BGR and set values to ave
void grayscale(int height, int width, RGBTRIPLE image[height][width]);
    //

// Convert image to sepia - convert BGR using formula
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally - swap pixels left to right
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image - average pixels with 1 column and 1 row pixels away
void blur(int height, int width, RGBTRIPLE image[height][width]);
