// Student stub code for ASCII Drawing assignment

#include <stdio.h>
#include <stdlib.h>

// Initializes all the pixels of a image to black.
// You shouldn't need to modify this function!
void initImage(int width, int height, double image[width][height])
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[x][y] = 0.0;
        }
    }
}

// TODO:  add a parameter list and implementation for the remaining functions.
// Check the calls in the main function to figure out the order and types of 
// the parameters that are passed to each function

void printImage()
{
}

void drawPoint()   
{
}

void drawRectangle()
{
}

void convertToBlackAndWhite()  
{
}

void drawLine()
{
}

void printStats() 
{
}

void floodFill()
{
}

// Print the resulting grayscale image as ASCII art.  
// You need to fix the lines marked with TODO comments to handle the file IO.   
// Dont change other things in the main function. 
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Usage: Draw <filename>\n");
        return 0;
    }

    // TODO: actually try and open the input file 
    FILE *fp = NULL;
    if (fp == NULL)
    {
        printf("ERROR: failed to open input file '%s'!\n", argv[1]);
        return 0;
    }

    // Read in the size of the drawing canvas
    int width = 0;
    int height = 0;
        
    // TODO: replace 0 with a call to fscanf that reads in both the width and height.       
    // The fscanf function returns a integer with the number of read in variables.
    // The main program uses this result to check for badly formatted input.   
    // The fscanf function can read in multiple variables in one call  (see the lecture slides).  
    int result = 0;
    
    // Program only supports images that are 1x1 or bigger
    if ((width <= 0) || (height <= 0) || (result != 2))
    {
        printf("ERROR: failed to read width and height!\n");
        
        // TODO: cleanup the open file handle
        
        return 0;
    }
    
    // Create an 2D array and initialize all the greyscale values to 0.0.
    // The first dimension is the x-coordinate.
    // The second dimension is the y-coordinate
    double image[width][height];
    initImage(width, height, image);
    
    char command = '\0';
    double color = 0.0;
    
    // Keep reading in drawing comands until we reach the end of the input
    while (fscanf(fp, " %c", &command) == 1)
    {
        switch (command)
        {		 
            case 'p': 	
            {
                // Draw a point, read in: x, y, color
                int x = 0;
                int y = 0;

                result = 0; // TODO: call to fscanf
                if (result != 3)
                {
                    printf("ERROR: invalid point command!\n");
                    return 0;
                }
                drawPoint(width, height, image, x, y, color);
                break;
            }
            case 'r': 	
            {
                // Draw a rectangle, read in: x, y, w, h, color
                int left = 0;
                int top = 0;
                int rectangleWidth = 0;
                int rectangleHeight = 0;

                result = 0; // TODO: call to fscanf
                if (result != 5)
                {
                    printf("ERROR: invalid rectangle command!\n");
                    return 0;
                }
                drawRectangle(width, height, image, left, top, rectangleWidth, rectangleHeight, color);
                break;
            }
            case 'b':   
            {
                // Convert to black and white
                double threshold = 0.0;

                result = 0; // TODO: call to fscanf
                if (result != 1)
                {
                    printf("ERROR: invalid black and white command!\n");  
                    return 0;
                }
                convertToBlackAndWhite(width, height, image, threshold);
                break;
            }

            case 'l':
            {
                // Draw a line, read in x1, y1, x2, y2, color
                int x1 = 0;
                int y1 = 0;
                int x2 = 0;
                int y2 = 0;      

                result = 0; // TODO: call to fscanf
                if (result != 5)
                {
                    printf("ERROR: invalid line command!\n");
                    return 0;
                }
                drawLine(width, height, image, x1, y1, x2, y2, color);
                break;
            }            
            case 'f':
            {
                // Flood fill a color in, read in: x, y, color
                int x = 0;
                int y = 0;

                result = 0; // TODO: call to fscanf
                if (result != 3)
                {
                    printf("ERROR: invalid flood fill command!\n");
                    return 0;
                }
                floodFill(width, height, image, x, y, color);
                break;
                
            }
            default:
            {
                printf("ERROR: unknown command!\n");
                return 0;
            }
        }
    }

    // TODO: clean up the open file handle
	
    // Print the final image
    printImage(width, height, image);    
    
    // Finally display some statistics about the image
    printStats(width, height, image);  

    return 0;
}

