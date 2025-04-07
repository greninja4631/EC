class Node:
    def __init__(self, pid, vruntime):
        self.pid = pid
        self.vruntime = vruntime
        self.color = 'RED'  # RED or BLACK
        self.parent = None
        self.left = None
        self.right = None

    def __repr__(self):
        return f"[{self.pid}, vr={self.vruntime}, {self.color}]"

class RedBlackTree:
    def __init__(self):
        self.NIL = Node(None, None)
        self.NIL.color = 'BLACK'
        self.root = self.NIL

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.NIL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.NIL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert(self, pid, vruntime):
        new_node = Node(pid, vruntime)
        new_node.left = self.NIL
        new_node.right = self.NIL

        parent = None
        current = self.root

        while current != self.NIL:
            parent = current
            if new_node.vruntime < current.vruntime:
                current = current.left
            else:
                current = current.right

        new_node.parent = parent
        if parent is None:
            self.root = new_node
        elif new_node.vruntime < parent.vruntime:
            parent.left = new_node
        else:
            parent.right = new_node

        new_node.color = 'RED'
        self.fix_insert(new_node)

    def fix_insert(self, k):
        while k != self.root and k.parent.color == 'RED':
            if k.parent == k.parent.parent.left:
                uncle = k.parent.parent.right
                if uncle.color == 'RED':
                    k.parent.color = 'BLACK'
                    uncle.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self.left_rotate(k)
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    self.right_rotate(k.parent.parent)
            else:
                uncle = k.parent.parent.left
                if uncle.color == 'RED':
                    k.parent.color = 'BLACK'
                    uncle.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.right_rotate(k)
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    self.left_rotate(k.parent.parent)
        self.root.color = 'BLACK'

    def inorder(self, node=None):
        if node is None:
            node = self.root
        if node != self.NIL:
            self.inorder(node.left)
            print(node)
            self.inorder(node.right)

    def get_min(self):
        current = self.root
        while current.left != self.NIL:
            current = current.left
        return current

# --- 実行例 ---
if __name__ == "__main__":
    rbt = RedBlackTree()
    rbt.insert(101, 30)
    rbt.insert(102, 10)
    rbt.insert(103, 50)
    rbt.insert(104, 20)
    rbt.insert(105, 60)

    print("\n📋 CFSタスク一覧（vruntime順）:")
    rbt.inorder()

    print("\n🚀 次にスケジュールすべきタスク:", rbt.get_min())