#include "SinglyLinkedList.h"

#include <iostream>
#include <stdexcept>

// --- Destructor ---

// ! DISCUSSION: Why do we need a destructor at all?
//   - Each node was created with 'new', which allocates memory on the heap
//   - If we don't 'delete' every node, that memory leaks — reserved but never freed
//   - The destructor traverses the chain and deletes each node one by one
//
// ! DISCUSSION: "Why not just delete head_ and be done?"
//   - 'delete head_' only frees the FIRST node
//   - The rest of the chain is still out there, unreachable and leaked
//   - We must follow the next pointers and delete each node individually
//
// ? SEE DIAGRAM: images/svgs/destructor_walk.svg — traversing the chain, deleting each node

SinglyLinkedList::~SinglyLinkedList() {
    // ! DISCUSSION: "Why do we need a temp pointer?"
    //   - We need to save head_ BEFORE we move it forward
    //   - If we do head_ = head_->next first, we lose the only
    //     pointer to the current node and can never delete it
    //   - Order matters: save → advance → delete

    // TODO 1: Loop while head_ is not nullptr.
    // TODO 2: Inside the loop, save head_ in a temp pointer, then advance
    //         head_ to head_->next.
    // TODO 3: delete the saved temp pointer.
}

// --- Insertion ---

// ? SEE DIAGRAM: images/svgs/push_front.svg — shows new node's next pointing to old head, then head moving

void SinglyLinkedList::push_front(int value) {
    // ! DISCUSSION: This is the beauty of push_front — it's always O(1).
    //   No matter how long the list is, we just:
    //   - Create a new node whose 'next' points to the current head
    //   - Update head to point to the new node
    //   - Compare to an array: inserting at the front means shifting
    //     EVERY element one slot to the right — O(n)
    // TODO 4: Make a new Node holding 'value' whose next is the current head_,
    //         and point head_ at it.
    // TODO 5: Increase size_ by one.
}

// ? SEE DIAGRAM: images/svgs/push_back.svg — shows traversing to the last node, then linking the new node

void SinglyLinkedList::push_back(int value) {
    // TODO 6: Create the new node on the heap, holding 'value'.

    if (false) {   // TODO 7: replace with the empty-list test (head_ is nullptr)
        // ! DISCUSSION: Empty list is a special case.
        //   - There's no existing node to attach to
        //   - The new node simply becomes the head
        // TODO 8: The list is empty, so the new node simply becomes head_.
    } else {
        // ! DISCUSSION: We must traverse to the END of the list to find the last node.
        //   - This makes push_back O(n) — the longer the list, the longer the traversal
        //   - Key tradeoff vs arrays, where appending to the end is O(1) (if there's capacity)
        //   - We could fix this by keeping a 'tail' pointer, but that adds
        //     complexity we'll explore later
        // TODO 9: Walk a 'current' pointer to the LAST node (the one whose
        //         next is nullptr), then attach the new node after it.
    }
    // TODO 10: Increase size_ by one.
}

// --- Removal ---

// ? SEE DIAGRAM: images/svgs/pop_front.svg — shows saving head, advancing head, deleting old head

void SinglyLinkedList::pop_front() {
    if (!head_) {
        throw std::underflow_error("Cannot pop from an empty list");
    }

    // ! DISCUSSION: Same temp-pointer pattern as the destructor.
    //   - Save the current head, advance head to the next node, then delete the old head
    //   - This is O(1) — no matter the list size, we only touch one node
    //
    // ! DISCUSSION: "What happens to the data in the deleted node?"
    //   - It's gone — if the caller needed that value, they should have
    //     read it before calling pop_front()
    //   - Some implementations return the value, but the STL convention
    //     (std::stack::pop, std::queue::pop) is to return void
    //   - Provide a separate top()/front() method to peek first
    // TODO 11: Save head_ in a temp pointer.
    // TODO 12: Advance head_ to head_->next, then delete the saved pointer.
    // TODO 13: Decrease size_ by one.
}

// ? SEE DIAGRAM: images/svgs/pop_back.svg — shows trailing pointer pattern to find and remove the last node

void SinglyLinkedList::pop_back() {
    if (!head_) {
        throw std::underflow_error("Cannot pop from an empty list");
    }

    // ! DISCUSSION: Special case — only one node in the list.
    //   - If head_->next is nullptr, the head IS the tail
    //   - Just delete it and set head_ to nullptr — no traversal needed
    // TODO 14: Handle the single-node case — if head_->next is nullptr, delete
    //          head_, set head_ to nullptr, decrease size_, and return.

    // ! DISCUSSION: The "trailing pointer" pattern.
    //   - We need TWO pointers: 'current' advances through the list,
    //     'previous' trails one node behind
    //   - When current reaches the last node, previous points to the second-to-last —
    //     exactly the node whose 'next' we need to set to nullptr
    //   - Why one pointer isn't enough: singly linked nodes don't know who points TO them —
    //     no way to go BACKWARDS, so the trailing pointer tracks where we came from
    //
    // ! DISCUSSION: This makes pop_back O(n).
    //   - We must traverse the entire list to find the second-to-last node
    //   - Compare to pop_front which is O(1)
    //   - A doubly linked list fixes this by giving each node a 'prev' pointer
    // TODO 15: Set 'previous' to head_ and 'current' to head_->next.
    // TODO 16: Walk both forward until current->next is nullptr, so that
    //          current is the last node and previous is the one before it.

    // ! DISCUSSION: Now 'current' is the last node, 'previous' is the second-to-last.
    //   Unlink and delete:
    //   - Set previous->next to nullptr (it's now the new tail)
    //   - Delete current (free the old tail's memory)
    // TODO 17: Set previous->next to nullptr, delete current, decrease size_.
}

// --- Getters ---

int SinglyLinkedList::get_size() const noexcept { return size_; }
bool SinglyLinkedList::is_empty() const noexcept { return size_ == 0; }

// --- Utility ---

void SinglyLinkedList::print() const {
    // ! DISCUSSION: Printing by traversing the list.
    //   - Use a 'current' pointer that starts at head and follows
    //     next pointers until it hits nullptr (end of list)
    //   - This is the fundamental traversal pattern for linked lists —
    //     you'll see it again in search and remove operations (CT 09)
    // TODO 18: Walk a 'current' pointer from head_ until it is nullptr,
    //          printing each node's data followed by " -> ", then print
    //          "nullptr" and a newline to mark the end.
}
