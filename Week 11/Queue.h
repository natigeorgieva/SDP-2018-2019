#ifndef QUEUE_H
#define QUEUE_H

const int MAXSIZE = 20;
template <typename T = int>

class queue
{
public:

    queue(int = MAXSIZE);
    ~queue();
    queue(const queue&);
    queue& operator=(const queue&);

    bool empty() const;
    bool full() const;
    void push(const T&);
    void pop(T&);
    void head(T&) const;
    void print();
private:
    int front,
        rear,
        queue_size,
        queue_len;
    T *arr;

    void copyQueue(const queue&);
    void deleteQueue();
};


template <typename T>
queue<T>::queue(int size)
{
    if (size <= 0)
        queue_size = MAXSIZE;
    else
        queue_size = size;
    arr = new T[queue_size];
    assert(arr != NULL);
    front = 0;
    rear = 0;
    queue_len = 0;
}

template <typename T>
queue<T>::~queue()
{
    deleteQueue();
}

template <typename T>
queue<T>::queue(const queue<T>& r)
{
    copyQueue(r);
}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& r)
{
    if (this != &r)
    {
        deleteQueue();
        copyQueue(r);
    }
    return *this;
}

template <typename T>
void queue<T>::copyQueue(const queue<T>& r)
{
    queue_size = r.queue_size;
    arr = new T[queue_size];
    assert(arr != NULL);
    for (int i = 0; i < queue_size; i++)
        arr[i] = r.arr[i];
    queue_len = r.queue_len;
    front = r.front;
    rear = r.rear;
}

template <typename T>
void queue<T>::deleteQueue()
{
    delete [] arr;
}


template <typename T>
bool queue<T>::empty() const
{
    return queue_len == 0;
}


template <typename T>
bool queue<T>::full() const
{
    return queue_len == queue_size;
}

template <typename T>
void queue<T>::push(const T& x)
{
    if (!full())
    {
        arr[rear] = x;
        queue_len++;
        rear++;
        rear = rear % queue_size;
    }
    else
    {
        cout << "The queue is full.\n";
        exit(1);
    }
}

template <typename T>
void queue<T>::pop(T& x)
{
    if (!empty())
    {
        x = arr[front];
        queue_len--;
        front++;
        front = front % queue_size;
    }
    else
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
}

template <typename T>
void queue<T>::head(T& x) const
{
    if (!empty())
        x = arr[front];
    else
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
}

template <typename T>
void queue<T>::print()
{
    T x;
    while (!empty())
    {
        pop(x);
        cout << x << " ";
    }
    cout << endl;
}

ÎÏÀØÊÀ – ÑÂÚÐÇÀÍÎ ÏÐÅÄÑÒÀÂßÍÅ

template <typename T = int>
struct elem_q
{
    T inf;
    elem_q<T>* link;
};
template <typename T = int>
class queue
{
public:

    queue();
    ~queue();
    queue(const queue&);
    queue& operator=(const queue&);

    bool empty() const;
    void push(const T&);
    void pop(T&);
    void head(T&) const;
    void print();
    int length();
private:
    elem_q<T> *front,
           *rear;
    void copyQueue(const queue&);
    void deleteQueue();
};

template <typename T>
queue<T>::queue()
{
    front = rear = NULL;
}

template <typename T>
queue<T>::~queue()
{
    deleteQueue();
}

template <typename T>
queue<T>::queue(const queue<T>& r)
{
    copyQueue(r);
}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& r)
{
    if (this != &r)
    {
        deleteQueue();
        copyQueue(r);
    }
    return *this;
}

template <typename T>
void queue<T>::copyQueue(const queue<T>& r)
{
    front = rear = NULL;
    elem_q<T> *p = r.front;
    while (p)
    {
        push(p->inf);
        p = p->link;
    }
}

template <typename T>
void queue<T>::deleteQueue()
{
    T x;
    while (!empty())
        pop(x);
}

template <typename T>
bool queue<T>::empty() const
{
    return rear == NULL;
}


template <typename T>
void queue<T>::push(const T& x)
{
    elem_q<T> *p = new elem_q<T>;
    assert(p != NULL);
    p->inf = x;
    p->link = NULL;
    if (rear)
        rear->link = p;
    else
        front = p;
    rear = p;
}

template <typename T>
void queue<T>::pop(T& x)
{
    if (empty())
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else
    {
        elem_q<T> *p = front;
        x = p->inf;
        if (p == rear)
            rear = front = NULL;
        else
            front = p->link;
        delete p;
    }
}


template <typename T>
void queue<T>::head(T& x) const
{
    if (empty())
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else
        x = front->inf;
}


template <typename T>
void queue<T>::print()
{
    T x;
    while (!empty())
    {
        pop(x);
        cout << x << " ";
    }
    cout << endl;
}


template <typename T>
int queue<T>::length()
{
    T x;
    int n = 0;
    while (!empty())
    {
        pop(x);
        n++;
    }
    return n;
}



#endif // QUEUE_H
