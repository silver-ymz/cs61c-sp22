#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    for (int xx = 0; xx < n; xx+=blocksize) {
        for (int yy = 0; yy < n; yy+=blocksize) {
            for (int x = xx; x < xx + blocksize; x++) {
                for (int y = yy; y < yy + blocksize; y++) {
                    dst[y + x * n] = src[x + y * n];
                }
            }
        }
    }
}
