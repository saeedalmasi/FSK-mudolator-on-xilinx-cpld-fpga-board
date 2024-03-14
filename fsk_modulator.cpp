//#include<stdint.h>
#include<ap_int.h>
#include<hls_math.h>

typedef ap_int<10> int10_t ;

void FSK_modulator(bool data_in, int10_t *waveout)
{
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS INTERFACE ap_none port=waveout
#pragma HLS INTERFACE ap_none port=data_in

float y;

	if (data_in==1)
	{
		y=1;}
	else{
		y=2;
		}
	for( int j=0; j<2 ; j++)
	{
		for( int i=0 ; i<128 ; i++ )
		{
			*waveout= (int10_t) (512*(hls::sinf(y*i*2*M_PI/128)));
		}
	}
}
