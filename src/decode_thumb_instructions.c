#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void print_binary(void* num, int size) {
    int bits = size * 8;  // Calculate the number of bits (16 or 32)

    // Cast the number to the appropriate type based on size
    uint32_t n = (size == sizeof(uint16_t)) ? *((uint16_t*)num) : *((uint32_t*)num);

    // Loop through each bit and print it
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}


int IsTHUMBSoftwareInterrupt(uint16_t opcode) {
    const uint16_t softwareInterruptFormat = 0b1101111100000000;
    const uint16_t formatMask = 0b1111111100000000;
    if ((opcode & formatMask) == softwareInterruptFormat)
    {
        return 10;
    }
    
}

int IsUnconditionalBranch(uint16_t opcode) {
    const uint16_t unconditionalBranchFormat = 0b1110000000000000;
    const uint16_t formatMask = 0b1111100000000000;
    if ((opcode & formatMask) == unconditionalBranchFormat)
    {
        return 10;
    }
    
}

int IsConditionalBranch(uint16_t opcode) {
    const uint16_t conditionalBranchFormat = 0b1101000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == conditionalBranchFormat)
    {
        return 10;
    }
    
}

int IsMultipleLoadStore(uint16_t opcode) {
    const uint16_t multipleLoadStoreFormat = 0b1100000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == multipleLoadStoreFormat)
    {
        return 10;
    }
    
}

int IsLongBranchWithLink(uint16_t opcode) {
    const uint16_t longBranchWithLinkFormat = 0b1111000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == longBranchWithLinkFormat)
    {
        return 10;
    }
    
}

int IsAddOffsetToStackPointer(uint16_t opcode) {
    const uint16_t addOffsetToStackPointerFormat = 0b1011000000000000;
    const uint16_t formatMask = 0b1111111100000000;
    if ((opcode & formatMask) == addOffsetToStackPointerFormat)
    {
        return 10;
    }
    
}

int IsPushPopRegisters(uint16_t opcode) {
    const uint16_t pushPopRegistersFormat = 0b1011010000000000;
    const uint16_t formatMask = 0b1111011000000000;
    if ((opcode & formatMask) == pushPopRegistersFormat)
    {
        return 10;
    }
    
}

int IsLoadStoreHalfword(uint16_t opcode) {
    const uint16_t loadStoreHalfwordFormat = 0b1000000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == loadStoreHalfwordFormat)
    {
        return 10;
    }
    
}

int IsSPRelativeLoadStore(uint16_t opcode) {
    const uint16_t spRelativeLoadStoreFormat = 0b1001000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == spRelativeLoadStoreFormat)
    {
        return 10;
    }
    
}

int IsLoadAddress(uint16_t opcode) {
    const uint16_t loadAddressFormat = 0b1010000000000000;
    const uint16_t formatMask = 0b1111000000000000;
    if ((opcode & formatMask) == loadAddressFormat)
    {
        return 10;
    }
    
}

int IsLoadStoreWithImmediateOffset(uint16_t opcode) {
    const uint16_t loadStoreImmediateOffsetFormat = 0b0110000000000000;
    const uint16_t formatMask = 0b1110000000000000;
    if ((opcode & formatMask) == loadStoreImmediateOffsetFormat)
    {
        return 10;
    }
    
}

int IsLoadStoreWithRegisterOffset(uint16_t opcode) {
    const uint16_t loadStoreRegisterOffsetFormat = 0b0101000000000000;
    const uint16_t formatMask = 0b1111001000000000;
    if ((opcode & formatMask) == loadStoreRegisterOffsetFormat)
    {
        return 10;
    }
    
}

int IsLoadStoreSignExtendedByteHalfword(uint16_t opcode) {
    const uint16_t loadStoreSignExtendedByteHalfwordFormat = 0b0101001000000000;
    const uint16_t formatMask = 0b1111001000000000;
    if ((opcode & formatMask) == loadStoreSignExtendedByteHalfwordFormat)
    {
        return 10;
    }
    
}

