/* Author: Isaac Asante
 * HackerRank URL for this exercise: https://www.hackerrank.com/challenges/tree-inorder-traversal/problem
 * Original video explanation: https://www.youtube.com/watch?v=67xonBF40Aw
 * Last verified on: March 28, 2021
 */

/* IMPORTANT:
 * This code is meant to be used as a solution on HackerRank (link above).
 * It is not meant to be executed as a standalone program.
 */

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}