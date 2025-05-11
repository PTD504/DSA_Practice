class StackNode:
    def __init__(self, val=0, mn=0, next=None):
        self.val = val
        self.mn = mn
        self.next = next

class MinStack:

    def __init__(self):
        self.head = None

    def push(self, val: int) -> None:
        if self.head:
            newHead = StackNode(val, min(val, self.head.mn), self.head)
            self.head = newHead
        else:
            self.head = StackNode(val, val)

    def pop(self) -> None:
        self.head = self.head.next

    def top(self) -> int:
        return self.head.val

    def getMin(self) -> int:
        return self.head.mn


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()