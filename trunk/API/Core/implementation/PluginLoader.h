#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <list>
#include <string>

#include "../LBAPI.h"

namespace LBAPI {

class PluginLoader {
public:
	void	loadPlugins(LBAPI& kernel, const std::string& pluginsPath);

private:
	void	getPluginList(std::list<std::string>& list, const std::string& pluginsPath);
};

} // namespace LBAPI

#endif // PLUGINLOADER_H
