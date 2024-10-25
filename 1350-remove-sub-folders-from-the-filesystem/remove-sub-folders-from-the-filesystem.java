class Solution {
    class TrieNode {
        char ch;
        int id;
        TrieNode lt;
        TrieNode mid;
        TrieNode rt;

        public TrieNode(char ch) {
            this.ch = ch;
            this.id = -1;
        }
    }

    List<String> rootFolders;

    public List<String> removeSubfolders(String[] folders) {
        Arrays.sort(folders, (a, b) -> (a.length() - b.length()));
        rootFolders = new ArrayList<>();

        TrieNode root = null;
        for (int id = 0; id < folders.length; id++) {
            root = insertInTrie(root, folders[id], id, 1);
        }

        return rootFolders;
    }

    private TrieNode insertInTrie(TrieNode node, String folder, int id, int strId) {
        if (strId >= folder.length()) {
            return node;
        }

        char ch = folder.charAt(strId);
        if (node == null) {
            node = new TrieNode(ch);
        }

        if (ch == node.ch) {
            if (strId == folder.length() - 1) {
                node.id = id;
                rootFolders.add(folder);
            }

            if (node.id != -1 && (strId < folder.length() - 1 && folder.charAt(strId + 1) == '/')) {
                return node;
            }
            
            node.mid = insertInTrie(node.mid, folder, id, strId + 1);
        } else if (ch < node.ch) {
            node.lt = insertInTrie(node.lt, folder, id, strId);
        } else {
            node.rt = insertInTrie(node.rt, folder, id, strId);
        }

        return node;
    }
}