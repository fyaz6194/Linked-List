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
    SparseArrayNode* tempPtr = headPointer->next;
    SparseArrayNode* tempPtr2 = headPointer;
    while (tempPtr != nullptr) {
        if (tempPtr->index < tempPtr2->index)
            return false;
        tempPtr2 = tempPtr2->next;
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
    if (headPointer == nullptr)
        return nullptr;
    SparseArrayNode* tempPtr = headPointer;
    SparseArrayNode* prePtr = nullptr;
    while (tempPtr != nullptr) {
        if (tempPtr->index == index)
            return prePtr;
        prePtr = tempPtr;
        tempPtr = tempPtr->next;
    }
    assert(invariant());
    return nullptr;
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
    if (value == defaultValue) {
        if (getExactNode(index) != nullptr) {
            remove(index);
            return;
        }
    }
    else {
        if (getExactNode(index) != nullptr && headPointer != nullptr)
        {
            SparseArrayNode* temp = headPointer;
            while (headPointer != nullptr) {
                if (headPointer->index == index) {
                    headPointer->value = value;
                    headPointer = temp;
                    return;
                }
                headPointer = headPointer->next;
            }
        }
        else if (headPointer == nullptr) {
            SparseArrayNode* newNode = new SparseArrayNode;
            newNode->index = index;
            newNode->value = value;
            newNode->next = headPointer;
            headPointer = newNode;
        }
        else if (headPointer != nullptr && getExactNode(index) == nullptr) {
            SparseArrayNode* newNode = new SparseArrayNode;
            newNode->index = index;
            newNode->value = value;

            if (headPointer->index >= index) {
                newNode->next = headPointer;
                headPointer = newNode;
            }
            else {
                SparseArrayNode* temp = headPointer;
                SparseArrayNode* previousptr = nullptr;
                while (temp != nullptr) {
                    if (temp->index >= index)
                        break;
                    previousptr = temp;
                    temp = temp->next;
                }
                newNode->next = previousptr->next;
                previousptr->next = newNode;
            }
        }
    }
    assert(invariant());
}
void SparseArray::remove(int index) {
    if (headPointer == nullptr) {
        return;
    }
    if (headPointer->index == index) {
        headPointer = headPointer->next;
        return;
    }
    SparseArrayNode* tempPtr = headPointer->next;
    while (tempPtr != nullptr) {
        if (tempPtr->index == index) {
            SparseArrayNode* temp = getPreviousNode(index);
            temp->next = tempPtr->next;
            return;
        }
        tempPtr = tempPtr->next;
    }
}
void SparseArray::clear() {
    assert(invariant());
    delete headPointer;
    headPointer = nullptr;
}