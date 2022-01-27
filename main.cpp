//
// Created by Ghost on 26.01.22.
//

#include <iostream>
#include <fstream>
#include "kraken.h"
#include "compress.h"

void error(const char *s, const char *curfile = NULL) {
    if (curfile)
        fprintf(stderr, "%s: ", curfile);
    fprintf(stderr, "%s\n", s);
    exit(1);
}

byte *load_file(const char *filename, int *size) {
    FILE *f = fopen(filename, "rb");
    if (!f) error("file open error", filename);
    fseek(f, 0, SEEK_END);
    int packed_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    byte *input = new byte[packed_size];
    if (!input) error("memory error", filename);
    if (fread(input, 1, packed_size, f) != packed_size) error("error reading", filename);
    fclose(f);
    *size = packed_size;
    return input;
}

int main() {
    const char *curfile = "/Users/ghost/Documents/Developer/kraken/oodle.txt";

    int input_size;
    byte *input = load_file(curfile, &input_size);

    byte *output = new byte[input_size + 65536];
    if (!output) error("memory error", curfile);
    *(uint64*)output = input_size;

    int outbytes = Kraken_Compress( input, input_size, output + 8, 5);
    if (outbytes < 0) error("compress failed", curfile);
    outbytes += 8;

    const char *destfile = "/Users/ghost/Documents/Developer/kraken/oodle.kark";
    FILE *f = fopen(destfile, "wb");
    if (!f) error("file open for write error", destfile);
    if (fwrite(output, 1, outbytes, f) != outbytes)
        error("file write error", destfile);
    fclose(f);

    return 0;
}
