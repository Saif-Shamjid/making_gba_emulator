#include <stdio.h>
#include <stdlib.h>  // Include for malloc and free
#include <stdint.h>  // Include for fixed-width types


#define ROM_SIZE 33554432  // 32 MB
// Define CPU structure
typedef struct {
    uint32_t registers[16];  // 16 general-purpose registers (R0-R15)
    uint32_t cpsr;           // Current Program Status Register
} CPUState;

// Function to initialize CPU state
void initialize_cpu(CPUState *cpu) {
    // Initialize all registers and CPSR to 0
    for (int i = 0; i < 16; i++) {
        cpu->registers[i] = 0;
    }
    cpu->cpsr = 0;
    printf("CPU initialized with all registers set to 0.\n");
}

// Function to load a ROM file into memory
int load_rom(const char *filepath, unsigned char *memory) {
    // Open the ROM file
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf("Error: Unable to open ROM file %s\n", filepath);
        return -1; // Error code
    }

    // Read the ROM file into memory
    size_t bytesRead = fread(memory, 1, ROM_SIZE, file);

    // Close the file
    fclose(file);

    // Check if we actually read anything
    if (bytesRead == 0) {
        printf("Error: ROM file is empty or couldn't be read correctly.\n");
        return -1;
    }
    printf("Successfully loaded %zu bytes from ROM.\n", bytesRead);
    return 0; // Success code
}

// Function to display GBA ROM header information
void display_rom_info(unsigned char *memory) {
    printf("GBA ROM Header Information:\n");

    // Game Title (0xA0 - 0xAC)
    printf("Game Title: ");
    for (int i = 0xA0; i < 0xAC; i++) {
        printf("%c", memory[i]);
    }
    printf("\n");

    // Game Code (0xAC - 0xB0)
    printf("Game Code: ");
    for (int i = 0xAC; i < 0xB0; i++) {
        printf("%c", memory[i]);
    }
    printf("\n");

    // Maker Code (0xB0 - 0xB2)
    printf("Maker Code: ");
    for (int i = 0xB0; i < 0xB2; i++) {
        printf("%c", memory[i]);
    }
    printf("\n");
}

// Skeleton function for the Fetch-Decode-Execute cycle
void run_emulator(CPUState *cpu, unsigned char *memory) {
    printf("Starting the fetch-decode-execute cycle...\n");
    while (1) {
        // Step 1: Fetch the instruction (For now, just simulate)
        uint32_t instruction = 0;  // Placeholder for an instruction
        printf("Fetched instruction: 0x%08X\n", instruction);

        // Step 2: Decode the instruction (Currently a placeholder)
        printf("Decoding instruction...\n");

        // Step 3: Execute the instruction (Currently a placeholder)
        printf("Executing instruction...\n");

        // Placeholder: For now, we'll break out of the loop to avoid an infinite loop
        break;
    }
}


int main() {
    // Allocate memory on the heap
    unsigned char *memory = (unsigned char *)malloc(ROM_SIZE);
    if (!memory) {
        printf("Error: Failed to allocate memory for ROM.\n");
        return 1;
    }

    // Load the ROM file into memory
    if (load_rom("./roms/pokemon.gba", memory) != 0) {
        free(memory);  // Free the allocated memory on failure
        return 1;  // Exit if loading the ROM fails
    }

    // // Print the first few bytes of the ROM
    // printf("First 100 bytes of ROM:\n");
    // for (int i = 0; i < 100; i++) {
    //     printf("%02X ", memory[i]);  // Print each byte in hexadecimal format
    // }
    // printf("\n");


    // Display the ROM header information
    display_rom_info(memory);


    // Initialize the CPU
    CPUState cpu;
    initialize_cpu(&cpu);

    // Run the emulator (for now, just the skeleton loop)
    run_emulator(&cpu, memory);


    // Free the allocated memory
    free(memory);

    return 0;
}
