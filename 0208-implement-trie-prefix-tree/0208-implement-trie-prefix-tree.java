class Trie {
    Map<Character,Node> map;
    public Trie() {
        map = new HashMap<>();
    }
    
    public void insert(String word) {
        char c = word.charAt(0);
        Node node ;
        if(map.containsKey(c)){
            node = map.get(c);
        }else{
            node = new Node(c);
            map.put(c,node);
        }

        for(int i=1;i<word.length();i++){
            c = word.charAt(i);
            if(node.nextMap.containsKey(c)){
                node = node.nextMap.get(c);
                continue;
            }
            Node nextNode = new Node(c);
            node.nextMap.put(c,nextNode);
            node = nextNode;
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        char c = word.charAt(0);
        if(!map.containsKey(c)) return false;
        Node node = map.get(c);
        for(int i=1;i<word.length();i++){
            c = word.charAt(i);
            if(node.nextMap.containsKey(c)){
                node = node.nextMap.get(c);
                continue;
            }else{
                return false;
            }
        }
       return node.isEnd;
    }
    
    public boolean startsWith(String word) {
        char c = word.charAt(0);
        if(!map.containsKey(c)) return false;
        Node node = map.get(c);
        for(int i=1;i<word.length();i++){
            c = word.charAt(i);
            if(node.nextMap.containsKey(c)){
                node = node.nextMap.get(c);
                continue;
            }else{
                return false;
            }
        }
       return true;
    }
}

class Node{
    char c;
    boolean isEnd;
    Map<Character,Node> nextMap;

    public Node(char c){
        this.c =c;
        nextMap = new HashMap<>();
        isEnd = false;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */