#include <iostream>
#include "../API/Core/Core.h"
#include "../API/Core/Logger.h"

using namespace LBAPI;

int main()
{
        logger().setLogFile("mylog.log");
        logger() << "Loading plugins..." << std::endl;
        Core::instance().loadPlugins("./plugins");
	return 0;
}
