#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "snr_test.h"

struct ideal_sat ideal_satellites[] = {{18, -500, 774}, {24, 500, 1081}, {23, 2000, 293}, {15, -2000, 57}, {10, 3000, 1854}, {13, -3000, 292}};
struct snr_ber ber_vs_snr[5] = {};

char i_samples[4096] = {
    40, 28, 17, 7, -11, 3, 20, 2, -10, -18, -26, -14, -13, -33, -38, -16, -15, -38, -5, 13, -12, 1, 12, 4, 7, -16, -11, 1, -20, -42, -30, -8, -12, -1, -17, -9, -7, -20, -6, 0, 9, 1, -7, -1, 18, 24, -1, 0, -10, -22, -11, 1, 1, -14, -21, 17, 30, -5, -25, -23, 15, -6, -24, -21, 3, 27, 24, 26, 2, -14, -7, -28, -27, 11, 7, -8, 5, 28, 12, -4, -3, -3, 9, 4, 5, 11, 3, -29, -24, 5, 0, -4, 5, 13, 6, 1, 11, 13, -5, 10, 39, 1, -15, -17, -16, 34, 44, 6, -22, -10, 17, -1, -17, 9, 13, 5, 3, -22, -18, 30, 29, -15, -2, 3, -10, 25, 18, 1, -9, 9, 18, 6, 20, 6, 1, 15, 6, 5, 4, -38, -27, -5, -5, 30, 23, 15, 4, -8, -6, -15, -5, -1, -2, 15, 6, 24, 32, -24, -26, -25, -34, -33, -21, -11, -3, 7, 8, -2, -12, -5, -4, -21, -36, -20, 12, 33, 17, 25, 33, -7, -27, -26, -22, 4, 15, 27, 22, 33, 43, -24, -42, 12, 12, 8, 20, 13, -5, -33, -12, -17, -27, -9, -1, 12, 10, -4, -3, 16, 17, -12, -8, -11, 0, -6, -10, 4, -4, -18, -8, 3, -9, -13, -28, 1, 15, 2, 3, -26, -20, 22, 4, -19, 25, 12, -21, -19, -11, 26, 26, -1, 14, 9, -24, -19, 9, 28, 28, -1, -8, -9, -18, -21, -21, -21, -26, 16, 20, -19, -22, -16, -34, -5, 9, 12, -10, -10, 40, -1, -18, -19, 6, 46, 6, -5, 21, 3, -43, -51, -21, -21, -40, -42, -27, -19, -37, -5, -5, -37, 19, 43, -13, -35, -13, 14, 14, 10, 27, 1, 26, 55, 46, 50, 26, -4, -13, -20, -19, 18, 40, 38, 7, 4, 42, 36, -18, -48, -25, -22, -44, -45, -25, 16, 32, 26, 31, 0, -31, -1, -5, -9, 21, 30, 53, 44, -17, -12, 7, -30, -25, 12, 12, -25, -5, 25, -19, -25, -3, -27, 22, 15, -14, 16, -9, 1, 18, -22, 10, -11, -53, 7, 1, 1, 35, -17, -40, -30, 18, 40, 29, 26, 11, 35, 33, 11, 19, 40, 36, 6, -1, 0, -25, -58, -40, -9, -1, 9, 25, 16, 15, -7, -46, -3, 0, 9, -8, -8, 21, 1, 21, 12, -20, -52, -61, -19, -1, 29, 49, -2, -15, -6, 24, 25, -18, -27, 1, 8, 14, 16, 16, 7, 28, 56, 11, -41, -5, 56, -6, -34, 20, 60, 25, -15, -13, -22, -12, -24, -33, -46, -25, 26, 15, -36, -34, 29, 10, -20, 7, 26, 3, 3, -19, -24, -14, -34, -10, -28, -5, 42, 36, 52, 17, -36, -54, -16, 11, -34, -42, -6, 27, 25, 31, 31, 29, 45, 22, -14, 17, 9, -25, -36, -4, 5, -25, 10, -6, -49, -15, -23, -61, -23, 3, -9, -20, -8, -1, 8, -5, -10, 19, 24, 47, 30, -23, -40, -24, -6, -11, 25, 44, 8, 0, -21, 7, 42, 20, -6, -6, 15, -3, 5, -2, -34, -39, -39, -4, -9, -43, 6, 5, -30, -27, -46, -21, 19, -12, -37, 15, 29, -21, -21, 0, 16, 30, 7, -21, 8, 42, 46, 45, 30, 7, 11, -6, -5, 23, 4, 23, 13, -5, -14, -51, -48, -33, -7, 16, 22, -3, -3, 11, -28, -22, -7, -16, -32, -35, 0, -11, 0, 10, -25, -43, -44, -18, 12, -14, -10, -2, -34, -7, -8, -1, 28, -6, -2, -1, -5, -3, -27, -12, -12, -12, 11, -8, -4, 33, 5, -11, -9, -25, -3, 7, -18, -17, -16, -12, 15, 3, 3, 36, 33, -17, -40, -6, -9, -33, -32, 2, 5, -20, -23, 6, 6, 0, 27, 2, -30, -10, -1, -12, -17, -3, 25, -7, -7, 30, 31, 15, -28, -7, 41, 30, -13, -27, -1, 10, -7, -15, -19, 28, 36, -21, -30, 9, 18, -1, -22, -20, 7, -14, -20, -13, -14, -17, -32, -13, -12, -27, -22, 19, 29, 28, 27, 33, 34, -8, -16, -27, -27, -10, -10, 4, -3, 16, 24, -17, -17, -15, -25, 12, 12, -41, -41, -41, -13, 13, -5, 31, 22, -18, -9, 20, 40, 16, 7, 59, 48, -1, 7, 16, 28, 38, -2, -1, 10, -43, -33, -7, -14, 8, 13, 5, -3, 7, 16, 6, 6, -21, -42, -2, 13, 10, 22, 29, 17, 11, 32, 7, -21, -37, -31, -26, -23, 29, 43, -4, -7, 13, 23, 58, 49, 8, 1, -11, -21, -23, -3, -14, -11, -40, -48, -1, 17, 39, 21, -1, -7, -3, 7, 41, 41, 7, -16, -44, -27, -22, -27, -14, -17, -7, -22, -18, 10, -3, -31, -4, 9, -35, -10, 18, 2, 20, 20, 2, -14, -69, -75, -49, -19, 6, -6, 35, 26, 3, 14, 17, -4, -13, -15, -44, -44, -22, -12, -44, -44, 3, 7, 7, 2, 43, 54, -9, -19, 3, 36, 6, -28, -16, -15, 19, 40, 9, 9, 22, 26, 18, -8, -16, 7, -48, -70, -45, -24, -2, -14, 10, 26, 45, 13, 13, 13, -32, -27, -9, -9, -32, -6, 4, 5, 13, 9, -32, -46, -27, -31, 6, 21, 19, 6, -1, -1, -6, 10, 6, -14, -46, -42, -19, -29, -26, -19, -25, -8, -14, -4, 22, -6, 5, 0, -32, -1, 8, 11, 27, 21, 48, 32, -23, -13, 42, 43, 39, 44, 32, 33, 7, -46, -24, 11, 2, -14, 9, 35, 25, 33, 17, -12, -8, 15, 45, 23, -22, -47, -35, 9, 24, 9, -8, 7, 32, -10, -22, 20, 40, -7, -2, -2, -5, -7, -20, -2, -3, 0, 4, -11, -31, -2, 16, 34, 39, 11, -18, -27, -6, 24, 30, 4, -4, -1, 13, 20, -9, -13, 3, 3, -11, -26, -3, -10, -34, -18, 16, 45, 9, -9, -15, 4, 37, 26, 7, 3, 2, 6, 39, 41, 36, 38, 15, 8, -7, -2, 9, 10, 34, 0, -10, -18, -20, 27, 26, -6, 2, -12, -20, -8, -28, 8, 0, 2, 36, 27, 21, 4, 20, 30, 1, -5, 13, -8, -23, 26, 18, -8, 16, 26, 17, -9, -25, -9, 8, -9, 5, 31, -1, -18, -7, -18, -28, 2, -6, -32, 1, 32, 42, 21, -8, -14, -14, 0, 20, 32, 17, -8, 2, 5, -2, -21, -20, -31, -50, -25, -20, 8, 13, 13, 12, -4, 9, -7, -5, -7, -19, 19, 24, -17, 1, 32, 2, 3, 10, -14, -6, 13, 4, -8, -5, 5, 2, 3, 8, 25, 24, -11, -2, 33, 20, -20, -7, -7, -23, -11, -6, -3, 7, 14, 16, 28, 13, -29, -37, -37, -16, 16, 4, -20, -20, -10, 11, 30, 19, 4, -15, -22, 8, -8, -28, -9, -8, 8, 18, 4, -5, -27, -21, -6, -10, 30, 32, -23, -18, 26, 18, 4, 12, 32, 38, -1, -27, -28, -8, 7, 1, -2, 5, 41, 19, 3, 23, -1, -1, 6, -2, 24, 19, -11, -6, 4, 1, -27, -16, 17, 12, 10, 2, 7, 17, 21, 8, 5, -2, 14, 35, 19, 22, 2, -12, 15, 15, -21, -6, 29, 29, 30, 19, 21, 21, 4, -6, 18, 35, 4, -3, -9, -18, -5, 8, -3, -17, 3, 14, -17, -23, 3, 15, 11, -5, -18, 3, 23, 2, 1, 4, 4, 22, -16, -25, 5, -7, 9, 18, 17, 15, -11, 2, 34, 35, 7, 7, 6, -19, 0, -1, -44, -36, 29, 21, -35, -9, 38, 30, 21, 29, -15, -22, 14, -5, -43, -33, -1, 7, -6, -8, -19, -36, -45, -18, 19, 0, -5, -4, -22, -11, 9, -12, -34, -14, -2, -5, -17, -32, 16, 32, 34, 15, 7, 25, 27, 20, -12, 4, 3, -14, 20, 13, -43, -27, -30, -23, 15, -8, -15, 2, 18, 13, 12, 17, 29, 19, -36, -26, 2, 2, 15, 4, -1, 5, -24, -20, -20, -25, 9, 3, -30, -24, -1, 2, -5, -10, -13, -15, 28, 44, -32, -48, 11, 20, 9, 10, -16, -37, -5, 17, -19, -36, -40, -46, -18, -9, -20, -5, -33, -44, 6, -7, -57, -57, -8, -1, -12, 4, 6, -4, -24, -39, 9, 32, 10, -14, -3, 6, -17, -8, 36, 29, 29, 15, -39, -24, 5, 28, 14, -9, 9, 9, 7, -7, -30, -16, 10, 30, 47, 25, 25, -5, -23, 2, -10, 2, 16, 1, -17, -5, -14, -38, -18, 18, 5, -29, -17, -19, -6, 30, 26, 2, 8, 5, 5, 25, -1, -1, 17, 6, 28, 32, 30, 31, 19, -17, 4, 4, -33, -16, -22, -22, 3, 29, 10, 8, 15, 0, -10, 16, 31, 3, -11, -18, 15, 22, -10, -26, -33, 2, 29, 0, -7, 3, -4, -15, -18, -7, -1, -7, -30, -49, -7, 16, 0, 10, 4, 4, 8, -7, 3, 5, -9, -4, -1, -14, -9, -14, -14, 18, 10, 7, 15, 2, 35, 33, -12, 10, -16, -25, 6, -12, 22, 10, -41, -14, -7, -19, 11, 26, 10, -6, -24, 14, 11, -17, 12, 21, 6, 2, 27, 20, -4, -16, -9, -4, 17, 12, -7, -14, -25, 4, 1, 19, 18, -22, 3, 31, 1, 8, 20, -2, -11, -25, -28, 8, 31, 27, 28, 28, 36, 31, 33, 2, -16, -3, 0, 6, -28, -34, -26, -2, 31, -6, -32, 6, 9, 9, 31, 34, 38, 14, 2, 1, 19, 44, 33, 9, -21, -24, -28, -28, -18, -2, 11, 21, 31, 5, 17, 10, -15, 18, 34, 33, 40, 3, -15, -3, -6, -15, -23, 13, -6, -11, 23, 29, 28, -8, -20, -12, -13, -21, -16, -16, -27, 4, -15, -10, 33, 27, 33, 10, -7, 21, 17, -11, 6, 3, 3, 33, 15, 8, 5, 5, 24, 24, 26, 11, -6, -14, 22, 56, 33, 33, 48, 39, -16, -16, 17, 26, 29, 0, 13, 30, 18, 2, -2, -11, -13, -3, 9, 19, 0, 11, 21, 10, -12, -2, 24, 5, 5, 5, -15, -22, -21, -12, 1, -2, -22, -40, -49, -45, 11, 26, 9, -4, -27, -27, -19, -12, 6, 6, -17, -15, -32, -35, 21, 31, 20, -3, -11, -5, -17, -11, -34, -33, 29, 13, -35, -31, 26, 51, 4, -27, -2, 3, -22, -22, 3, 15, -21, -33, -12, 6, 2, -4, 27, 15, -5, 4, -12, -3, 5, 5, 27, 10, -2, 15, -1, -9, -24, -31, -41, -50, -12, -4, -28, -28, -9, -1, -6, -15, -41, -30, 22, 31, 5, -24, -9, -7, -20, -13, -1, 32, 22, 10, 2, -9, -15, -35, -20, 20, 11, -9, 15, 35, 26, 26, 11, -21, -1, 15, 24, 44, -4, -13, 46, 46, 17, 0, 11, -9, -45, -33, -16, -2, 18, 10, -22, -17, -10, 16, 41, -1, -41, -41, 1, 32, 32, 30, 8, 10, 31, 35, -14, -6, 4, -37, -32, -10, 26, 24, 36, 29, -21, -2, 16, -3, -18, -33, -2, 31, 22, 23, -8, -27, 8, 13, 8, 11, -7, -7, -17, -39, -28, -8, 11, -10, -16, -9, 4, 12, 25, 12, -43, -11, 38, 28, -8, -17, 4, 4, -22, -22, 3, 24, 43, 22, -3, -11, -40, -44, -22, -26, -35, -18, -23, -27, 21, 29, -17, 0, 40, 11, -9, 20, 28, -13, -9, 32, 51, 33, 24, 14, -21, -23, 7, 28, 9, 18, 26, 0, -47, -30, 8, -11, -29, -28, -27, -21, -9, -16, -27, -18, -1, 1, -23, -34, 2, 30, 34, 7, -9, 1, -30, -49, -53, -44, -2, 6, -1, 7, -10, -25, -31, -32, 4, 5, -22, 1, -21, -54, -3, -6, -38, -4, 52, 24, -23, -21, -34, -10, -9, -19, 12, 0, 34, 53, -17, -29, -29, -27, 5, 2, -9, -5, 4, 6, 2, 2, 24, 3, -34, -15, 5, 3, -17, -6, 31, 22, 23, 20, -11, -22, -14, 11, 25, -3, -26, -15, 16, 15, -29, -25, -2, -4, 7, 15, 29, 27, 48, 57, 28, 12, 24, 33, 1, 0, 0, 2, -6, -16, 22, 22, -14, -17, 13, 7, -11, -3, 9, 10, 27, 35, 12, -1, 40, 45, -6, 4, 3, 2, 8, 11, 16, 2, 28, 31, -2, 6, -15, -29, -11, 5, -9, -25, -31, -24, 10, 9, -14, -11, -44, -50, 30, 33, 11, 1, -16, 9, 20, 20, 27, 8, 3, 25, 42, 39, 34, 8, -15, -9, 1, 5, 3, 4, 7, 10, 7, 11, 3, 8, 20, 6, 17, 25, -14, -12, -22, -38, -23, -17, -48, -44, -12, -11, -5, -20, -3, -3, -22, -17, -21, -13, -45, -24, -3, -13, 13, 1, -6, -12, -39, -19, -23, -13, 28, 9, 17, 8, -20, -10, -30, -30, 4, -8, -32, -24, -24, 8, -2, -17, -27, -9, 48, 34, 38, 36, 5, 10, -21, -22, 39, 33, -7, -6, -20, -40, 17, 13, -5, 8, -22, -28, -9, -17, -10, 8, 10, -16, -41, -26, -3, 5, 25, 49, 23, 26, 54, 16, -2, 18, -16, -35, -10, 23, -1, 4, 10, -12, 7, 4, -30, -43, -28, -22, 14, 43, 59, 59, 4, -19, 11, -9, -41, -16, 6, -9, -3, 9, -7, -19, -22, -20, -4, -13, -5, -2, 16, 39, 31, 45, 30, 7, 21, -10, -7, 20, 24, 27, -8, -18, -12, -6, -29, -47, -11, -8, -15, 12, -3, -1, -14, -34, -22, -35, -9, -8, -22, -22, -30, -17, -21, -15, 7, 5, 4, -2, -19, -39, -26, -30, -44, -38, -29, -21, 0, -6, -19, -26, -9, 13, 8, 11, 16, 11, 8, 27, 13, 20, -1, -11, -7, 1, 22, -11, -36, -33, 1, 20, 24, 48, 46, 34, 15, -4, 14, 6, -7, 17, 30, -16, -34, -14, 6, 38, 41, 30, 14, -11, -11, -10, -13, -21, -2, 37, 25, -8, -32, -42, -25, -7, -7, -25, -19, 4, -1, 7, 1, -20, -33, -8, 29, 13, 12, 17, 17, 12, 7, 5, 7, 33, 21, 0, 1, 7, 4, -2, 8, 17, 4, -20, -27, -32, -18, -7, -14, -1, 6, -20, -3, 32, 27, 15, 2, 12, -5, -32, -23, 2, -3, -9, 7, 11, 2, 12, 12, -9, -10, 4, -4, 2, 18, 16, 1, -29, -19, 18, 18, 12, 13, -4, -11, -17, -11, 8, 2, 2, 8, 18, 3, -8, -2, -5, 4, 7, 12, 11, -3, -33, -31, -5, 6, -1, -1, 4, 16, 13, 13, 0, -16, 13, 31, -11, -21, -25, -8, 4, -10, -9, 13, 17, -14, -27, -30, -31, -6, 34, 13, 8, 32, 26, 24, 11, 2, -12, -5, -1, -19, -4, 14, 16, 16, 28, 6, -13, 11, 16, -6, -13, 8, 2, -9, -5, -4, -14, -36, -32, -2, 28, 20, 13, 3, -13, -23, -45, -25, -11, -9, 1, 0, -13, -6, 26, -1, -17, 13, -2, -7, 39, 31, 9, 17, 5, 0, -22, -24, -5, -3, 13, 16, 11, 20, -4, -11, -9, -9, 3, 6, 11, 6, 15, 20, 15, -6, -39, -15, 7, 2, -4, -12, -3, 9, 17, 0, -32, -16, 2, 2, 21, 6, -22, -5, -6, -12, 3, -9, 4, 10, 4, 16, 16, 14, 12, 7, -22, -24, -6, -1, -27, -18, 31, 12, -25, -14, 27, 16, -7, -5, 4, 19, 0, -15, 2, 13, -27, -26, -4, -8, 3, 7, 30, 20, -6, -4, 18, 11, -4, 16, 21, 21, -1, -11, -14, -14, -8, -15, 12, 17, -32, -24, 25, 29, 27, 11, 5, 5, 5, -3, 10, 25, 0, -3, 3, 3, 22, 31, 28, 28, 21, -1, 21, 20, -11, -7, -30, -20, 16, 15, 19, -3, 3, 36, 17, 17, 48, 38, 24, 12, -23, -24, -6, -4, 19, 18, 32, 45, 12, -1, 24, 34, 33, 10, 3, 26, -11, -21, -27, -12, 27, -1, -6, 23, 24, 4, 21, 26, -30, -23, 3, -3, -8, -23, -43, -37, 9, 29, 41, 23, -16, -1, -29, -27, 34, 34, -19, -35, -4, -7, 14, 38, 9, -22, -34, -28, -14, -3, -8, -13, 2, 24, 4, -25, -23, -3, 10, -3, -15, 7, 26, 26, -14, -14, 32, 7, -5, 16, -6, -31, 3, 19, -16, -5, 31, 16, 2, 7, 12, 19, 9, 2, 16, 6, -2, 18, 32, 12, -14, 9, 15, -9, -15, -22, -24, -9, -23, -19, 4, -8, -29, -17, 12, 12, -7, -11, -15, -23, -38, -47, -22, -4, 6, 27, 17, -5, -29, -29, 5, 5, 17, 32, 31, 19, -19, -30, 1, 11, 6, 19, -8, -17, -15, -19, 2, -7, -37, -15, -9, -35, -21, -17, 6, 15, -25, -16, 19, -8, -4, 5, -5, 5, -2, -2, 7, -8, -42, -21, -28, -23, 2, -4, -5, 10, 30, 2, 6, 18, 15, -9, -34, -10, 8, 16, 18, 27, 14, 6, 33, 16, -13, -17, 24, 36, 7, 7, 19, 28, 31, 30, -10, -10, 25, 13, 6, 8, -13, -14, 18, 7, 8, 8, -3, 6, 43, 46, -13, -42, -44, -18, -13, -40, -43, -32, -7, 28, 20, -9, -18, -18, -4, -6, 13, -2, -26, 12, -1, -12, -30, -37, -3, -6, -22, -41, -18, -9, 7, 7, -12, -16, 1, 1, -36, -29, -23, -22, -28, -16, 25, 5, -21, 8, 22, 1, -38, -47, -22, 2, -22, -22, -14, -5, -1, -26, -40, -33, 15, 0, 18, 41, 41, 31, -39, -18, -19, -53, -53, -53, 4, 6, -41, -41, 3, 27, -27, -20, -18, -30, 10, 3, 4, 4, 23, 29, 22, 23, -4, -4, 12, 4, -13, -18, 6, 19, -7, -26, -41, -29, 33, 29, 2, 20, -8, -30, -10, -13, 17, 36, 27, 32, 20, 17, -5, -10, 37, 31, -16, -16, -17, -5, -35, -38, -6, 2, -22, -33, -45, -25, -18, -43, -3, 8, -15, -35, -40, -20, 25, 49, 28, 24, -10, -47, 3, 2, -15, -10, -22, -1, -9, -29, -6, 17, 23, 24, 3, -3, 3, 5, 29, 44, 21, 15, -2, -22, 18, 11, -3, -4, 9, 36, 25, 5, 9, 28, 26, 28, -9, -36, -50, -57, -32, -32, -37, -2, 30, 29, 24, 21, 23, -9, -35, -24, -31, -43, 6, 12, -44, -46, -27, -25, -1, 6, 5, 6, -9, -18, -33, -25, -17, -17, 12, 30, 21, 36, 45, -8, -33, -2, 23, 47, 21, 9, 4, -33, -34, -23, 20, 22, -20, 4, 29, -5, -14, -12, 14, 38, 12, -15, -40, -39, 12, 15, 14, 34, -8, -38, -25, 4, 31, 14, -3, 20, -15, -28, -18, -42, -43, 9, 33, -14, 4, 47, 20, 3, 3, -4, 27, 6, -20, -11, 7, 34, -6, -4, -3, -6, -14, 0, 2, -46, -20, -14, -14, -3, -5, 25, 34, 16, 0, -23, 11, 49, 25, -8, -44, -33, -15, -15, 0, 1, -7, -31, -22, -29, -45, -43, -52, -29, -7, 9, 17, 7, -15, 12, 24, 19, -10, -53, -18, 30, 38, 0, 15, 20, -15, 22, 8, 8, 43, -3, 4, 14, -8, -24, -15, -27, -14, 14, -29, -11, 47, 32, -4, -12, -41, -26, 33, 2, -57, -37, 25, 42, -11, -25, 18, 15, 5, 3, -40, -66, -35, -18, 5, 54, 5, -45, -46, -19, 8, -26, -53, -55, -35, -32, -33, -2, 8, 9, 16, -11, -24, -18, -15, -13, -45, -12, 14, 10, 49, 56, 10, -8, 10, -11, -18, -47, -40, 5, 4, 30, 1, -20, 4, -25, -25, -20, -44, -37, -37, -18, -5, -8, 40, 2, -39, -19, -10, -3, -42, 1, 33, -17, 12, 61, 61, 23, -17, 0, 30, 17, 27, 57, 48, 52, 31, -52, -31, 19, 16, -9, -28, -12, 21, 17, -13, -21, -34, -7, 44, 10, -27, -37, -40, 11, 11, -7, 21, 16, 20, 10, -20, -28, 2, 41, 9, -33, -3, 6, -24, -18, -4, 4, 22, 40, 52, 67, 58, 63, 15, -39, 0, 34, 7, -24, -6, 8, 30, 23, -23, 4, 37, 6, 16, 3, -3, 4, 6, 9, -37, -47, -8, 9, -9, -7, 31, 53, 8, 1, -5, -23, 14, 24, 30, 34, -4, 6, 38, 44, -1, -36, -21, -54, -69, -23, -16, -20, 25, 37, 37, 17, -4, 9, -3, -8, 25, 25, 13, 7, -2, 6, 15, -12, 1, 39, 5, -17, 8, -9, -42, 4, 37, 17, 0, -9, -35, -16, 31, -7, -54, -24, 19, 15, 17, 34, 19, 3, -16, -3, -11, -16, 25, 43, 43, 28, 27, 38, 6, -10, -18, -9, 21, -6, -26, -2, 19, -14, -4, 40, 48, 12, -7, 4, 15, 46, 16, -21, -23, 13, 15, -32, -32, -10, 18, 22, -6, -1, 5, -8, 14, 13, -1, 12, 26, 36, -3, -12, -8, -13, 31, 37, 25, 23, -11, -9, -7, -21, 11, -2, -36, -9, 1, -19, 7, 31, 0, -8, -8, -17, -24, -32, -28, -20, -20, -30, -1, -5, -5, 28, 28, 25, 25, 3, -19, -27, 2, 2, -37, -31, -25, -3, 0, -30, -1, 2, -7, -13, -10, 25, 2, 0, 29, 38, 11, -31, 4, 13, -22, -28, -34, 0, 29, -4, -4, -1, -2, -1, -18, -14, 9, 3, -3, 15, 22, 1, -11, -8, 4, 6, -21, -6, -12, -27, 6, 12, -21, 4, 7, -17, 14, 38, 44, 19, 16, 34, 23, -10, -14, -10, 1, 41, 49, 32, -4, 2, 6, 11, 0, -26, 8, 19, 17, 18, 13, -6, -4, -2, -3, -10, 3, 15, -25, -46, -40, -20, 1, -10, -38, 10, 30, 3, 17, -17, -10, 13, -8, 12, 13, -26, -26, -12, -36, -16, 28, 6, 14, 14, -3, -2, 15, 12, -15, -12, 6, 22, 4, -8, -8, -2, -5, 0, 26, 54, 40, 20, -9, -8, 3, -18, 32, 45, 45, 32, -25, -33, -2, 13, 17, 14, 20, 2, -11, -21, -36, -45, -24, -15, -10, 6, -12, 6, 12, -13, -20, 7, 13, -15, -21, 27, 45, 9, -9, 17, 17, -25, -30, 3, 15, 8, -12, -22, 19, 25, 5, 28, 48, 11, 4, 7, -10, -15, -36, -27, -27, -48, -44, -15, 39, 21, 2, 1, -5, -9, -9, 5, -17, -20, -20, -2, 19, 3, 17, 27, -18, -31, 14, -7, -20, 3, 25, 42, -12, -43, -30, 14, 1, -7, 2, -4, 42, 23, 23, 47, 38, 39, 47, 2, 11, 37, -3, -6, 13, -24, -9, -6, -30, 8, 10, -7, 3, -3, -3, 40, 34, 39, 45, -4, 8, 1, -30, -8, -1, 21, 41, 65, 56, -19, -41, -21, -26, -31, 0, 44, 26, -6, -10, 22, 22, -40, -23, 6, -19, -30, -1, 5, 8, -12, -36, -11, -2, 9, 20, 11, 3, -33, -43, -28, -19, -23, -27, 20, 21, 5, -4, -21, -19, 13, 13, -12, -12, 4, 5, 13, 20, -30, -17, -2, -29, -10, -4, -1, -6, -44, -11, 34, 26, 15, -2, -9, -19, 0, 28, 29, 19, -19, -9, 14, 14, 14, -6, -7, 8, -10, 0, 26, 19, -31, -31, -6, -19, -31, -42, 4, 9, -20, -9, -19, -25, -8, -2, -6, 9, 12, -14, 3, 3, -30, -10, -16, -18, 12, 14, 6, 7, 46, 51, 25, 3, 2, 15, -8, -10, -30, -32, 26, 35, 0, -9, 22, 14, -21, -3, 26, 28, 22, 10, -10, -8, -3, -5, 7, 9, 16, 6, 7, 17, 0, -10, -14, -6, -16, -15, -16, -26, -13, 7, -3, -15, 23, 23, 5, 5, -3, -1, -13, -6, 5, -1, -7, -6, 6, -6, -9, -8, -8, 2, 11, 12, -11, -17, 27, 37, 5, -13, -20, -4, 3, -10, -2, 11, -13, -24, -2, -8, -10, -8, -16, -16, -5, 10, 12, 10, 11, -3, 4, 3, -4, 12, 14, 5, 3, 15, 27, 11, -12, -3, -3, -15, -35, -23, -13, -25, -16, 1, 2, -6, 1, -8, 4, 11, 14, 22, 27, 16, -1, -16, -6, -1, 8, 11, -8, -11, -17, -2, 24, 11, -15, 4, 26, 8, -10, 3, 11, 8, 4, 3, -4, -22, -5, -5, -20, 1, 18, 18, 5, 13, 25, 9, -5, -5, -19, -15, 5, -4, -4, -2, 0, -9, -10, 1, -10, -3, -5, 4, 28, 19, 2, 1, 12, -3, 0, 0, -5, 3, 2, 9, 11, 2, -19, -29, -24, -22, -19, -8, -20, -40, -10, 28, 30, 23, 9, 8, 19, 19, 20, 3, 0, 14, -3, -12, -2, 10, 17, 8, 1, -8, -16, 3, -5, -17, -10, -16, -3, 6, -22, -12, -8, 3, 8, -10, 4, -4, -17, -7, -1, -11, 3};
