Approach
For this problem we can encounter two kinds of nodes .

Nodes in the subtree rooted with target node.
Other nodes, may be an ancestor of target, or a node in some other subtree.
Finding the first type of nodes is easy to implement. Just traverse subtrees rooted with the target node and decrement k in recursive call. When the k becomes 0, print the node currently being traversed .
For the output nodes not lying in the subtree with the target node as the root, we must go through all ancestors. For every ancestor, we find its distance from target node, let the distance be d, now we go to other subtree (if target was found in left subtree, then we go to right subtree and vice versa) of the ancestor and find all nodes at k-d distance from the ancestor.
Java Code

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class BinaryTree {

    private class Node {
        int data;
        Node left;
        Node right;

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    private Node root;
    private int size;

    public int size() {
        return this.size;
    }

    public boolean isempty() {
        return this.size == 0;
    }

    public BinaryTree() {}

    ////////////////// New Constructor//////////

    public BinaryTree(int[] pre, int[] in) {
        // this.root = this.construct(pre, 0, pre.length - 1, in, 0, in.length -
        // 1);//for preorder
        this.root = this.construct(pre, in, 0, in.length - 1);// for
                                                                // postorder

    }

    private int search(int[] arr, int si, int ei, int data) {
        for (int i = si; i <= ei; i++) {
            if (arr[i] == data)
                return i;
        }
        return -1;
    }


    private static int preIndex = 0;

    private Node construct(int[] pre, int[] in, int isi, int iei) {
        if (isi > iei) {
            return null;
        }
        Node tNode = new Node(pre[preIndex++], null, null);

        if (isi == iei) {
            return tNode;
        }

        int inIndex = search(in, isi, iei, tNode.data);
        tNode.left = construct(pre, in, isi, inIndex-1);
        tNode.right = construct(pre, in, inIndex+1, iei);
        return tNode;

    }



    private void printKDistanceNodedown(Node node, int k,ArrayList<Integer> arr) {
        if(node == null || k<0) {
            return ;
        }
        if(k==0) {
//            System.out.println(node.data);
            arr.add(node.data);
            return;
        }
        printKDistanceNodedown(node.left, k-1, arr);
        printKDistanceNodedown(node.right, k-1, arr);

    }

    private int printkNodeDistance(Node node, int target,int k,ArrayList<Integer> arr) {
        if(node == null) {
            return -1;
        }
        if(node.data == target) {
            printKDistanceNodedown(node, k,arr);
            return 0;
        }
        int dl = printkNodeDistance(node.left, target, k, arr);
        if(dl!=-1) {
            if(dl+1==k) {
//                System.out.println(node.data);
                arr.add(node.data);
            }
            else {
                printKDistanceNodedown(node.right, k - dl - 2,arr);
            }
            return 1+dl;
        }
        int dr = printkNodeDistance(node.right, target, k, arr);
        if(dr!=-1) {
            if(dr+1 == k) {
//                System.out.println(node.data);
                arr.add(node.data);

            } else {
                printKDistanceNodedown(node.left, k - dr - 2,arr);
            }
            return 1+dr;
        }
        return -1;
    }

    public ArrayList<Integer> printkNodeDistance(int target, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        printkNodeDistance(this.root, target, k, arr);
        Collections.sort(arr);
        return arr;
    }


    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] pre = new int[n];
        int[] in = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i]=scn.nextInt();
        }
        for (int i = 0; i < n; i++) {
            in[i]=scn.nextInt();
        }

        BinaryTree bt = new BinaryTree(pre, in);
//        bt.display();
        int t=scn.nextInt();
        while(t-- > 0) {
            int tar = scn.nextInt();
            int k=scn.nextInt();
            ArrayList<Integer> a= bt.printkNodeDistance(tar, k);
            for(int i:a) {
                System.out.print(i+" ");
            }
            if(a.size()==0) {
                System.out.print(0);
            }
            System.out.println();
        }

    }
}
C++ Code

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *createTreeFromTrav(int *inOrder, int *preOrder, int s, int e)
{
    static  int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(preOrder[i]);

    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (inOrder[j] == preOrder[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(inOrder, preOrder, s, index - 1);
    root->right = createTreeFromTrav(inOrder, preOrder, index + 1, e);
    return root;
}

vector<int> v;

/* Recursive function to print all the nodes at distance k in the 
   tree (or subtree) rooted with given root. See  */
void printChildrenAtK(node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, print it
    if (k == 0)
    {
        // cout << root->data << " ";
        v.push_back(root->data);
        return;
    }

    printChildrenAtK(root->left, k - 1);
    printChildrenAtK(root->right, k - 1);
}

int printkdistanceNode(node *root, int target, int k)
{
    if (root == NULL)
        return -1;

    if (root->data == target)
    {
        printChildrenAtK(root, k);
        return 0;
    }

    // Recursive call for left subtree
    //distanceLeft is Distance of root's left child from target
    int distanceLeft = printkdistanceNode(root->left, target, k);

    // Check if target node was found in left subtree
    if (distanceLeft != -1)
    {
        // If root is at distance k from target, print root
        if (distanceLeft + 1 == k)
        {
            v.push_back(root->data);
        }

        // Else go to right subtree and print all k-distanceLeft-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printChildrenAtK(root->right, k - distanceLeft - 2);

        // Add 1 to the distance and return value for parent calls
        return 1 + distanceLeft;
    }

    //Try the same for right subtree as well
    int distanceRight = printkdistanceNode(root->right, target, k);
    if (distanceRight != -1)
    {
        if (distanceRight + 1 == k)
        {
            v.push_back(root->data);
        }
        else
            printChildrenAtK(root->left, k - distanceRight - 2);

        return 1 + distanceRight;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int inOrder[n], preOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int k, target;
        cin >> target >> k;
        v.clear();
        printkdistanceNode(root, target, k);
        if (v.size() == 0)
        {
            cout << "0";
        }
        else
        {
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}