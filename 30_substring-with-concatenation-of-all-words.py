class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_freq = Counter(words)
        table = {}

        index_list = []

        concat_len = len(words[0]) * len(words)

        for i in range(len(s)-concat_len+1):
            substr = s[i:i+concat_len]
            table.clear()
            
            match = True
            for j in range(len(words)):
                word = substr[j*len(words[0]):(j+1)*len(words[0])]
                
                if word in word_freq and table.get(word, 0) < word_freq[word]:
                    table[word] = table.get(word, 0) + 1
                else:
                    match = False
                    break
            
            if match:
                index_list.append(i)
        
        return index_list
