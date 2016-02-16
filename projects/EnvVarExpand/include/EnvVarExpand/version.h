
#pragma once

#define ENVVAREXPAND_MAJOR 1
#define ENVVAREXPAND_MINOR 0
#define ENVVAREXPAND_PATCH 2


#if defined _MSC_VER
#   ifdef _DEBUG
        const char ENVVAREXPAND_DebugFlag[] = "DEBUG";
#   else
        const char ENVVAREXPAND_DebugFlag[] = "RELEASE";
#   endif
#else
#   ifdef DEBUG
        const char ENVVAREXPAND_DebugFlag[] = "DEBUG";
#   else
        const char ENVVAREXPAND_DebugFlag[] = "RELEASE";
#   endif
#endif


