#include <iostream>

template <typename T>
class DynamicArrayBinaryTree {
private:
    T* array;
    int capacity;
    int size;

public:
    DynamicArrayBinaryTree(int initialCapacity = 10) {
        capacity = initialCapacity;
        array = new T[capacity];
        size = 0;
    }

    ~DynamicArrayBinaryTree() {
        delete[] array;
    }

    void insert(const T& value) {
        if (size >= capacity) {
            // If the array is full, double its capacity
            capacity *= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        array[size++] = value;
    }

    bool contains(const T& value) const {
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                return true;
            }
        }
        return false;
    }

    void inorderTraversal(int index = 0) const {
        if (index < size) {
            inorderTraversal(2 * index + 1);  // Left child
            std::cout << array[index] << " ";
            inorderTraversal(2 * index + 2);  // Right child
        }
    }

    void remove(const T& value) {
        int foundIndex = -1;
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            // Shift elements to the left to fill the gap
            for (int i = foundIndex; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
    }
};

int main() {
    DynamicArrayBinaryTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    if (tree.contains(7)) {
        std::cout << "Tree contains 7." << std::endl;
    }

    tree.remove(5);

    std::cout << "Inorder Traversal after removing 5: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    return 0;
}
