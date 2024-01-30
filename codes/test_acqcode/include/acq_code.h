/*header file for acquisition algorithm*/
#define pi 3.14159265358979323846264338328

typedef struct 
{
    float real;
    float imag;
} Complex;

typedef struct 
{
    int real;
    int imag;
} Complex_int;

struct satellites{
    char id;
    int doppler;
    int codephase;
};

extern struct satellites satellite_outcomes[32];

void g1_lfsr(unsigned char *out);
unsigned char *g2_lfsr(unsigned char tap0,unsigned char tap1);
void combine_g1_and_g2(unsigned char * g1, unsigned char * g2, unsigned char * out);
void fft(Complex* x,unsigned int size);
int gps_acq(char *i_samples, char *q_samples);



