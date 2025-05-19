#ifndef HEADER_H
#define HEADER_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur untuk node pada tree
typedef struct TreeNode {
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Fungsi untuk membuat node baru
TreeNode* createNode(char character);

// Fungsi untuk memasukkan karakter ke dalam tree berdasarkan kode Morse
void insertToTree(TreeNode* root, const char* morse, char character);

// Fungsi untuk menerjemahkan kode Morse ke karakter
char morseToChar(TreeNode* root, const char* morse);

// Fungsi untuk menerjemahkan karakter ke kode Morse
void charToMorse(TreeNode* root, char character, char* result, char* path, int depth);

// Fungsi untuk membebaskan memory tree
void freeTree(TreeNode* root);

// Fungsi untuk mencetak tree 
void printTree(TreeNode* root, int level);

// Fungsi untuk mencetak tabel kode Morse
void printMorseTable(TreeNode* root);

// fungsi untuk mengecek apakah struktur kanan dan kiri sama (balancing)
int checkHeight(TreeNode* node, boolean* isBalanced);
boolean isBalanced(TreeNode* root);

#endif
