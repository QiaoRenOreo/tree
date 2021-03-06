// Fig. 19.22: Tree.h
// Tree class-template definition.
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
#include <iomanip>
// Tree class-template definition
template< typename NODETYPE > class Tree
{
	public:
		// constructor
		Tree()
		: rootPtr( nullptr ) { /* empty body */ }

		// insert node in Tree
		void insertNode( const NODETYPE &value )
		{
			insertNodeHelper( &rootPtr, value );
		} // end function insertNode

		// begin preorder traversal of Tree
		void preOrderTraversal() const
		{
			preOrderHelper( rootPtr );
		} // end function preOrderTraversal

		// begin inorder traversal of Tree
		void inOrderTraversal() const
		{
			inOrderHelper( rootPtr );
		} // end function inOrderTraversal

		// begin postorder traversal of Tree
		void postOrderTraversal() const
		{
			postOrderHelper( rootPtr );
		} // end function postOrderTraversal

		void search( const NODETYPE value )
		{
			searchHelper(rootPtr, value );
		} // end function insertNode

		void RightFirstInOrderTraversal()
		{
			RightFirstinOrderHelper( rootPtr,0 );
		}

		void RightFirstPreOrderTraversal() const
		{
			RightFirstPreOrderHelper( rootPtr );
		} // end function preOrderTraversal

		void RightFirstPostOrderTraversal()const
		{
			RightFirstPostOrderHelper( rootPtr );
		}
	private:
		TreeNode< NODETYPE > *rootPtr;

		// utility function called by insertNode; receives a pointer
		// to a pointer so that the function can modify pointer's value
		void insertNodeHelper(
			TreeNode < NODETYPE>**ptr, const NODETYPE &value )
		{
			// subtree is empty; create new TreeNode containing value
			if ( *ptr== nullptr )
				*ptr= new TreeNode< NODETYPE >( value );
			else // subtree is not empty
			{
				// data to insert is less than data in current node
				if ( value < ( *ptr)->data )
					insertNodeHelper( &( (*ptr )->leftPtr ), value );
				else
				{
					// data to insert is greater than data in current node
					if ( value > (*ptr )->data )
						insertNodeHelper( &( ( *ptr)->rightPtr ), value );
					else // duplicate data value ignored
						std::cout << value << " dup" << std::endl;
				} // end else
			} // end else
		} // end function insertNodeHelper

		// utility function to perform preorder traversal of Tree
		void preOrderHelper( TreeNode< NODETYPE > *ptr ) const
		{
			if ( ptr != nullptr )
			{
				std::cout <<ptr->data << ' '; // process node
				preOrderHelper( ptr->leftPtr ); // traverse left subtree
				preOrderHelper( ptr->rightPtr ); // traverse right subtree
			} // end if
		} // end function preOrderHelper

		void RightFirstPreOrderHelper( TreeNode< NODETYPE > *ptr )const
		{
			if ( ptr != nullptr )
			{
				std::cout <<ptr->data << ' '; // process node
				RightFirstPreOrderHelper( ptr->rightPtr ); // traverse left subtree
				RightFirstPreOrderHelper( ptr->leftPtr ); // traverse right subtree
			} // end if
		}

		// utility function to perform inorder traversal of Tree
		void inOrderHelper ( TreeNode< NODETYPE > *ptr ) const
		{
			if ( ptr != nullptr )
			{
				inOrderHelper( ptr->leftPtr ); // traverse left subtree
				std::cout << ptr->data << ' '; // process node
				inOrderHelper( ptr->rightPtr ); // traverse right subtree
			} // end if
		} // end function inOrderHelper

		void RightFirstinOrderHelper ( TreeNode< NODETYPE > *ptr, int indent)
		{
			if ( ptr != nullptr )
			{
				indent =indent+1;
				RightFirstinOrderHelper( ptr->rightPtr, indent); // traverse left subtree
				std::cout <<std::setw(4*indent)<< ptr->data<<'\n';//

				RightFirstinOrderHelper( ptr->leftPtr, indent ); // traverse right subtree
				indent =indent-1;

			} // end if
		}
		// utility function to perform postorder traversal of Tree
		void postOrderHelper( TreeNode< NODETYPE > *ptr ) const
		{
			if ( ptr != nullptr )
			{
				postOrderHelper( ptr->leftPtr ); // traverse left subtree
				postOrderHelper( ptr->rightPtr ); // traverse right subtree
				std::cout << ptr->data << ' '; // process node
			} // end if
		} // end function postOrderHelper

		void RightFirstPostOrderHelper( TreeNode< NODETYPE > *ptr ) const
		{
			if ( ptr != nullptr )
			{
				RightFirstPostOrderHelper( ptr->rightPtr ); // traverse left subtree
				RightFirstPostOrderHelper( ptr->leftPtr ); // traverse right subtree
				std::cout << ptr->data << ' '; // process node
			} // end if
		} // end function postOrderHelper

		TreeNode< NODETYPE > * searchHelper(TreeNode< NODETYPE > *ptr,const NODETYPE value)// return a pointer
		{
			TreeNode< NODETYPE > *ReturnedPtr;
			ReturnedPtr=nullptr;//0 means the search key is not found, 1 means found.
			if ( ptr== nullptr )
			{
				std::cout<<"the tree is empty \n";
			}
			else // subtree is not empty
			{
				if ( value < ptr->data )
				{
					if ((ptr->leftPtr) !=nullptr )
					{
						searchHelper( ptr->leftPtr, value );
					}
					else
					{
						std::cout<<"the value "<<value<<" does not exist in the tree\n";
					}
				}
				else if (value > ptr->data)
				{
					if ((ptr->rightPtr) !=nullptr )
					{
						searchHelper( ptr->rightPtr, value );
					}
					else
					{
						std::cout<<"the value "<<value<<" does not exist in the tree\n";
					}
				}
				else  //value == ptr->data
				{
					ReturnedPtr=ptr;
					std::cout<<"the pointer of value "<<value<<" is "<<ReturnedPtr;
				}
			}
			return ReturnedPtr;
		}
}; // end class Tree

#endif
