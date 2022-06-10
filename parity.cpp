short Parity(unsigned long long x){
  short result = 0;
  while(x){
    result ^= (x & 1);
    x >>= 1;
  }
  return result;
}

short Parity(unsigned long long x){
  short result = 0;
  while(x){
    result ^= 1;
    x &= (x-1); // x의 하위 비트를 지운다.
  }
  return result;
}

short Parity(unsigned long long x){
  const int kMaskSize = 16;
  const int kBitMask = 0xFFFF;
  return kPreComputedParity[x >> (3 * kMaskSize)] ^
    kPreComputedParity[(x >> (2 * kMaskSize)) & kBitMask] ^
    kPreComputedParity[(x >> kMaskSize) & kBitMask] ^
    kPreComputedParity[x & kBitMask];
}

short Parity(unsigned long long x){
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}
