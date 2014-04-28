/*
 * =====================================================================================
 *
 *       Filename:  tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2014 11:26:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
struct node
{
    int val;
    node * left;
    node * right;
    node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void tree(node *head)
{

    vector< node * > store;
    if( head->left != NULL )
    {
        cout<<head->left->val<<endl;
        store.push_back(head->left);
    }

    if( head ->right != NULL )
    {
        cout<<head->right->val<<endl;
        store.push_back(head->right);
    }

    for( int i = 0; i < store.size() ; i++ )
    {
        tree(store[i]);
    }
}


int main(int argc, char *argv[])
{
    node * head = new node(0);
    head->left = new node(1);
    head->right = new node(2);
    head->left->left = new node(3);
    head->left->right = new node(4);
    head->right->left = new node(5);
    head->right->right = new node(6);
    head->left->left->left = new node(7);
    head->left->right->right = new node(8);
    head->right->left->right = new node(9);
    tree(head);
}
