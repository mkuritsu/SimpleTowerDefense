#include <simpletdengine/filesystem/file_utils.h>

namespace simpletdengine
{
    std::string ReadTextFile(const std::string& filepath)
    {
        std::ifstream file(filepath);
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }
}
