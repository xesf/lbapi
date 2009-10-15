#include <iostream>

#include "ExamplePlugin_global.h"
#include "../../API/Core/Core.h"
#include "../../API/Core/Logger.h"

extern "C" EXAMPLEPLUGIN_EXPORT int getLbapiVersion()
{
	return LBAPI_VERSION;
}

extern "C" EXAMPLEPLUGIN_EXPORT void registerLbapiPlugin(LBAPI::Core& core)
{
        LBAPI::logger() << "Registering plugin ExamplePlugin" << std::endl;
	// Register drivers
	// ...
	// ...
}
