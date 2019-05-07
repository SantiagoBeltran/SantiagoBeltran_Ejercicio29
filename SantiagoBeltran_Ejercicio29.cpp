#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void ecOnda(int nmax, int nt,string filename);
const float T=40;
const float rho=0.01;
const float c= 1;
const float pi=4*atan(1);

int main(){
  ecOnda(101, 301, "intento.dat");
  return 0;
}

void ecOnda(int nmax, int nt,string filename){
    float T[nmax][3]={0};
    const float dx=1/100;
    const float dt=1/100;
    const float c1=1;
    float ratio;
    ofstream outfile;
    outfile.open(filename);
    
    for (int i=0; i<nmax;i++){
        T[i][0]=sin(pi*i/100);
        T[i][2]=T[i][0];
        }
    ratio=(c*c)/(c1*c1);
    for(int j=0; j<nmax; j++){
            outfile << T[j][0] << " ";
            if(j==nmax-1){outfile<<endl;}
        }
    for(int j=1; j<nmax-1;j++){
        T[j][1]=T[j][0]+0.5*ratio*(T[j+1][0]+T[j-1][0]-2*T[j][0]);}
    
    for(int j=0; j<nmax; j++){
            outfile << T[j][1] << " ";
            if(j==nmax-1){outfile<<endl;}
        }
    for(int j=0; j<nmax; j++){
            outfile << T[j][2] << " ";
            if(j==nmax-1){outfile<<endl;}
        }    
    
    float error=100.0;
    for(int k=3; k<nt;k++){
        for(int i=0;i<nmax;i++){
            T[i][0]=T[i][1];
            T[i][1]=T[i][2];
            T[i][2]=0;
        }
        for(int i=1; i<nmax-1; i++){
            T[i][2]=2*T[i][1]-T[i][0]+ratio*(T[i+1][1]+T[i-1][1]-2*T[i][1]);
        }
        for(int j=0; j<nmax; j++){
            outfile << T[j][2] << " ";
            if(j==nmax-1){outfile<<endl;}
        }
    }    
}