int IsPCRelativeLoad(uint16_t opcode) {
    const uint16_t pcRelativeLoadFormat = 0b0100100000000000;
    const uint16_t formatMask = 0b1111100000000000;
    if ((opcode & formatMask) == pcRelativeLoadFormat)
    {
        return 10;
    }
    
}

int IsHiRegisterOperationsBranchExchange(uint16_t opcode) {
    
    const uint16_t hiRegisterOperationsBranchExchangeFormat = 0b0100010000000000;
    const uint16_t formatMask = 0b1111110000000000;
    if ((opcode & formatMask) == hiRegisterOperationsBranchExchangeFormat)
    {
        return 10;
    }
    
}

int IsALUOperations(uint16_t opcode) {
    const uint16_t aluOperationsFormat = 0b0100000000000000;
    const uint16_t formatMask = 0b1111110000000000;
    if ((opcode & formatMask) == aluOperationsFormat)
    {
        return 10;
    }
    
}

int IsMoveCompareAddSubtractImmediate(uint16_t opcode) {
    const uint16_t moveCompareAddSubtractImmediateFormat = 0b0010000000000000;
    const uint16_t formatMask = 0b1110000000000000;
    if ((opcode & formatMask) == moveCompareAddSubtractImmediateFormat)
    {
        return 10;
    }
    
}

int IsAddSubtract(uint16_t opcode) {
    const uint16_t addSubtractFormat = 0b0001100000000000;
    const uint16_t formatMask = 0b1111100000000000;
    if ((opcode & formatMask) == addSubtractFormat)
    {
        return 10;
    }
    
}

int IsMoveShiftedRegister(uint16_t opcode) {
    const uint16_t moveShiftedRegistersFormat = 0b0000000000000000;
    const uint16_t formatMask = 0b1110000000000000;
    if ((opcode & formatMask) == moveShiftedRegistersFormat)
    {
        return 10;
    }
     
}

void DecodeTHUMBInstruction(uint16_t opcode) {
    if (IsTHUMBSoftwareInterrupt(opcode)== 10)   printf("THUMBSoftwareInterrupt\n");
    else if (IsUnconditionalBranch(opcode)== 10)  printf("UnconditionalBranch\n");
    else if (IsConditionalBranch(opcode)== 10)  printf("ConditionalBranch\n");
    else if (IsMultipleLoadStore(opcode)== 10)  printf("MultipleLoadstore\n");
    else if (IsLongBranchWithLink(opcode)== 10)  printf("LongBranchWithLink\n");
    else if (IsAddOffsetToStackPointer(opcode)== 10)  printf("AddOffsetToStackPointer\n");
    else if (IsPushPopRegisters(opcode)== 10)  printf("PushPopRegisters\n");
    else if (IsLoadStoreHalfword(opcode)== 10)  printf("LoadStoreHalfword\n");
    else if (IsSPRelativeLoadStore(opcode)== 10)  printf("SPRelatvieLoadStore\n");
    else if (IsLoadAddress(opcode)== 10)  printf("LoadAddress\n");
    else if (IsLoadStoreWithImmediateOffset(opcode)== 10)  printf("LoadStoreWithImmediateOffset\n");
    else if (IsLoadStoreWithRegisterOffset(opcode)== 10)  printf("LoadStoreWithRegisterOffset\n");
    else if (IsLoadStoreSignExtendedByteHalfword(opcode)== 10)  printf("LoadStoreSignExtendedByteHalfword\n");
    else if (IsPCRelativeLoad(opcode)== 10)  printf("PCRelativeLoad\n");
    else if (IsHiRegisterOperationsBranchExchange(opcode))  printf("HiRegisterOperationsBranchExchange\n");
    else if (IsALUOperations(opcode)== 10)  printf("ALUOperations\n");
    else if (IsMoveCompareAddSubtractImmediate(opcode)== 10)  printf("MoveCompareAddSubtractImmediate\n");
    else if (IsAddSubtract(opcode)== 10)  printf("AddSubtract\n");
    else if (IsMoveShiftedRegister(opcode)== 10)  printf("MoveShiftedRegister\n");

    else printf("UnimplementedTHUMBInstruction\n");
}