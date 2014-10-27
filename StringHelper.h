/************************************************
 *
 * file  : StringHelper.cpp
 * author: bobding
 * date  : 2014-10-27
 * detail:
 *
************************************************/

#ifndef _STRINGHELPER_H_
#define _STRINGHELPER_H_

#if _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning(push)
#pragma warning(disable:4996)
#endif

#include <string>
#include <algorithm>

class StringHelper
{
public:
    static std::string lowercase(const std::string& s)
    {
        std::string ss(s);
        std::transform(ss.begin(), ss.end(), ss.begin(), tolower);

        return ss;
    }

    static std::string uppercase(const std::string& s)
    {
        std::string ss(s);
        std::transform(ss.begin(), ss.end(), ss.begin(), toupper);

        return ss;
    }

    static bool euqals(const std::string& src, const std::string& dst, size_t length = std::string::npos)
    {
        if (std::string::npos == length)
        {
            return src.length() == dst.length() && 0 == strncmp(src.c_str(), dst.c_str(), src.length());
        }
        else
        {
            return 0 == strncmp(src.c_str(), dst.c_str(), length);
        }
    }

    static bool equalsIgnoreCase(const std::string& src, const std::string& dst, size_t length = std::string::npos)
    {
        if (std::string::npos == length)
        {
            return src.length() == dst.length() && 0 == strnicmp(src.c_str(), dst.c_str(), src.length());
        }
        else
        {
            return 0 == strnicmp(src.c_str(), dst.c_str(), length);
        }
    }

    static bool stringToBool(const std::string& s)
    {
        return equalsIgnoreCase("true", s);
    }

    static short stringToShort(const std::string& s)
    {
        return (short)atoi(s.c_str());
    }

    static unsigned short stringToUShort(const std::string& s)
    {
        return (unsigned short)atoi(s.c_str());
    }

    static int stringToInt(const std::string& s)
    {
        return atoi(s.c_str());
    }

    static unsigned int stringToUInt(const std::string& s)
    {
        return (unsigned int)atoi(s.c_str());
    }

    static unsigned int stringToHex(const std::string& s)
    {
        return (unsigned int)strtol(s.c_str(), 0, 16);
    }

    static long long stringToInt64(const std::string& s)
    {
    #if defined(_WIN32) || defined(_WIN64)
        #define strtoll _strtoi64
    #endif
        return strtoll(s.c_str(), 0, 10);
    }

    static unsigned long long stringToUInt64(const std::string& s)
    {
    #if defined(_WIN32) || defined(_WIN64)
        #define strtoull _strtoui64
    #endif
        return strtoull(s.c_str(), 0, 10);
    }

    static float stringToFloat(const std::string& s)
    {
        return (float)atof(s.c_str());
    }

    static double stringToDouble(const std::string& s)
    {
        return atof(s.c_str());
    }

    static std::string boolToString(bool v)
    {
        return v ? "true" : "false";
    }

#if defined(_WIN32) || defined(_WIN64)
    #define snprintf _snprintf
#endif

    static std::string shortToString(short v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%d", (int)v);
        return buffer;
    }

    static std::string ushortToString(unsigned short v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%u", (unsigned int)v);
        return buffer;
    }

    static std::string intToString(int v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%d", v);
        return buffer;
    }

    static std::string uintToString(unsigned int v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%u", v);
        return buffer;
    }

    static std::string hexToString(unsigned int v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%x", v);
        return buffer;
    }

    static std::string int64ToString(long long v)
    {
        char buffer[64] = {0};
    #if defined(_WIN32) || defined(_WIN64)
        snprintf(buffer, sizeof(buffer) - 1, "%I64i", v);
    #else
        snprintf(buffer, sizeof(buffer) - 1, "%lld", v);
    #endif
    }

    static std::string uint64ToString(unsigned long long v)
    {
        char buffer[64] = {0};
    #if defined(_WIN32) || defined(_WIN64)
        snprintf(buffer, sizeof(buffer) - 1, "%I64u", v);
    #else
        snprintf(buffer, sizeof(buffer) - 1, "%llu", v);
    #endif
    }

    static std::string floatToString(float v)
    {
        char buffer[32] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%f", v);
        return buffer;
    }

    static std::string doubleToString(double v)
    {
        char buffer[64] = {0};
        snprintf(buffer, sizeof(buffer) - 1, "%e", v);
        return buffer;
    }
};

#if _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning(pop)
#endif

#endif // _STRINGHELPER_H_