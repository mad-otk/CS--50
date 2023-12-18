#include "helpers.h"
#include "bmp.h"
#include<math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double grayscale_avg = 0;
    for(int i =0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {

            grayscale_avg = round((image[i][j].rgbtRed + image[i][j].rgbtRed + image[i][j].rgbtRed)/3);
            if(grayscale_avg > 255)
            grayscale_avg = 255;
            image[i][j].rgbtRed = (int)grayscale_avg;
            image[i][j].rgbtGreen = (int)grayscale_avg;
            image[i][j].rgbtBlue = (int)grayscale_avg;
        }
        
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
double sepia_blue, sepia_green, sepia_red = 0;
    int red=0,green=0,blue =0;
    for(int i =0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            sepia_red = round(0.393*image[i][j].rgbtRed + 0.769*image[i][j].rgbtGreen + 0.189*image[i][j].rgbtBlue);
            if(sepia_red > 255)
            image[i][j].rgbtRed = 255;
            else
            {
                red = (int)sepia_red;
                image[i][j].rgbtRed = red;
            }
            sepia_green = (0.349*image[i][j].rgbtRed + 0.686*image[i][j].rgbtGreen + 0.168*image[i][j].rgbtBlue);
            if(sepia_green > 255)
                image[i][j].rgbtGreen = 255;
            else
            {
                green = (int)sepia_green;
                image[i][j].rgbtGreen = green;
            }

            sepia_blue = (0.272*image[i][j].rgbtRed + 0.534*image[i][j].rgbtGreen + 0.131*image[i][j].rgbtBlue);
            if(sepia_blue > 255)
                image[i][j].rgbtRed = 255;
            else
            {
                blue = (int)sepia_blue;
                image[i][j].rgbtBlue = blue; 
            }
        }
        
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    BYTE tempimage[1][3];
    
    for(int i =0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            tempimage[0][0] = image[i][j].rgbtRed;
            tempimage[0][1] = image[i][j].rgbtGreen;
            tempimage[0][2] = image[i][j].rgbtBlue;

            image[i][j] = image[i][width-j-1];

            image[i][width-j-1].rgbtRed = tempimage[0][0];
            image[i][width-j-1].rgbtGreen = tempimage[0][1];
            image[i][width-j-1].rgbtBlue = tempimage[0][2];    
        }
        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE blur_image[height][width];
    // blur_image[i][j].rgbtBlue = blur_image[i][j].rgbtRed = blur_image[i][j].rgbtGreen = 0;

    BYTE blur_image[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            blur_image[i][j] = image[i][j]; 
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {   
            // 
            if(i==0 && j==0)
            {
                image[i][j].rgbtRed = round((blur_image[0][0].rgbtRed + blur_image[0][1].rgbtRed + blur_image[1][0].rgbtRed + blur_image[1][1].rgbtRed)/4);
                image[i][j].rgbtBlue = round((blur_image[0][0].rgbtBlue + blur_image[0][1].rgbtBlue + blur_image[1][0].rgbtBlue + blur_image[1][1].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((blur_image[0][0].rgbtGreen + blur_image[0][1].rgbtGreen + blur_image[1][0].rgbtGreen + blur_image[1][1].rgbtGreen)/4);
            }
            else if((i==height-1)&&(j==0))
            {
                image[i][j].rgbtRed = round((blur_image[i][0].rgbtRed + blur_image[i][1].rgbtRed + blur_image[i-1][0].rgbtRed + blur_image[i-1][1].rgbtRed)/4);
                image[i][j].rgbtBlue = round((blur_image[i][0].rgbtBlue + blur_image[i][1].rgbtBlue + blur_image[i-1][0].rgbtBlue + blur_image[i-1][1].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((blur_image[i][0].rgbtGreen + blur_image[i][1].rgbtGreen + blur_image[i-1][0].rgbtGreen + blur_image[i-1][1].rgbtGreen)/4);
            }
            else if((i==0)&&(j==width-1))
            {
                image[i][j].rgbtRed = round((blur_image[0][j].rgbtRed + blur_image[0][j-1].rgbtRed + blur_image[1][j].rgbtRed + blur_image[1][j-1].rgbtRed)/4);
                image[i][j].rgbtBlue = round((blur_image[0][j].rgbtBlue + blur_image[0][j-1].rgbtBlue + blur_image[1][j].rgbtBlue + blur_image[1][j-1].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((blur_image[0][j].rgbtGreen + blur_image[0][j-1].rgbtGreen + blur_image[1][j].rgbtGreen + blur_image[1][j-1].rgbtGreen)/4);
            }

            else if((i==height-1)&&(j==width-1))
            {
                image[i][j].rgbtRed = round((blur_image[i][j].rgbtRed + blur_image[i][j-1].rgbtRed + blur_image[i-1][j].rgbtRed + blur_image[i-1][j-1].rgbtRed)/4);
                image[i][j].rgbtGreen = round((blur_image[i][j].rgbtGreen + blur_image[i][j-1].rgbtGreen + blur_image[i-1][j].rgbtGreen + blur_image[i-1][j-1].rgbtGreen)/4);
                image[i][j].rgbtBlue = round((blur_image[i][j].rgbtBlue + blur_image[i][j-1].rgbtBlue + blur_image[i-1][j].rgbtBlue + blur_image[i-1][j-1].rgbtBlue)/4);

            }

            else if(i==0 && j!=0 && j!=width-1)
            {
                image[i][j].rgbtRed = round((blur_image[0][j].rgbtRed + blur_image[0][j-1].rgbtRed + blur_image[0][j+1].rgbtRed + blur_image[1][j-1].rgbtRed + blur_image[1][j].rgbtRed + blur_image[i][j+1].rgbtRed)/6);
                image[i][j].rgbtGreen = round((blur_image[0][j].rgbtGreen + blur_image[0][j-1].rgbtGreen + blur_image[0][j+1].rgbtGreen + blur_image[1][j-1].rgbtGreen + blur_image[1][j].rgbtGreen + blur_image[i][j+1].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((blur_image[0][j].rgbtBlue + blur_image[0][j-1].rgbtBlue + blur_image[0][j+1].rgbtBlue + blur_image[1][j-1].rgbtBlue + blur_image[1][j].rgbtBlue + blur_image[i][j+1].rgbtBlue)/6);

            }

            else if(i==height-1 && j!=0 && j!=width-1)
            {
                image[i][j].rgbtRed = round((blur_image[i][j].rgbtRed + blur_image[i][j-1].rgbtRed + blur_image[i][j+1].rgbtRed + blur_image[i-1][j-1].rgbtRed + blur_image[i-1][j].rgbtRed + blur_image[i-1][j+1].rgbtRed)/6);
                image[i][j].rgbtGreen = round((blur_image[i][j].rgbtGreen + blur_image[i][j-1].rgbtGreen + blur_image[i][j+1].rgbtGreen + blur_image[i-1][j-1].rgbtGreen + blur_image[i-1][j].rgbtGreen + blur_image[i-1][j+1].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((blur_image[i][j].rgbtBlue + blur_image[i][j-1].rgbtBlue + blur_image[i][j+1].rgbtBlue + blur_image[i-1][j-1].rgbtBlue + blur_image[i-1][j].rgbtBlue + blur_image[i-1][j+1].rgbtBlue)/6);

            }

            else if(j==0 && i!=0 && i!=height-1)
            {
                image[i][j].rgbtRed = round((blur_image[i][0].rgbtRed + blur_image[i-1][0].rgbtRed + blur_image[i+1][0].rgbtRed + blur_image[i-1][1].rgbtRed + blur_image[i][1].rgbtRed + blur_image[i+1][1].rgbtRed)/6);
                image[i][j].rgbtGreen = round((blur_image[i][0].rgbtGreen + blur_image[i-1][0].rgbtGreen + blur_image[i+1][0].rgbtGreen + blur_image[i-1][1].rgbtGreen + blur_image[i][1].rgbtGreen + blur_image[i+1][1].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((blur_image[i][0].rgbtBlue + blur_image[i-1][0].rgbtBlue + blur_image[i+1][0].rgbtBlue + blur_image[i-1][1].rgbtBlue + blur_image[i][1].rgbtBlue + blur_image[i+1][1].rgbtBlue)/6);

            }

            else if(j== width-1 && i!= 0 && i!=height-1)
            {
                image[i][j].rgbtRed = round((blur_image[i][j-1].rgbtRed + blur_image[i-1][j-1].rgbtRed + blur_image[i+1][j-1].rgbtRed + blur_image[i-1][j].rgbtRed + blur_image[i][j].rgbtRed + blur_image[i+1][j].rgbtRed)/6);
                image[i][j].rgbtGreen = round((blur_image[i][j-1].rgbtGreen + blur_image[i-1][j-1].rgbtGreen + blur_image[i+1][j-1].rgbtGreen + blur_image[i-1][j].rgbtGreen + blur_image[i][j].rgbtGreen + blur_image[i+1][j].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((blur_image[i][j-1].rgbtBlue + blur_image[i-1][j-1].rgbtBlue + blur_image[i+1][j-1].rgbtBlue + blur_image[i-1][j].rgbtBlue + blur_image[i][j].rgbtBlue + blur_image[i+1][j].rgbtBlue)/6);
            }
            }
        }
    for(int i = 1; i<height-1;i++)
    {
        for(int j=1;j<width-1;j++)
        {
            image[i][j].rgbtRed = round((blur_image[i-1][j-1].rgbtRed + blur_image[i-1][j].rgbtRed + blur_image[i-1][j+1].rgbtRed + blur_image[i][j-1].rgbtRed + blur_image[i][j].rgbtRed + blur_image[i][j+1].rgbtRed + blur_image[i+1][j-1].rgbtRed + blur_image[i+1][j].rgbtRed + blur_image[i+1][j+1].rgbtRed )/9);
            image[i][j].rgbtGreen = round((blur_image[i-1][j-1].rgbtGreen + blur_image[i-1][j].rgbtGreen + blur_image[i-1][j+1].rgbtGreen + blur_image[i][j-1].rgbtGreen + blur_image[i][j].rgbtGreen + blur_image[i][j+1].rgbtGreen  + blur_image[i+1][j-1].rgbtGreen + blur_image[i+1][j].rgbtGreen + blur_image[i+1][j+1].rgbtGreen)/9);
            image[i][j].rgbtBlue = round((blur_image[i-1][j-1].rgbtBlue + blur_image[i-1][j].rgbtBlue + blur_image[i-1][j+1].rgbtBlue + blur_image[i][j-1].rgbtBlue + blur_image[i][j].rgbtBlue + blur_image[i][j+1].rgbtBlue + blur_image[i+1][j-1].rgbtBlue + blur_image[i+1][j].rgbtBlue + blur_image[i+1][j+1].rgbtBlue) /9);

        }
    }

   
    return;
}





