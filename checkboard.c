#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, j;
   int w = 256, h = 256;

   // This 2D array will be converted into an image The size is 256 x 256
   int image[w][h];

   for (i=0; i<256; i++) {
       for(j=0; j<256; j++) {
            if ((i/32%2!=0 && j/32%2==0) || (i/32%2==0 && j/32%2!=0))
            {
                image[i][j]= 0;
            }
            else {
                image[i][j]= 255;
            }
        }
    }

   FILE* pgmimg;
   pgmimg = fopen("my_pgmimg.pgm", "wb"); // Write the file in binary mode
   fprintf(pgmimg, "P2\n"); // Writing Magic Number to the File
   fprintf(pgmimg, "%d %d\n", w, h); // Writing Width and Height into the file
   fprintf(pgmimg, "255\n"); // Writing the maximum gray value
   int count = 0;
   for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
         fprintf(pgmimg, "%d ", image[i][j]); //Copy gray value from array to file
      }
      fprintf(pgmimg, "\n");
   }
   fclose(pgmimg);
}