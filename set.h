
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

#ifndef SET_H
#define SET_H




template <class T>
class Set
{
private:
        struct Node
        {
                T data;
                Node *next;
        };

        Node *head;

public:
                        Set             (void);
                        Set             (const Set<T> &s);
                        ~Set            (void);
                        
	string          to_string       (void) const;

        void            insert          (const T& value);
        void            remove          (const T& value);
        int             cardinality     (void) const;
        bool            empty           (void) const;
        bool            contains        (const T& value) const; 

        bool            operator==      (const Set<T> &s);
        bool            operator<=      (const Set<T> &s);
        Set<T>          operator+       (const Set<T> &s);
        Set<T>          operator&       (const Set<T> &s);
	Set<T>          operator-       (const Set<T> &s);

	friend std::ostream &operator<<(std::ostream &os, const Set<T> &myset) 
	{
		Node *ptr = myset.head;
		os << "[ ";
		while (ptr != nullptr) 
		{
			if (ptr->next != nullptr)
		        os << ptr->data << ", ";
		    	else
		        os << ptr->data << " ";
		    	ptr = ptr->next;
		}
		os << "]";
		return os;
	}
};
// #include "set.cpp"
#endif 
