#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> line {"Build", "in", "vscode"};
    std::vector<std::string>::iterator it = line.begin();
    while (it != line.end()) {
        std::cout<<*it<<std::endl;
        it++;
    }

    return 0;
}
