let sum = 0;

class Node {
    constructor(val) {
        this.data = val;
        this.next = null;
    }
}

function push(head_ref, new_data) {
    let new_node = new Node();

    new_node.data = new_data;

    new_node.next = (head_ref);

    (head_ref) = new_node;
    return head_ref;
}

function sumOfNodes(head) {
    if (head == null)
        return;

    // recursively traverse the remaining nodes
    sumOfNodes(head.next);

    // accumulate sum
    sum = sum + head.data;
}

// utility function to find the sum of nodes
function sumOfNodesUtil(head) {

    sum = 0;

    // find the sum of nodes
    sumOfNodes(head);

    // required sum
    return sum;
}

let head = null;

// create linked list 7.6.8.4.1
head = push(head, 7);
head = push(head, 6);
head = push(head, 8);
head = push(head, 4);
head = push(head, 1);

document.write("Sum of nodes = " +
    sumOfNodesUtil(head));