char q_samples[4096] = {
    -17, 2, -1, 2, 7, 5, 10, 24, -22, -2, 40, -19, -17, 23, -4, -30, -42, 7, 53, 19, -12, -8, 26, 47, 38, 47, 62, 15, -11, 28, 20, -19, -10, 27, 16, -16, -37, -34, -3, 16, 21, 4, -16, -9, 15, -1, -17, -28, -33, 5, 11, -14, -14, 8, 16, -19, -21, 1, -23, -45, -10, 44, 53, 55, 44, 25, 33, 21, 3, 36, 1, -27, -9, -35, -27, 3, 22, 5, -16, -29, -58, -58, -18, 13, 36, 28, -21, -17, 7, 2, 1, -10, -13, 1, 8, 5, -3, -21, -10, 14, 14, 15, 21, 14, -13, -8, 20, 37, 13, 13, 9, 17, 6, -11, -5, 3, 12, -2, 17, -7, -38, -13, 16, 37, -10, -32, 31, 15, -21, -4, -8, -3, 7, 18, 13, 0, -3, -2, 8, 6, -8, -16, -16, -11, -33, -54, 5, 35, -19, -14, 9, 9, -17, -26, -35, -44, -14, 14, 45, 22, 7, 5, -23, -26, -14, 6, 11, -8, 2, -5, -11, -2, 7, 0, 14, 5, -18, 2, 14, 8, 19, 39, -16, -49, -35, -16, 6, -2, 6, 17, 21, -8, -8, 18, 17, -1, -12, 0, -2, 6, 32, 20, 33, 15, 0, 17, 9, 0, -3, 8, -8, -6, 44, 42, 18, 11, -33, -26, 40, 41, -35, -33, -43, -53, -4, 4, -7, 3, 15, -1, 0, -2, 8, 14, -13, -22, -4, -1, -12, -12, -2, 10, -16, -28, 30, 17, 23, 31, -17, -7, -30, -27, 39, 39, 20, 13, 1, 4, -10, 7, 8, -9, 14, 11, -16, -16, 19, 34, 25, 15, 4, -11, -21, -14, -17, -7, -15, -21, -13, -13, -16, -26, 3, 9, -43, -40, -25, -15, -3, -20, -31, -5, 25, -3, -9, 5, 26, 30, 23, 5, 3, 12, 33, 38, -7, -15, -14, -11, 8, 13, 21, 8, -10, -18, -39, -35, -4, 8, -14, -14, 6, 18, 12, 4, -4, 0, -13, -17, 23, 9, -31, -10, -7, -28, -17, -5, -12, -16, -6, -2, -2, -6, -14, -17, -11, -23, -30, -16, -2, -13, -35, -37, -19, 2, -12, -30, -16, -12, -12, -13, -29, -29, 2, 12, -15, 0, 29, 17, 24, 21, 19, 23, 5, 10, 6, -10, 1, 5, 15, 23, -5, -22, -28, -25, -4, 5, 5, 2, -2, 4, -8, -21, -23, -9, 1, 1, -15, -11, -1, -1, -3, -22, -16, -5, 5, 6, -11, -20, -2, -3, -12, -10, -13, -15, -18, -10, 1, -9, 2, 4, -3, 11, 26, 18, 7, 14, 2, -13, -6, 14, -6, -24, -17, -16, -26, -19, 0, -4, 5, 15, -7, -18, -8, 6, 4, 0, 26, 20, -16, -16, -5, -10, 2, -7, -35, -28, 4, 11, 15, 22, 15, 12, 10, -7, -8, -1, -12, -15, -6, -5, -11, -11, -31, -25, 28, 30, -10, -6, 34, 14, -11, -16, -33, -21, -3, -7, 4, 10, -10, -9, 4, 11, 22, 19, -21, -5, 6, -12, -23, -5, 8, -7, 11, 0, -38, -26, -22, -18, 7, 6, -10, -28, -22, -12, -22, -9, 11, -4, -27, -4, 26, -5, -1, -1, -25, -27, 16, 44, 10, 0, -15, -25, -9, -7, -17, -34, -14, 11, 13, 13, -23, -13, -8, -17, 12, 23, 8, 0, 18, 8, -27, -36, -1, 26, 9, -13, -20, -20, 16, -3, -2, -11, -55, -6, -2, -28, -8, -8, -18, -10, -22, -33, 13, 3, -7, 4, 4, 37, 20, -13, 5, -17, -48, -23, 1, 10, 15, -6, 19, 7, -28, 7, -19, -20, -1, 0, 21, 20, -22, -12, 24, 3, 20, 55, 52, 16, 23, 33, 7, 2, -24, -16, 17, -8, -8, 6, -29, -28, 19, 45, 7, -11, -26, -36, 11, 11, -4, 5, 9, -22, -7, 36, -10, -17, 11, 9, 3, -22, -34, 0, -2, -8, -15, -15, 33, 33, 0, -3, 8, 0, -10, -14, -13, 23, 41, -9, -35, -14, 21, -7, -28, -30, 2, 5, -25, 5, 2, -20, -40, -19, 3, -7, -1, -1, 16, 29, 25, 19, 35, 10, 14, 41, 37, 10, -33, -23, -3, 10, -7, 6, 41, 36, 32, 25, 4, -7, -13, 7, 37, 37, -4, -5, -8, -31, -15, -11, 15, 21, -5, 0, 8, -5, 2, -2, 27, 44, -6, -1, 11, -8, 1, 16, 11, 5, -39, -36, 5, -10, 15, 32, 23, 17, 35, 37, -1, -1, -28, -25, 28, 11, 1, -4, 15, 19, 10, 8, -7, 13, -24, -40, -36, -17, 41, 30, 5, -5, 6, 6, 20, 20, 0, 10, -12, -8, -3, -7, -3, -3, -36, -43, -10, -3, -9, -17, -2, 10, 13, 9, 11, 11, 19, 23, -8, 0, -13, -22, 3, -6, -21, -1, -5, -18, -14, -1, 20, 21, -6, -28, -23, -4, 10, 9, 21, 9, -19, -6, 0, -15, -23, -26, -18, -7, 13, 12, -13, -5, 38, 28, 9, 9, 1, 5, -24, -24, -13, -3, 14, -6, 3, 8, 8, 12, 29, 29, 11, 0, -31, -22, 8, -6, -30, -30, -31, -18, -3, -13, -32, -25, -12, -9, 11, -1, -8, 12, 3, -1, -12, -9, -10, -10, 25, 17, -19, -19, 6, 22, -2, -11, -14, -31, -28, -10, -22, -14, 19, 1, 6, 14, 18, 18, 19, 12, -21, -32, -12, 7, -8, -9, -10, 1, 19, 3, -29, -27, 12, -3, 11, 29, -8, -1, -7, -16, 9, 27, 31, 7, 25, 38, 20, 19, 17, 28, 2, -7, 15, -6, -44, -39, -30, -19, -17, -15, 13, 7, 15, 3, -40, -10, 34, 15, -9, -1, -6, -17, 26, 8, 0, 27, -13, -41, -26, 2, 24, 12, 3, 3, 5, -4, -31, -19, 25, 47, 30, 2, -27, -17, 28, 28, -13, -15, 23, 36, 21, 30, 38, 25, 31, 28, -20, -31, -21, -30, -20, -20, -32, -30, -17, -13, 24, 39, 3, -10, -18, -19, -14, -12, -2, 15, 2, -31, -13, 20, 2, -23, 4, 38, 23, 16, 16, -10, -5, 28, 25, 19, 29, 18, 24, 17, 9, 22, 24, 26, 25, 33, 2, -12, -5, 12, 25, 28, -4, -5, 29, 24, 28, -11, -17, 24, 0, -20, -1, -15, 1, 0, -5, 19, 8, 6, -22, -20, 4, 15, 43, 44, 12, -1, -4, 2, 8, -13, -27, -11, 31, 14, -44, -24, -24, -39, -7, 4, 38, 15, 6, 34, 20, -12, -12, -5, -21, -18, -3, 4, 11, 13, 36, 21, -32, -34, 21, 56, -10, -21, 17, 5, -13, -24, -17, -9, -10, 9, -17, -64, -64, -24, 43, 45, 5, -9, -9, -28, -45, -20, -20, -34, -16, -12, -21, -31, -22, -11, 30, 29, 27, 9, -8, 2, -46, -50, -20, -20, 15, 26, -8, 8, 35, 19, -24, -9, 14, -10, -17, -8, 5, 16, -17, -1, 15, -22, -1, 25, 4, 11, 22, 16, 16, -7, -17, 11, 47, 16, -20, 8, -2, -8, 7, -8, -5, 1, -12, 4, -10, -18, -4, 2, 36, 38, -11, -6, 39, 33, 49, 42, 23, 33, 41, 30, -8, -9, -23, -20, 20, 12, -29, -37, -26, -15, -15, -5, 47, 23, 5, 11, -19, 2, -10, -15, -15, -27, -16, -32, -32, -26, -46, -44, 3, 12, 26, 4, -7, 41, 14, -14, -18, -9, 9, 2, 6, -20, -59, -25, 5, -10, -13, -13, 1, 5, -38, -32, 11, 32, 23, 0, -35, 10, 49, 14, -2, -24, -41, -37, -5, -5, -34, -22, -31, -14, -14, -24, 20, 38, 47, 47, 17, -2, 27, 24, -29, -50, -20, -17, -47, -24, -8, -40, -3, 31, 23, 6, -1, 6, -24, -5, 30, 21, -22, -41, -3, -3, -7, 17, 1, -17, 8, 2, -3, 39, 30, 18, 42, 35, -8, -47, -13, -18, -57, -35, 3, 0, -42, -32, -18, -32, 5, 43, 28, 3, -34, -33, 19, 54, 14, -5, 6, 9, -3, -35, -32, 15, 38, 13, 13, 18, 22, -2, -41, 9, 43, 43, 55, 9, 2, 11, 18, 41, 28, 8, -26, -32, -5, 10, 1, 17, 25, 17, -4, -8, -2, 6, 21, 10, -5, -17, 16, 24, 6, 35, 48, 36, -5, -9, 3, -21, -6, 17, 17, 24, 42, 19, -24, -11, 0, 19, 45, 22, -1, 14, 37, 9, 13, 24, 14, 7, 16, 20, 5, 24, -2, -31, -12, 1, -19, -43, -43, -27, 0, 2, -25, -14, -6, -7, 27, 27, 16, 20, 20, 41, 23, 1, -16, -35, 1, 17, 14, 24, 12, -4, -31, -25, 12, 14, 4, 6, -22, -47, -4, 21, -4, -22, -22, -13, -14, -22, -27, -12, -11, -39, -26, -29, -29, 15, 28, 10, 10, 22, 0, -33, 5, -2, -45, -16, -4, 2, -12, -24, -1, -15, 2, 11, -4, 25, 4, -14, 15, 33, 1, -29, -9, -9, -28, -20, -28, -4, 20, -18, -5, -3, 5, -9, -47, -32, -11, -19, -9, 3, 13, 0, -5, 10, -13, -11, -27, -31, -4, 0, 17, 17, -27, -24, -1, -2, 26, 19, 6, 17, 12, 11, 18, 4, -1, -8, 6, 47, 35, 30, 21, 13, -3, -10, 10, -13, 3, 7, 14, 32, 29, 29, 22, 7, 15, 18, -3, -13, -13, 6, -1, -3, 24, 8, -20, 4, -17, -21, 28, 21, -10, 16, -3, -25, -17, -12, -12, -28, -15, -11, -4, 13, 12, -16, -4, 4, -9, -4, -22, -43, -23, 26, 5, -37, -37, -15, -24, -39, -20, 15, 46, 33, 5, 11, -7, -24, 0, 29, 29, -8, -13, -5, -17, -46, -16, 3, -29, -10, -18, -33, -2, 4, 17, 28, 32, 21, 1, 29, 1, 1, 0, -15, -14, -21, 7, 16, 36, 17, -3, 1, 0, 6, -31, -23, -11, -45, -24, -17, -24, 17, 4, -23, -10, -29, -38, -8, -14, -33, -12, 10, 10, -9, -6, -24, -21, -5, -26, -32, -26, -25, -25, -20, 0, 41, 41, 16, -4, -24, -23, -33, -28, -3, -9, -13, 19, 44, 24, -23, -25, 29, -3, -33, -1, 14, 30, -11, -38, -26, -27, -4, -11, -13, 15, 30, 21, 2, 23, 54, 51, 0, -29, -18, 21, 41, 19, 3, 3, 11, 11, -13, -26, 10, 23, -23, -40, -24, -13, -21, 6, 5, -24, 1, 11, -21, -6, 52, 40, -36, -46, -10, 2, -23, -35, -9, -9, -4, 3, 4, 6, 1, -21, -8, 3, -31, -30, -22, -20, -18, -32, 5, 15, -24, 0, 36, 12, -2, 2, 10, 20, 44, 43, 11, 21, 20, 20, -11, -21, -17, -8, 48, 29, -13, -4, 12, 21, 23, 14, 3, 4, 9, -8, -6, 12, -17, -18, 20, 29, 20, 4, -17, -8, 15, 6, -13, -13, -45, -33, 5, -7, -51, -60, 5, 8, -12, -12, -5, 5, 6, 15, 7, 1, -3, -15, -2, 1, 13, 23, 34, 17, 27, 37, -18, -18, -31, -37, -9, -1, -4, -12, 32, 33, 14, 10, -11, -1, -19, -19, 33, 31, -4, 4, 26, 16, 8, 16, 21, 13, -33, -34, 8, 9, 25, 33, 31, 15, 14, 24, -22, -23, -11, -14, -7, -14, -25, -20, -26, -18, -30, -36, 9, 8, -41, -36, 15, 16, 13, 18, 15, 15, 18, 8, 15, 22, -17, -24, -7, -3, -19, -26, 5, 0, 1, 9, 32, 28, 4, 9, 26, 35, -9, -31, -35, -12, -10, -20, -2, 9, -5, -16, 34, 21, 1, 10, -38, -37, 4, 19, 20, 2, -16, -13, 22, 10, 11, 20, -16, -1, -12, -18, 16, 13, -7, -14, -1, -9, -33, -11, 16, -6, -21, -4, -24, -32, -22, -32, -5, 20, 45, 45, 14, -1, -19, -28, -26, -16, -34, -18, -25, -50, -30, 6, 6, -4, -5, 5, 6, -4, -2, 34, 37, -6, -37, -48, -16, 1, -27, -37, -32, 5, 41, 24, 12, 21, 18, -2, 11, 11, 9, 6, 5, 5, -20, -36, -46, -27, -1, -1, 11, 38, 17, -2, -1, 30, 52, 10, -13, -36, -36, -36, -26, 3, -10, 17, 26, 30, 29, 17, 17, -3, 18, 17, 1, -5, -21, 4, 6, -21, 1, -16, -30, -30, -42, 0, 8, -13, -1, 4, 5, -22, -28, -23, -30, 8, 10, -33, -35, 20, 26, -25, -36, 11, 31, 21, 16, 1, 0, 40, 23, 0, 12, 31, 21, 3, 18, -2, 0, 37, 11, -53, -30, 10, 12, 4, 4, -18, -28, -18, -15, 12, 9, 6, 26, 12, 6, 4, -2, 3, 5, 13, 22, 16, 4, 29, 28, -23, -23, -10, -6, 12, 12, 20, 5, -21, -10, -29, -40, 27, 17, -20, -9, 27, 21, -8, 23, 46, 34, 34, 33, -15, -20, -30, -36, 4, -2, -15, 3, 3, 18, 12, -2, -13, -28, -34, -7, 18, 1, -8, -26, -1, 10, -8, -6, -22, -32, -14, -14, -49, -38, -11, -12, -13, -5, -36, -31, 28, 7, -1, 6, -4, 9, -29, -52, -5, 16, -7, -14, -13, -12, -20, -20, 1, 6, 29, 39, -12, -2, 64, 47, -14, -7, -13, -31, -44, -56, -20, 8, 5, 17, 28, 6, 0, -25, -26, -2, -10, -21, -19, 9, 0, -27, 22, 21, 14, 25, 1, 1, 1, -1, 11, -5, -22, -7, 17, 21, -3, 12, 46, 34, 34, 19, 14, 42, 4, -20, 16, 29, 31, 23, 2, 19, -1, -17, 15, 6, -18, -1, 29, 4, -17, -21, -30, -26, -20, -18, -22, 4, 17, -30, -35, -17, -9, -5, -17, 0, 0, -36, -36, 1, 6, -34, -9, 12, -23, -14, -4, -16, -7, -15, -1, 7, 26, 17, 38, 59, 45, 34, -8, 12, 45, 26, 38, 58, 13, 3, 9, 0, 3, -19, -61, -41, 28, 50, 38, -4, -2, 19, 3, 22, 6, -4, 26, 2, -7, 7, 3, 6, -11, -14, -12, -25, -29, -6, 29, 37, 12, 6, 16, 16, 46, 17, -43, -9, 7, 1, 12, -21, -46, -42, -22, -22, -29, 10, 32, 24, 1, -39, 10, 26, 2, 18, 7, 17, 9, 8, 48, 40, 28, 17, 13, -5, -28, -3, 13, -2, -19, 4, 0, -39, -8, 16, -20, -11, -2, -35, -17, -11, -16, 10, 11, 21, 21, -15, -3, 0, -39, -48, -21, -12, -28, -2, -1, 9, 47, 47, 22, -9, 26, 21, 18, 44, 26, 0, -35, -33, 17, 19, -2, -5, -18, -7, -27, -4, 12, -11, -11, 12, 50, 23, 31, 19, -10, 29, 15, 3, -1, -27, -34, -30, -13, 9, -6, -6, 42, 31, -6, -6, -1, 23, 47, 42, -3, -43, -31, 31, 40, 6, 20, 49, 40, 18, -25, -60, -58, -1, 66, 41, 28, 44, 25, 38, 30, 31, -3, -39, 3, -1, -8, -14, -9, -9, 10, 7, -6, 41, 31, 3, 3, 32, 14, -14, 16, 34, 1, -46, -31, 14, 38, 41, 27, -24, -31, -28, -63, -14, 3, -39, -50, -30, -10, -22, -6, -20, -29, -2, 2, 20, 41, 46, 42, 33, 3, -9, -16, -24, -11, -2, 16, 19, 27, 57, 4, -53, -17, -17, -8, 43, 29, 8, 26, 15, -20, -22, -36, -30, 0, 25, 31, -18, -32, 6, 33, 2, -18, 26, 24, 23, 42, 2, -33, -1, 17, 25, 14, -10, -6, -14, 2, -15, -12, 8, -10, -2, 14, -24, -38, 14, 5, 14, 36, 6, -2, -15, -6, 7, -4, -25, -28, 10, 29, -9, -6, 15, -21, 18, 42, 4, -2, -16, -8, 37, 21, -40, -19, 11, -2, 14, 12, 12, 4, -11, -21, -15, -6, 10, 41, 29, 3, -22, -6, 15, -14, -40, -3, -3, -24, -14, 0, 44, 39, 8, -2, -12, -18, -29, 16, 6, -25, -9, -11, -26, -20, 33, 15, -5, 12, 2, 22, 18, -1, -22, -20, -20, -21, 18, 11, 15, 9, -10, 1, -20, -29, -4, -4, 8, 17, 1, 8, -14, -22, -12, -21, 0, -26, -34, 4, -10, 0, 0, -8, -8, -22, 16, 18, 26, 32, -23, -29, -3, -33, -20, 1, 9, 14, -30, -34, 12, 28, 11, 27, -3, -22, -22, -37, -19, 19, 46, 20, 17, 23, 19, 12, 18, 22, 3, -34, -4, 14, -29, 17, 53, 31, 14, 21, 44, 37, -5, 21, 21, -8, -7, -14, 15, -9, -50, -15, 13, 4, -10, -6, 2, 3, -17, -48, -55, 10, 3, -27, -20, -5, 10, 11, 1, 9, 17, 38, 42, 27, 12, 8, 26, 41, 25, -5, -8, -27, -18, -24, -33, 1, 14, 45, 35, 13, 30, 28, 26, -17, -33, 9, 17, 14, 17, 5, 5, 33, 33, 12, 0, -29, -17, 0, -13, -2, -2, -28, -26, 27, 27, -34, -36, -23, -20, 19, 18, -17, -6, -33, -45, 2, 1, 33, 47, 1, -9, -22, -24, -10, -12, -34, -34, -15, -1, 18, 20, 27, 16, -24, -13, 20, 6, -2, 6, 21, 27, 22, 9, -32, -21, 41, 34, 11, 7, -20, -15, -11, -1, 1, -14, -35, -24, 28, 23, 21, 25, -1, -11, 19, 29, -20, -36, -11, 5, -17, -17, 0, -6, 22, 13, 8, 9, -22, 1, 29, 18, 10, 12, 26, 23, 27, 19, 21, 26, 30, 17, 7, 7, -45, -36, 8, 12, 1, 9, 18, 24, 29, 11, -46, -31, 3, -9, -6, -2, -20, -20, -33, -45, 3, 3, -18, -14, -48, -48, -19, -23, -15, -15, -19, -8, -25, -31, -22, -27, -45, -25, -9, -9, 1, 8, 25, 2, -23, -13, 11, -5, -40, -18, -11, -35, 2, 34, 40, 18, 18, 18, -3, -13, -11, -11, -44, -17, 6, 12, 6, -4, 6, -18, -14, -5, -8, 16, 25, 8, -34, -34, 1, 2, -7, -19, 19, 30, 7, -3, -18, -15, -27, -19, 0, 10, -10, -33, -20, -19, 14, 28, 22, 30, -15, -14, -2, -23, -3, 14, -6, -6, 3, 8, 35, 26, 26, 7, -21, -14, -16, 6, 27, 20, -26, -20, 0, -36, -21, 15, -3, 4, 13, -9, -12, -12, -12, -25, -41, -20, 26, 12, 9, 23, -8, -24, -13, -13, -8, -15, -2, 20, -6, 10, 32, 12, -1, 0, -9, 4, 14, -15, -37, -9, -23, -21, 10, 5, 14, 28, 39, -1, -10, -16, -7, -7, -25, -6, 8, 13, -27, -5, 25, 9, 2, -25, -19, 7, -1, 1, 4, -20, -23, 1, 2, -17, -23, 1, -1, -5, 3, -17, -17, 7, 8, 8, 25, 7, -5, 15, -8, 8, 21, -14, -27, 2, 10, -6, 3, 17, 4, -6, 35, 46, 17, 4, -9, -33, -32, -5, 22, 25, 12, 4, -12, -33, -22, -9, -15, 4, 31, 11, -15, -5, -12, -1, 21, 31, 16, 5, 14, -24, -33, 14, 8, -31, 10, 49, 49, 12, -24, 11, 7, -17, 2, -3, -15, -21, -21, -8, 26, 2, -13, 20, -9, -16, -3, -7, 22, 11, -37, -19, 5, -8, -17, -21, -11, 4, 10, -9, -34, 0, 15, -3, 1, 27, 11, 17, 14, 15, 35, 1, -10, -3, -8, -36, -41, -22, 1, 22, 26, 34, 13, -35, -41, 0, 10, 0, 8, 11, 1, 1, -5, -4, -1, 5, 15, 21, 22, 12, 13, 13, 4, -7, -13, 12, 18, -6, 12, 16, -1, 11, 28, 35, -3, -29, 3, 0, -26, 2, 9, -23, 2, 30, 24, -4, -19, 7, 11, 24, 32, -9, -27, 0, 18, -4, -18, 0, 20, 7, -10, -19, -13, -10, -28, -23, -3, 15, 5, 0, 16, 4, -8, -10, -9, 15, 24, 4, -7, 0, -4, -7, -4, -19, -10, 3, -15, -13, -13, 7, 24, 8, 8, 12, -4, -5, 5, 1, -1, -10, -10, -7, -9, 3, 5, 3, 4, 1, -16, -16, -9, -17, -24, -31, -23, -16, -14, -2, 3, -6, -11, -6, -15, 4, 17, 11, 14, 8, 9, 6, -6, -6, -3, -3, 9, -8, -17, 14, 15, 9, 1, -2, 7, -3, 1, 23, 18, -13, -15, -5, -10, -6, -2, -17, -5, 16, 8, -3, 1, -1, -5, 6, -2, -4, -3, -10, -9, -13, -19, -7, 1, -15, -12, 4, 0, -8, -5, 12, 5, -20, -8, 18, 8, -17, -13, -6, -3, -1, 3, 3, -8, -14, -7, 15, 20, 7, -1, -19, -23, 8, 20, 14, 2, 11, 24, 20, 7, 1, 9, -5, -12, -2, -2, 7, 5, -23, -17, 3, -2, -2, 1, -3, -7, -11, -7, 10, 6, -15, -9, 0, -9, 24, 31, -22, -29, 6, 17, 10, 3, -9, -4, 5, -1, -9, 4, -4, -12, 21, 18, -8, -16, -30, -13, 8, 4, -14, -14, 15, 23, 11, -9, -6, 12, -7, -4, 28, 26, 15, 18, 24, 24, 9, -10, 25, 35, 14, -16, -27, -31, -11, 19, -23, -54, -28, -28, -34, 3, 2, -36, -14, 7, 8, 33, 14, -5, 16, 17, -3, 13, 30, -12, -28, -4, -20, -21, 1, 11, -21, -43, -33, -21, 26, 36, 2, -25, -31, -24, -14, -5, -24, -24, -32, -42, -7, 13, 0, 0, 1, -15, 15, 16, -10, 12, -10, -10, 38, 5, -16, 13, 4, -10, -20, -5, 25, -12, -15, 8, 33, 62, 42, 20, -18, -24, 2, 0, -24, -45, -25, -23, -28, -29, -34, -25, -48, -39, 20, 34, 12, 25, 16, -36, -51, -20, -6, 3, 28, 20, 13, 30, 15, -14, 7, 10, 9, 18, 18, 20, 1, -14, -2, 2, -3, 21, 16, 5, 12, 0, -37, -7, 10, -3, 30, 36, 1, -9, -12, -13, -30, -52, -20, 0, 33, 47, 22, 32, 12, 0, 12, 2, 27, 36, -8, -26, 27, 32, 5, 7, 2, 13, 15, -7, 2, -4, -30, 10, 17, -20, -44, -46, -13, -4, -10, -10, 6, 2, -5, 2, 0, 10, 27, 33, 28, 22, 13, -1, 3, 7, -26, -31, 0, 0, -19, -28, 2, 17, -11, 12, 8, -16, -9, -22, 0, 24, -6, -6, 15, 12, -2, -13, 15, 34, 28, 15, 11, -3, -29, -9, -6, 2, 3, 11, 16, 5, 6, -18, -27, -22, -8, -13, -15, 8, 9, 20, 22, 10, 10, 10, 1, -24, -19, -15, 7, 15, 16, 27, -3, -22, -11, 8, 9, 3, -22, -33, -2, 4, -24, -24, -5, -5, 10, 28, 23, 11, 9, 4, -8, -8, 8, 12, -6, -7, -17, -21, 6, 17, 21, 5, 8, 24, 4, 16, -5, -7, 31, 10, -29, -40, -23, -13, -6, -2, 7, 18, 17, 18, 0, -3, -6, 4, -9, -6, 37, 31, 7, 12, 5, -4, 0, 6, -1, -8, 21, 29, -19, -19, 35, 24, 8, 19, 6, 0, -2, -6, 10, 17, 23, 31, 19, 14, 15, 10, 4, -7, -24, -19, -18, -6, 11, -1, -19, -19, -12, 1, 35, 16, -5, 7, -11, 1, 25, 5, 9, 7, 16, 26, -24, -30, 3, 4, -19, -20, 35, 30, 4, 17, 19, 23, -18, -28, 0, 0, 23, 10, -1, 11, -9, -15, -13, 3, 25, 19, -24, -16, 2, -18, 2, 17, -24, -19, 32, 7, -17, 1, -27, -32, -21, -3, -10, -28, -1, -1, 12, 11, -29, 0, 14, -4, 1, 7, 22, 22, 34, 5, -4, 15, 26, 14, 0, 2, -9, -2, 0, 19, 31, 22, -26, -24, 2, 2, 21, 30, 14, 2, -23, -11, -15, -18, -7, -16, 23, 6, 1, 19, -5, 13, 42, 33, 12, 11, 53, 54, 17, -11, -20, 7, -43, -62, -12, 7, -9, -36, -48, -11, 45, 26, -8, -27, -15, -14, -32, -34, -46, -45, 1, 11, 5, 13, 33, 27, -13, 14, 11, 2, -8, -8, 19, 1, -17, 4, 6, -15, 32, 23, 3, 18, 10, -8, -11, 3, -2, -20, -13, 14, -8, 6, 0, -26, -20, 6, -11, -37, -43, -17, 32, 18, -9, -22, 10, 20, -5, 7, 53, 58, 40, 0, -16, 18, 19, -3, 1, -10, -30, 4, 19, -5, -20, -6, -39, -54, 14, 16, 12, 32, -11, -32, -53, -45, 18, 10, -15, -15, -39, -17, 18, 10, -11, -17, -23, -5, -20, -12, 13, 28, 42, 11, -8, -26, -16, 32, 17, -37, 15, 20, -31, -1, 44, 48, -4, -18, -21, 11, 53, 39, 14, -8, 13, -1, -43, -37, 6, 39, 25, 25, 14, -36, -1, 51, 46, 32, 9, 29, -15, -21, 7, -19, -18, -38, 1, 31, 7, -29, -41, -10, 5, 5, 42, 63, 55, 29, 8, 13, -8, -16, -27, 2, 20, -27, -39, 5, 0, -33, 11, 37, 41, 28, -6, -6, 39, 28, -3, -20, -60, -57, -56, -31, -10, -7, -20, -34, -34, -23, -32, -31, 14, 16, 14, 2, -44, -40, -28, -40, 0, 27, 0, -13, -35, -32, -6, -9, 31};


