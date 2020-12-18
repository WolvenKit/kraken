mkdir build
mkdir obj
cl /Fo:"obj\\kraken.obj" /Fe:build\\kraken.dll /Oi /LD /MT kraken.cpp
