#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // Include for fixed-width types like uint32_t

#include "./src/decode_arm_instructions.c"
#include "./src/decode_thumb_instructions.c"

#define ROM_SIZE 33554432  // 32 MB


uint64_t ROM_SIZE_CURRENT;

typedef struct 
{
    uint32_t registers[16];
    uint32_t cpsr;
}CPUState;


int load_rom(const char *file_path, unsigned char *memory){
    FILE *file = fopen(file_path, "rb");
    if(!file){
        printf("invalid path, Can't open file");
        return -1;
    }

    size_t byteRead = fread(memory,1,ROM_SIZE,file);
    ROM_SIZE_CURRENT = byteRead;
    
    fclose(file);

    if(byteRead==0){
        printf("can't read data");
        return -1;
    }
    else{
        printf("SUCCESS! read %zu Byte from rom \n",byteRead );
        return 0;
    }
}


int display_rom_header(unsigned char *memory){
    printf("ROM Header !!! \n");

    printf("Title: ");
    for (int i = 0xA0; i < 0xAC; i++)
    {
        printf("%c", memory[i]);
    }
    printf("\n");

    printf("Game Code: ");
    for (int i = 0xAC; i < 0xB0; i++)
    {
        printf("%c", memory[i]);
    }
    printf("\n");

    printf("Maker Code: ");
    for (int i = 0xB0; i < 0xB2; i++)
    {
        printf("%c", memory[i]);
    }
    printf("\n");
}








void init_cpu(CPUState *cpu){
    for(int i =0; i<16; i++){
        cpu-> registers[i]=0;
    }
    cpu-> cpsr=0;
    cpu-> registers[15]=516;
    printf("CPU Init Done!\n");
}


uint32_t fetch_instruction(CPUState *cpu, unsigned char *memory){
    uint32_t pc = cpu-> registers[15];
    uint32_t instruction = (memory[pc]<<0)| (memory[pc+1]<<8)| (memory[pc+2]<<16)| (memory[pc+3]<<24);
    printf("Fetched instruction[pc+4byte] 0x%08X at address[pc =] 0x%08X\n", instruction, pc);
    return instruction;
}

uint16_t fetch_thumb_instruction(CPUState *cpu, unsigned char *memory){
    uint32_t pc = cpu-> registers[15];
    uint16_t instruction = (memory[pc]<<0)| (memory[pc+1]<<8);
    printf("Fetched instruction[pc+2byte] 0x%04X at address[pc =] 0x%08X\n", instruction, pc);
    return instruction;
}



void run_emulator(CPUState *cpu, unsigned char *memory){
    printf("Starting the CPU cycle: Fetch-Decode-Execute\n");

    while(1){

        // Step 1: Fetch Instruction and send to decoder
        // for now it will break but mainly it's an infinite loop
        
        if (cpu -> cpsr ==0)
        {
            // fetching instruction
            uint32_t instruction32 = fetch_instruction(cpu,memory);
            //advanced PC:
            cpu-> registers[15] += 4;

            //sending to decoder
            printf("Decoding instruction... \n");
            print_binary(&instruction32, sizeof(instruction32));
            
            DecodeARMInstruction(instruction32);
        }
        else if(cpu -> cpsr == 1){
            uint16_t instruction16 = fetch_thumb_instruction(cpu,memory);
            cpu-> registers[15] += 2;


            printf("Decoding instruction... \n");
            print_binary(&instruction16,sizeof(instruction16));

            DecodeTHUMBInstruction(instruction16);

        }
        

        // Step 3:
        printf("Executing instruction...\n");

        //end step 3 here above

        if (cpu->registers[15]>=528){
            printf("This is the End of ROM\n");
            break;
        }
        
    }
}


int main(){
    unsigned char *main_memory = (unsigned char *)malloc(ROM_SIZE);

    if(!main_memory){
        printf("can't create memory in heap");
        return 1;
    }

    int load_rom_determiner = load_rom("./roms/pokemon.gba", main_memory);

    if(load_rom_determiner !=0){
        free(main_memory);
        return 1;
    }

    display_rom_header(main_memory);

    // Initialize the CPU
    CPUState cpu;
    init_cpu(&cpu);

    //run the cpu
    run_emulator(&cpu, main_memory);


    // printf("%d",main_memory[15]>>4);

    //ending

    free(main_memory);

    return 0;
    
}