int main()
{
    clock_t begin = clock();
    int data_len = 4096;
    char *noise_samp;
    char *i_samples_noise;
    char *q_samples_noise;
    float run_len;
    int counter;
    int temp;

    FILE *f = fopen("ber_vs_snr.txt","a");
    fprintf(f, "error_prob, snr\n");

    for (float snr = -40; snr < -20; snr++)
    {
        float std;
        float error_prob;
        counter = 0;
        run_len = 1000.0;
        temp = 0;
        ber_vs_snr[temp].snr = snr;
        // char *acq_samp = malloc(data_len*sizeof(double));
        i_samples_noise = malloc(data_len * sizeof(double));
        q_samples_noise = malloc(data_len * sizeof(double));
        std = pow(10, ((-snr) / 20));

        

        for (int i = 0; i < run_len; i++)
        {
            noise_samp = malloc(data_len * sizeof(char)); //(char *)calloc(data_len,sizeof(char));
            noise_gen(std, noise_samp);
            for (int j = 0; j < data_len; j++)
            {
                //*(acq_samp + j) = *(sig_samp+(j)) + *(noise_samp+(j));
                *(i_samples_noise + j) = i_samples[j] + *(noise_samp + j);
                *(q_samples_noise + j) = q_samples[j] + *(noise_samp + j);
                *(i_samples_noise + j)>>= 4;
                *(q_samples_noise + j)>>= 4;
            }
            // for(int l=0;l<5;l++){
            //     printf("%d,%d,%d\n",i_samples[l],q_samples[l],noise_samp[l]);
            //     printf("%d,%d\n",i_samples_noise[l],q_samples_noise[l]);

            // }
            gps_acq(i_samples_noise, q_samples_noise);
            for (int j = 0; j < 5; j++)
            {
                //printf("%d %d %d %d\n", ideal_satellites[j].codephase,satellite_outcomes[ideal_satellites[j].id].codephase,ideal_satellites[j].doppler,satellite_outcomes[ideal_satellites[j].id].doppler);
                if ((ideal_satellites[j].codephase == satellite_outcomes[ideal_satellites[j].id].codephase) &
                    (ideal_satellites[j].doppler == satellite_outcomes[ideal_satellites[j].id].doppler))
                {
                }
                else
                {
                    counter++;
                    break;
                }
            }
        }
        //printf("errors for snr %f is %d\n", snr, counter);
        error_prob = counter / run_len;
        ber_vs_snr[temp].error_prob = error_prob;
        //printf("error probability is %f\n", error_prob);
        fprintf(f,"%f, %f\n",ber_vs_snr[temp].error_prob, ber_vs_snr[temp].snr);
        temp++;
    }

    fclose(f);
    free(noise_samp);
    free(i_samples_noise);
    free(q_samples_noise);

    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("\n The program took %f seconds to run. \n ", time_spent);
}