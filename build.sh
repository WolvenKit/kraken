mkdir build
mkdir obj

g++ -pedantic \
-fpermissive \
-pedantic-errors \
-Wstrict-aliasing \
-Wno-misleading-indentation \
"-ftemplate-depth=1024" \
-mavx \
-mavx2 \
-fsanitize=undefined \
-c kraken.cpp \
-O3 \
-fPIC \
-o build/kraken.so