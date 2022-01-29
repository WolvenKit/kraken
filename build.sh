mkdir build
mkdir obj

g++ -std=c++17 \
-pedantic \
-fpermissive \
-pedantic-errors \
-Wstrict-aliasing \
-Wno-misleading-indentation \
"-ftemplate-depth=1024" \
-mavx \
-mavx2 \
kraken.cpp \
-O3 \
-shared \
-fPIC \
-o build/kraken.dylib