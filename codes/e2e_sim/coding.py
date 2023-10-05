import numpy as np
from numpy.random import randint
import sk_dsp_comm.fec_conv as fec
import sk_dsp_comm.digitalcom as dc
import matplotlib.pyplot as plt
# Soft decision rate 1/2 simulation
N_bits_per_frame = 1000
EbN0 = 4
total_bit_errors = 0
total_bit_count = 0
cc1 = fec.FECConv(('11101','10011'),25)
# Encode with shift register starting state of '0000'
state = '0000'
while total_bit_errors < 100:
   # Create 100000 random 0/1 bits
     x = randint(0,2,N_bits_per_frame)
     #print(len(x))
     y,state = cc1.conv_encoder(x,state)
     #print(len(y))
     # Add channel noise to bits
     yn_soft = dc.cpx_awgn(2*y-1,EbN0-3,1) # Channel SNR is 3 dB less for rate 1/2
     yn_hard = ((np.sign(yn_soft.real)+1)/2).astype(int)
     #print(len(yn_hard))
     z = cc1.viterbi_decoder(yn_hard,'hard')
     #print(len(z))
     # Count bit errors
     bit_count, bit_errors = dc.bit_errors(x,z)
     total_bit_errors += bit_errors
     total_bit_count += bit_count
     #print('Bits Received = %d, Bit errors = %d, BEP = %1.2e' %                    (total_bit_count, total_bit_errors,                    total_bit_errors/total_bit_count))
#print('*****************************************************')
#print('Bits Received = %d, Bit errors = %d, BEP = %1.2e' %                (total_bit_count, total_bit_errors,                total_bit_errors/total_bit_count))


`
