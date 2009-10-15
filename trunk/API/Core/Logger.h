#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>

namespace LBAPI {

class Logger {
public:
    Logger();
    ~Logger();

    Logger& operator<< (bool& val );
    Logger& operator<< (short& val );
    Logger& operator<< (unsigned short& val );
    Logger& operator<< (int& val );
    Logger& operator<< (unsigned int& val );
    Logger& operator<< (long& val );
    Logger& operator<< (unsigned long& val );
    Logger& operator<< (float& val );
    Logger& operator<< (double& val );
    Logger& operator<< (long double& val );
    Logger& operator<< (const void* val );
    Logger& operator<< (const std::string& val );
    Logger& operator<< (const char* val );
    Logger& operator<< (std::ostream& ( *pf )(std::ostream&));

    void    setEnabled(bool val) { m_Enabled = val; }
    bool    isEnabled() { return m_Enabled; }
    void    setLogFile(const std::string fileName);

private:
    std::ostream*   m_Stream;
    std::fstream    m_File;
    bool            m_Enabled;
};

Logger& logger();

} // namespace LBAPI

#endif // LOGGER_H
