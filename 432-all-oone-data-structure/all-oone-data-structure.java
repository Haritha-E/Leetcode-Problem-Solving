// Doubly linked list node.
class DNode{
    String s;
    int ct;
    DNode next, prev;
    DNode(String s, int ct){
        this.s = s;
        this.ct = ct;
    }
}

class AllOne {
    Map<String, DNode> strToNode;
    TreeMap<Integer, DNode> countToList;
    public AllOne() {
        strToNode = new HashMap<String, DNode>();
        countToList = new TreeMap<Integer, DNode>();
    }
    
    public void inc(String key) {
        DNode curNode;
        if(strToNode.containsKey(key)){
            curNode = strToNode.get(key);
            removeFromCurrentList(curNode);
            curNode.ct++;
        }else{
            curNode = new DNode(key, 1);
            strToNode.put(key, curNode);
        }
        addCurrentNodeToNewList(curNode);
    }
    
    public void dec(String key) {
        DNode curNode = strToNode.get(key);
        removeFromCurrentList(curNode);
        curNode.ct--;
        if(curNode.ct==0){
            strToNode.remove(key);
            return;
        }
        addCurrentNodeToNewList(curNode);
    }
    
    public String getMaxKey() {
        if(countToList.size()==0)
            return "";
        return countToList.get(countToList.lastKey()).s;
    }
    
    public String getMinKey() {
        if(countToList.size()==0)
            return "";
        return countToList.get(countToList.firstKey()).s;
    }

    void addCurrentNodeToNewList(DNode curNode){
        if(countToList.containsKey(curNode.ct)){
            DNode tempHead = countToList.get(curNode.ct);
            curNode.next = tempHead;
            tempHead.prev = curNode; 
        }
        countToList.put(curNode.ct, curNode); 
    }

    void removeFromCurrentList(DNode curNode){
        DNode curHead = countToList.get(curNode.ct);
        if(curHead == curNode){
            if(curHead.next == null){
                countToList.remove(curNode.ct); 
            }else{
                curHead = curHead.next;
                curHead.prev = null;
                countToList.put(curNode.ct, curHead);
                curNode.next = null;
            }
        }else{
            removeReference(curNode);
        }
    }

    void removeReference(DNode curNode){
        DNode prev = curNode.prev, next = curNode.next;
        if(prev != null && next != null){
            prev.next = next;
            next.prev = prev;
        }else {
            prev.next = null;
        }
        curNode.next = null;
        curNode.prev = null;
    }
}