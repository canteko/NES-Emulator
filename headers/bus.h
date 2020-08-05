#include <cstdint>
#include <array>
#include "olc6502.h"

class Bus 
{
    public:
        Bus();
        ~Bus();

        //Devices attatched to the bus
        olc6502 cpu;
        std::array<uint8_t, 64*1024> ram;

        //Bus Read and Write
        void write(uint16_t addr, uint8_t data);
        uint8_t read(uint16_t addr, bool readOnly = false);
};