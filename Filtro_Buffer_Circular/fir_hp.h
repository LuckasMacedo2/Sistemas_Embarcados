/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: High Pass
Filter model: Bessel
Filter order: 10
Sampling Frequency: 4 Hz
Cut Frequency: 1.000000 Hz
Coefficents Quantization: float

Z domain Zeros
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000

Z domain Poles
z = -0.023868 + j -0.486108
z = -0.023868 + j 0.486108
z = 0.015377 + j -0.327829
z = 0.015377 + j 0.327829
z = -0.106544 + j -0.685974
z = -0.106544 + j 0.685974
z = 0.035305 + j -0.190015
z = 0.035305 + j 0.190015
z = 0.043875 + j -0.062310
z = 0.043875 + j 0.062310
***************************************************************/
#define Ntap 31

float fir(float NewSample) {
    float FIRCoef[Ntap] = { 
        -0.00019249925159216095,
        0.00041253568360759041,
        0.00026030035896561161,
        -0.00105184845005546940,
        -0.00016216785318462089,
        0.00250695061984682400,
        -0.00061412772297141159,
        -0.00570207722016592530,
        0.00359633383017065590,
        0.01259962505928858400,
        -0.01347395017867842300,
        -0.02773119323437993000,
        0.04873400864569731000,
        0.06520215919065588900,
        -0.28812943725340839000,
        0.40756461785240178000,
        -0.28812943725340839000,
        0.06520215919065588900,
        0.04873400864569731000,
        -0.02773119323437993000,
        -0.01347395017867842300,
        0.01259962505928858400,
        0.00359633383017065590,
        -0.00570207722016592530,
        -0.00061412772297141159,
        0.00250695061984682400,
        -0.00016216785318462089,
        -0.00105184845005546940,
        0.00026030035896561161,
        0.00041253568360759041,
        -0.00019249925159216095
    };

    static float x[Ntap]; //input samples
    float y=0;            //output sample
    int n;

    //shift the old samples
    for(n=Ntap-1; n>0; n--)
       x[n] = x[n-1];

    //Calculate the new output
    x[0] = NewSample;
    for(n=0; n<Ntap; n++)
        y += FIRCoef[n] * x[n];
    
    return y;
}
