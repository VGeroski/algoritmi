/**
 * Given the root of a binary tree and an integer targetSum, return the number of paths
 * where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf,
 * but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 */

#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *node,
        long long currentSum,
        int targetSum,
        unordered_map<long long, int> &prefixSumCount)
{
    if (!node)
        return 0;

    // Azuriramo trenutnu prefiksnu sumu dodajuci vrednost iz cvora
    currentSum += node->val;

    // proveravamo da li postoji prethodna prefiksna suma takva da
    // currentPrefixSum - previousPrefixSum = targetSum
    // to znaci da je prethodna_prefiks_suma = currentPrefixSum - targetSum
    int paths = prefixSumCount[currentSum - targetSum];
    // Dodajemo trenutnu sumu u mapu
    prefixSumCount[currentSum]++;

    paths += dfs(node->left, currentSum, targetSum, prefixSumCount);
    paths += dfs(node->right, currentSum, targetSum, prefixSumCount);

    // Backtracking, izbacujemo trenutnu sumu iz mape
    // ne zelimo da imamo tu sumu u drugim cvorovima
    prefixSumCount[currentSum]--;

    return paths;
}

int pathSum(TreeNode *root, int targetSum)
{
    // <prefix sum value : count of occurrences>
    unordered_map<long long, int> prefixSumCount;
    prefixSumCount[0] = 1;

    return dfs(root, 0, targetSum, prefixSumCount);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    cout << "Test 1 (target = 8): "
         << pathSum(root, 8) << " (expected 3)" << endl;

    cout << "Test 2 (target = 18): "
         << pathSum(root, 18) << " (expected 3)" << endl;

    cout << "Test 3 (target = 10): "
         << pathSum(root, 10) << " (expected 1)" << endl;

    cout << "Test 4 (target = 100): "
         << pathSum(root, 100) << " (expected 0)" << endl;

    return 0;
}