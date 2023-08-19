#include "Cpu_Simulator.hpp"
#include <fstream>

int main(int argc, char** argv) {
    Cpu fake_cpu;
    init_cpu(fake_cpu);
    std::ifstream file("commands.myasm");
    open_file(file,argc,argv);

    std::map<size_t, Instruction> instructions;
    std::multimap<std::string, size_t> labels;
    std::string buf;
    size_t line = 0;
    while (!file.eof()) {
        std::getline(file, buf);
        if (buf[0] == '\0') {
            continue;
        }
        instructions[line] = parse(buf,labels,line);
        error_checker(instructions[line], line + 1);
        ++line;
    }
    execute_cpu(fake_cpu,instructions,labels);
    return 0;
}