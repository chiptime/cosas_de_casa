#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define UINT    unsigned int
#define USINT   unsigned short int
#define UCHAR   unsigned char

void test()
{
    printf("\nTEST\n");
}

typedef struct BitmapHeader
{
    USINT    Type;
    UINT     Size;
    USINT    Reserved1;
    USINT    Reserved2;
    UINT     Offset;
} Header;

typedef struct BitmapInfoHeader
{
    UINT     Size;
    int      Width, Height;
    USINT    Planes;
    USINT    Bits;
    UINT     Compression;
    UINT     ImageSize;
    int      xResolution, yResolution;
    UINT     Colors;
    UINT     ImportantColors;
}InfoHeader;

typedef struct Pixels
{
    UCHAR Blue;
    UCHAR Green;
    UCHAR Red;
}Pixels;

typedef struct Bitmap
{
    Header header;
    InfoHeader infoHeader;
    Pixels** pixels;
}BMP;
/*************************
 *
 *  UCHAR getPixelRed(BMP bmp,int x, int y)
 *  {
 *  printf("Largeur %d\n", bmp.infoHeader.Width);
 *  printf("Hauteur %d\n", bmp.infoHeader.Height);
 *  if( x < 0 || y < 0 || x >= bmp.infoHeader.Width || y >= bmp.infoHeader.Height)
 *  {
 *      printf("Coordonnees du pixel erronees : %d %d\n", x, y);
 *      exit(1);
 *   }
 *   else
 *   {
 *      return bmp.pixels[x][y].Red;
 *   }
 *   }
 ***************************/

BMP readBMP(char* filename)
{
    int filler;
    int i, j;
    char temp[4];

    FILE *bmp_input = fopen(filename, "rb");
    printf("Nombre del archivo : %s\n", filename);
    if(bmp_input == NULL)
    {
        printf("No se puede abrir archivo.\n");
        exit(1);
    }

    BMP bmp;
    fread(&bmp.header, sizeof(Header), 1, bmp_input);
    fread(&bmp.infoHeader, sizeof(InfoHeader), 1, bmp_input);

    filler = bmp.infoHeader.Width % 4;
    if(filler != 0) filler = 4 - filler;

    bmp.pixels = (Pixels **)calloc(bmp.infoHeader.Height, sizeof(Pixels*));

    for(i=0; i < bmp.infoHeader.Height; i++)
    {
        bmp.pixels[i] = (Pixels *)calloc(bmp.infoHeader.Width, sizeof(Pixels));
    }
    for(i=0; i < bmp.infoHeader.Height; i++)
    {
        for(j = 0; j <bmp.infoHeader.Width; j++)
        {
            fread(&bmp.pixels[i][j], 1, 3, bmp_input);
            printf("[%d][%d][%d]\n",bmp.pixels[i][j].Red, bmp.pixels[i][j].Green,bmp.pixels[i][j].Blue);
        }
        if(filler != 0)
            fread(&temp, filler, 1, bmp_input);
    }
    fclose(bmp_input);

    return bmp;
}

void writeBMP(BMP bmp, char* filename)
{
    int i, j;
    int filler;
    char temp[4];

    filler = bmp.infoHeader.Width % 4 == 0 ? 0 : 4 - bmp.infoHeader.Width % 4;

    /* ALLOCATION DE MEMOIRE POUR LES PIXELS */
    bmp.pixels = (Pixels **)calloc(bmp.infoHeader.Height, sizeof(Pixels*));
    for(i=0; i < bmp.infoHeader.Height; i++)
    {
        bmp.pixels[i] = (Pixels *)calloc(bmp.infoHeader.Width, sizeof(Pixels));
    }

    /* OUVERTURE/CREATION DU FICHIER DE SORTIE */
    FILE *bmp_output = fopen(filename, "wb");
    if(bmp_output == NULL)
    {
        printf("No se puede crear archivo.\n");
        exit(1);
    }

    fwrite(&bmp.header, sizeof(Header), 1, bmp_output);
    fwrite(&bmp.infoHeader, sizeof(InfoHeader), 1, bmp_output);

    for(i=0; i < bmp.infoHeader.Height; i++)
    {
        for(j=0; j < bmp.infoHeader.Width; j++)
        {
            fwrite(&bmp.pixels[i][j], sizeof(UCHAR), 1, bmp_output);
        }
        if(filler != 0)
        {
            fwrite(&temp, filler, 1, bmp_output);
        }
    }
    fclose(bmp_output);
}

int main(int argc, char* argv[])
{
    BMP bmp = readBMP(argv[1]);
    writeBMP(bmp, argv[2]);

    return 1;
}

