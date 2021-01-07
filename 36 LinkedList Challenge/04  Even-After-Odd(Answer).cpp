Intuition:
We can take two pointers before and after to keep track of the two linked lists as described above. These two pointers could be used two create two separate lists and then these lists could be combined to form the desired reformed list.

Algo:

Take Two Fake_heads to take care of odd and even list.
Put loop on the given LinkedList.
If the node is odd add it to odd fake_ head list.
If the node is Even add it to the even fake_head list.
At the set connect both of the list together and set head to odd list.
Code

    public void evenAfter() throws Exception {

        Node Even_head = new Node(0, null);
        Node Odd_head = new Node(0, null);

        Node even = Even_head;
        Node odd = Odd_head;

        Node temp = this.head;

        while(temp != null){

            if(temp.data % 2 == 0){
                even.next = temp;
                even = even.next;
            }else{

                odd.next = temp;
                odd = odd.next;
            }

            temp = temp.next;
        }

        odd.next = Even_head.next;
        this.head = Odd_head.next;
        this.tail = even;
        this.tail.next = null;

    }