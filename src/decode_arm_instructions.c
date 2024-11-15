#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>





int IsBranchAndBranchExchange(uint32_t opcode) {
    const uint32_t branchAndExchangeFormat = 0b00000001001011111111111100010000;
    const uint32_t formatMask = 0b00001111111111111111111111110000;
    uint32_t extractedFormat = opcode & formatMask;
    if (extractedFormat == branchAndExchangeFormat){
        return 10;
    }
}

int IsBlockDataTransfer(uint32_t opcode) {
    const uint32_t blockDataTransferFormat = 0b00001000000000000000000000000000;
    const uint32_t formatMask = 0b00001110000000000000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if( extractedFormat == blockDataTransferFormat){
        return 10;
    }
}

int IsBranchAndBranchWithLink(uint32_t opcode) {
    const uint32_t branchFormat = 0b00001010000000000000000000000000;
    const uint32_t branchWithLinkFormat = 0b00001011000000000000000000000000;
    const uint32_t formatMask = 0b00001111000000000000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == branchFormat || extractedFormat == branchWithLinkFormat) {
        return 10;
    }
}

int IsSoftwareInterrupt(uint32_t opcode) {
    const uint32_t softwareInterruptFormat = 0b00001111000000000000000000000000;
    const uint32_t formatMask = 0b00001111000000000000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == softwareInterruptFormat) {
        return 10;
    }
}

int IsUndefined(uint32_t opcode) {
    const uint32_t undefinedFormat = 0b00000110000000000000000000010000;
    const uint32_t formatMask = 0b00001110000000000000000000010000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == undefinedFormat){
        return 10;
    }
}

int IsSingleDataTransfer(uint32_t opcode) {
    const uint32_t singleDataTransferFormat = 0b00000100000000000000000000000000;
    const uint32_t formatMask = 0b00001100000000000000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if (extractedFormat == singleDataTransferFormat){
        return 10;
    }
}

int IsSingleDataSwap(uint32_t opcode) {
    const uint32_t singleDataSwapFormat = 0b00000001000000000000000010010000;
    const uint32_t formatMask = 0b00001111100000000000111111110000;
    uint32_t extractedFormat = opcode & formatMask;
    if (extractedFormat == singleDataSwapFormat){
        return 10;
    }
}

int IsMultiply(uint32_t opcode) {
    const uint32_t multiplyFormat = 0b00000000000000000000000010010000;
    const uint32_t multiplyLongFormat = 0b00000000100000000000000010010000;
    const uint32_t formatMask = 0b00001111100000000000000011110000;
    uint32_t extractedFormat = opcode & formatMask;
    if (extractedFormat == multiplyFormat || extractedFormat == multiplyLongFormat){
        return 10;
    }
}

int IsHalfwordDataTransferRegister(uint32_t opcode) {
    const uint32_t halfwordDataTransferRegisterFormat = 0b00000000000000000000000010010000;
    const uint32_t formatMask = 0b00001110010000000000111110010000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == halfwordDataTransferRegisterFormat){
        return 10;
    }
}

int IsHalfwordDataTransferImmediate(uint32_t opcode) {
    const uint32_t halfwordDataTransferImmediateFormat = 0b00000000010000000000000010010000;
    const uint32_t formatMask = 0b00001110010000000000000010010000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == halfwordDataTransferImmediateFormat){
        return 10;
    }
}

int IsPSRTransferMRS(uint32_t opcode) {
    const uint32_t mrsFormat = 0b00000001000011110000000000000000;
    const uint32_t formatMask = 0b00001111101111110000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == mrsFormat){
        return 10;
    }
}

int IsPSRTransferMSR(uint32_t opcode) {
    const uint32_t msrFormat = 0b00000001001000001111000000000000;
    const uint32_t formatMask = 0b00001101101100001111000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == msrFormat){
        return 10;
    }
}

int IsDataProcessing(uint32_t opcode) {
    const uint32_t dataProcessingFormat = 0b00000000000000000000000000000000;
    const uint32_t formatMask = 0b00001100000000000000000000000000;
    uint32_t extractedFormat = opcode & formatMask;
    if ( extractedFormat == dataProcessingFormat){
        return 10;
    }
}


void DecodeARMInstruction(uint32_t opcode) {
    if (IsBranchAndBranchExchange(opcode)==10) printf("BranchAndBranchExchange \n");
   else if (IsBlockDataTransfer(opcode)==10) printf("BlockDataTransfer\n");
   else if (IsBranchAndBranchWithLink(opcode)==10) printf("BranchAndBranchWithLink\n");
   else if (IsSoftwareInterrupt(opcode)==10) printf("SoftwareInterrupt\n");
   else if (IsUndefined(opcode)==10) printf("Undefined\n");
   else if (IsSingleDataTransfer(opcode)==10) printf("SingleDataTransfer\n");
   else if (IsSingleDataSwap(opcode)==10) printf("SingleDataSwap\n");
   else if (IsMultiply(opcode)==10) printf("Multiply\n");
   else if (IsHalfwordDataTransferRegister(opcode)==10) printf("HalfwordDataTransferRegister\n");
   else if (IsHalfwordDataTransferImmediate(opcode)==10) printf("HalfwordDataTransferImmediate\n");
   else if (IsPSRTransferMRS(opcode)==10) printf("PSRTransferMRS\n");
   else if (IsPSRTransferMSR(opcode)==10) printf("PSRTransferMSR\n");
   else if (IsDataProcessing(opcode)==10) printf("DataProcessing\n");

    else printf("UnimplementedARMInstruction \n");
}