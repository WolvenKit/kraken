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
    const char *curfile = "E:\\GitHub\\kraken\\oodle.txt";

    int input_size;
    byte *input = load_file(curfile, &input_size);

    byte *output = NULL;
    output = new byte[input_size + 65536];

    int outbytes1 = Kraken_Compress( input, input_size, output);
    int outbytes = CompressBlock(8, input, output + 8, input_size, 2, 0, 0, 0);

    std::ofstream file("E:\\GitHub\\kraken\\oodle.kark", std::ios::binary);

    if (file)
    {
        file.write((char*) output, sizeof(output));
    }

    file.close();

    return 0;
}
