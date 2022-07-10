#include "node.h"
#include <iostream>
using namespace std;
int main() {
    Node A = Node(1,3);
    A.addChild(2);
    A[0].addChild(3);
    cout<<A.getHeight()<<endl;
    return 0;
}