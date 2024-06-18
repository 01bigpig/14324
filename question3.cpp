#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    vector<Node *> children;
};

int nodeCount(Node *node)
{
    if (node == NULL)
        return 0;

    int count = 1;  // 当前节点
    for (size_t i = 0; i < node->children.size(); ++i)
    {
        count += nodeCount(node->children[i]);  // 递归计算子节点的数量
    }
    return count;
}

int edgeCount(Node *node)
{
    return nodeCount(node) - 1;
}

int leafCount(Node *node)
{
    if (node == NULL)
        return 0;

    if (node->children.empty())
        return 1;

    int count = 0;
    for (size_t i = 0; i < node->children.size(); ++i)
    {
        count += leafCount(node->children[i]);  // 递归计算子节点的叶子数量
    }
    return count;
}

void testTreeFunctions()
{
    // 创建一个示例树
    Node *root = new Node{1, {}};
    Node *child1 = new Node{2, {}};
    Node *child2 = new Node{3, {}};
    Node *child3 = new Node{4, {}};
    Node *child4 = new Node{5, {}};
    Node *child5 = new Node{6, {}};

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    child1->children.push_back(child4);
    child1->children.push_back(child5);

    cout << "Node count: " << nodeCount(root) << endl;   // 应该输出 6
    cout << "Edge count: " << edgeCount(root) << endl;   // 应该输出 5
    cout << "Leaf count: " << leafCount(root) << endl;   // 应该输出 4

    // 清理内存
    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete child5;
}

int main()
{
    testTreeFunctions();
    return 0;
}

