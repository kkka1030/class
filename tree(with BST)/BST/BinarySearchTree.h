#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <memory>
#include "dsexceptions.h"
#include <algorithm>
using namespace std;       

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return *findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return *findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }


  protected:
    struct BinaryNode
    {
        std::unique_ptr<Comparable> element;
        BinaryNode *left;
        BinaryNode *right;
        int height;
        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
          : element{std::make_unique<Comparable>(theElement)}, left{ lt }, right{ rt }, height{ 0 } {
            updateHeight();
            }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
          : element{std::make_unique<Comparable>(std::move(theElement))}, left{ lt }, right{ rt }, height{ 0 } 
        {
        updateHeight();
        }
        
        void updateHeight() 
        {
        int leftHeight = (left != nullptr) ? left->height : -1;   
        int rightHeight = (right != nullptr) ? right->height : -1; 
        height = std::max(leftHeight, rightHeight) + 1;           
        }
    };

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < *t->element )
            insert( x, t->left );
        else if( *t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
        t->updateHeight();
        balance(t);
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ std::move( x ), nullptr, nullptr };
        else if( x < *t->element )
            insert( std::move( x ), t->left );
        else if( *t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing
        t->updateHeight();
        balance(t);
    }
    
    int height(BinaryNode *t) const {
    return t == nullptr ? -1 : t->height;
    }
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    /*
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }
    */
    // 左单旋转
    void rotateWithLeftChild(BinaryNode* &k2) 
    {
        BinaryNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->updateHeight();  
        k1->updateHeight();
        k2 = k1;
    }

    // 右单旋转
    void rotateWithRightChild(BinaryNode *&k2) 
    {
        BinaryNode* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->updateHeight();  
        k1->updateHeight();
        k2 = k1;
    }

    // 左右双旋转
    void doubleWithLeftChild(BinaryNode *&k3) 
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    // 右左双旋转
    void doubleWithRightChild(BinaryNode *&k3) 
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }
    
    //单个节点平衡
    void balance(BinaryNode* &t) 
    {
    if (t == nullptr)  
        return;

    if (height((t->left)) - height((t->right)) > 1) 
    {  // 左子树过重
        if (height((t->left->left)) >= height(t->left->right))  
            rotateWithLeftChild(t);
        else  
            doubleWithLeftChild(t);
    } 
    else if (height(t->right) - height(t->left) > 1) 
    {  // 右子树过重
        if (height(t->right->right) >= height(t->right->left))  
            rotateWithRightChild(t);
        else  
            doubleWithRightChild(t);
    }
    }
    
    //整个树进行平衡
    void superbalance(BinaryNode* &t) 
    {
        if (t == nullptr) return;  
        superbalance(t->left);
        superbalance(t->right);
        balance(t);
    }
    
    
    //找到这个树里最小的节点，删除它，并返回它
    BinaryNode* detachMin(BinaryNode*& t) 
    {
    if (t == nullptr)
    {
        return nullptr;
    }
    BinaryNode* parent = nullptr;
    BinaryNode* current = t;
    
    while (current->left != nullptr) 
    {
        parent = current;
        current = current->left;
    }

    if (parent != nullptr) 
    {
        parent->left = current->right; 
    }
    else 
    {
        t = current->right; 
    }
    
    current->left = nullptr;
    current->right = nullptr;
    return current; 
    }

    void remove(const Comparable &x, BinaryNode *&t) {
    if (t == nullptr) 
    {
        return; 
    }

    if (x < *t->element) 
    {
        remove(x, t->left);
    } 
    else if (*t->element < x) 
    {
        remove(x, t->right);
    } 
    else if (t->left != nullptr && t->right != nullptr) 
    {
        BinaryNode *minNode = findMin(t->right);
        std::swap(t->element, minNode->element);  
        remove(*minNode->element, t->right);
    } 
    else 
    {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }

    
    if (t != nullptr) {
        t->updateHeight();
    }

    balance(t);
}

    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < *t->element )
            return contains( x, t->left );
        else if( *t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << *t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinaryNode{ *t->element, clone( t->left ), clone( t->right ) };
    }
};

#endif
