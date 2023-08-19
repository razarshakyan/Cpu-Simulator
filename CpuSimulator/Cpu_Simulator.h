#ifndef CPU_SIMULATOR
#define CPU_SIMULATOR

#include <iostream>
#include <map>

struct Cpu {
    struct Registers {
        short ra,rb,rc,rd,re,
        rf,//flag register
        ri;//instruction pointer register
    }registers;
};

enum class Opcode {
    MOV,ADD,SUB,MUL,DIV,AND,OR,
    NOT,CMP,JMP,JG,JL,JE,
    ERROR = 666
};

enum class eRegisters {
    RA,RB,RC,RD,RE,RF,RI,
    ERROR = 666
};

struct Instruction {
    Opcode opcode;
    eRegisters dest_reg;
    eRegisters source_reg;
    short source_immediate;
    std::string target;
};

void mov(short& dest, short& source);
void add(short& dest, short& source);
Opcode get_opcode(const std::string& arg);
eRegisters get_register(const std::string& arg);
Instruction parse(std::string& line, std::map<std::string, size_t>& labels, size_t line_num);
void init_cpu(Cpu& fake_cpu);
void execute_cpu(Cpu& fake_cpu, std::map<size_t, Instruction>& instructionconst, std::multimap<std::string, size_t>& labels);
void alu_mappings(std::map<Opcode, void (*)(short&,short&)>& alu_map);
void registers_mapping(std::map<eRegisters, short*>& register_map, Cpu& fake_cpu);
void error_checker(Instruction& current_instruction, short line);

#endif