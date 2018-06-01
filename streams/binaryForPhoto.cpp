#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

typedef struct{
    char signature[2];
    int size;
    unsigned short reserved;
    unsigned short reserved1;
    unsigned data_offset;
}BMPHeader;

typedef struct{
    int          size;
    int          width, height;
    unsigned int planes;
    unsigned int bits;
    unsigned int compression;
    unsigned int imageSize;
    int          xResolution, yResolution;
    unsigned int colors;
    unsigned int importantColors;
}BMPinfo;

typedef struct{
    unsigned char Blue;
    unsigned char Green;
    unsigned char Red;
}Pixels;

typedef struct{
     BMPHeader header;
     BMPinfo   info;
     Pixels**  pixels;
}BMP;


void show(BMPHeader header){
    printf("Signature: %c%c\n", header.signature[0],header.signature[1]);
    printf("Tamaño: %i\n",header.size);
    printf("Datos de la imagen: %i (%Xh)\n", header.data_offset, header.data_offset);
}


int main(){
    const char *filename = "l2crest.bmp";
    FILE *pbmp = NULL;
    BMPHeader header;
    BMPinfo info;
    Pixels  pixels
    BMP     bmp;
    if(!(pbmp = fopen(filename,"r"))){//fclose(pbmp);
        fprintf(stderr,"No he encontado el fichero.\n");
        return EXIT_FAILURE;
    }
    fread(&header, sizeof(BMPHeader),1,pbmp);
    fread(&info,   sizeof(BMPinfo),  1,pbmp);
    fread(&pixels, sizeof(Pixels),   1,pbmp);
    fread(&bmp,    sizeof(BMP),      1,pbmp);
    fclose(pbmp);
    show(header);
    
   // FILE *fopen(filename,"r");

    return EXIT_SUCCESS;
}
