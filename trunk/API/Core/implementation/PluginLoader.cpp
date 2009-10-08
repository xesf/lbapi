#include <iostream>

#include "PluginLoader.h"
#include "../Core.h"

using namespace LBAPI;

PluginLoader::~PluginLoader()
{
	std::list<PluginHandle>::iterator it;
	for (it = m_loadedPlugins.begin(); it != m_loadedPlugins.end(); ++it)
	{
#ifdef WIN32
		FreeLibrary(*it);
#else

#endif
	}
}

void	PluginLoader::loadPlugins(Core& core, const std::string& pluginsPath)
{
	std::list<std::string> list;
	getPluginList(list, pluginsPath);
	std::list<std::string>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		//std::cout << *it << std::endl;
		loadPlugin(core, *it);
	}
}

void	PluginLoader::getPluginList(std::list<std::string>& list, const std::string& pluginsPath)
{
#ifdef WIN32
	WIN32_FIND_DATAA fdata;
	HANDLE dhandle;
	char buf[MAX_PATH];

	GetFullPathNameA(pluginsPath.c_str(), MAX_PATH, buf, NULL);
	std::string fullPath(buf);
	fullPath += "\\*.dll";
	//std::cout << "fullpath: " << fullPath << std::endl;
	if ((dhandle = FindFirstFileA(fullPath.c_str(), &fdata)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::string file(buf);
			file += "\\";
			file += fdata.cFileName;
			list.push_back(file);
		}
		while (FindNextFileA(dhandle, &fdata));
	}
#else

#endif
}

void	PluginLoader::loadPlugin(Core& core, const std::string& file)
{
#ifdef WIN32
	HMODULE module = LoadLibraryA(file.c_str());
	//std::cout << "Loading library : " << file <<  std::endl;
	if (module)
	{
		GetLbapiVersionFct getLbapiVersion = (GetLbapiVersionFct)GetProcAddress(module, "getLbapiVersion");
		RegisterLbapiPluginFct registerLbapiPlugin = (RegisterLbapiPluginFct)GetProcAddress(module, "registerLbapiPlugin");
		//std::cout << "Checking export table..." << std::endl;
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

#endif
}
