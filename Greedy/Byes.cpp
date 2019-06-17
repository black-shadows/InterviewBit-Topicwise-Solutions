int numZeroes(long long v) {
    if (v == 0) return 0;
    return 64 - __builtin_clzll(v) - __builtin_popcountll(v);
  }

int Solution::solve(int lowerBound, int numberOfByes) {
    if (numberOfByes > 0) {
      lowerBound = max(lowerBound, 2);
    }
    lowerBound --;
    while (numZeroes(lowerBound) < numberOfByes) {
      lowerBound += (lowerBound & (-lowerBound));
    }
    for (long long v = 1; numZeroes(lowerBound) > numberOfByes; v <<= 1) {
      lowerBound |= v;
    }
    return lowerBound+1;
}
