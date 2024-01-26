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
// Parameters: T item (item to be added)
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
	cur->next = cur->next->next
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
	return ( head = NULL );
}

//==============================================================
// contains
// Returns weather an element x is contained in the set s.
// Parameters: None
// Return Value: bool value
//==============================================================

template <class T>
bool		Set<T>::contain	( const T &value ) const
{
	Node *cur = head;
	
	while (cur != NULL)
	{
		if (cur->data = value)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}

//==============================================================
// operator== 
// 
//
//
//==============================================================

template <class T>
bool		Set<T>::operator==	( const set<T> &s )
{
	if (this->cardinality != s.cardinality())
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
		cur=cur->next
	}	
	return true;
}

//==============================================================
// operator<= 
//
//
//
//==============================================================

template <class T>
bool		Set<T>::operator<=	( const set<T> &s )
{
	if (this->cardinality > s.cardinality())
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
		cur=cur->next
	}	
	return true;
}

//==============================================================
// operator+
//
//
//
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
//
//
//
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
// operator+
//
//
//
//==============================================================
template <class T>
Set<T>		Set<T>::operator-	(const Set<T> &s)
{
    Set<T> difSet;

    Node* cur = head;
    while (cur != NULL) 
    {
        if (!.contains(cur->data)) 
        {
            difSet.insert(cur->data);
        }
        cur = cur->next;
    }

    return difSet;
}
//==============================================================
// to_string
//
//
//
//==============================================================
template <class T>
string		 Set<T>::to_string	( void ) const 
{
    string res;
    Node* cur = head;

    while (cur != NULL) 
    {
        result += to_string(cur->data); 
        if (cur->next != NULL) 
        {
            res += " "; 
        }
        cur = cur->next;
    }
    return res;
}





















