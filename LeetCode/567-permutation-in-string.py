from collections import Counter, defaultdict
from typing import Dict


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        wSize = len(s1)  # window size
        cnt1 = Counter(s1)
        cnt2: Dict[str, int] = defaultdict(int)  # counter of the sliding window

        s2 = "#" * wSize + s2  # laziness
        for i in range(wSize, len(s2)):
            cnt2[s2[i]] += 1
            cnt2[s2[i - wSize]] -= 1

            if all(cnt <= cnt2[c] for c, cnt in cnt1.items()):
                return True

        return False


s = Solution()

res = s.checkInclusion("ab", "eidboaoo")
print(f"{res = } (False)")

res = s.checkInclusion("adc", "dcda")
print(f"{res = } (True)")
