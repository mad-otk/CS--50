#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
// Checking if the user is providing correct file name "card.raw"
 if (argc != 2)
 {
 printf("Invalid arguments\n");
 return 1;
 }

// File pointer to open input file
 FILE *inptr = fopen(argv[1], "r");
 if(inptr == NULL)
 {
    fprintf(stderr, "Unable to open file : %s \n", argv[1]);
    fclose(inptr);
    return 2;
 }

//Outfile pointer is set to NULL
FILE* outptr = NULL;

//Array of 512 elements to stor bytes from the memory card
BYTE buffer[512];
int jpeg = 0;
char filename[8]={0};

//Read memory card untill the end of the file
while(fread(buffer, sizeof(BYTE)*512, 1, inptr)==1)
{
// Check if jpg file is found
   if(buffer[0]==0xFF && buffer[1]==0xD8 && buffer[2]==0xFF && ((buffer[3] & 0xF0)== 0xE0))
    {

      // Close previously opened jpg file written by outptr
      if(outptr != NULL)
      {
      fclose(outptr);
      }

      // File names start with 000.jpg, 001.jpg, 002.jpg and so on
      sprintf(filename, "%03d.jpg", jpeg++);

      // Opens a new outptr to write a new found ###.jpg
      outptr = fopen(filename, "wb");

      // Error handling if the outptr was unable to open a file
      if(outptr==NULL){
         fprintf(stderr, "Can't open file %s \n", filename);
         return 1;
      }
    }
      // Keep writing to jpg file untill a new jpg file is found
      if(outptr!=NULL)
      {
      fwrite(buffer, sizeof(BYTE)*512,1,outptr);
      }
}
   // Close the last output pointer file
   if(outptr!=NULL)
   {
   fclose(outptr);
   }

   // Close the input file
   fclose(inptr);
   return 0;
}