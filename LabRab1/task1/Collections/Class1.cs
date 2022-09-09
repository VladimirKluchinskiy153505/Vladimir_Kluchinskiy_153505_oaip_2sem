using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1
{
    class MyCustomCollection<T> : ICustomCollection<T> where T:IEquatable<T>
    {
        internal class Node
        {
           public Node(T data) {
                this.data = data;
                this.next = null;
            }
            public Node next;
            public T data;
        }
     
        int size = 0,position=0;
        Node head;
        private Node GetLastNode()
        {
            Node temp = head;
            for(int i = 0; i < size-1; ++i)
            {
                temp = temp.next;
            }
            return temp;
        }
       public T this[int index]
        {
            get
            {
                if (index >= size) { return head.data ; }
                else
                {
                    Node cur_node = head;
                    for(int i = 0; i < index; ++i)
                    {
                        cur_node = cur_node.next;
                    }
                    position = index;
                    return cur_node.data;
                }
            }
            set
            {
                if(index >= size) { return; }
                else { position = index; }
            }
        }
        public void Reset()
        {
            position = 0;
        }
        public void Next()
        {
            if (position == size - 1) { position = 0; }
            else { ++position; }
        }
       public T Current()
        {
            return this[position];
        }
       public int Count { get { return size; } }
       public void Add(T item)
        {
            Node new_node = new Node(item);
            if (head == null)
            {
                head = new_node;
            }
            else
            {
                Node lastNode = GetLastNode();
                lastNode.next = new_node;
            }
            ++size;
        }
       public int Remove(T item)
        {
            if (size == 0) { return 0; }
            if (item.Equals(head.data))
            {
                head = head.next;
                --size;
                if(position == 0)
                {
                    position = size - 1;
                }
                return 1;
            }
            else
            {
                Node temp = head;
                Node prev = null;
                while (temp != null && !item.Equals(temp.data) )
                {
                    prev = temp;
                    temp = temp.next;
                }
                if (temp != null)
                {
                    prev.next = temp.next;
                    GC.Collect();
                    --size;
                    --position;
                    return 1;
                }
                else { return 0; }
            }
        }
       public void RemoveCurrent()
        {
            if (size == 0) { return; }
            if (position == 0)
            {
                head = head.next;
                --size;
                if (position == 0)
                {
                    position = size - 1;
                }
            }
            else
            {
                Node temp = head;
                for (int i = 0; i < position-1; ++i)
                {
                    temp = temp.next;
                }
                if (temp != null)
                {
                    temp.next=temp.next.next;
                    GC.Collect();
                    --size;
                    --position;
                }
            }
            
        }
    }
}
