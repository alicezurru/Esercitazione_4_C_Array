#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>
#include <string>


using namespace std;

int main()
{
    string namefile="data.csv";
    ifstream ifstr(namefile);
    ofstream ofstr("result.txt");
    if (ifstr.fail()){
        cerr<<"file not found"<<endl;
        return 1;
    }
    if (ofstr.fail()){
        cerr<<"file not found"<<endl;
        return 2;
    }
    //prima riga
    string SStr;
    char c;
    getline(ifstr,SStr);
    istringstream convertS(SStr);
    double S;
    convertS>>c>>c>>S; //per mettere i primi 2 caratteri e poi il numero


    //seconda riga
    string nStr;
    getline(ifstr,nStr);
    istringstream convertn(nStr);
    int n;
    convertn>>c>>c>>n; //per mettere i primi 2 caratteri e poi il numero
    ofstr<<fixed<<setprecision(2)<<"S = "<<S<<", n ="<<n<<endl;

    //terza riga
    string terza;
    getline(ifstr,terza);


    //vettori r e w
    double *ptrr=new double[n];
    double *ptrw=new double[n];
    string line;
    istringstream convert;
    double r;
    double w;
    string rString;
    string wString;
    for (int i=0;i<n;i++) {
        getline(ifstr,line);
        convert=istringstream(line);
        convert>>w>>c>>r;
        *(ptrw+i)=w;
        *(ptrr+i)=r+1;
        wString= wString + to_string(w) + " ";
        rString= rString + to_string(r) + " ";
    }

    ofstr<<"w= [ "<<wString<<"]"<<endl;
    ofstr<<"r= [ "<<rString<<"]"<<endl;

    //sum[(ri+1)*wi]S
    double V= dot(ptrr,ptrw,n);
    V=V*S;
    double R=(V-S)/S;

    ofstr<<fixed<<"Rate of return of the portfolio: "<<R<<endl;;
    ofstr<<fixed<<setprecision(2)<<"V: "<<V<<endl;

    delete [] ptrr;
    delete [] ptrw;
    ifstr.close();
    ofstr.close();

  return 0;
}

