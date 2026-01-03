/*
 * OMNICORP SECURITY SYSTEMS
 * LEGACY DECRYPTION TOOL v1.0.4
 * AUTHOR: C. RANKING
 * 
 * WARNING: UNAUTHORIZED USE IS A CLASS A FELONY.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void xor_decrypt(const char *hex_input, const char *key) {
    int key_len = strlen(key);
    int data_len = strlen(hex_input) / 2;
    
    printf("\n[SYSTEM] PROCESSING DATA STREAM...\n");
    printf("[SYSTEM] OUTPUT: ");
    
    for (int i = 0; i < data_len; i++) {
        char byte_str[3] = {hex_input[i*2], hex_input[i*2+1], '\0'};
        int byte_val = (int)strtol(byte_str, NULL, 16);
        char decoded_char = byte_val ^ key[i % key_len];
        printf("%c", decoded_char);
    }
    printf("\n\n");
}

int main() {
    char hex_message[2048];
    char key[100];

    printf("==========================================\n");
    printf("   OMNICORP INTERCEPTOR DECODER           \n");
    printf("==========================================\n");
    printf("   ENTER ENCRYPTED HEX STRING: ");
    
    if (scanf("%2047s", hex_message) != 1) {
        printf("Error reading input.\n");
        return 1;
    }
    
    printf("   ENTER DECRYPTION KEY: ");
    if (scanf("%99s", key) != 1) {
        printf("Error reading key.\n");
        return 1;
    }
    
    xor_decrypt(hex_message, key);
    
    return 0;
}