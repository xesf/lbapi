#include <iostream>

#include "PluginLoader.h"
#include "../Core.h"
#include "../Logger.h"

#ifndef WIN32
# include <sys/types.h>
# include <dirent.h>
# include <dlfcn.h>
#endif

using namespace LBAPI;

PluginLoader::~PluginLoader()
{
	std::list<PluginHandle>::iterator it;
	for (it = m_loadedPlugins.begin(); it != m_loadedPlugins.end(); ++it)
	{
#ifdef WIN32
            FreeLibrary(*it);
#else
            dlclose(*it);
#endif
	}
}

#warning "TODO: Implement unicode version of loadPlugins()"
void	PluginLoader::loadPlugins(Core& core, const std::string& pluginsPath)
{
	std::list<std::string> list;
        getLibraryList(list, pluginsPath);
	std::list<std::string>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		loadPlugin(core, *it);
        }
}

void	PluginLoader::getLibraryList(std::list<std::string>& list, const std::string& pluginsPath)
{
#ifdef WIN32
	WIN32_FIND_DATAA fdata;
	HANDLE dhandle;

	std::string searchPath = pluginsPath + "\\*.dll";
	if ((dhandle = FindFirstFileA(searchPath.c_str(), &fdata)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::string file(pluginsPath);
			file += "\\";
			file += fdata.cFileName;
			list.push_back(file);
		}
		while (FindNextFileA(dhandle, &fdata));
	}
        else
        {
            logger() << "Plugin path: " << pluginsPath << " is not a valid path" << std::endl;
        }
#else
    struct dirent *de = NULL;
    DIR *d = NULL;

    d = opendir(pluginsPath.c_str());
    if (d)
    {
        while((de = readdir(d)) != NULL)
        {
            std::string file(pluginsPath);
            file += "/";
            file += de->d_name;
            if (file.size() > 3 && file.compare(file.size() - 3, 3, ".so") == 0)
            {
                list.push_back(file);
            }
        }
    }
    else
    {
        logger() << "Plugin path: " << pluginsPath << " is not a valid path" << std::endl;
    }

    closedir(d);

#endif
}

void	PluginLoader::loadPlugin(Core& core, const std::string& file)
{
#ifdef WIN32
	HMODULE module = LoadLibraryA(file.c_str());
	if (module)
	{
		GetLbapiVersionFct getLbapiVersion = (GetLbapiVersionFct)GetProcAddress(module, "getLbapiVersion");
		RegisterLbapiPluginFct registerLbapiPlugin = (RegisterLbapiPluginFct)GetProcAddress(module, "registerLbapiPlugin");
		if (getLbapiVersion && registerLbapiPlugin && getLbapiVersion() == LBAPI_VERSION)
		{
			registerLbapiPlugin(core);
			m_loadedPlugins.push_back(module);
		}
		else
		{
			FreeLibrary(module);
		}
	}
#else
    void* dl = dlopen(file.c_str(), RTLD_NOW);
    if (dl)
    {   
        GetLbapiVersionFct getLbapiVersion = (GetLbapiVersionFct)dlsym(dl, "getLbapiVersion");
        RegisterLbapiPluginFct registerLbapiPlugin = (RegisterLbapiPluginFct)dlsym(dl, "registerLbapiPlugin");
        if (getLbapiVersion && registerLbapiPlugin && getLbapiVersion() == LBAPI_VERSION)
        {
                registerLbapiPlugin(core);
                m_loadedPlugins.push_back(dl);
        }
        else
        {
                dlclose(dl);
        }
    }
#endif
}
