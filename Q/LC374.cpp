class Solution {
 public:
  int guessNumber(int n) {
    int l = 1;
    int r = n;

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (guess(m) <= 0) 
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};