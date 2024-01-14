#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an employee in HR management system
struct Employee {
    int empID;
    char name[50];
    // Add other employee details as needed
};

// Define a structure for a binary tree node
struct TreeNode {
    struct Employee data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new employee node
struct TreeNode* createEmployeeNode(int empID, const char* name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data.empID = empID;
    strcpy(newNode->data.name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an employee into the binary tree
struct TreeNode* insertEmployee(struct TreeNode* root, int empID, const char* name) {
    if (root == NULL) {
        return createEmployeeNode(empID, name);
    }

    // Simple comparison, assuming empID is the key
    if (empID < root->data.empID) {
        root->left = insertEmployee(root->left, empID, name);
    } else if (empID > root->data.empID) {
        root->right = insertEmployee(root->right, empID, name);
    }

    return root;
}

// Function to create a binary tree using level order (BFS)
struct TreeNode* createTreeLevelOrder(int empIDs[], const char* names[], int n) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEmployee(root, empIDs[i], names[i]);
    }
    return root;
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
        inOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
    }
}

int main() {
    // Domain: HR Management System
    int empIDs[] = {101, 102, 103, 104, 105};
    const char* names[] = {"Annmary", "Sona", "Rojal", "Manju", "Ancy"};

    // Creating a binary tree using level order
    struct TreeNode* rootLevelOrder = createTreeLevelOrder(empIDs, names, 5);

    // Performing pre-order traversal
    printf("Pre-order Traversal:\n");
    preOrderTraversal(rootLevelOrder);

    // Performing in-order traversal
    printf("\nIn-order Traversal:\n");
    inOrderTraversal(rootLevelOrder);

    // Performing post-order traversal
    printf("\nPost-order Traversal:\n");
    postOrderTraversal(rootLevelOrder);

    return 0;
}

