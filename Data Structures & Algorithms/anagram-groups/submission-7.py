class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash={}

        for s in strs:
            count=[0]*26

            for c in s:
                count[ord(c)-ord('a')]+=1

            key = str(count[0])
            for i in range(26):
                key += "," +str(count[i])
            if key not in hash:
                hash[key] = []
            hash[key].append(s)

        res =[]
        for i in hash.values():
            res.append(i)

        return res
        