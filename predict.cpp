#include <iostream>
#include<bits/stdc++.h>

using namespace std;
float w0[2][6] = { { -0.5468823,  -0.14767098,  0.52103525,  2.0302563,  -0.31882265, -0.29947653 },{ -0.3527497,   2.6865528,   1.9953825,  -2.0724196,   0.05666221,  2.1026747  } };
float b0[6] = {0.0,          0.43384153,  0.5114199,   1.1765654,  -0.04385916, -0.44039676};

float w1[6][2] = { { 0.41678566, -0.501751 },{ 2.2760332,   2.327208 },{0.78877336,  1.8958851},{-4.6289067,  -4.6149497},{-0.5490287,  -0.55230045},{1.4287139,   1.7659128} };
float b1[2] = {0.3146908, 0.3218678 };



float w2[2][1] = { {3.657283 },{ 3.1764765  } };
float b2 = 0.30167854;
float activation(float val)
{
    float a = 0.0;
    if(val < 0.0)
    {
        return a;
    }
    return val;
}
// prediction function for new inputs
float predict(float x,float y)
{
    float t[1][2] = {{x,y}};
    float f1[1][6] = {{0.0,0.0}};
    for(int k = 0; k < 2; k++)
    {
        for(int i = 0; i < 1; i++)
        {
            float tmp = t[i][k];
            for(int j = 0; j < 6; j++)
            {
                f1[i][j] = f1[i][j] + tmp * w0[k][j];
            }
        }
    }
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<6; j++)
        {
            f1[i][j]+=b0[j];
            f1[i][j] = activation(f1[i][j]);
        }
    }
    float f2[1][2] = {{0.0,0.0}};
    for(int k = 0; k < 6; k++)
    {
        for(int i = 0; i < 1; i++)
        {
            float tmp = f1[i][k];
            for(int j = 0; j < 2; j++)
            {
                f2[i][j] = f2[i][j] + tmp * w1[k][j];
            }
        }
    }
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<2; j++)
        {
            f2[i][j]+=b1[j];
            f2[i][j] = activation(f2[i][j]);
        }
    }

    float fin = f2[0][0]*w2[0][0] + f2[0][1]*w2[1][0] + b2;
    float answer =  fin/100;
    if (answer > 100){
        answer-=abs(answer-100);
    }
    else if( answer <=0){
        return 0;
    }
    return answer;
}

int main()
{
    float a = 25.045045, b =	76.856857;
    cout << "The final prediction is: " << predict(a,b) << endl;
    cout << "The final prediction is: " << predict(a,b) << endl;

    return 0;
}
