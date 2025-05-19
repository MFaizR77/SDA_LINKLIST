#include "header.h"

void initializeMorseTree(TreeNode* root) {
    // Angka
    insertToTree(root, ".", '1');      // 1 = .
    insertToTree(root, "..", '2');     // 2 = ..
    insertToTree(root, ".-", '3');     // 3 = .-
    insertToTree(root, "...", '4');    // 4 = ...
    insertToTree(root, "..-", '5');    // 5 = ..-
    insertToTree(root, "-", '6');      // 6 = -
    insertToTree(root, "-.", '7');     // 7 = -.
    insertToTree(root, "--", '8');     // 8 = --
    insertToTree(root, "-..", '9');    // 9 = -..
    insertToTree(root, "-.-", '0');    // 0 = -.-

    // Huruf 
    insertToTree(root, ".-..", 'A');   // A = .-..
    insertToTree(root, "-....", 'B');   // B = -...
    insertToTree(root, "...-.", 'C');  // C = ...-.
    insertToTree(root, ".--.", 'D');   // D = .--.
    insertToTree(root, "...-", 'E');   // E = ...-
    insertToTree(root, ".---", 'F');   // F = .---
    insertToTree(root, "-.--", 'G');   // G = -.--
    insertToTree(root, "--..", 'H');   // H = --..
    insertToTree(root, "-...", 'I');   // I = -.... 
    insertToTree(root, "--.-", 'J');   // J = --.-
    insertToTree(root, "---.", 'K');   // K = ---.
    insertToTree(root, "----", 'L');   // L = ----
    insertToTree(root, "-..-.", 'M');  // M = -..-.
    insertToTree(root, "-...-", 'N');  // N = -...-
    insertToTree(root, "-..-", 'O');   // O = -..-
    insertToTree(root, "-.-.", 'P');   // P = -.-.
    insertToTree(root, ".-.", 'Q');    // Q = .-.
    insertToTree(root, "..-.", 'R');   // R = ..-.
    insertToTree(root, ".-.-", 'S');   // S = .-.-
    insertToTree(root, "..--", 'T');  // T = ..-.- 
    insertToTree(root, "---", 'U');    // U = ---
    insertToTree(root, "...--", 'V');  // V = ...--
    insertToTree(root, ".--", 'W');   // W = .-- 
    insertToTree(root, "....-", 'X');  // X = ....-
    insertToTree(root, "--.", 'Y');    // Y = --.
    insertToTree(root, ".....", 'Z');  // Z = .....
    insertToTree(root, "-..--", ' ');  // SPASI = -..--
}

int main() {
    TreeNode* root = createNode('\0');
    initializeMorseTree(root);
    
    int choice;
    char input[100];
    char output[1000] = {0};
    
    printf("Program Konversi Kode Morse Custom\n");
    printf("==================================\n\n");
    
    do {
        printf("Menu:\n");
        printf("1. Terjemahkan dari teks ke kode Morse\n");
        printf("2. Terjemahkan dari kode Morse ke teks\n");
        printf("3. Tampilkan tabel kode Morse\n");
        printf("4. Visualisasikan tree\n");
        printf("5. Check Balance\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer
        
        switch (choice) {
            case 1: {
                printf("Masukkan teks (huruf kapital dan angka): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Menghapus newline
                
                output[0] = '\0';
                for (int i = 0; input[i] != '\0'; i++) {
                    char morse[10] = {0};
                    char path[10] = {0};
                    
                    if (isalpha(input[i])) {
                        charToMorse(root, toupper(input[i]), morse, path, 0);
                    } else if (isdigit(input[i])) {
                        charToMorse(root, input[i], morse, path, 0);
                    } else if (input[i] == ' ') {
                        charToMorse(root, ' ', morse, path, 0);
                    }
                    
                    if (morse[0] != '\0') {
                        strcat(output, morse);
                        strcat(output, " ");
                    }
                }
                
                printf("Hasil: %s\n\n", output);
                break;
            }
            case 2: {
                printf("Masukkan kode Morse (gunakan . dan - dan pisahkan dengan spasi): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Menghapus newline
                
                char* token = strtok(input, " ");
                output[0] = '\0';
                
                while (token != NULL) {
                    char c = morseToChar(root, token);
                    if (c != '\0') {
                        char str[2] = {c, '\0'};
                        strcat(output, str);
                    } else {
                        strcat(output, "?");  // Karakter tidak dikenali
                    }
                    token = strtok(NULL, " ");
                }
                
                printf("Hasil: %s\n\n", output);
                break;
            }
            case 3:
                printMorseTable(root);
                printf("\n");
                break;
            case 4:
                printf("\nVisualisasi Tree:\n");
                printf("================\n");
                printTree(root, 0);
                printf("\n");
                break;
            case 5: 
                if (isBalanced(root))
                printf("Tree Balance.\n\n");
                else
                printf("Tree tidak Balance.\n\n");
                break;     
            case 0:
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n\n");
        }
    } while (choice != 0);
    
    freeTree(root);
    return 0;
}