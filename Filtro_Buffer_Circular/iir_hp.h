/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: High Pass
Filter model: Bessel
Filter order: 19
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
z = -0.006900 + j -0.440645
z = -0.006900 + j 0.440645
z = 0.013892 + j -0.359292
z = 0.013892 + j 0.359292
z = -0.035814 + j -0.535125
z = -0.035814 + j 0.535125
z = 0.037091 + j -0.263680
z = 0.037091 + j 0.263680
z = 0.017753 + j -0.233862
z = 0.017753 + j 0.233862
z = -0.080387 + j -0.643805
z = -0.080387 + j 0.643805
z = -0.014147 + j -0.079961
z = -0.014147 + j 0.079961
z = 0.087272 + j -0.132590
z = 0.087272 + j 0.132590
z = -0.155977 + j -0.778402
z = -0.155977 + j 0.778402
z = 0.102782 + j -0.000000
***************************************************************/
#define NCoef 19
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.00000851912617345340,
        -0.00016186339729561450,
        0.00145677057566053030,
        -0.00825503326207633820,
        0.03302013304830535300,
        -0.09906039914491607300,
        0.23114093133813748000,
        -0.42926172962796966000,
        0.64389259444195446000,
        -0.78697983765127766000,
        0.78697983765127766000,
        -0.64389259444195446000,
        0.42926172962796966000,
        -0.23114093133813748000,
        0.09906039914491607300,
        -0.03302013304830535300,
        0.00825503326207633820,
        -0.00145677057566053030,
        0.00016186339729561450,
        -0.00000851912617345340
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        0.17165123343922659000,
        1.74583309462876830000,
        0.03478190497614821300,
        1.19081264927436830000,
        -0.11273207899490943000,
        0.42403544517915120000,
        -0.07305971971351331300,
        0.08739947343460292800,
        -0.01829313176029460900,
        0.01067578583318921600,
        -0.00221342836162145280,
        0.00074512938555712765,
        -0.00013127510473352324,
        0.00002691691853190949,
        -0.00000347278107188946,
        0.00000041349531061514,
        -0.00000003163025176944,
        0.00000000170839413405,
        -0.00000000004221983644
    };

    static float y[NCoef+1]; //output samples
    static float x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
