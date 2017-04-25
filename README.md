# Linked List

*** Tested with Valgrind, no memory leak ***

```
linkedlist<int> ll1;
ll1.push_back(42);  // LL = [42]
ll1.push_back(7);   // LL = [42 7]
ll1.push_front(3);  // LL = [3 42 7]
ll1.push_back(21);  // LL = [3 42 7 21]
ll1.push_front(13); // LL = [13 3 42 7 21]
ll1.push_front(1);  // LL = [1 13 3 42 7 21]

cout << ll1 << "\n";

/*******************************************/

linkedlist<int> ll2;
ll2.insert_sorted(42);  // LL = [42]
ll2.insert_sorted(121); // LL = [42 121]
ll2.insert_sorted(50);  // LL = [42 50 121]
ll2.insert_sorted(96);  // LL = [42 50 96 121]
ll2.insert_sorted(128); // LL = [42 50 96 121 128]

cout << ll2 << "\n";

/*******************************************/

linkedlist<int> ll3;
ll3.push_back(3);
ll3.push_back(2);
ll3.push_back(1);
ll3.push_front(4);
ll3.push_front(5);
ll3.push_front(6);

ll3.pop_at(6); // Works!
cout << ll3 << "\n";
```
