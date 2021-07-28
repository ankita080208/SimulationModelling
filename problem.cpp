#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=13; //total time in seconds
    float xb[t]={80, 90, 99, 108, 116, 125, 133, 141, 151, 160, 169, 179, 180}; //x coordinates of bomber plane
    float yb[t]={0, -2, -5, -9, -15, -18, -23, -29, -28, -25, -21, -20, -17}; //y coordinates of bomber plane
    float xf[t], yf[t]; //coordinates of fighter plane
    float dist[t];
    float sinTheta,cosTheta;

    cout<<"\n\nxb: 80, 90, 99, 108, 116, 125, 133, 141, 151, 160, 169, 179, 180\n";
    cout<<"yb: 0, -2, -5, -9, -15, -18, -23, -29, -28, -25, -21, -20, -17\n";
    //Initialize initial position and velocity
    xf[0]=0; yf[0]=50;
    int VF=20; 

    cout<<"\n\nxf[0]:"<<xf[0]<<"\nyf[0]: "<<yf[0]<<"\n\nVelocity of fighter:"<<VF<<"\n\n";
    for(int t=0; t<=12; t++)
    {
        //Find distance between 2 planes using euclidean formula
        dist[t]= sqrt( pow( (yb[t] - yf[t]) ,2)+pow( (xb[t] - xf[t]),2));
        sinTheta= (yb[t]-yf[t])/dist[t];
        cosTheta= (xb[t]-xf[t])/dist[t];

        //Find next coordinates of fighter plane to reach closer to bomber
        xf[t+1]= xf[t] + (VF*cosTheta);
        yf[t+1]= yf[t] + (VF*sinTheta);

        //If distance less than or equal to 10, bomber taken down
        if(dist[t]<=10)
        {
            cout<<"t:"<<t<<"\nDistance:"<<dist[t]<<"\n";
            break;
        }
        //If time is more than 11 sec, bomber escaped
        else if(t>11)
            cout<<"Target Escaped\n";
    }
    return 0;
}
