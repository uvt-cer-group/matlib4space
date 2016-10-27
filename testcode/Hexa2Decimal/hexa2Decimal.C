/* Author: Madalina Erascu*/
/* Input:  csv file with numbers in hexa fomat
   Output: csv file with numbers in decimal fomat with 80 decimals
   Usage: main list_input_files list_output_files
   Attention: function hex2double - the specifier llx might not give the same output on computers with other OS than Windows, MinGW compiler, etc.
*/

#include <stdio.h>
#include <stdlib.h>

long double hex2double(const char *);

int main(int argc, char *argv[])
{
   char buffer[1024] ;
   char *record,*line;
   long double x;
   int i,j;

   printf( "argc = %d\n", argc );
   for( i = 1; i <= argc/2; ++i ) {
        printf( "argv[ %d ] = %s\n", i, argv[ i ] );
        printf( "argv[ %d ] = %s\n", (argc/2) + i, argv[ (argc/2) + i ] );

        FILE *fstream_in =  fopen(argv[  i           ],"r");
        FILE *fstream_out = fopen(argv[ (argc/2) + i ],"w");

        if(fstream_in == NULL) {
                printf("\nFile opening failed:", fstream_in);
                return -1 ;
        }

        while((line=fgets(buffer,sizeof(buffer),fstream_in))!=NULL) {
                record = strtok(line,",");
                while(record != NULL) {
                        printf("String : %s\n",record) ;
                        x = hex2double(record) ;
                        fprintf(fstream_out,"%.80e\n", x);
                        record = strtok(NULL,",");
                }
        }
   }
   return 0 ;
 }

long double hex2double(const char *s)
{
    long double d = 0.0;
    sscanf(s, "%llx",  &d);

    return d;
}
