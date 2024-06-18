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

    int count = 1;  // ��ǰ�ڵ�
    for (size_t i = 0; i < node->children.size(); ++i)
    {
        count += nodeCount(node->children[i]);  // �ݹ�����ӽڵ������
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
        count += leafCount(node->children[i]);  // �ݹ�����ӽڵ��Ҷ������
    }
    return count;
}

void testTreeFunctions()
{
    // ����һ��ʾ����
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

    cout << "Node count: " << nodeCount(root) << endl;   // Ӧ����� 6
    cout << "Edge count: " << edgeCount(root) << endl;   // Ӧ����� 5
    cout << "Leaf count: " << leafCount(root) << endl;   // Ӧ����� 4

    // �����ڴ�
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

