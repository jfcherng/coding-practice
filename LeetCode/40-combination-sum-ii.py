from collections import defaultdict, Counter
from typing import DefaultDict, List, Set, Tuple


class Solution:
    def combinationSum2_bt(self, nums: List[int], target: int) -> List[List[int]]:
        def bt(idx: int, target: int) -> None:
            if target == 0:
                res.append(combination.copy())
                return

            if idx == len(unums) or (num := unums[idx]) > target:
                return

            # pick current num
            if counter[num] > 0:
                combination.append(num)
                counter[num] -= 1
                bt(idx, target - num)
                combination.pop()
                counter[num] += 1

            # don't pick current num
            bt(idx + 1, target)

        res: List[List[int]] = []
        counter = Counter(nums)
        unums = sorted(counter.keys())  # unique nums (sorted)
        combination: List[int] = []
        bt(0, target)
        return res

    def combinationSum2_dfs_mnemonic(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()

        cache: DefaultDict[int, Set[Tuple[int, ...]]] = defaultdict(set)
        cache[0] = {tuple()}

        for num in nums:
            if num > target:
                break
            # newly added cache for this run
            cache_tmp: DefaultDict[int, Set[Tuple[int, ...]]] = defaultdict(set)
            for carry, combs in cache.items():
                if (new_carry := num + carry) > target:
                    continue
                for comb in combs:
                    cache_tmp[new_carry].add(comb + (num,))
            # update cache
            for carry in cache_tmp.keys():
                cache[carry] |= cache_tmp[carry]

        return list(map(list, cache[target]))

    combinationSum2 = combinationSum2_bt


s = Solution()

res = s.combinationSum2([4, 4, 2, 1, 4, 2, 2, 1, 3], 6)
print(f"{res = }")
