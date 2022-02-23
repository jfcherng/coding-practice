from typing import Dict, List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups: Dict[str, List[str]] = defaultdict(list)
        for s in strs:
            groups[''.join(sorted(s))].append(s)
        return list(groups.values())


s = Solution()
res = s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])

print(f"{res = }")
