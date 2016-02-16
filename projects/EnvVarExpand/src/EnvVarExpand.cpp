
#include "EnvVarExpand/EnvVarExpand.h"
#include "EnvVarExpand/version.h"

#include <stdlib.h>

namespace EnvVarExpand_ns
{
    void EnvVarExpand_get_version(int & major, int & minor, int & patch)
    {
        major = ENVVAREXPAND_MAJOR;
        minor = ENVVAREXPAND_MINOR;
        patch = ENVVAREXPAND_PATCH;
    }

    bool EnvVarExpand::expand(const std::string & str,
        std::map<std::string, std::string> theMap,
        enumEnvVarType type,
        std::string & strNew)
    {
        std::string strSpecialChar;
        switch(type)
        {
            case Custom:
                strSpecialChar = "@";
                break;

            case Env:
                strSpecialChar = "$";
                break;
        }
        size_t pos = str.find(strSpecialChar);
        if (pos != str.npos)
        {
            std::string strBeginning;
            if (pos != 0)
            {
                strBeginning = str.substr(0, pos);
            }

            size_t posVarBegin = str.find("(");
            size_t posVarEnd = str.find(")");

            if (posVarBegin == str.npos || posVarEnd == str.npos)
            {
                return false;
            }

            std::string strLookup = str.substr(posVarBegin + 1, posVarEnd - posVarBegin - 1);

            std::string strVariableValue;
            switch(type)
            {
                case Custom:
                    strVariableValue = theMap[strLookup];
                    break;

                case Env:
                {
                    char * p = getenv(strLookup.c_str());
                    if (!p)
                    {
                        return false;
                    }
                    strVariableValue = p;

                    break;
                }
            }

            std::string strInMapNew;
            if (!expand(strVariableValue, theMap, type, strInMapNew))
            {
                return false;
            }

            std::string strRemaining = str.substr(posVarEnd + 1);
            if (!strRemaining.empty())
            {
                std::string strInner;
                if (!expand(strRemaining, theMap, type, strInner))
                {
                    return false;
                }

                strNew = strBeginning + strInMapNew + strInner;
            }
            else
            {
                strNew = strBeginning + strInMapNew;
            }
        }
        else
        {
            strNew = str.c_str();
        }

        return true;
    }


    bool EnvVarExpand::expand_custom_variables(const std::string & str,
        std::map<std::string, std::string> theMap,
        std::string & strNew)
    {
        return expand(str, theMap, Custom, strNew);
    }


    bool EnvVarExpand::expand_env_variables(const std::string & str,
        std::string & strNew)
    {
        std::map<std::string, std::string> theMap;
        return expand(str, theMap, Env, strNew);
    }


    bool EnvVarExpand::expand_variables(const std::string & str,
        std::map<std::string, std::string> theMap,
        std::string & strNew)
    {
        std::string strNewCustom;
        if (!expand_custom_variables(str, theMap, strNewCustom))
            return false;

        return expand_env_variables(strNewCustom, strNew);
    }

} // EnvVarExpand_ns namespace
