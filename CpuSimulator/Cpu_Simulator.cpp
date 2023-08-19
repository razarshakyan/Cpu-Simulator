#include "Cpu_Simulator.h"
#include "Helpers.h"

void mov(short &dest, short &source)
{
    dest = source;
}

void add(short &dest, short &source)
{
    dest += source;
}

Opcode get_opcode(const std::string &arg)
{
    std::map<std::string, Opcode> opcodes_mapped;
    opcodes_mapped["mov"] = Opcode::MOV;
    opcodes_mapped["add"] = Opcode::ADD; 
    opcodes_mapped["sub"] = Opcode::SUB; 
    opcodes_mapped["mul"] = Opcode::MUL; 
    opcodes_mapped["div"] = Opcode::DIV; 
    opcodes_mapped["and"] = Opcode::AND; 
    opcodes_mapped["or"] = Opcode::OR; 
    opcodes_mapped["not"] = Opcode::NOT; 
    opcodes_mapped["cmp"] = Opcode::CMP; 
    opcodes_mapped["jmp"] = Opcode::JMP; 
    opcodes_mapped["jg"] = Opcode::JG; 
    opcodes_mapped["jl"] = Opcode::JL; 
    opcodes_mapped["je"] = Opcode::JE;

    if (opcodes_mapped.count(arg)) {
        return opcodes_mapped[arg];
    }
    else {
        return Opcode::ERROR;
    } 
}

eRegisters get_register(const std::string &arg)
{
    std::map<std::string,eRegisters> registers_mapped;
    registers_mapped["ra"] = eRegisters::RA;
    registers_mapped["rb"] = eRegisters::RB; 
    registers_mapped["rc"] = eRegisters::RC; 
    registers_mapped["rd"] = eRegisters::RD; 
    registers_mapped["re"] = eRegisters::RE; 
    registers_mapped["rf"] = eRegisters::RF; 
    registers_mapped["ri"] = eRegisters::RI;

    if (registers_mapped.count(arg)) {
        return registers_mapped[arg];
    }
    else {
        return eRegisters::ERROR;
    }
}

Instruction parse(std::string &line, std::map<std::string, size_t> &labels, size_t line_num)
{
    Instruction current_instruction;
    to_lower(line);
    auto string_vector = splitter(line, ", ");
    // ստեղ եմ հասել
    
}

void init_cpu(Cpu &fake_cpu)
{
    fake_cpu.registers = {0,0,0,0,0,0,0};
}

void execute_cpu(Cpu &fake_cpu, std::map<size_t, Instruction> &instructionconst, std::multimap<std::string, size_t> &labels)
{
}

void alu_mappings(std::map<Opcode, void (*)(short &, short &)> &alu_map)
{
    alu_map[Opcode::MOV] = mov;
    alu_map[Opcode::ADD] = add;
}

void registers_mapping(std::map<eRegisters, short*> &register_map, Cpu &fake_cpu)
{
    register_map[eRegisters::RA] = &fake_cpu.registers.ra;
    register_map[eRegisters::RB] = &fake_cpu.registers.rb;
    register_map[eRegisters::RC] = &fake_cpu.registers.rc;
    register_map[eRegisters::RD] = &fake_cpu.registers.rd;
    register_map[eRegisters::RE] = &fake_cpu.registers.re;
    register_map[eRegisters::RF] = &fake_cpu.registers.rf;
    register_map[eRegisters::RI] = &fake_cpu.registers.ri;
}

void error_checker(Instruction &current_instruction, short line)
{
    if (current_instruction.opcode == Opcode::ERROR) {
        std::cerr << "You have error in line: " << line << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (current_instruction.dest_reg == eRegisters::ERROR) {
        std::cerr << "You have error in line: " << line << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (current_instruction.source_reg == eRegisters::ERROR) {
        std::cerr << "You have error in line: " << line << std::endl;
        exit(EXIT_FAILURE);
    }
}
