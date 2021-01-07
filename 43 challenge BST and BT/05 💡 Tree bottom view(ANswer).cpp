X
Recursive Approach
This problem can be easily solved with the help of Hashing. The idea is to create an empty map where each key represents the relative horizontal distance of the node from the root node and value in the map maintains a pair containing node’s value and its level number. Then we do a pre-order traversal of the tree and if current level of a node is more than or equal to maximum level seen so far for the same horizontal distance as current node’s or current horizontal distance is seen for the first time, we update the value and the level for current horizontal distance in the map. For each node, we recurse for its left subtree by decreasing horizontal distance and increasing level by 1 and recurse for right subtree by increasing both level and horizontal distance by 1. tree
tree

C++ Code for Recursive Approach

void bottomViewHelper(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
    if(root == NULL) {
        return;
    }
    if(mp.find(dist) == mp.end() or level>=mp[dist].second) {
        mp[dist] = {root->data, level};
    }
    bottomViewHelper(root->left, level+1, dist-1, mp);
    bottomViewHelper(root->right, level+1, dist+1, mp);
}
void bottomView(node *root)
{
   map<int, pair<int, int> >mp;
   bottomViewHelper(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}
Java Code for Recursive Approach

public  void bottomView() {

        HashMap map = new HashMap<>();
        dfs(root, 0, 0, map);
        ArrayList keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);

        for (int key : keys) {
            System.out.print(map.get(key).data + " ");
        }

    // display(root);

    }

    public  void dfs(Node root, int vlevel, int ht, HashMap map) {

        if (root == null) {
            return;
        }


        if (!map.containsKey(vlevel)) {
            Pair np = new Pair();
            np.data = root.data;
            np.ht = ht;
            map.put(vlevel, np);
        } else {

             if (map.get(vlevel).ht <= ht) {
                map.get(vlevel).ht = ht;
                map.get(vlevel).data = root.data;
            }
        }

        dfs(root.left, vlevel - 1, ht + 1, map);
        dfs(root.right, vlevel + 1, ht + 1,  map);
    }

     class Pair {

        int ht;
        int data;
    }

Iterative Approach
Another approach can be using a queue.

The idea here is to observe that, if we try to see a tree from its bottom, then only the nodes which are at bottom in vertical order will be seen.
Start BFS from root. Maintain a queue of pairs comprising of node(Node *) type and vertical distance of node from root. Also, maintain a map which should store the node at a particular horizontal distance.
As you reach a node , simply update its vertical distance key value in the map with the data of this current node.
Only the last nodes of each vertical line will remain in the map while all other previous nodes will get overwritten.
Print the values in the map.
C++ Code for Iterative Approach

void bottomViewIterative(node *root)
{
    queue<pair<node *, int>> qu;
    qu.push({root, 0});
    map<int, int> mp;
    while (!qu.empty())
    {
        node *temp = qu.front().first;
        int dist = qu.front().second;
        qu.pop();
        mp[dist] = temp->data;
        if (temp->left)
        {
            qu.push({temp->left, dist - 1});
        }
        if (temp->right)
        {
            qu.push({temp->right, dist + 1});
        }
    }

    for (auto x : mp)
    {
        cout << x.second << " ";
    }
}

Java Code for Iterative Approach

static void bottomViewIterative(TreeNode root) {
    Queue<NodeIntPair> qu = new LinkedList<>();
    qu.add(new NodeIntPair(root, 0));
    Map<Integer, Integer> mp = new TreeMap<>();
    while (!qu.isEmpty()) {
        TreeNode temp = qu.peek().first;
        int dist = qu.peek().second;
        qu.remove();
        mp.put(dist, temp.data);
        if (temp.left != null) {
            qu.add(new NodeIntPair(temp.left, dist - 1));
        }
        if (temp.right != null) {
            qu.add(new NodeIntPair(temp.right, dist + 1));
        }
    }

    mp.forEach((k, v) -> System.out.print(v + " "));
}