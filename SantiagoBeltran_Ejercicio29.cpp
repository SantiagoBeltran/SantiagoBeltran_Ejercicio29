#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

void ecOnda(int nmax, int nt,string filename);
const float T=40;
const float rho=0.01;
const float c= 1;
const float pi=4*atan(1);

int main(){
  ecOnda(101, 101, "intento.dat");
  return 0;
}

void ecOnda(int nmax, int nt,string filename){
    float T_old[nmax][nt]={0};
    float T_new[nmax][nt]={0};
    const float dx=1/100;
    const float dt=1/100;
    const float c1=1;
    float ratio;
    ofstream outfile;
  outfile.open(filename);
    for (int i=0; i<nmax;i++){
        T_old[i][0]=0.001*sin(2*pi*i/100);T_new[i][0]=0.001*sin(2*pi*i/100);
        T_old[i][1]=T_old[i][0];T_new[i][1]=T_new[i][0];
        }
    ratio=(c*c)/(c1*c1);
    float error=100.0;
    while(error>0.00001){
    
        for(int i=0; i<nmax; i++){
        for(int j=1; j<nt-1; j++){
            
            T_new[i][j+1]=2*T_old[i][j]-T_old[i][j-1]+ratio*(T_old[i+1][j]+T_old[i-1][j]-2*T_old[i][j]);
        }
        }
          
        error=0.0;    
        for(int i=1; i<nmax-1; i++){
        for(int j=0; j<nt-1; j++){
            error=error+abs(T_new[i][j]-T_old[i][j]);
        }    
    }
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nt; j++){
            T_old[i][j]=T_new[i][j];
        }       
}    
    }
    
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nt; j++){
            outfile << T_new[i][j] << " ";
            if(j==nt-1){outfile<<endl;}
        } 
}
}