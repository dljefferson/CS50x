/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * resizes an input file by a factor of n 
 * then outputs the resized file 
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    int resizeFactor = atoi(argv[1]);
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
   
    if((resizeFactor < 0) || (resizeFactor > 100))
    {
        printf("Resize factor must be between 1 and 100.\n");
        return 2;
    }
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    //remember input header information
    int heightInpt = bi.biHeight;
    int widthInpt = bi.biWidth;
    
    
    //calculate padding information
    int paddingInpt =  (4 - (widthInpt * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //update image height and width info
   
    bi.biHeight = bi.biHeight * resizeFactor;
    bi.biWidth = bi.biWidth * resizeFactor;
    
    //recalculate padding for output file
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //update file size info
    bi.biSizeImage = (sizeof(RGBTRIPLE) * bi.biWidth * abs(bi.biHeight)) + padding * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + 54;
  
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(heightInpt); i < biHeight; i++)
    {
        //resize row vertically
        for(int j = 0; j < resizeFactor; j++ )
        {
            // iterate over pixels in scanline
            for (int k = 0; k < widthInpt; k++)
            {
                // temporary storage
                RGBTRIPLE triple;
                 
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for(int l = 0; l < resizeFactor; l++) 
                {
                    // write RGB triple to outfile 
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            
            }
           // skip over padding, if any
           fseek(inptr, paddingInpt, SEEK_CUR);

           //add padding if needed
           for (int m = 0; m < padding; m++)
           {
               fputc(0x00, outptr);
           }
           //return back to the start of row
           fseek(inptr, -(widthInpt * sizeof(RGBTRIPLE) + paddingInpt), SEEK_CUR);
           
           
            
        }
        //go to the end of copied row plus padding
        fseek(inptr, widthInpt * sizeof(RGBTRIPLE) + paddingInpt, SEEK_CUR);
       
        
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

