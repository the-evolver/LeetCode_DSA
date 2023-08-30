class Solution {
    
    Trie root = new Trie();
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        for(String word : wordDict) {
            addWord(word, root);
        }
        List<String> res = new ArrayList<>();
        List<String> current = new ArrayList<>();
        dfs(s, 0, root, current, res);
        return res;
    }
    private void dfs(String s, int index, Trie node, List<String> current, List<String> res) {
        if(index == s.length()) {
            if(node == root) {
                res.add(String.join(" ", current));
            }
            return;
        }
        if(node == null) return;//invalid
        Trie trie = node.next[s.charAt(index) - 'a'];
        if(trie != null && trie.isWord) {
            current.add(trie.word);
            dfs(s, index + 1, root, current, res);
            current.remove(current.size() - 1);
        }
        dfs(s, index + 1, trie, current, res);
    }
    private void addWord(String word, Trie dic) {
        Trie ptr = root;
        for(int i = 0; i < word.length(); ++i) {
            int idx = word.charAt(i) - 'a';
            if(ptr.next[idx] == null) ptr.next[idx] = new Trie();
            ptr = ptr.next[idx];
        }
        ptr.isWord = true;
        ptr.word = word;
    }
    
    class Trie {
        boolean isWord;
        String word;
        Trie[] next;
        Trie() {
            next = new Trie[26];
        }
    }
}