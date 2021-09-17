namespace Model
{
    public class NodeTrie
    {
        static readonly int ALPHABET_SIZE = 26;
        public NodeTrie[] children;
        public bool isEndOfWord;
        public int freq; // To store frequency
        public NodeTrie()
        {
            children = new NodeTrie[ALPHABET_SIZE];
            freq = 1;
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
        public NodeTrie(int size)
        {
            children = new NodeTrie[size];
            freq = 1;
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
    }
}
