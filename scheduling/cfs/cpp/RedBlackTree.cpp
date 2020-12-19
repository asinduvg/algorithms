#include "RedBlackTree.h"
#include <iostream>

void RBTree::insert(int data) {
    Node *newNode = new Node(data);
    if (root == nullptr) {
        root = newNode;
    } else {
        insertIntoTree(root, newNode);
    }
    fixViolation(newNode);
}

void RBTree::insert(Node *node) {
    node->setColor(RED);
    if (root == nullptr) {
        root = node;
    } else {
        insertIntoTree(root, node);
    }
    fixViolation(node);
}

void RBTree::traverse() {
    inOrderTraverse(root);
}

Node *RBTree::insertIntoTree(Node *travelNode, Node *newNode) {
    if (travelNode->getVirtualTime() > newNode->getVirtualTime()) {
        if (travelNode->getLeftChild() == nullptr) {
            travelNode->setLeftChild(newNode);
            newNode->setParent(travelNode);
            return newNode;
        } else {
            insertIntoTree(travelNode->getLeftChild(), newNode);
        }
    } else if (travelNode->getVirtualTime() <= newNode->getVirtualTime()) {
        if (travelNode->getRightChild() == nullptr) {
            travelNode->setRightChild(newNode);
            newNode->setParent(travelNode);
            return newNode;
        } else {
            insertIntoTree(travelNode->getRightChild(), newNode);
        }
    }
}

void RBTree::inOrderTraverse(Node *travelNode) {
    if (travelNode == nullptr) return;
    inOrderTraverse(travelNode->getLeftChild());
    std::cout << travelNode->getVirtualTime() << " color : " << travelNode->getColor() << std::endl;
    inOrderTraverse(travelNode->getRightChild());
}

void RBTree::rightRotate(Node *baseNode) {
//    cout << "Rotating right" << endl;
    Node *temp = baseNode->getLeftChild();

    baseNode->setLeftChild(temp->getRightChild());

    if (baseNode->getLeftChild() != nullptr)
        baseNode->getLeftChild()->setParent(baseNode);
    temp->setParent(baseNode->getParent());

    if (temp->getParent() == nullptr) {
        root = temp;
    } else if (baseNode->getParent()->getLeftChild() == baseNode) {
        baseNode->getParent()->setLeftChild(temp);
    } else {
        baseNode->getParent()->setRightChild(temp);
    }
    temp->setRightChild(baseNode);
    baseNode->setParent(temp);
}

void RBTree::leftRotate(Node *baseNode) {
//    cout << "Rotating left" << endl;
    Node *temp = baseNode->getRightChild();

    baseNode->setRightChild(temp->getLeftChild());

    if (baseNode->getRightChild() != nullptr)
        baseNode->getRightChild()->setParent(baseNode);

    temp->setParent(baseNode->getParent());

    if (temp->getParent() == nullptr) {
        root = temp;
    } else if (baseNode->getParent()->getRightChild() == baseNode) {
        baseNode->getParent()->setRightChild(temp);
    } else {
        baseNode->getParent()->setLeftChild(temp);
    }
    temp->setLeftChild(baseNode);
    baseNode->setParent(temp);
}

void RBTree::fixViolation(Node *node) {
    Node *parent = nullptr;
    Node *grandParent = nullptr;

    while (node != root && node->getColor() != BLACK && node->getParent()->getColor() == RED) {
        parent = node->getParent();
        grandParent = node->getParent()->getParent();

        if (parent == grandParent->getLeftChild()) {
            Node *uncle = grandParent->getRightChild();

            if (uncle != nullptr && uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandParent->setColor(RED);
                node = grandParent;
            } else {
                if (node == parent->getRightChild()) {
                    leftRotate(parent);
                    node = parent;
                    parent = node->getParent();
                }
//                else {
                rightRotate(grandParent);
                NodeColor tempColor = parent->getColor();
                parent->setColor(grandParent->getColor());
                grandParent->setColor(tempColor);
                node = parent;
//                }
            }
        } else {
            Node *uncle = grandParent->getLeftChild();

            if (uncle != nullptr && uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandParent->setColor(RED);
            } else {
                if (node == parent->getLeftChild()) {
                    rightRotate(parent);
                    node = parent;
                    parent = node->getParent();
                }

                leftRotate(grandParent);
                NodeColor tempColor = parent->getColor();
                parent->setColor(grandParent->getColor());
                grandParent->setColor(tempColor);
                node = parent;

            }
        }
    }

    if (root->getColor() == RED) root->setColor(BLACK);

}

Node *RBTree::findNode(Node *temp, int data) {
    if (temp == nullptr) return nullptr;
    if (temp->getVirtualTime() == data) return temp;
    if (temp->getVirtualTime() > data) {
        findNode(temp->getLeftChild(), data);
    } else {
        findNode(temp->getRightChild(), data);
    }
}

Node *RBTree::inOrderSuccessor(Node *node) {
    //left most element of the right subtree
    if (node->getLeftChild() == nullptr) return node;
    inOrderSuccessor(node->getLeftChild());
}

//void RBTree::deleteNode(int data) {
//    Node *node = findNode(root, data);
//    Node *nodeToDelete = selectNodeToDelete(node);
//    delete nodeToDelete;
//}

// for assignment
void RBTree::deleteNode(Node *node) {
//    Node *node = findNode(root, data);
    Node *nodeToDelete = selectNodeToDelete(node);
    delete nodeToDelete;
}
// for assignment

