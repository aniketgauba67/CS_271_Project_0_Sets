#include "set.h"
#include <string>
#include <sstream>
using namespace std;

//========================================================
// Set
// Default constructor creating an empty set.
// Parameters: None
// Return Value: None
//========================================================

template <class T>
		Set<T>::Set		( void )
{
	head = NULL;
}

//==============================================================
// Set
// Copy constructor to create a new set from an existing one.
// Parameters: const Set<T> &s
// Return Value: None
//==============================================================

template <class T>
		Set<T>::Set		( const Set<T> &s )
{
	Node *pre = NULL;
	Node *cur = s.head;
	
	while ( cur != NULL )
	{
		Node *newNode = new Node;
		newNode->data = cur->data;
		newNode->next = NULL;
    	
		if ( pre == NULL )
		{
			head = newNode;
		}
		else
		{
			pre->next = newNode;
		}
		pre = newNode;
		cur = cur->next;
	}
}

//==============================================================
// ~Set
// Destructor to clean up the memory of the set.
// Parameters: None
// Return Value: None
//==============================================================

template <class T>
		Set<T>::~Set		( void )
{
	Node *cur = head;
	Node *next = NULL;
	
	while (cur != NULL)
	{
	next = cur->next; 
	delete cur; 
	cur = next; 
	}	
	head = NULL;
}

//==============================================================
// insert
// Adds a new Elements at the head of the list.
// Parameters: T  item(item to be added)
// Return Value: None
//==============================================================

template <class T>
void		Set<T>::insert		( const T &value )
{
	Node *cur = head;
	while ( cur != NULL )
	{
		if (cur->data == value)
		{
			return;
		}
		cur = cur->next;
	}
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

//==============================================================
// remove
// Removes an element x from the set s.
// Parameters: 
// Return Value: None
//==============================================================

template <class T>
void		Set<T>::remove		( const T &value )
{
	if ( head == NULL )
	{
		return;
	}
	
	if ( head->data == value )
	{
	Node *temp = head;
	head = head->next;
	delete temp;
	return;
	}
	
	Node *cur = head;
	while (cur->next != NULL && cur->next->data != value)
	{
	cur = cur->next;
	}
	
	if (cur->next != NULL)
	{
	Node *temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
	}
}

//==============================================================
// cardinality
// Returns the cardinality of set s.
// Parameters: None
// Return Value: cardinality of set
//==============================================================

template <class T>
int		Set<T>::cardinality	( void ) const
{
	int count = 0;
	Node *cur = head;
	
	while ( cur != NULL)
	{
		count++;
		cur=cur->next;
	}
	return count;
}

//==============================================================
// empty
// Returns true or false whether s is the empty set.
// Parameters: None
// Return Value: bool value
//==============================================================

template <class T>
bool		Set<T>::empty		( void ) const
{
	return ( head == NULL );
}

//==============================================================
// contains
// Returns weather an element x is contained in the set s.
// Parameters: None
// Return Value: bool value
//==============================================================

template <class T>
bool		Set<T>::contains	( const T &value ) const
{
	Node *cur = head;
	
	while (cur != NULL)
	{
		if (cur->data == value)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}

//==============================================================
// operator==
// Checks if the current set is equal to another set 's'.
//
// Parameters:
//   s - The set to compare with.
//
// Return Value:
//   Returns 'true' if the current set is equal to set 's', 
//   meaning they contain the same elements; otherwise, returns 'false'.
//==============================================================

template <class T>
bool		Set<T>::operator==	( const Set<T> &s )
{
	if (this->cardinality() != s.cardinality())
	{
		return false;
	}
	
	Node *cur = head;
	while (cur != NULL)
	{
		if (!s.contains(cur->data))
		{
			return false;
		}
		cur=cur->next;
	}	
	return true;
}

//==============================================================
// operator<=
// Checks if the current set is a subset of or equal to another set 's'.
//
// Parameters:
//   s - The set to compare with.
//
// Return Value:
//   Returns 'true' if the current set is a subset of or equal to set 's', 
//   meaning all elements of the current set are also in 's'; otherwise, returns 'false'.
//==============================================================

template <class T>
bool		Set<T>::operator<=	( const Set<T> &s )
{
	if (this->cardinality() > s.cardinality())
	{
		return false;
	}
	
	Node *cur = head;
	while (cur != NULL)
	{
		if (!s.contains(cur->data))
		{
			return false;
		}
		cur=cur->next;
	}	
	return true;
}

//==============================================================
// operator+
// Performs the union operation between the current set and another set 's'.
//
// Parameters:
//   s - The set to perform the union with.
//
// Return Value:
//   Returns a new set containing all unique elements from both the current set and 's'.
//==============================================================

template <class T>
Set<T>		Set<T>::operator+	(const Set<T> &s) 
{
    Set<T> uniSet;

    Node* cur = s.head;
    while (cur != NULL) 
    {
        uniSet.insert(cur->data);
        cur = cur->next;
    }

    cur = head;
    while (cur != NULL) 
    {
        uniSet.insert(cur->data);
        cur = cur->next;
    }

    return uniSet;
}

//==============================================================
// operator&
// Performs the intersection operation between the current set and another set 's'.
//
// Parameters:
//   s - The set to perform the intersection with.
//
// Return Value:
//   Returns a new set containing elements that are common to both the current set and 's'.
//==============================================================

template <class T>
Set<T>		Set<T>::operator&	(const Set<T> &s) 
{
    Set<T> intersecSet;

    Node* cur = head;
    while (cur != NULL) 
    {
        if (s.contains(cur->data)) 
        {
        
            intersecSet.insert(cur->data);
        }
        cur = cur->next;
    }

    return intersecSet;
}

//==============================================================
// operator-
// Performs the set difference operation between the current set and another set 's'.
//
// Parameters:
//   s - The set to perform the difference with.
//
// Return Value:
//   Returns a new set containing elements that are in the current set but not in 's'.
//==============================================================

template <class T>
Set<T>		Set<T>::operator-		(const Set<T> &s)
{
    Set<T> difSet;

    Node* cur = head;
    while (cur != NULL) 
    {
        if (!s.contains(cur->data)) 
        {
            difSet.insert(cur->data);
        }
        cur = cur->next;
    }

    return difSet;
}

//==============================================================
// to_string
// Converts the elements of the set into a string representation.
//
// Return Value:
//   Returns a string containing a space-separated list of elements in the set.
//==============================================================

template<class T>
string Set<T>::to_string() const 
{
    stringstream result;
    Node *cur = head;
    while (cur != NULL) 
    {
        if (cur->next)
        	result << cur-> data << " ";
        else
        	result << cur->data;
        cur = cur->next;

    }

    return result.str();
}






















