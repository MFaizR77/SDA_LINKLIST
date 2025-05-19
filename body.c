#include "header.h"
#include <stdio.h>


TreeNode* createNode(char character) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void insertToTree(TreeNode* root, const char* morse, char character) {
    TreeNode* current = root;
    
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            if (current->left == NULL) {
                current->left = createNode('\0');
            }
            current = current->left;
        } else if (morse[i] == '-') {
            if (current->right == NULL) {
                current->right = createNode('\0');
            }
            current = current->right;
        }
    }
    
    current->character = character;
}


char morseToChar(TreeNode* root, const char* morse) {
    TreeNode* current = root;
    
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            if (current->left == NULL) {
                return '\0';
            }
            current = current->left;
        } else if (morse[i] == '-') {
            if (current->right == NULL) {
                return '\0';
            }
            current = current->right;
        } else {
            return '\0';  
        }
    }
    
    return current->character;
}


void charToMorse(TreeNode* root, char character, char* result, char* path, int depth) {
    if (root == NULL) {
        return;
    }
    
    if (root->character == character) {
        path[depth] = '\0';
        strcpy(result, path);
        return;
    }
    
    path[depth] = '.';
    charToMorse(root->left, character, result, path, depth + 1);
    
    path[depth] = '-';
    charToMorse(root->right, character, result, path, depth + 1);
}


void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


void printTree(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    
    printTree(root->right, level + 1);
    
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    
    if (root->character != '\0') {
        printf("%c\n", root->character);
    } else {
        printf("*\n");
    }
    
    printTree(root->left, level + 1);
}


void printMorseTable(TreeNode* root) {
    printf("\nTabel Kode Morse:\n");
    printf("==================\n");
    
    for (int i = 0; i <= 9; i++) {
        char morse[10] = {0};
        char path[10] = {0};
        charToMorse(root, '0' + i, morse, path, 0);
        printf("%d: %s\n", i, morse);
    }
    
    printf("\n");
    
    for (char c = 'A'; c <= 'Z'; c++) {
        char morse[10] = {0};
        char path[10] = {0};
        charToMorse(root, c, morse, path, 0);
        printf("%c: %s\n", c, morse);
    }
    
    char morse[10] = {0};
    char path[10] = {0};
    charToMorse(root, ' ', morse, path, 0);
    printf("SPASI: %s\n", morse);
}

int checkHeight(TreeNode* node, boolean* isBalanced) {
    if (node == NULL) return 0;

    int leftHeight = checkHeight(node->left, isBalanced);
    int rightHeight = checkHeight(node->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1) {
        *isBalanced = false;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


boolean isBalanced(TreeNode* root) {
    boolean balanced = true;
    checkHeight(root, &balanced);
    return balanced;
}

