from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()

        res = 0
        l, r = 0, len(people) - 1

        while l <= r:
            # the lightest person can share with the heaviest person?
            if people[r] + people[l] <= limit:
                l += 1
            # handle the heaviest person
            r -= 1
            res += 1

        return res


s = Solution()

res = s.numRescueBoats([3, 2, 2, 1], 3)
print(f"{res = }")
