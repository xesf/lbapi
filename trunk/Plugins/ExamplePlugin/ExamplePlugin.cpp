#include <iostream>

#include "ExamplePlugin_global.h"
#include "../../API/Core/Core.h"

extern "C" EXAMPLEPLUGIN_EXPORT int getLbapiVersion()
{
	return LBAPI_VERSION;
}

extern "C" EXAMPLEPLUGIN_EXPORT void registerLbapiPlugin(LBAPI::Core& core)
{
	std::cout << "Registering plugin ExamplePlugin" << std::endl;
	// Register drivers
	// ...
	// ...
}
