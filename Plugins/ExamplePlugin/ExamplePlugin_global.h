#ifndef EXAMPLEPLUGIN_GLOBAL_H
#define EXAMPLEPLUGIN_GLOBAL_H

#ifdef WIN32
#  define EXAMPLEPLUGIN_EXPORT __declspec(dllexport)
#else
#  define EXAMPLEPLUGIN_EXPORT
#endif

#endif // EXAMPLEPLUGIN_GLOBAL_H
