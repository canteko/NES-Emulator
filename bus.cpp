#include "headers/bus.h"


Bus::Bus()
{
    //Clear RAM
    for (auto &i : ram)
    {
        i = 0x00;
    }

    //Connect the CPU to this bus
    cpu.connectBus(this);
}

Bus::~Bus()
{

}

//Bus Read and Write
void Bus::write(uint16_t addr, uint8_t data)
{
    if (addr >= 0x0000 and addr <= 0xFFFF)
    {
        ram[addr] = data;
    }
}

uint8_t Bus::read(uint16_t addr, bool readOnly)
{
    if (addr >= 0x0000 and addr <= 0xFFFF)
    {
        return ram[addr];
    }
    return 0x00; 
}