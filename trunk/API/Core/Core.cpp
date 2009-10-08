#include "Core.h"

using namespace LBAPI;

void	Core::loadPlugins(const std::string& pluginsPath)
{
	m_pluginLoader.loadPlugins(*this, pluginsPath);
}

Core	Core::m_instance;
