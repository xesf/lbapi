#ifndef LBAPI_H
#define LBAPI_H

#include <string>

#include "../PackagingServer/PackagingServer.h"
#include "../GraphicsServer/GraphicsServer.h"
#include "../SoundServer/SoundServer.h"
#include "../GameplayServer/GameplayServer.h"

namespace LBAPI {

class LBAPI {
public:
	static LBAPI&		instance();

	void				loadPlugins(const std::string& pluginsPath = "./plugins");

    PackagingServer&    getPackagingServer() { return m_PackagingServer; }
    GraphicsServer&     getGraphicsServer() { return m_GraphicsServer; }
    SoundServer&        getSoundServer() { return m_SoundServer; }
    GameplayServer&     getGameplayServer() { return m_GameplayServer; }

private:
	PackagingServer     m_PackagingServer;
	GraphicsServer      m_GraphicsServer;
	SoundServer         m_SoundServer;
	GameplayServer      m_GameplayServer;

	static LBAPI		m_instance;
};

} // namespace LBAPI

#endif // LBAPI_H
