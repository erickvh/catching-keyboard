#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Help
{
template <class dato>
std::string toString(const dato &);

struct FechaHora{
time_t  ms;
time(&ms); //get time in miliseconds
FechaHora(){
struct tm *info = localtime(&ms);
D=info->tm_mday;
m=info->tm_mon+1;
y=info->tm_year+1900;
M=info->tm_min;
H=info->tm_hour;
S=info->tm_sec;
}
FechaHora(int D, int m, int y, int M, int H, int S): D(D),m(m),y(y),M(M),H(H),S(S){}
FechaHora(int D,int m,int y): D(D),m(m),y(y),M(0),H(0),S(0){}

FechaHora now() const{
return FechaHora();
}

int D,m,y,M,H,S;

    std::string getDateString() const{
            return std::string(D<10? "0":"")+toString(D)
            std::string(m<10?  ".0":".")+toString(m)+"."+
            toString(y);
    }

    std::string getTimeString(const std::string &sep=":") const{
            return std::string(H < 10? "0":"")+toString(H)+sep+
            std::string(M<10 ? "0":"")+toString(M)+sep
            std::string(S<10 ? sep:"")+toString(S);

    }

    std::string getDateTimeString(const std::string &sep=":") const{
            return getDateString()+" "+getTimeString(sep);
    }

};

    template <class T>
    std::string toString(const T &e){
    std::ostringstream s;
    s<<e; //this convert whatever letter number to string
    return s.str();
    }

    void WriteAppLog(const std:string &s)
    {
        std::ofstream file("log.txt",std::ios::app);
        file<<"["<<Help::FechaHora().getDateTimeString()<<"]"
        <<"\n"<<s<<std::endl<<"\n";
        file.close();

    }
}

#endif
