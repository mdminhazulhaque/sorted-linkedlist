#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>

using std::ostream;

#define Ptr Node<Data>

template<class Data>
struct Node
{
    Data data;
    Ptr *next;
};

template<class Data>
class linkedlist
{
private:
    Ptr *head;

public:
    linkedlist()
    {
        head = NULL;
    }

    ~linkedlist()
    {
        if(head != NULL)
        {
            Ptr *curr = head;
            Ptr *next;

            while(curr != NULL)
            {
                next = curr->next;
                delete curr;
                curr = next;
            }

            head = NULL;
        }
    }

    Data& front()
    {
        return head->data;
    }

    Data& back()
    {
        Ptr *curr = head;
        Ptr *prev;

        while(curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        return prev->data;
    }

    void push_front(const Data& d)
    {
        Ptr *first = new Ptr;
        first->data = d;
        first->next = head;
        head = first;
    }

    void push_back(const Data &d)
    {
        if(head == NULL)
        {
            Ptr *first = new Ptr;
            first->data = d;
            first->next = NULL;
            head = first;
        }
        else
        {
            Ptr *curr = head;

            while(curr->next != NULL)
            {
                curr = curr->next;
            }

            Ptr *temp = new Ptr;
            temp->data = d;
            temp->next = NULL;

            curr->next = temp;
        }
    }

    void insert_sorted(const Data &d)
    {
        if(head == NULL)
        {
            Ptr *first = new Ptr;
            first->data = d;
            first->next = head;
            head = first;
            return;
        }
        else
        {
            Ptr *curr = head;
            Ptr *prev;

            while(curr != NULL)
            {
                if(d < curr->data)
                {
                    break;
                }

                prev = curr;
                curr = curr->next;
            }

            Ptr *toInsert = new Ptr;
            toInsert->next = prev->next;
            prev->next = toInsert;
            toInsert->data = d;
        }
    }

    void pop_front()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            Ptr *newHead = head->next;
            delete head;
            head = newHead;
        }
    }

    void pop_back()
    {
        if(head == NULL)
        {
            return;
        }
        else
        {
            Ptr *curr = head;
            Ptr *tail;

            while(curr->next != NULL)
            {
                tail = curr;
                curr = curr->next;
            }

            tail->next = NULL;
            delete curr;
        }
    }

    void pop_at(const Data &d)
    {
        if(head == NULL)
        {
            return;
        }
        else
        {
            Ptr *curr = head;
            Ptr *prev = NULL;

            while(curr->next != NULL)
            {
                if(curr->data == d)
                    break;
                prev = curr;
            }

            prev->next = curr->next;
            delete curr;
        }
    }

    /** Print using cout **/
    friend ostream& operator << (ostream& out, const linkedlist<Data> &ll)
    {
        if(ll.head == NULL)
        {
            return out;
        }
        else
        {
            Ptr *curr = ll.head;

            while(curr != NULL)
            {
                out << curr->data << " ";
                curr = curr->next;
            }

            return out;
        }
    }
};

#endif // LINKEDLIST_H
