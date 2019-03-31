/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

public class Solution {
    TreeNode maxNode = null;
    double maxVal = -Float.MAX_VALUE;
    
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    public TreeNode findSubtree2(TreeNode root) {
        helper(root);
        return maxNode;
    }
    
    private int[] helper(TreeNode node) {
        if(node == null)
            return new int[]{0, 0};
        
        int[] left = helper(node.left);
        int[] right = helper(node.right);
        int sum = left[0] + node.val + right[0];
        int count = left[1] + right[1] + 1;
        
        if((float)sum / count > maxVal) {
            maxNode = node;
            maxVal = (float)sum / count;
        }
        
        return new int[]{sum, count};
    }
}
