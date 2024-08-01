#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
using namespace std;

struct BSTNode {
    int val;
    BSTNode* lchild;
    BSTNode* rchild;
    BSTNode(int val) {
        this->val = val;
        lchild = rchild = NULL;
    }
};
vector<int> inputRead() {        //读取数据
    vector<int> nums;
    string str, numStr;
    while (getline(cin, str)) {
        istringstream ss(str);
        while (ss >> numStr) {
            int num = atoi(numStr.c_str());
            nums.push_back(num);
        }
    }
    return nums;
}

BSTNode* insertNode(BSTNode* root, int val) {      //创建一个节点
    if (root == NULL) {
        root = new BSTNode(val);
    }
    else if (val < root->val) {
        root->lchild = insertNode(root->lchild, val);
    }
    else {
        root->rchild = insertNode(root->rchild, val);
    }
    return root;
}

BSTNode* createBST(vector<int>& nums) {           //创建二叉排序树
    BSTNode* root = NULL;
    for (int i = 1; i < nums.size() - 1; i++) {
        root = insertNode(root, nums[i]);
    }
    return root;
}

int searchBST(BSTNode* root, int key, int& count) {          //求二叉排序树查找次数
    if (root == NULL) {
        return 0;
    }
    if (root->val == key) {
        count++;
        return count;
    }
    if (root->val > key) {
        count++;
        return searchBST(root->lchild, key, count);
    }
    else {
        count++;
        return searchBST(root->rchild, key, count);
    }
}

void inorderTraversal(BSTNode* root) {      //中序遍历
    if (root != NULL) {
        inorderTraversal(root->lchild);
        cout << root->val << " ";
        inorderTraversal(root->rchild);
    }
}

//二分查找次数
int binarySearch(const vector<int>& inorderNums, int key) {
    int left = 0;
    int right = inorderNums.size() - 1;
    int count = 0;

    while (left <= right) {
        count++;
        int mid = left + (right - left) / 2;
        if (inorderNums[mid] == key) {
            return count;
        }
        else if (inorderNums[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = inputRead();  //读取数据
    BSTNode* root = createBST(nums); //创建二叉排序树
    int key = nums[nums.size() - 1];  //查找二叉排序树
    int count = 0;
    int BSTtimes = searchBST(root, key, count);
    cout << BSTtimes << endl;
    //中序遍历
    inorderTraversal(root);
    cout << endl;
    //中序遍历结果本质上是升序排序），直接升序复制到一个数组
    vector<int> inorderNums(nums.begin() + 1, nums.end() - 1);
    sort(inorderNums.begin(), inorderNums.end());
    //二分法查找
    int BStimes = binarySearch(inorderNums, key);
    cout << BStimes;
}