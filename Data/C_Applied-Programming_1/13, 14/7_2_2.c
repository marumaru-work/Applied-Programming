#include <process.h>
#include <stdio.h>

#define Y_SIZE 256  // 画像の縦幅
#define X_SIZE 256  // 画像の横幅

enum Color { Black = 0, White = 255 };  // 画像の色

unsigned short bfType, bfReserved1, bfReserved2, biPlanes, biBitCount;
unsigned long bfSize, bfOffBits, biSize, biWidth, biHeight, biCompression, biSizeImage, biXPelsPerMeter, biYPelsPerMeter, biClrUsed, biClrImportant;

unsigned char imageIn[Y_SIZE][X_SIZE];   // 読み込んだ画像用の配列
unsigned char imageOut[Y_SIZE][X_SIZE];  // 出力画像用の配列

void readBmp(char *filename, unsigned char image[Y_SIZE][X_SIZE])
{
    FILE *fp;
    int i, j, k;

    if ((fp = fopen(filename, "rb")) == NULL)
    {
        printf("error: readBmp (file not found?)\n");
        exit(1);
    }
    printf("read file : %s\n", filename);

    // read header
    fread(&bfType, sizeof(bfType), 1, fp);
    fread(&bfSize, sizeof(bfSize), 1, fp);
    fread(&bfReserved1, sizeof(bfReserved1), 1, fp);
    fread(&bfReserved2, sizeof(bfReserved2), 1, fp);
    fread(&bfOffBits, sizeof(bfOffBits), 1, fp);
    fread(&biSize, sizeof(biSize), 1, fp);
    fread(&biWidth, sizeof(biWidth), 1, fp);
    fread(&biHeight, sizeof(biHeight), 1, fp);
    fread(&biPlanes, sizeof(biPlanes), 1, fp);
    fread(&biBitCount, sizeof(biBitCount), 1, fp);
    fread(&biCompression, sizeof(biCompression), 1, fp);
    fread(&biSizeImage, sizeof(biSizeImage), 1, fp);
    fread(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, fp);
    fread(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, fp);
    fread(&biClrUsed, sizeof(biClrUsed), 1, fp);
    fread(&biClrImportant, sizeof(biClrImportant), 1, fp);

    // read rgb image
    printf("read rgb\n");
    for (i = 0; i < (int)biHeight; i++)
    {
        for (j = 0; j < (int)biWidth; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fread(&image[i][j], sizeof(char), 1, fp);
            }
        }
    }
    fclose(fp);
    printf("end: read img\n");
}

void writeBmp(unsigned char image[Y_SIZE][X_SIZE], char *filename)
{
    FILE *fp;
    int i, j, k;

    if ((fp = fopen(filename, "wb")) == NULL)
    {
        printf("write bmp: Open error!\n");
        exit(1);
    }
    printf("output file: %s\n", filename);

    fwrite(&bfType, sizeof(bfType), 1, fp);
    fwrite(&bfSize, sizeof(bfSize), 1, fp);
    fwrite(&bfReserved1, sizeof(bfReserved1), 1, fp);
    fwrite(&bfReserved2, sizeof(bfReserved2), 1, fp);
    fwrite(&bfOffBits, sizeof(bfOffBits), 1, fp);
    fwrite(&biSize, sizeof(biSize), 1, fp);
    fwrite(&biWidth, sizeof(biWidth), 1, fp);
    fwrite(&biHeight, sizeof(biHeight), 1, fp);
    fwrite(&biPlanes, sizeof(biPlanes), 1, fp);
    fwrite(&biBitCount, sizeof(biBitCount), 1, fp);
    fwrite(&biCompression, sizeof(biCompression), 1, fp);
    fwrite(&biSizeImage, sizeof(biSizeImage), 1, fp);
    fwrite(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, fp);
    fwrite(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, fp);
    fwrite(&biClrUsed, sizeof(biClrUsed), 1, fp);
    fwrite(&biClrImportant, sizeof(biClrImportant), 1, fp);

    for (i = 0; i < (int)biHeight; i++)
    {
        for (j = 0; j < (int)biWidth; j++)
        {
            for (k = 0; k < 3; k++)
            {
                fwrite(&image[i][j], 1, 1, fp);
            }
        }
    }
    fclose(fp);
}

int main(void)
{
    char inputFile[] = "./tanq_binary.bmp";  // 入力画像のファイル名
    char outputFile[] = "./result_7_2_2.bmp";  // 出力画像のファイル名

    // 画像の読み込み
    readBmp(inputFile, imageIn);

    // 実装する場所
    int n = 2, threshold = 12;
    for (int y = 0; y < Y_SIZE; y++)
    {
        for (int x = 0; x < X_SIZE; x++)
        {
            if (imageIn[y][x] == Black)
            {
                int count = 0;
                for (int i = -1 * n; i <= 1 * n; i++)
                {
                    for (int j = -1 * n; j <= 1 * n; j++)
                    {
                        if (y + i >= 0 && x + j >= 0 && y + i < Y_SIZE && x + j < X_SIZE && imageIn[y + i][x + j] == White)
                        {
                            count++;
                        }
                    }
                }
                if (threshold <= count)
                {
                    for (int i = -1 * n; i <= 1 * n; i++)
                    {
                        for (int j = -1 * n; j <= 1 * n; j++)
                        {
                            if (y + i >= 0 && x + j >= 0 && y + i < Y_SIZE && x + j < X_SIZE)
                            {
                                imageOut[y + i][x + j] = White;
                            }
                        }
                    }
                }
                else
                {
                    imageOut[y][x] = Black;
                }
            }
            else
            {
                imageOut[y][x] = White;
            }
        }
    }

    // 画像の保存
    writeBmp(imageOut, outputFile);

    return 0;
}
