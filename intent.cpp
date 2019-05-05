#include <iostream>
#include <fstream>
using namespace std;

void laplaceline(int iter, int nmax, string filename);

int main(){
  laplaceline(70, 100, "intento.dat");
  return 0;
}

void laplaceline(int iter, int nmax,string filename){
    float *V;
    ofstream outfile;
  outfile.open(filename);
    V= new float[nmax,nmax];
    for(int i=0;i<nmax;i++){
        V[i,0]=100;}
    
    for(int k=0; k<iter; k++){
    
        for(int i=1; i<nmax-2; i++){
        for(int j=1; j<nmax-2; j++){
            V[i,j]=0.25*(V[i+1,j]+V[i-1,j]+V[i,j+1]+V[i,j-1]);
        }
    }
    }
    for(int i=0; i<nmax; i++){
        for(int j=0; j<nmax; j++){
            outfile << V[i,j] << " ";
            if(j==nmax-1){outfile<<endl;}
        }       
}}