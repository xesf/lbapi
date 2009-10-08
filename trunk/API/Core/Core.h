#ifndef LBAPI_H
#define LBAPI_H

#include <string>

#include "../PackagingServer/PackagingServer.h"
#include "../GraphicsServer/GraphicsServer.h"
#include "../SoundServer/SoundServer.h"
#include "../GameplayServer/GameplayServer.h"

#include "implementation/PluginLoader.h"

#define LBAPI_VERSION 1

namespace LBAPI {

class Core {
public:
	static Core&		instance() { return m_instance; }

	void				loadPlugins(const std::string& pluginsPath = "./plugins");

    PackagingServer&    getPackagingServer() { return m_PackagingServer; }
    GraphicsServer&     getGraphicsServer() { return m_GraphicsServer; }
    SoundServer&        getSoundServer() { return m_SoundServer; }
    GameplayServer&     getGameplayServer() { return m_GameplayServer; }

private:
	Core() {}

	PackagingServer     m_PackagingServer;
	GraphicsServer      m_GraphicsServer;
	SoundServer         m_SoundServer;
	GameplayServer      m_GameplayServer;

	static Core		m_instance;
	PluginLoader	m_pluginLoader;
};

} // namespace LBAPI

typedef int		(*GetLbapiVersionFct)();
typedef void	(*RegisterLbapiPluginFct)(LBAPI::Core&);

#endif // LBAPI_H
