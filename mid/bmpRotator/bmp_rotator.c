#include "basic.h"
#include "coord.h"
#include "bmp.h"

typedef struct _sColor {
    uint8_t blue;
	uint8_t green;
	uint8_t red;
} __attribute__((__packed__)) sColor;

const sColor white = {
    .blue = 255,
    .green = 255,
    .red = 255,
};


double absf(double x) {
	if(x < 0) return -x;
	return x;
}

int main() {
    double deg, rad;
	printf("Please enter degree: ");
    scanf("%lf", &deg);
    rad = degree2Radian(deg);

    FILE *pFile = fopen("maldives.bmp", "rb");
    FILE *pFile2 = fopen("maldives_out.bmp", "wb");

    if (pFile == NULL || pFile2 == NULL) {
        printf("File could not be opened!\n");
        return 0;
    }

    sBmpHeader header, header2;
    fread(&header, sizeof(header), 1, pFile);
	header2 = header;
    header2.height = ceil(absf(header.height * cos(rad)) + absf(header.width * sin(rad)));
    header2.width = ceil(absf(header.height * sin(rad)) + absf(header.width * cos(rad)));
    header2.width = (header2.width + 3) / 4 * 4; //padding width
    fwrite(&header2, sizeof(header2), 1, pFile2);

	printf("============header=============\n");
	print_bmp_header(&header);
	printf("============header2=============\n");
	print_bmp_header(&header2);


    sColor *colors = malloc(header.bitmap_size);
	i64 count = fread(colors, 1, header.bitmap_size, pFile);
	printf("read byte: %ld\n", count);

	sVector v;
	sVector cent = vec((header.width-1) / 2.0, (header.height-1) / 2.0);
	sVector cent2 = vec((header2.width-1) / 2.0, (header2.height-1) / 2.0);
	for(i32 i2 = 0; i2 < header2.height; i2++) {
		for(i32 j2 = 0; j2 < header2.width; j2++) {
			v = sub(vec(1.0 * j2, 1.0 * i2), cent2);
			v = rotateVector(v, -rad);
			v = add(v, cent);

			i32 i = round(v.y), j = round(v.x);
			if(i >= 0 && i < header.height && j >= 0 && j < header.width) {
				fwrite(&colors[i*header.width+j], 1, 3, pFile2);
			}
			else fwrite(&white, 1, 3, pFile2);
		}
	}
	free(colors);

    fclose(pFile);
    fclose(pFile2);

    return 0;
}
