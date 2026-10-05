#include "SinglyLinkedList.h"

#include <iostream>

int main() {
    std::cout << "=== Code-Together 7: Farr's Ice Cream Ticket Queue ===\n\n";

    // ! DISCUSSION: Arrays vs linked lists — when to use which?
    //   Imagine Farr's Ice Cream on a busy Friday night. Customers grab
    //   a ticket number and wait in line.
    //   - An array would work, but serving someone (remove from the front)
    //     means shifting EVERY remaining ticket down one slot — O(n)
    //   - A linked list just moves the head pointer — O(1)
    //   - Arrays: fast random access (who has ticket #5?), but expensive
    //     insert/remove at front (shift everything)
    //   - Linked lists: fast insert/remove at front (just move pointers),
    //     but no random access (must walk to find ticket #5)

    SinglyLinkedList line;

    // --- 1. Customers arrive (push_back) ---
    std::cout << "--- 1. Customers arriving at Farr's ---\n";

    // TODO 1: Three customers arrive and join the BACK of the line.
    //         Add tickets 101, 102 and 103 with push_back, printing a line
    //         like "push_back(101) -- Ticket #101 arrives" before each.

    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    // ! DISCUSSION: push_back makes sense here.
    //   - New customers join the END of the line, not the front
    //   - First come, first served

    // --- 2. A VIP cuts to the front (push_front) ---
    std::cout << "--- 2. VIP cuts to the front ---\n";

    // TODO 2: A VIP cuts to the FRONT. Add ticket 200 with push_front,
    //         printing "push_front(200) -- VIP cuts to the front!" first.

    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    // ! DISCUSSION: "Why is the order 200 -> 101 -> 102 -> 103?"
    //   - push_front puts the new node BEFORE the current head
    //   - The VIP jumps ahead of everyone — shows how O(1) front insertion
    //     works, no shifting needed

    // --- 3. Serving customers (pop_front) ---
    std::cout << "--- 3. Serving customers ---\n";

    // TODO 3: Serve the customer at the FRONT with pop_front, printing
    //         "pop_front() -- Serving ticket at the front" first.
    //         (The second serving further down is left for you too.)

    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    std::cout << "pop_front() -- Serving another ticket\n";
    line.pop_front();
    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    // ! DISCUSSION: "Where did tickets #200 and #101 go?"
    //   - pop_front removed them from memory entirely (delete)
    //   - They've been served their ice cream and left
    //   - The head now points to ticket #102

    // --- 4. More customers arrive while others are served ---
    std::cout << "--- 4. More customers arrive ---\n";

    std::cout << "push_back(104) -- Ticket #104 arrives\n";
    line.push_back(104);
    std::cout << "push_back(105) -- Ticket #105 arrives\n";
    line.push_back(105);
    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    // ! DISCUSSION: This is a linked list's sweet spot — a queue where people constantly join and leave.
    //   - No shifting, no resizing, just pointer updates
    //   - This is exactly how std::queue works under the hood

    // --- 5. Customer at the back gives up and leaves (pop_back) ---
    std::cout << "--- 5. Customer at the back gives up ---\n";

    // TODO 4: The customer at the BACK gives up. Remove them with pop_back,
    //         printing "pop_back() -- Ticket at the back gives up waiting" first.

    std::cout << "Current line: ";
    line.print();
    std::cout << "People waiting: " << line.get_size() << "\n\n";

    // ! DISCUSSION: "Why is pop_back slower than pop_front?"
    //   - To remove the last node, we traverse the ENTIRE list
    //     to find the second-to-last node (trailing pointer pattern)
    //   - pop_front just moves head — O(1); pop_back must traverse — O(n)
    //   - A doubly linked list solves this with a 'prev' pointer on each node

    return 0;
}