Node *RBTree::selectNodeToDelete(Node *node) {
    Node *y = nullptr;


    if (node->getLeftChild() == nullptr || node->getRightChild() == nullptr) {
        //node having only child or having no children
        //delete node
        y = node;
    } else {
        // node having two children
        //delete successor
        y = inOrderSuccessor(node->getRightChild());
    }

    Node *x = nullptr;

    if (y->getLeftChild() != nullptr) {
        x = y->getLeftChild();
        x->setParent(y->getParent());
    } else if (y->getRightChild() != nullptr) {
        x = y->getRightChild();
        x->setParent(y->getParent());
    }

    bool isLeft = false;

    if (y->getParent() == nullptr) {
        root = x;

//        cout << "x-burst" << x->getBurstTime() << endl;
//        cout << "x-virtual" << x->getVirtualTime() << endl;
//        cout << "v-time " << y->getVirtualTime() << endl;
//        cout << "b-time " << y->getBurstTime() << endl;
//        cout << root->getBurstTime() << endl;
    } else if (y == y->getParent()->getLeftChild()) {
        y->getParent()->setLeftChild(x);
        isLeft = true;
    } else {
        y->getParent()->setRightChild(x);
    }

    if (y != node) {
        node->setVirtualTime(y->getVirtualTime());
    }

//    if(node == root){
//        if(node->getRightChild() != nullptr){
//            root = node->getRightChild();
//            root->setColor(BLACK);
//        }else{
//            root = nullptr;
//        }
//        return node;
//    }

    if (y->getColor() == BLACK) {
        if (root != nullptr) {
            if (y->getLeftChild() == root && y->getRightChild() == nullptr) {
                y->getLeftChild()->setColor(BLACK);
            } else if (y->getRightChild() == root && y->getLeftChild() == nullptr) {
                y->getRightChild()->setColor(BLACK);
            } else {
                deleteFixUp(y, isLeft);
            }
        }
    }
    return y;
}

void RBTree::deleteFixUp(Node *node, bool isLeft) {
    while (node != root && node->getColor() == BLACK) {
        Node *sibling = nullptr;
        if (isLeft) {
            sibling = node->getParent()->getRightChild();

            //case 1 :
            if (sibling->getColor() == RED) {
                sibling->setColor(BLACK);
                node->getParent()->setColor(RED);
                leftRotate(node->getParent());
                sibling = node->getParent()->getRightChild();
            }
            //case 1 //

            //case 2 :
            if ((sibling->getLeftChild() == nullptr && sibling->getRightChild() == nullptr) ||
                ((sibling->getLeftChild() != nullptr && sibling->getLeftChild()->getColor() == BLACK) &&
                 (sibling->getRightChild() != nullptr && sibling->getRightChild()->getColor() == BLACK))) {
                sibling->setColor(RED);
                if (node->getParent()->getColor() == RED) {
                    node->getParent()->setColor(BLACK);
                    node = root; // parent is red black and fixing ends
                } else {
                    node = node->getParent();
                }
            }
                //case 2 //

                //case 3 :
            else if (sibling->getRightChild() == nullptr ||
                     (sibling->getRightChild() != nullptr && sibling->getRightChild()->getColor() == BLACK)) {
                sibling->getLeftChild()->setColor(BLACK);
                sibling->setColor(RED);
                rightRotate(sibling);
                sibling = node->getRightChild();
            }
                //case 3 //

                // case 4 :
            else if (sibling->getRightChild()->getColor() == RED) {
                sibling->setColor(node->getParent()->getColor());
                node->getParent()->setColor(BLACK);
                sibling->getRightChild()->setColor(BLACK);
                leftRotate(node->getParent());
                node = root; //terminating case -- hence node is root and ends up the while loop
            }
            //case 4 //

        } else {
            sibling = node->getParent()->getLeftChild();

            //case 1 :
            if (sibling->getColor() == RED) {
                sibling->setColor(BLACK);
                node->getParent()->setColor(RED);
                rightRotate(node->getParent());
                sibling = node->getParent()->getLeftChild();
            }
            //case 1 //

            //case 2 :
            if ((sibling->getLeftChild() == nullptr && sibling->getRightChild() == nullptr) ||
                ((sibling->getLeftChild() != nullptr && sibling->getLeftChild()->getColor() == BLACK) &&
                 (sibling->getRightChild() != nullptr && sibling->getRightChild()->getColor() == BLACK))) {

                sibling->setColor(RED);
                if (node->getParent()->getColor() == RED) {
                    node->getParent()->setColor(BLACK);
                    node = root; // parent is red black and fixing ends
                } else {
                    node = node->getParent();
                }
            }
                //case 2 //

                //case 3 :
            else if (sibling->getLeftChild() == nullptr ||
                     (sibling->getLeftChild() != nullptr && sibling->getLeftChild()->getColor() == BLACK)) {
                sibling->getRightChild()->setColor(BLACK);
                sibling->setColor(RED);
                rightRotate(sibling);
                sibling = node->getLeftChild();
            }
                //case 3 //

                //case 4 :
            else if (sibling->getLeftChild()->getColor() == RED) {
                sibling->setColor(node->getParent()->getColor());
                node->getParent()->setColor(BLACK);
                sibling->getLeftChild()->setColor(BLACK);
                rightRotate(node->getParent());
                node = root;
            }
            //case 4 //
        }

        node->setColor(BLACK);
    }
}

Node *RBTree::getLeftMost() {
    return leftMostNode(root);
}

Node *RBTree::leftMostNode(Node *node) {
    if (node->getLeftChild() == nullptr) return node;
    leftMostNode(node->getLeftChild());
}

Node *RBTree::getRoot() const {
    return root;
}



