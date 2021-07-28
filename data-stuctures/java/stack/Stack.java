public class Stack {

    private int maxSize;
    private long[] stackArray;
    private int top;

    public Stack(int size) {
        this.maxSize = size;
        this.stackArray = new long[maxSize];
        this.top = -1;
    }

    public void push(int item) {
        if (this.maxSize - 1 <= this.top) {
            System.out.println("The stack is full");
        } else {
            stackArray[++top] = item;
        }
    }

    public void pop() {
        if (this.top == -1) {
            System.out.println("The stack is empty");
        } else {
            stackArray[top] = 0;
            top--;
        }
    }

    public void printStack() {
        for (var i = 0; i <= top; i++) {
            System.out.println(stackArray[i] + " ");
        }
    }

}

class App {
    public static void main(String[] args) {
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.pop();
        stack.push(60);
        stack.printStack();
    }
}