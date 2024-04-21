#include "singly_linked_list.hpp"

int main() {
    Linked_list<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display();

    list.remove(2);
    list.insert(4);
    list.display();

    std::cout << list.find(1) << ' ' << list.find(2) << ' ' << list.find(3) << '\n';

    std::cout << "Everything works as expected.\n";
    return 0;
}