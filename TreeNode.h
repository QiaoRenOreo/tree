// Fig. 19.21: TreeNode.h
// TreeNode class-template definition.
#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template< typename NODETYPE > class Tree;//a prototype

// TreeNode class-template definition
template< typename NODETYPE >
class TreeNode
{
	friend class Tree< NODETYPE >;
	public:
		// constructor
		TreeNode( const NODETYPE &d )
		:	leftPtr( nullptr ), // pointer to left subtree
			data( d ), // tree node data
			rightPtr( nullptr ) // pointer to right substree
		{
			// empty body
		} // end TreeNode constructor

		// return copy of node's data
		NODETYPE getData() const
		{
			return data;
		} // end getData function
	private:
		TreeNode< NODETYPE > *leftPtr; // pointer to left subtree
		NODETYPE data;
		TreeNode< NODETYPE > *rightPtr; // pointer to right subtree
}; // end class TreeNode

#endif
