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
    unsigned int n;
    convertn>>c>>c>>n; //per mettere i primi 2 caratteri e poi il numero

    //prima di cambiare la precisione salvo quella vecchia
    ios prec(NULL);
    prec.copyfmt(cout);

    ofstr<<fixed<<setprecision(2)<<"S = "<<S<<", n = "<<n<<endl;

    //la ricambio
    ofstr.copyfmt(prec);


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

    ofstr<<"w = [ ";
    for (unsigned int i=0;i<n;i++) {
        getline(ifstr,line);
        convert=istringstream(line);
        convert>>w>>c>>r;
        ofstr<<w<<" "; //comincio già a stampare il primo
        ptrw[i]=w;
        ptrr[i]=r;
    }
    ofstr<<"]"<<endl;

    //ho gia stampato w, ora stampo r
    ofstr<<"r = [ ";
    for (unsigned int i=0;i<n;i++) {
        ofstr<<(ptrr[i])<<" ";
        //e gli aggiungo 1 per la formula successiva
        ptrr[i]=ptrr[i]+1;
    }
    ofstr<<"]"<<endl;

    //sum[(ri+1)*wi]S
    double V= dot(ptrr,ptrw,n);
    V=V*S;
    double R=(V-S)/S;

    ofstr<<"Rate of return of the portfolio: "<<R<<endl;;
    ofstr<<fixed<<setprecision(2)<<"V: "<<V<<endl;

    delete [] ptrr;
    delete [] ptrw;
    ifstr.close();
    ofstr.close();

  return 0;
}

