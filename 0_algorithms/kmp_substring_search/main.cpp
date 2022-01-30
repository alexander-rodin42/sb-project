#include <iostream>
#include <vector>

bool KMP(std::string str, std::string substr)
{
    std::vector<int> matches;
    std::vector<int> p(substr.size() + str.size(), -1);

    for (int i = 0, j = -1;i < substr.size();)
    {
        while (j > -1 && substr[i] != substr[j])
            j = p[j];
        i++;
        j++;
        p[i] = j;
    }
    for (int i=0, j = 0;i < str.size();)
    {
        while (j > -1 && str[i] != substr[j])
            j = p[j];
        i++;
        j++;
        if (j == substr.size())
        {
            return true;
        }

    }
    return false;
}

int main() {
    std::string haystack = "abacabcbadd";
    std::string needle = "abc";

    if (KMP(haystack, needle))
        std::cout << "Is substring" << std::endl;
    else
        std::cout << "Not a substring" << std::endl;

    return 0;
}
