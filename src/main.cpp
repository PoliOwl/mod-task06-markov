#include "textgen.h"
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid number of arguments: filepath wasn't found\n";
        return 1;
    }
    auto file = std::ifstream(argv[1]);
    textgen gen(file);
    file.close();
    std::cout << gen.generate_text();
}