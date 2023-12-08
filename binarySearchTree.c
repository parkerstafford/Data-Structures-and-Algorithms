using System;

class TreeNode
{
    public int Value;
    public TreeNode Left;
    public TreeNode Right;
    public TreeNode Parent;

    public TreeNode(int value)
    {
        Value = value;
        Left = null;
        Right = null;
        Parent = null;
    }
}

class BinarySearchTree
{
    public TreeNode Root;

    public TreeNode TreeSearch(TreeNode currentNode, int find)
    {
        if (currentNode == null)
        {
            return null;
        }
        if (currentNode.Value == find)
        {
            return currentNode;
        }

        if (find < currentNode.Value && currentNode.Left != null)
        {
            return TreeSearch(currentNode.Left, find);
        }

        if (find > currentNode.Value && currentNode.Right != null)
        {
            return TreeSearch(currentNode.Right, find);
        }

        return null;
    }

    public TreeNode FindTreeNode(int find)
    {
        if (Root == null)
        {
            return null;
        }
        return TreeSearch(Root, find);
    }

    public void InsertTreeNode(int add)
    {
        if (Root == null)
        {
            Root = new TreeNode(add);
        }
        else
        {
            InsertNode(Root, add);
        }
    }

    private void InsertNode(TreeNode treeNode, int add)
    {
        if (add == treeNode.Value)
        {
           
        }
        if (add < treeNode.Value)
        {
            if (treeNode.Left != null)
            {
                InsertNode(treeNode.Left, add);
            }
            else
            {
                TreeNode node = new TreeNode(add);
                treeNode.Left = node;
                node.Parent = treeNode;
            }
        }
        else
        {
            if (treeNode.Right != null)
            {
                InsertNode(treeNode.Right, add);
            }
            else
            {
                TreeNode node = new TreeNode(add);
                treeNode.Right = node;
                node.Parent = treeNode;
            }
        }
    }

    public void RemoveTreeNode(TreeNode node)
    {
        if (Root == null || node == null)
        {
            throw new InvalidOperationException("Invalid operation");
        }

        if (node.Left == null && node.Right == null)
        {
            RemoveLeafNode(node);
        }
        else if (node.Left == null || node.Right == null)
        {
            RemoveNodeWithOneChild(node);
        }
        else
        {
            RemoveNodeWithTwoChildren(node);
        }
    }

    private void RemoveLeafNode(TreeNode node)
    {
        if (node.Parent == null)
        {
            Root = null;
        }
        else if (node.Parent.Left == node)
        {
            node.Parent.Left = null;
        }
        else
        {
            node.Parent.Right = null;
        }
    }

    private void RemoveNodeWithOneChild(TreeNode node)
    {
        TreeNode child = (node.Left != null) ? node.Left : node.Right;
        child.Parent = node.Parent;

        if (node.Parent == null)
        {
            Root = child;
        }
        else if (node.Parent.Left == node)
        {
            node.Parent.Left = child;
        }
        else
        {
            node.Parent.Right = child;
        }
    }

    private void RemoveNodeWithTwoChildren(TreeNode node)
    {
        TreeNode successor = FindSuccessor(node);
        RemoveTreeNode(successor);

        successor.Parent = node.Parent;
        successor.Left = node.Left;
        successor.Right = node.Right;

        if (node.Parent == null)
        {
            Root = successor;
        }
        else if (node.Parent.Left == node)
        {
            node.Parent.Left = successor;
        }
        else
        {
            node.Parent.Right = successor;
        }

        if (node.Left != null)
        {
            node.Left.Parent = successor;
        }
        if (node.Right != null)
        {
            node.Right.Parent = successor;
        }
    }

    private TreeNode FindSuccessor(TreeNode node)
    {
        TreeNode successor = node.Right;
        while (successor.Left != null)
        {
            successor = successor.Left;
        }
        return successor;
    }
}
