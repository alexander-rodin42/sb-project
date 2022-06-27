#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

auto recursiveGetFileNamesByExtension =
        [](const fs::path& path,
           const std::string& extension)
{
    std::vector<std::string> result;
    for(auto & it: fs::recursive_directory_iterator(path))
    {
        if (it.is_regular_file() && it.path().extension() == extension)
        {
            result.push_back(it.path().filename().string());
        }
    }
    return result;
};

int main()
{
    std::vector<std::string> vector;
    std::string path;
    std::string extension;

    std::cout << "Enter folder path: ";
    std::cin >> path;
    std::cout << "Enter file extension: ";
    std::cin >> extension;

    vector = recursiveGetFileNamesByExtension(path, extension);

    for (auto i : vector) {
        std::cout << i << std::endl;
    }
    return 0;
}
