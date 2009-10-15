#include "Logger.h"

using namespace LBAPI;

Logger basic_logger;

Logger& LBAPI::logger()
{
    return basic_logger;
}

Logger::Logger() : m_Stream(&std::cout), m_Enabled(true) {}

Logger::~Logger()
{
    if (m_File.is_open())
        m_File.close();
}

Logger::Logger& Logger::operator<< (bool& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (short& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (unsigned short& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (int& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (unsigned int& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (long& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (unsigned long& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (float& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (double& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (long double& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (const void* val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (const std::string& val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (const char* val ) { if (m_Enabled) *m_Stream << val; return *this; }
Logger::Logger& Logger::operator<< (std::ostream& ( *pf )(std::ostream&)) { if (m_Enabled) *m_Stream << pf; return *this; }

void    Logger::setLogFile(const std::string fileName)
{
    if (m_File.is_open())
        m_File.close();
    m_File.open(fileName.c_str(), std::ios::out);
    if (m_File.is_open())
        m_Stream = &m_File;
    else
        *m_Stream << "Can't open log file: " << fileName << std::endl;
}
