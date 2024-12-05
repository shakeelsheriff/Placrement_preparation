#include <stdio.h>
#include <stdint.h>

// Fixed macros
#define HEADER 0xAA
#define FOOTER 0x55
#define DEVICE_ID 0x01

// Global variable to store decoded data
uint8_t decodedData[100] = {0};

// Bit masks and shifts
#define HEADER_SHIFT     56
#define SIZE_SHIFT       48
#define DEVICE_ID_SHIFT  40
#define LENGTH_SHIFT     32
#define ORDER_SHIFT      24
#define DATA_SHIFT       16
#define FOOTER_SHIFT      0

#define HEADER_MASK      0xFF
#define SIZE_MASK        0xFF
#define DEVICE_ID_MASK   0xFF
#define LENGTH_MASK      0xFF
#define ORDER_MASK       0xFF
#define DATA_MASK        0xFF
#define FOOTER_MASK      0xFF

// Function prototype
int decodePacket(uint64_t packets[], size_t packetCount, uint8_t deviceId);

// Provided function to print decoded data
void printDecodedData() {
    printf("Decoded Data: ");
    for (int i = 0; i < 100; i++) {
        if (decodedData[i] != 0) {
            printf("%c", decodedData[i]);
        }
    }
    printf("\n");
}

// Main function (provided for testing)
int main() {
    uint64_t packets[] = {
        0xAA090109056F0055, 
        0xAA090109066F0055,  
        0xAA09010901680055,  
        0xAA09010907770055,  
        0xAA090109086F0055, 
        0xAA09010909720055,  
        0xAA090109036C0055, 
        0xAA0901090A6C0055,  
        0xAA09010902650055,  
        0xAA090109046C0055 
    };

    size_t packetCount = sizeof(packets) / sizeof(packets[0]);

    if (decodePacket(packets, packetCount, DEVICE_ID) == 0) {
        printDecodedData();
    } else {
        printf("Failed to decode packets.\n");
    }

    return 0;
}

/*  
    Name: Shakeel Sheriff M
    Batch: 24002
    Date: 04/12/2024
    Problem : Write a function to extract and validate specific fields 
               from a 64-bit packet using bitwise operations.
*/

// Your implementation of decodePacket() goes here
int decodePacket(uint64_t packets[], size_t packetCount, uint8_t deviceId) {
    // TODO: Implement this function

    // Iterating throug all packets
    for (size_t i=0; i<packetCount; i++){
        uint64_t packet = packets[i]; // Getting current packet

        // 1. Validate packet HEADER bit 56–63 8-bit header value (0xAA)
        uint8_t header = (packet >> HEADER_SHIFT) & HEADER_MASK;
        if(header != HEADER){
            return -1; //Invalid packet wrong header
        }

        // 2. Validate packet FOOTER bit 0–7 8-bit footer value (0x55)
        uint8_t footer = packet & FOOTER_MASK;
        if(footer != FOOTER){
            return -1; //Invalid packet wrong footer
        }

        // 3. Validate device ID bit 40–47 8-bit device ID (used to validate the packet; fixed as 0x01)
        uint8_t packetdeviceID = (packet >> DEVICE_ID_SHIFT) & DEVICE_ID_MASK;
        if(packetdeviceID != DEVICE_ID){
            return -1; //Invalid packet wrong device Id
        }

        // 4. Extract dataOrder (bits 24-31) and data (bits 16-23)
        uint8_t dataOrder = (packet >> ORDER_SHIFT) & ORDER_MASK;
        uint8_t data = (packet >> DATA_SHIFT) & DATA_MASK;

        // 5. Store data in decodedData array
        decodedData[dataOrder - 1] = data;
    }
    //All packets decoded successfully
    return 0;
}
