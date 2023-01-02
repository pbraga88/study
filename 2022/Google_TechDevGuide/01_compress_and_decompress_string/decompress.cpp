#include <iostream>
#include <string>

std::string recursion_func(int times, std::string str) {
    return (--times && !str.empty()) ? str+recursion_func(times, str) : str;
}

std::string decompress(std::string compressed) {
    std::string decomp, aux;
    std::string times;

    for (int i = 0; i < compressed.length(); i++) {
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            times.push_back(compressed[i]);
        }
        else if (compressed[i] == '[') {
            i++;
            while (compressed[i] != ']') {
                aux.push_back(compressed[i]);
                i++;
            }
            decomp.append(recursion_func(std::stoi(times), aux));
            times.erase();
            aux.erase();
        }
        else {
            decomp.push_back(compressed[i]);
        }
    }

    return decomp;
}

int main() {
    std::string decomp = decompress("10[abc]4[ab]c");
    std::cout<<decomp<<std::endl;
    return 0;
}