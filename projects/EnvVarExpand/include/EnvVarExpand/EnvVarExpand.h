
#ifndef __ENVVAREXPAND_H__
#define __ENVVAREXPAND_H__

#include "EnvVarExpand/ENVVAREXPAND_Export.h"
#include "EnvVarExpand/version.h"

#include <string>
#include <map>

namespace EnvVarExpand_ns
{
    extern "C" ENVVAREXPAND_Export void EnvVarExpand_get_version(int & major, int & minor, int & patch);

    enum enumEnvVarType {
        Custom,
        Env
    };

    class ENVVAREXPAND_Export EnvVarExpand
    {
    public:
        static bool expand(const std::string & str,
            std::map<std::string, std::string> theMap,
            enumEnvVarType type,
            std::string & strNew);

        static bool expand_custom_variables(const std::string & str,
            std::map<std::string, std::string> theMap,
            std::string & strNew);

        static bool expand_env_variables(const std::string & str,
            std::string & strNew);

        static bool expand_variables(const std::string & str,
            std::map<std::string, std::string> theMap,
            std::string & strNew);
    };

} // EnvVarExpand_ns namespace


#endif // __ENVVAREXPAND_H__
