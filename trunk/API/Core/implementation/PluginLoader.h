#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <list>
#include <string>

#ifdef WIN32
# include <windows.h>
#endif

#ifdef WIN32
	typedef HMODULE PluginHandle;
#else

#endif

namespace LBAPI {

class Core;

class PluginLoader {
public:
	~PluginLoader();

	void	loadPlugins(Core& core, const std::string& pluginsPath);

private:
	void	getPluginList(std::list<std::string>& list, const std::string& pluginsPath);
	void	loadPlugin(Core& core, const std::string& file);

	std::list<PluginHandle>		m_loadedPlugins;
};

} // namespace LBAPI

#endif // PLUGINLOADER_H
