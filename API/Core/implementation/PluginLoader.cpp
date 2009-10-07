#include "PluginLoader.h"

#ifdef WIN32
# include <windows.h>
#endif

using namespace LBAPI;

void	PluginLoader::loadPlugins(LBAPI& kernel, const std::string& pluginsPath)
{
	std::list<std::string> list;
	getPluginList(list, pluginsPath);
}

void	PluginLoader::getPluginList(std::list<std::string>& list, const std::string& pluginsPath)
{
#ifdef WIN32

#else

#endif
}
