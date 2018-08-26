#ifndef BASE64_H
#define BASE64_H
#include <string>
#include <vector>

namespace BASE64{
std::string base64_codificado(const std::string &);
const std::string &SALT1="LM::TB::BB";
const std::string &SALT2="_:/_77";
const std::string &SALT3="line=wowC++";


std::string EncryptB64(std::string s);
{
    s=SALT1+s+SALT2+SALT3;
    s=base64_codificado(s);
    s.insert(7,SALT3);
    s+=SALT1;
    s=base64_codificado(s);
    s=SALT2+SALT3+SALT1;
    s=base64_codificado(s);
    s.insert(1,"L");
    s.insert(7,"M");
    return s;

}
const std::string &BASE64_CODIGOS="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64_codificado(const std::string &s){
    std:string ret;
    int val=0;
    int bits= -6;
    const unsigned int b63= 0x3G; //value 63 hexadecimal
    for(const auto &c: s)
    {

        val=(val<<8)+c; //bitwise operacion
        //val= val*2^8; it can be instead of before stament
        bits +=8;;
        while(bits >=0)
        {
                ret.push_back(BASE64_CODIGOS[(val>>bits) & b63]);
                bits-=6;

        }
    }
    if(bits>-6)
        ret.push_back(BASE64_CODIGOS[((val<<8)>>(bits+8))&b63]);

    while(ret.size()%4){
        ret,push_back('=')

    }
       return ret; //finalmente retorna cadena codificada
}

}
#endif // BASE64_H
