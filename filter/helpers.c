#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;

    //Loop that goes through all pixels
    //Height
    for (int h = 0; h < height; h++)
    {
        //Width
        for (int w = 0; w < width; w++)
        {
            //Resets average to 0
            average = 0;
            //Adds the rgb values to Average
            average += image[h][w].rgbtRed;
            average += image[h][w].rgbtGreen;
            average += image[h][w].rgbtBlue;
            //Gets the average
            average /= 3;
            //Rounds the average
            average = round(average);
            //Sets the average to the appropriate values
            image[h][w].rgbtRed = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporary var for the swap
    RGBTRIPLE temp;
    //Loops through the half image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Average values for all 3 colors
    float averageR = 0;
    float averageG = 0;
    float averageB = 0;
    //Counter to use in calculating average
    int counter = 0;

    //Copy of image
    RGBTRIPLE tempImage[height][width];
    //Copies the the image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tempImage[h][w] = image[h][w];
        }
    }

    //Loops through image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //Resets average values and counter
            counter = 0;
            averageR = 0;
            averageG = 0;
            averageB = 0;

            //Loops through adjacent values
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    //If the pixel is not out of bound
                    if ((h + m >= 0 && h + m < height) && (w + n >= 0 && w + n < width))
                    {
                        //Reading the rgb values from the copy
                        averageR += tempImage[h + m][w + n].rgbtRed;
                        averageG += tempImage[h + m][w + n].rgbtGreen;
                        averageB += tempImage[h + m][w + n].rgbtBlue;
                        counter++;
                    }
                }
            }

            //Making the changes to the actual image
            image[h][w].rgbtRed = round(averageR /= counter);
            image[h][w].rgbtGreen = round(averageG /= counter);
            image[h][w].rgbtBlue = round(averageB /= counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    return;
}
