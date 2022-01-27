#pragma once
#include <vector>



struct CompressOptions {
  int unknown_0;
  int min_match_length;
  int seekChunkReset;
  int seekChunkLen;
  int unknown_1;
  int dictionarySize;
  int spaceSpeedTradeoffBytes;
  int unknown_2;
  int makeQHCrc;
  int maxLocalDictionarySize;
  int makeLongRangeMatcher;
  int hashBits;
};

struct LzScratchBlock {
  void *ptr;
  int size;

  LzScratchBlock() : ptr(0), size(0) {}
  void *Allocate(int wanted_size);
  ~LzScratchBlock();
};



struct LzCoder {
  int codec_id;
  int compression_level;
  int platforms;
  const CompressOptions *opts;
  int quantum_blocksize;
  void *hasher;
  int max_matches_to_consider;
  float speed_tradeoff;
  int entropy_opts;
  int encode_flags;
  char limit_local_dictsize;
  char check_plain_huffman;
  int compressor_file_id;
  LzScratchBlock lvsymstats_scratch;
  int last_chunk_type;
};
