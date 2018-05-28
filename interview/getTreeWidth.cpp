/* 题目描述，得到树的最大宽度
 * struct TreeNode {
 *     TreeNode* children;
 * }
 * 思路： 树的层次遍历，在这里用vector实现队列
 */

int getTreeWidth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    vector<TreeNode*> vec;
    int qHead = 0, curHead = 1, curTail = 1; //队列头指针，当前入队的层头，层尾
    int maxWidth = 1, curMaxWidth = 0;
    int numChildren = 0;
    vec.push_back(root);
    while (vec[qHead]) {
        numChildren = vec[qHead] -> children.size();
        for (int i = 0; i < numChildren; i++) {
            vec.push_back(vec[qHead] -> children[i]);
            qTail++;
        }
        if (qHead == curHead - 1) {
            curMaxWidth = curTail - curTail + 1;
            if (curMaxWidth > maxWidth) {
                maxWidth = curMaxWidth;
            }
            curTail ++;
            curHead = curTail;
            qHead ++;
        } else if (qHead < curHead - 1) {
            qHead ++;
            continue;
        }
    }
    return maxWidth;
}
