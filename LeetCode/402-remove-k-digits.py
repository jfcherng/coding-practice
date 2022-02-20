class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        rm_idx = 0
        nums = list(num)
        while k > 0 and nums:
            while rm_idx < len(nums) - 1 and nums[rm_idx] <= nums[rm_idx + 1]:
                rm_idx += 1

            nums.pop(rm_idx)
            rm_idx = max(0, rm_idx - 1)
            k -= 1

        return "".join(nums).lstrip("0") or "0"


s = Solution()
res = s.removeKdigits("1432219", 3)
# res = s.removeKdigits("12345", 2)

print(f"{res = }")
