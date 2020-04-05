#include "SparseArray.h"
bool SparseArray::isAnyDefault() const {
    SparseArrayNode* tempptr = headPointer;
    if (headPointer == nullptr)
        return false;
    while (tempptr != nullptr) {
        if (tempptr->value == getDefaultValue()) {
            return true;
        }
        tempptr = tempptr->next;
    }
    return false;
}
bool SparseArray::isSorted() const {
    if (headPointer == nullptr)
        return true;
    int beforeIndex;
    SparseArrayNode* tempPtr = headPointer;
    while (tempPtr != nullptr) {
        if (tempPtr == headPointer) {
            beforeIndex = tempPtr->index;
        }
        if (beforeIndex > tempPtr->index) {
            return false;
        }
        beforeIndex = tempPtr->index;
        tempPtr = tempPtr->next;
    }
    return true;
}
const SparseArrayNode* SparseArray::getExactNode(int index) const {
    SparseArrayNode* tempptr = headPointer;
    while (tempptr != nullptr) {
        if (tempptr->index == index)
            return tempptr;
        tempptr = tempptr->next;
    }
    return nullptr;
}
SparseArrayNode* SparseArray::getExactNode(int index) {
    SparseArrayNode* tempptr = headPointer;
    while (tempptr != nullptr) {
        if (tempptr->index == index)
            return tempptr;
        tempptr = tempptr->next;
    }
    return nullptr;
}
SparseArrayNode* SparseArray::getPreviousNode(int index) {
    if (getExactNode(index) == nullptr)
        return nullptr;
    return getExactNode(index)->next;
}
SparseArrayNode* SparseArray::copyLinkedList(const SparseArrayNode* p_old_head) const {
    SparseArrayNode* tempPtr = nullptr;
    SparseArrayNode* newNodePtr = nullptr;
    SparseArrayNode* newNode = new SparseArrayNode;
    unsigned long int count = 0; //unused int... But might be use in future :)
    if (p_old_head == nullptr) {
        return newNodePtr;
    }
    else {

        newNodePtr = newNode;
        newNode->index = p_old_head->index;
        newNode->value = p_old_head->value;
        newNode->next = nullptr;
        tempPtr = p_old_head->next;
        count++;
    }
    while (tempPtr != nullptr) {
        SparseArrayNode* newNode2 = new SparseArrayNode;
        newNode->next = newNode2;
        newNode2->index = tempPtr->index;
        newNode2->value = tempPtr->value;
        newNode2->next = nullptr;
        tempPtr = tempPtr->next;
        newNode = newNode->next;
        newNode2 = nullptr;
        count++;
    }
    return newNodePtr;
}
bool SparseArray::invariant() const {
    cout << endl << isSorted() << endl;
    bool boolReturn;
    boolReturn = isAnyDefault() == false && isSorted() == true;
    return boolReturn;
}
SparseArray::SparseArray() {
    defaultValue = "";
    headPointer = nullptr;
}
SparseArray::SparseArray(const string& default_value) {
    headPointer = nullptr;
    defaultValue = default_value;
    assert(invariant());
}
SparseArray::SparseArray(const SparseArray& to_copy) {
    assert(to_copy.invariant());
    defaultValue = to_copy.defaultValue;
    SparseArrayNode* newNode = copyLinkedList(to_copy.headPointer);
    headPointer = newNode;
    assert(invariant());
}
SparseArray::~SparseArray() {
    assert(invariant());
    clear();
    headPointer = nullptr;

}
SparseArray& SparseArray::operator= (const SparseArray& to_copy) {
    assert(to_copy.invariant());
    clear();
    defaultValue = to_copy.getDefaultValue();
    SparseArrayNode* newNode = copyLinkedList(to_copy.headPointer);
    headPointer = newNode;
    assert(invariant());
    return *this;
}
bool SparseArray::isEmpty() const {
    if (headPointer == nullptr)
        return true;
    return false;
}
const string& SparseArray::getDefaultValue() const {
    return defaultValue;
}
bool SparseArray::isSet(int index) const {

    if (getExactNode(index) != nullptr) {
        return true;
    }
    return false;
}
const string& SparseArray::getAt(int index) const {
    if (getExactNode(index) != nullptr)
        return getExactNode(index)->value;
    return defaultValue;
}
unsigned int SparseArray::getNodeCount() const {
    SparseArrayNode* tempptr = headPointer;
    unsigned int count = 0;
    while (tempptr != nullptr) {
        tempptr = tempptr->next;
        count += 1;
    }
    return count;
}
void SparseArray::printNodes() const {
    cout << "Nodes:";
    if (getNodeCount() == 0) {
        cout << " NONE";
    }
    else {
        SparseArrayNode* tempptr = headPointer;
        while (tempptr != nullptr)
        {
            cout << " -> [" << tempptr->index << ": \"" << tempptr->value << "\"]";
            tempptr = tempptr->next;
        }
    }
    cout << endl;
}
void SparseArray::insert(int index, const string& value) {
    assert(invariant());
    if (value != defaultValue) {
        SparseArrayNode* newNode = new SparseArrayNode;
        newNode->value = value;
        newNode->index = index;
        if (headPointer == nullptr) {
            headPointer = newNode;
            headPointer->next = nullptr;
        }
        else
        {
            SparseArrayNode* tempPtr = headPointer;
            while (tempPtr != nullptr) {
                if (tempPtr->index == index) {
                    tempPtr->value = value;
                    assert(invariant());
                    return;
                }
                tempPtr = tempPtr->next;
            }
            tempPtr = headPointer;
            SparseArrayNode* nullPtrPervious = nullptr;
            unsigned long int checkIndex;
            while (tempPtr != nullptr) { //find the address of present index is less then inserting index
                checkIndex = tempPtr->index;
                if (index < checkIndex) {
                    break;
                }
                nullPtrPervious = tempPtr;
                tempPtr = tempPtr->next;
            }
            if (tempPtr == headPointer) {
                newNode->next = headPointer;
                headPointer = newNode;
            }
            else if (tempPtr != nullptr && tempPtr != headPointer) {
                newNode->next = tempPtr;
                nullPtrPervious->next = newNode;
            }
            else if (tempPtr == nullptr && tempPtr != headPointer) {
                newNode->next = nullptr;
                nullPtrPervious->next = newNode;
            }
            nullPtrPervious = nullptr;
            tempPtr = nullptr;
        }
    }
    else if (value == getDefaultValue()) {
        if (headPointer == nullptr) {
            return;
        }
        SparseArrayNode* tempPtr = headPointer;
        while (tempPtr != nullptr) {

            if (tempPtr->index == index) {
                if (tempPtr == headPointer) {
                    headPointer = tempPtr->next;
                }
                else if (tempPtr != headPointer) {
                    remove(tempPtr->index);
                }
                return;
            }
            tempPtr = tempPtr->next;
        }
    }
    assert(invariant());
}
void SparseArray::remove(int index) {
    assert(invariant());
    while (headPointer != nullptr) { // use can use if condition here
        if (headPointer->index == index) {
            headPointer = headPointer->next;
        }
        else {
            SparseArrayNode* tempptr = headPointer;
            while (tempptr->next != nullptr) {
                if (getPreviousNode(tempptr->index)->index == index) {
                    tempptr->next = getPreviousNode(tempptr->index)->next;
                    break;
                }
                tempptr = getPreviousNode(tempptr->index);
            }
            tempptr = nullptr;
        }
        break;
    }
    assert(invariant());
}
void SparseArray::clear() {
    assert(invariant());
    delete headPointer;
    headPointer = nullptr;
}