//链表节点
function Node(data) {
    this.data = data;
    this.next = null;
}

//哨兵节点
function List() {
    this.head = new Node();
    this.size = 0;
}

List.prototype = {
    //在链表尾部添加新节点
    add: function(data) {
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        current.next = new Node(data);
        this.size ++;
    },
    //遍历链表
    forEach: function(callback) {
        for (let current = this.head.next; current !== null; current = current.next) {
            callback(current.data);
        }
    },
    //打印链表元素
    print: function() {
        this.forEach(function(item) {
            console.log(item);
        })
    },
    //查找链表中元素的位置
    indexOf: function(data) {
        let position = 0;
        let current = this.head.next;
        while (current !== null) {
            if (current.data === data) {
                break;
            }
            current = current.next;
            position ++;
        }
        return position;
    },
    //删除相应元素
    remove: function(data) {
        let current = this.head;
        while (current.next !== null) {
            if (current.next.data === data) {
                let nextNode = current.next.next;
                current.next = nextNode;
                this.size --;
                break;
            }
            current = current.next;
        }
    },
    /**
     * 删除指定位置的元素
     * 若成功则返回删除的值，若失败则返回null
     */
    removeAt: function(index) {
        if (index < 0 || this.size - 1 < index) {
            return null;
        }
        let current = this.head;
        while (index > 0) {
            current = current.next;
            index --;
        }
        let nextNode = current.next.next;
        let removeData = current.next.data;
        current.next = nextNode;
        this.size --;
        return removeData;
    },
    /**
     * 在位置pos处插入节点值为data
     * 若成功则返回插入的值，若失败则返回null
     */
    insert: function(pos, data) {
        if (pos < 0 || this.size - 1 < pos) {
            return null;
        }
        let current = this.head;
        while (pos > 0) {
            current = current.next;
            pos --;
        }
        let nextNode = current.next;
        current.next = new Node(data);
        current.next.next = nextNode;
        return data;
    }
}

var list=new List();
list.add(1);
list.add(2);
list.add(3);
list.insert(1,2);
console.log(list.indexOf(2));   //2
list.remove(3);
list.removeAt(1);
console.log(list.size);   //2
list.print();   //1 2
