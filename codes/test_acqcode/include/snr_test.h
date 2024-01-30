/* Header file for main*/

#include "noise.h"
#include "acq_code.h"

struct ideal_sat
{
    int id;
    int doppler;
    int codephase;
};

struct snr_ber
{
    float error_prob;
    float snr;
};

