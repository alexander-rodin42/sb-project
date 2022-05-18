#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string url = "https://httpbin.org";

    cpr::Response response = cpr::Get(cpr::Url(url + "/html"),
                               cpr::Header({{"Accept", "text/html"}}));

    for (int i = response.text.find("<h1>") + 4; i < response.text.find("</h1>"); ++i) {
        std::cout << response.text[i];
    }
    std::cout << std::endl;
    //std::cout << response.text << std::endl;
    return 0;
}
